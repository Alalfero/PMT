
grammar JsonGrammar;
@header {
package name.panitz.json;
import static name.panitz.json.Json.*;
}
obj returns[JsonObject result]
   : '{' pair (',' pair)* '}'
   | '{' '}';
pair returns[Pair<String,Json> result]
   : stringB ':' json;
arr returns[Json result]
   : '[' json (',' json)* ']'
   | '[' ']' ;
json returns[Json result]
   : nullB
   | NUMBER
   | obj
   | arr
   | trueB
   | falseB
   | stringB ;
nullB: 'null';
trueB: 'true';
falseB: 'false';
stringB  returns[String result]: STRING;



STRING: '"' (ESC | SAFECODEPOINT)* '"';
fragment ESC: '\\' (["\\/bfnrt] | UNICODE);
fragment UNICODE: 'u' HEX HEX HEX HEX;
fragment HEX: [0-9a-fA-F];
fragment SAFECODEPOINT: ~ ["\\\u0000-\u001F];
NUMBER:  ('-')?INT ('.' [0-9] +)? EXP?;
fragment INT: '0' |  [1-9] [0-9]*;
fragment EXP: [Ee] [+\-]? INT;
WS: [ \t\n\r] + -> skip;


