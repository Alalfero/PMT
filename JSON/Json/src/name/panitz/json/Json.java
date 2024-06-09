package name.panitz.json;

import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTreeWalker;
import org.bson.Document;

import javax.print.Doc;
import java.io.Reader;
import java.io.StringWriter;
import java.io.Writer;
import java.util.*;
import java.util.function.Consumer;


public interface Json {


	static String ex1 = """
			{ "vorname": "Eva"
			, "name": "Luator"
			, "gebJahr": 1962
			}
			""";


	static String xs = """
			{ "head": 1
			, "tail": 
			  { "head": 2
			  , "tail": 
			    { "head": 3
			    , "tail":
			       { "head": 4
			       , "tail": null
			       }
			    }
			  }
			}
			""";


	static String windsor = """
			{ "name": "George"
			, "children": 
			  [{ "name": "Elizabeth"
			   , "children":  
			     [{ "name": "Charles"
			      , "children": 
			        [{ "name": "William"
			         , "children": 
			           [{"name":"George"},{"name":"Charlotte"},{"name":"Louise"}]}
			        ,{ "name": "Henry","children": [{ "name": "Archie"}]}
			      ]}
			     ,{ "name": "Anne"
			      , "children" :
			         [{ "name": "Peter"
			          , "children": [{ "name": "Savannah"},{ "name": "Isla"}]}
			         ,{ "name": "Zara","children":[{ "name": "Mia"},{ "name": "Lena"}]}
			         ]}
			     ,{ "name": "Andrew"
			      , "children": [{"name":"Beatrice"},{"name": "Eugenie"}]}
			     ,{ "name": "Edward"
			      , "children": [{"name":"Louise"},{ "name": "James"}]}]}
			  ,{ "name": "Magaret"
			   , "children":  
			     [{ "name": "David"
			      , "children": [{ "name": "Charles"},{ "name": "Margarita"}]}
			     ,{ "name": "Sarah"
			      , "children": [{ "name": "Samuel"},{ "name": "Arthur"}]}
			     ]}
			  ]}
			""";


	public static record JsonLong(long n) implements Json {
	}


	public static record JsonDouble(double n) implements Json {
	}


	public static record JsonBoolean(boolean b) implements Json {
	}


	public static record JsonString(String s) implements Json {
	}


	public static record JsonObject(Map<String, Json> map) implements Json {
	}


	public static record JsonArray(List<Json> elements) implements Json {
	}


	public static JsonObject parse(Reader in) throws Exception {
		var codePointCharStream = CharStreams.fromReader(in);
		var lexer = new JsonGrammarLexer(codePointCharStream);
		var parser = new JsonGrammarParser(new CommonTokenStream(lexer));

		var tree = parser.obj();
		ParseTreeWalker.DEFAULT.walk(new JsonTreeBuilder(), tree);
		return tree.result;
	}


	default void forEach(Consumer<JsonObject> consume) {
		if (this instanceof JsonObject jsonObject) {
			consume.accept(jsonObject);
			for (Json value : jsonObject.map.values()) if (value != null) value.forEach(consume);
		} else if (this instanceof JsonArray jsonArray) {
			for (Json elem : jsonArray.elements()) if (elem != null) elem.forEach(consume);
		}
	}


	default Set<String> collectNames() {
		var result = new HashSet<String>();
		collectNames(result);
		return result;
	}


	default void collectNames(Set<String> result) {

		if (this instanceof JsonObject jsonObject) {
			if (jsonObject.map.get("name") instanceof JsonString jsonString) result.add(jsonString.s());
			for (Json value : jsonObject.map.values()) if (value != null) value.collectNames(result);
		} else if (this instanceof JsonArray jsonArray) {
			for (Json elem : jsonArray.elements) if (elem != null) elem.collectNames(result);
		}
	}


	default void write(Writer out) throws Exception {
		write("\n", out);
	}


	default void write(String indent, Writer out) throws Exception {
		if (this instanceof JsonString s) out.write("\"" + s.s + "\"");
		else if (this instanceof JsonLong l) out.write(l.n + "");
		else if (this instanceof JsonDouble d) out.write(d.n + "");
		else if (this instanceof JsonBoolean bo) out.write(bo.b ? "true" : "false");
		else if (this instanceof JsonObject o) {
			out.write("{");
			int index = 0;
			for (var entry : o.map().entrySet()) {
				out.write("\"" + entry.getKey() + "\": ");
				if (entry.getValue() != null) entry.getValue().write(indent, out);
				else out.write("null");

				if (index < o.map().size() - 1) out.write(", ");
				index++;
			}
			out.write("}");
		} else if (this instanceof JsonArray a) {
			out.write("[");
			int index = 0;
			for (Json elem : a.elements()) {
				if (elem != null) elem.write(indent, out);
				else out.write("null");

				if (index < a.elements().size() - 1) out.write(", ");
				index++;
			}
			out.write("]");
		} else
			throw new RuntimeException("Missing pattern: " + this.getClass());
	}


