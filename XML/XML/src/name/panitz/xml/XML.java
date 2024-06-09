


package name.panitz.xml;

import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.Attributes;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.SAXParserFactory;
import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.XMLEvent;
import javax.xml.transform.Source;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.stream.StreamResult;
import javax.xml.transform.stream.StreamSource;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathExpressionException;
import javax.xml.xpath.XPathFactory;
import java.io.*;
import java.util.*;
import java.util.concurrent.ConcurrentHashMap;


public interface XML {


	XML setParent(XML parent);

	XML parentNode();


	public static record Text(String text, XML parentNode) implements XML {
		public XML setParent(XML parent) {
			return new Text(text, parent);
		}

		@Override
		public String toString() {
			return "Text[" + text + "]";
		}
	}


	public static record
	Element(String name, List<XML> childNodes, Map<String, String> attributes, XML parentNode)
			implements XML {
		public XML setParent(XML parent) {
			var newChildNodes = new ArrayList<XML>();
			var r = new Element(name, newChildNodes, attributes, parent);
			for (var cn : childNodes) newChildNodes.add(cn.setParent(r));
			return r;
		}

		@Override
		public String toString() {
			return "Element[" + name + "," + childNodes + "," + attributes + "]";
		}
	}


	default int count() {
		if (this instanceof Text t) return 1;
		else if (this instanceof Element e)
			return 1 + e.childNodes().parallelStream()
					.map(x -> x.count()).reduce(0, (r, x) -> r + x);
		throw new RuntimeException("unmatched pattern: " + this);
	}


	default void write(Writer out) throws IOException {
		if (this instanceof Text t) out.write(t.text);
		else if (this instanceof Element e) {
			out.write("<");
			out.write(e.name());
			for (var atr : e.attributes().entrySet()) {
				out.write(" ");
				out.write(atr.getKey());
				out.write("=\"");
				out.write(atr.getValue());
				out.write("\"");
			}
			;
			out.write(">");
			for (var c : e.childNodes()) c.write(out);
			out.write("</");
			out.write(e.name());
			out.write(">");
		}
	}


	default String show() {
		try {
			var out = new StringWriter();
			write(out);
			return out.toString();
		} catch (IOException e) {
			return "";
		}
	}


	public static Document parseXml(String xmlFileName) {
		try {
			return
					DocumentBuilderFactory
							.newInstance()
							.newDocumentBuilder()
							.parse(new File(xmlFileName));
		} catch (Exception e) {
			return null;
		}
	}


	static int count(Node n) {
		var result = 1;
		var cs = n.getChildNodes();
		for (var i = 0; i < cs.getLength(); i++) {
			result += count(cs.item(i));
		}
		return result;
	}


	static Set<String> tagNames(Node n) {
		var result = new TreeSet<String>();
		tagNames(n, result);
		return result;
	}


	static void tagNames(Node n, Set<String> result) {
		if (n.getNodeType() == Node.ELEMENT_NODE) result.add(n.getNodeName());
		var cs = n.getChildNodes();
		for (var i = 0; i < cs.getLength(); i++) {
			tagNames(cs.item(i), result);
		}
	}


	static XML toMyXML(Node n) {
		if (n.getNodeType() == Node.ELEMENT_NODE) {
			var ats = new TreeMap<String, String>();
			var as = n.getAttributes();
			for (var i = 0; i < as.getLength(); i++) {
				ats.put(as.item(i).getNodeName(), as.item(i).getNodeValue());
			}
			var children = new ArrayList<XML>();
			var r = new Element(n.getNodeName(), children, ats, null);
			var cs = n.getChildNodes();
			for (var i = 0; i < cs.getLength(); i++) {
				var cld = toMyXML(cs.item(i));
				if (cld != null)
					children.add(cld.setParent(r));
			}
			return r;
		} else if (n.getNodeType() == Node.TEXT_NODE
				|| n.getNodeType() == Node.CDATA_SECTION_NODE) {
			var t = n.getNodeValue().trim();
			return t.isEmpty() ? null : new Text(n.getNodeValue(), null);
		}
		if (n.getNodeType() == Node.DOCUMENT_NODE) {
			return toMyXML(n.getChildNodes().item(0));
		}
		throw new RuntimeException("unsuported node type: " + n);
	}


	public static void parse(File file, DefaultHandler handler)
			throws Exception {
		SAXParserFactory.newInstance()
				.newSAXParser()
				.parse(file, handler);
	}


