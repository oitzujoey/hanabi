grammar hanabi;

// @these --for example
nook_init
    : INITIALIZE ALPHANUMERIC
        (
            ATTRIBUTE ALPHANUMERIC
            WHITESPACE+
            ATTRIBUTE ALPHANUMERIC
        |
            ATTRIBUTE ALPHANUMERIC
        );

nook
    : NOOK
        (nook_init)*
        (
            directive WHITESPACE+ directive
        |
            directive
        )+;

directive   : operation value value;
value       : (NUMBER | STRING);
operation   : (PLUS | MINUS | AND | OR | XOR | GREATER | LESSER);

AND : 'and';
OR  : 'or';
XOR : 'xor';

GREATER : '>';
LESSER  : '<';

SHIFT_LEFT  : '<<';
SHIFT_RIGHT : '>>';

STRING
 : '"' ( ~["]* | '\\' . )* '"'
 | '\'' ( ~[']* | '\\' . ) '\''
 ;
ALPHANUMERIC
  : ('a'..'z' | 'A'..'Z' | '0'..'9')+;

ATTRIBUTE   : '--';
NUMBER      : [0-9]+;
PLUS        : '+';
MINUS       : '-';
MULTIPLY    : '*';
DIVIDE      : '/';
NOOK        : ':';
COMMENT     : ';';
ENDLINE     : '\n';
PIPE        : '|';
PASS        : '#';
INITIALIZE  : '@';
COMPILERMOD : '%%';
PREPROCESS  : '%';
MULTI_CRMD0 : '%%/';
MULTI_CRMD1 : '/%%';
MULTI_PRE0  : '%/';
MULTI_PRE1  : '/%';
TABBING     : ('    '|'\t');
WHITESPACE  : (' ')+;