	default String show() {
		try {
			var out = new StringWriter();
			write(out);
			return out.toString();
		} catch (Exception e) {
			return "";
		}
	}


	static record Person(String name, String vorname, int gebJahr) {


		Json toJson() {
			var map = new HashMap<String, Json>();
			map.put("name", new JsonString(name));
			map.put("vorname", new JsonString(vorname));
			map.put("gebJahr", new JsonLong(gebJahr));
			return new JsonObject(map);
		}
	}


	default Person getPerson() {
		if (this instanceof JsonObject o) {
			if (o.map().containsKey("name") && o.map().containsKey("vorname") && o.map().containsKey("gebJahr")) {
				Json nameJ = o.map().get("name");
				Json vornameJ = o.map().get("vorname");
				Json gebJahrJ = o.map().get("gebJahr");

				if (nameJ instanceof JsonString && vornameJ instanceof JsonString && gebJahrJ instanceof JsonLong) {
					String name = ((JsonString) nameJ).s();
					String vorname = ((JsonString) vornameJ).s();
					int gebJahr = (int) ((JsonLong) gebJahrJ).n();
					return new Person(name, vorname, gebJahr);
				}
			}
		} else throw new RuntimeException("json not a Person: " + this.toString());

		return null;
	}


	default Document toBSON() {
		if (this instanceof JsonObject o) {
			return (Document) toBSON2();
		}
		return null;
	}


	default Object toBSON2() {
		if (this instanceof JsonObject o) {
			Document doc = new Document();
			for (var entry : o.map().entrySet()) {
				String key = entry.getKey();
				Json value = entry.getValue();
				if (value != null) doc.put(key, value.toBSON2());
				else doc.put(key, null);
			}
            return doc;
		}
        else if (this instanceof JsonDouble d) return d.n;
        else if (this instanceof JsonLong l) return l.n;
        else if (this instanceof JsonString s) return s.s;
        else if (this instanceof JsonBoolean bo) return bo.b;
        else if (this instanceof JsonArray a) {
          List<Object> bsonArray = new ArrayList<>();
          for (Json element : a.elements()) {
            bsonArray.add(element.toBSON2());
          }
          return bsonArray;
        }

		return null;
	}


	static Json toJson(Document bson) {
      //warum man
		try {
          if(bson == null) return null;
          Map<String, Json> map = new HashMap<>();
          for(var entry : bson.entrySet()){
            String entryKey = entry.getKey();
            Object entryValue = entry.getValue();
            if(entryValue instanceof String) map.put(entryKey, new JsonString(entryValue.toString()));
            else  if(entryValue instanceof Long) map.put(entryKey, new JsonLong((Long) entryValue));
            else  if(entryValue instanceof Double) map.put(entryKey, new JsonDouble((Double) entryValue));
            else  if(entryValue instanceof Document) map.put(entryKey, toJson((Document) entryValue));
            else  if(entryValue instanceof List) {
              List<Json> elements = new ArrayList<Json>();
                for( var elem : (List) entryValue){
                  if (elem instanceof Document) elements.add(toJson((Document) elem));
                  else if (elem instanceof Double) elements.add(new JsonDouble((Double) elem));
                  else if (elem instanceof String) elements.add(new JsonString((String) elem));
                  else if (elem instanceof Boolean) elements.add(new JsonBoolean((Boolean) elem));
                }
                map.put(entryKey, new JsonArray(elements));
            }
          }
          return new JsonObject(map);
        }
		catch (Exception e) {
			throw new RuntimeException(e);
		}
	}


	default void saveToCollection(String dbname, String collectionName) {
		var mongoClient = MongoClients.create();
		var database = mongoClient.getDatabase(dbname);
		var collection = database.getCollection(collectionName);
		collection.insertOne(toBSON());
	}


	static MongoCollection<Document>
	getCollection(String dbname, String collectionName) {
		var mongoClient = MongoClients.create();
		var database = mongoClient.getDatabase(dbname);
		return database.getCollection(collectionName);
	}


	static Set<String> getNames(String dbname, String collectionName) {
		var result = new HashSet<String>();
		var mongo = getCollection(dbname, collectionName);
		var docs = mongo.find();
		for (var doc : docs) {
          for(String key : doc.keySet()) if(key.equals("name") && doc.get(key) instanceof String)
			  result.add((String) doc.get(key));
        }
		return result;
	}


}