	public static void parse(Reader reader, DefaultHandler handler)
			throws Exception {
		SAXParserFactory.newInstance()
				.newSAXParser()
				.parse(new InputSource(reader), handler);
	}


	public static class Count extends DefaultHandler {
		public int result = 0;

		@Override
		public void startElement(String uri, String localName, String qName,
		                         Attributes attributes) throws SAXException {
			result++;
		}
	}


	public static class GetTagNames extends DefaultHandler {
		public Set<String> result = new TreeSet<>();

		@Override
		public void startElement(String uri, String localName, String qName,
		                         Attributes attributes) throws SAXException {
			result.add(qName);
		}
	}


	public static class GetProgramCode extends DefaultHandler {
		public StringBuffer result = new StringBuffer();
		boolean isInCodeElement = false;

		@Override
		public void startElement
				(String uri, String localName, String qName, Attributes attributes)
				throws SAXException {
			if (qName.equals("code")) {
				isInCodeElement = true;
			}
		}

		@Override
		public void characters(char[] ch, int start, int length)
				throws SAXException {
			String text = new String(ch, start, length);
			if (isInCodeElement)
				result.append(text);
		}

		@Override
		public void endElement(String uri, String localName, String qName)
				throws SAXException {
			if (qName.equals("code")) {
				isInCodeElement = false;
			}
		}
	}


	static XMLEventReader staxReader(String fileName) throws XMLStreamException, IOException {
		return XMLInputFactory
				.newInstance()
				.createXMLEventReader(new FileReader(fileName));
	}


	static int count(XMLEventReader reader) {
		var result = 0;
		Iterable<Object> it = () -> reader;
		for (Object o : it) {
			var ev = (XMLEvent) o;
			if (ev.isStartElement()) result++;
		}
		return result;
	}


	public static NodeList evalXPath(String xpathExpression, Reader reader)
			throws XPathExpressionException {


		var xpath = XPathFactory.newInstance().newXPath();


		var ns = (NodeList) xpath.evaluate(xpathExpression,
				new InputSource(reader), XPathConstants.NODESET);
		return ns;
	}


	static public String transform(File xslt, File doc) {
		return transform(new StreamSource(doc), new StreamSource(doc));
	}

	static public String transform(Source xslt, Source doc) {
		try {
			StringWriter writer = new StringWriter();
			Transformer t =
					TransformerFactory
							.newInstance()
							.newTransformer(xslt);
			t.transform(doc, new StreamResult(writer));
			return writer.getBuffer().toString();
		} catch (TransformerException e) {
			return "";
		}
	}


	default long height() {
		if (this instanceof Text) return 1;
		else if (this instanceof Element e) {
			return 1 + e.childNodes().stream().mapToLong(XML::height).max().orElse(0L);
		}
		throw new RuntimeException("unmatched pattern: " + this);
	}


	public static enum Axes {
		self, child, descendant, descendant_or_self, parent, ancestor, ancestor_or_self, following_sibling, following, preceding_sibling, preceding;
	}

	public default List<XML> select(Axes ax) {
		return switch (ax) {
			case self -> self();
			case child -> child();
			case descendant -> descendant();
			case descendant_or_self -> descendantOrSelf();
			case parent -> parent();
			case ancestor -> ancestor();
			case ancestor_or_self -> ancestorOrSelf();
			case following_sibling -> followingSibling();
			case following -> following();
			case preceding_sibling -> precedingSibling();
			case preceding -> preceding();
		};
	}

	public default List<XML> self() {
		return self(new ArrayList<>());
	}


	public default List<XML> self(List<XML> result) {
		result.add(this);
		return result;
	}

	public default List<XML> child() {
		return child(new ArrayList<>());
	}


	public default List<XML> child(List<XML> result) {
		if (this instanceof Element e) result.addAll(e.childNodes());
		return result;
	}

	public default List<XML> descendant() {
		return descendant(new ArrayList<>());
	}


	public default List<XML> descendant(List<XML> result) {
		if (this instanceof Element e) {
			result.addAll(e.childNodes());
			for (var child : e.childNodes())
				child.descendant(result);
		}
		return result;
	}

	public default List<XML> descendantOrSelf() {
		return descendantOrSelf(new ArrayList<>());
	}


	public default List<XML> descendantOrSelf(List<XML> result) {
		result.add(this);
		descendant(result);
		return result;
	}

