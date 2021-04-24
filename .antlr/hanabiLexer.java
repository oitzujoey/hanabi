// Generated from c:\Users\ethan\Documents\GitHub\hanabi\hanabi.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class hanabiLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		AND=1, OR=2, XOR=3, GREATER=4, LESSER=5, SHIFT_LEFT=6, SHIFT_RIGHT=7, 
		STRING=8, ALPHANUMERIC=9, ATTRIBUTE=10, NUMBER=11, PLUS=12, MINUS=13, 
		MULTIPLY=14, DIVIDE=15, NOOK=16, COMMENT=17, ENDLINE=18, PIPE=19, PASS=20, 
		INITIALIZE=21, COMPILERMOD=22, PREPROCESS=23, MULTI_CRMD0=24, MULTI_CRMD1=25, 
		MULTI_PRE0=26, MULTI_PRE1=27, TABBING=28, WHITESPACE=29;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"AND", "OR", "XOR", "GREATER", "LESSER", "SHIFT_LEFT", "SHIFT_RIGHT", 
			"STRING", "ALPHANUMERIC", "ATTRIBUTE", "NUMBER", "PLUS", "MINUS", "MULTIPLY", 
			"DIVIDE", "NOOK", "COMMENT", "ENDLINE", "PIPE", "PASS", "INITIALIZE", 
			"COMPILERMOD", "PREPROCESS", "MULTI_CRMD0", "MULTI_CRMD1", "MULTI_PRE0", 
			"MULTI_PRE1", "TABBING", "WHITESPACE"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'and'", "'or'", "'xor'", "'>'", "'<'", "'<<'", "'>>'", null, null, 
			"'--'", null, "'+'", "'-'", "'*'", "'/'", "':'", "';'", "'\n'", "'|'", 
			"'#'", "'@'", "'%%'", "'%'", "'%%/'", "'/%%'", "'%/'", "'/%'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "AND", "OR", "XOR", "GREATER", "LESSER", "SHIFT_LEFT", "SHIFT_RIGHT", 
			"STRING", "ALPHANUMERIC", "ATTRIBUTE", "NUMBER", "PLUS", "MINUS", "MULTIPLY", 
			"DIVIDE", "NOOK", "COMMENT", "ENDLINE", "PIPE", "PASS", "INITIALIZE", 
			"COMPILERMOD", "PREPROCESS", "MULTI_CRMD0", "MULTI_CRMD1", "MULTI_PRE0", 
			"MULTI_PRE1", "TABBING", "WHITESPACE"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public hanabiLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "hanabi.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\37\u00af\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\3\2\3\2\3\2\3"+
		"\2\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\7\3\b\3\b\3\b"+
		"\3\t\3\t\7\tU\n\t\f\t\16\tX\13\t\3\t\3\t\7\t\\\n\t\f\t\16\t_\13\t\3\t"+
		"\3\t\3\t\7\td\n\t\f\t\16\tg\13\t\3\t\3\t\5\tk\n\t\3\t\5\tn\n\t\3\n\6\n"+
		"q\n\n\r\n\16\nr\3\13\3\13\3\13\3\f\6\fy\n\f\r\f\16\fz\3\r\3\r\3\16\3\16"+
		"\3\17\3\17\3\20\3\20\3\21\3\21\3\22\3\22\3\23\3\23\3\24\3\24\3\25\3\25"+
		"\3\26\3\26\3\27\3\27\3\27\3\30\3\30\3\31\3\31\3\31\3\31\3\32\3\32\3\32"+
		"\3\32\3\33\3\33\3\33\3\34\3\34\3\34\3\35\3\35\3\35\3\35\3\35\5\35\u00a9"+
		"\n\35\3\36\6\36\u00ac\n\36\r\36\16\36\u00ad\2\2\37\3\3\5\4\7\5\t\6\13"+
		"\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'"+
		"\25)\26+\27-\30/\31\61\32\63\33\65\34\67\359\36;\37\3\2\6\3\2$$\3\2))"+
		"\5\2\62;C\\c|\3\2\62;\2\u00b8\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t"+
		"\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2"+
		"\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2"+
		"\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2"+
		"+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2"+
		"\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\3=\3\2\2\2\5A\3\2\2\2\7D\3\2\2\2\t"+
		"H\3\2\2\2\13J\3\2\2\2\rL\3\2\2\2\17O\3\2\2\2\21m\3\2\2\2\23p\3\2\2\2\25"+
		"t\3\2\2\2\27x\3\2\2\2\31|\3\2\2\2\33~\3\2\2\2\35\u0080\3\2\2\2\37\u0082"+
		"\3\2\2\2!\u0084\3\2\2\2#\u0086\3\2\2\2%\u0088\3\2\2\2\'\u008a\3\2\2\2"+
		")\u008c\3\2\2\2+\u008e\3\2\2\2-\u0090\3\2\2\2/\u0093\3\2\2\2\61\u0095"+
		"\3\2\2\2\63\u0099\3\2\2\2\65\u009d\3\2\2\2\67\u00a0\3\2\2\29\u00a8\3\2"+
		"\2\2;\u00ab\3\2\2\2=>\7c\2\2>?\7p\2\2?@\7f\2\2@\4\3\2\2\2AB\7q\2\2BC\7"+
		"t\2\2C\6\3\2\2\2DE\7z\2\2EF\7q\2\2FG\7t\2\2G\b\3\2\2\2HI\7@\2\2I\n\3\2"+
		"\2\2JK\7>\2\2K\f\3\2\2\2LM\7>\2\2MN\7>\2\2N\16\3\2\2\2OP\7@\2\2PQ\7@\2"+
		"\2Q\20\3\2\2\2R]\7$\2\2SU\n\2\2\2TS\3\2\2\2UX\3\2\2\2VT\3\2\2\2VW\3\2"+
		"\2\2W\\\3\2\2\2XV\3\2\2\2YZ\7^\2\2Z\\\13\2\2\2[V\3\2\2\2[Y\3\2\2\2\\_"+
		"\3\2\2\2][\3\2\2\2]^\3\2\2\2^`\3\2\2\2_]\3\2\2\2`n\7$\2\2aj\7)\2\2bd\n"+
		"\3\2\2cb\3\2\2\2dg\3\2\2\2ec\3\2\2\2ef\3\2\2\2fk\3\2\2\2ge\3\2\2\2hi\7"+
		"^\2\2ik\13\2\2\2je\3\2\2\2jh\3\2\2\2kl\3\2\2\2ln\7)\2\2mR\3\2\2\2ma\3"+
		"\2\2\2n\22\3\2\2\2oq\t\4\2\2po\3\2\2\2qr\3\2\2\2rp\3\2\2\2rs\3\2\2\2s"+
		"\24\3\2\2\2tu\7/\2\2uv\7/\2\2v\26\3\2\2\2wy\t\5\2\2xw\3\2\2\2yz\3\2\2"+
		"\2zx\3\2\2\2z{\3\2\2\2{\30\3\2\2\2|}\7-\2\2}\32\3\2\2\2~\177\7/\2\2\177"+
		"\34\3\2\2\2\u0080\u0081\7,\2\2\u0081\36\3\2\2\2\u0082\u0083\7\61\2\2\u0083"+
		" \3\2\2\2\u0084\u0085\7<\2\2\u0085\"\3\2\2\2\u0086\u0087\7=\2\2\u0087"+
		"$\3\2\2\2\u0088\u0089\7\f\2\2\u0089&\3\2\2\2\u008a\u008b\7~\2\2\u008b"+
		"(\3\2\2\2\u008c\u008d\7%\2\2\u008d*\3\2\2\2\u008e\u008f\7B\2\2\u008f,"+
		"\3\2\2\2\u0090\u0091\7\'\2\2\u0091\u0092\7\'\2\2\u0092.\3\2\2\2\u0093"+
		"\u0094\7\'\2\2\u0094\60\3\2\2\2\u0095\u0096\7\'\2\2\u0096\u0097\7\'\2"+
		"\2\u0097\u0098\7\61\2\2\u0098\62\3\2\2\2\u0099\u009a\7\61\2\2\u009a\u009b"+
		"\7\'\2\2\u009b\u009c\7\'\2\2\u009c\64\3\2\2\2\u009d\u009e\7\'\2\2\u009e"+
		"\u009f\7\61\2\2\u009f\66\3\2\2\2\u00a0\u00a1\7\61\2\2\u00a1\u00a2\7\'"+
		"\2\2\u00a28\3\2\2\2\u00a3\u00a4\7\"\2\2\u00a4\u00a5\7\"\2\2\u00a5\u00a6"+
		"\7\"\2\2\u00a6\u00a9\7\"\2\2\u00a7\u00a9\7\13\2\2\u00a8\u00a3\3\2\2\2"+
		"\u00a8\u00a7\3\2\2\2\u00a9:\3\2\2\2\u00aa\u00ac\7\"\2\2\u00ab\u00aa\3"+
		"\2\2\2\u00ac\u00ad\3\2\2\2\u00ad\u00ab\3\2\2\2\u00ad\u00ae\3\2\2\2\u00ae"+
		"<\3\2\2\2\r\2V[]ejmrz\u00a8\u00ad\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}