	public default List<XML> parent() {
		return parent(new ArrayList<>());
	}


	public default List<XML> parent(List<XML> result) {
		if (parentNode() != null) result.add(parentNode());
		return result;
	}

	public default List<XML> ancestor() {
		return ancestor(new ArrayList<>());
	}


	public default List<XML> ancestor(List<XML> result) {
		if (parentNode() != null) {
			result.add(parentNode());
			parentNode().ancestor(result);
		}
		return result;
	}

	public default List<XML> ancestorOrSelf() {
		return ancestorOrSelf(new ArrayList<>());
	}


	public default List<XML> ancestorOrSelf(List<XML> result) {
		result.add(this);
		ancestor(result);
		return result;
	}

	public default List<XML> followingSibling() {
		return followingSibling(new ArrayList<>());
	}


	public default List<XML> followingSibling(List<XML> result) {
		if (parentNode() instanceof Element e) {
			boolean self = false;
			for (var child : e.childNodes) {
				if (self) result.add(child);
				if (child == this) self = true;
			}
		}
		return result;
	}

	public default List<XML> precedingSibling() {
		return precedingSibling(new ArrayList<>());
	}


	public default List<XML> precedingSibling(List<XML> result) {
		if (parentNode() instanceof Element e) {
			for (var child : e.childNodes) {
				if (child == this) break;
				result.add(child);
			}
		}
		return result;
	}

	public default List<XML> following() {
		return following(new ArrayList<>());
	}


	public default List<XML> following(List<XML> result) {
		//Manus Lösung
		for (var ancestor : ancestorOrSelf()) {
			for (var sibling : ancestor.followingSibling()) result.addAll(sibling.descendantOrSelf());
		}
		return result;

	}

	public default List<XML> preceding() {
		return preceding(new ArrayList<>());
	}


	public default List<XML> preceding(List<XML> result) {
		// meine Lösung, geht auch klar
		if (parentNode() == null) return result;

		if (parentNode() instanceof Element e) {
			for (XML child : e.childNodes()) {
				if (child == this) break;
				else {
					result.add(child);
					result.addAll(child.descendant());
				}
			}
		}
		return parentNode().preceding(result);
	}


	public static class DOMUtil {


		public static long height(Node n) {
			if (n == null) return 0;

			long height = 0;
			for (int i = 0; i < n.getChildNodes().getLength(); i++)
				height = Math.max(height, height(n.getChildNodes().item(i)));

			return n.hasChildNodes() ? 1 + height : 1;
		}


		public static String text(Node n) {
			StringBuffer result = new StringBuffer();
			collectText(n, result);
			return result.toString();
		}


		public static void collectText(Node n, StringBuffer result) {
			if (n.getNodeType() == Node.TEXT_NODE) result.append(n.getNodeValue());

			if (n.hasChildNodes())
				for (int i = 0; i < n.getChildNodes().getLength(); i++) collectText(n.getChildNodes().item(i), result);

		}


		public static boolean containsTag(Node n, String tagname) {
			return false;
		}


		public static Set<String> collectTagnames(Node n) {
			Set<String> result = ConcurrentHashMap.newKeySet();
			collectTagnames(n, result);
			return result;
		}


		public static void collectTagnames(Node n, Set<String> result) {
			if (n.getNodeType() == Node.ELEMENT_NODE) result.add(n.getNodeName());

			for (int i = 0; i < n.getChildNodes().getLength(); i++) collectTagnames(n.getChildNodes().item(i), result);
		}


		public static long getMaxHAttributeValue(Node n, String attrKey) {
			long result = 0;
			if (n.getNodeType() == Node.ELEMENT_NODE) {
				Node attributes = n.getAttributes().getNamedItem(attrKey);
				if (attributes != null) {
					String max = attributes.getNodeValue();
					result = Long.parseLong(max);
				}
			}
			for (int i = 0; i < n.getChildNodes().getLength(); i++) {
				long childMax = getMaxHAttributeValue(n.getChildNodes().item(i), attrKey);
				result = Math.max(result, childMax);
			}
			return result;
		}
	}


	public static class GetBirthYears extends DefaultHandler {
		public Set<Integer> result = new HashSet<>();

		public void startElement(String uri, String localName, String qName, Attributes attributes) {
			if ("element".equals(qName)) {
				String attribute = attributes.getValue("born");
				if (attribute != null) result.add(Integer.parseInt(attribute));
			}
		}

	}


}
