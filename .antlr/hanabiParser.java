// Generated from c:\Users\ethan\Documents\GitHub\hanabi\hanabi.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class hanabiParser extends Parser {
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
	public static final int
		RULE_nook_init = 0, RULE_nook = 1, RULE_directive = 2, RULE_value = 3, 
		RULE_operation = 4;
	private static String[] makeRuleNames() {
		return new String[] {
			"nook_init", "nook", "directive", "value", "operation"
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

	@Override
	public String getGrammarFileName() { return "hanabi.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public hanabiParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class Nook_initContext extends ParserRuleContext {
		public TerminalNode INITIALIZE() { return getToken(hanabiParser.INITIALIZE, 0); }
		public List<TerminalNode> ALPHANUMERIC() { return getTokens(hanabiParser.ALPHANUMERIC); }
		public TerminalNode ALPHANUMERIC(int i) {
			return getToken(hanabiParser.ALPHANUMERIC, i);
		}
		public List<TerminalNode> ATTRIBUTE() { return getTokens(hanabiParser.ATTRIBUTE); }
		public TerminalNode ATTRIBUTE(int i) {
			return getToken(hanabiParser.ATTRIBUTE, i);
		}
		public List<TerminalNode> WHITESPACE() { return getTokens(hanabiParser.WHITESPACE); }
		public TerminalNode WHITESPACE(int i) {
			return getToken(hanabiParser.WHITESPACE, i);
		}
		public Nook_initContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nook_init; }
	}

	public final Nook_initContext nook_init() throws RecognitionException {
		Nook_initContext _localctx = new Nook_initContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_nook_init);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(10);
			match(INITIALIZE);
			setState(11);
			match(ALPHANUMERIC);
			setState(23);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				{
				setState(12);
				match(ATTRIBUTE);
				setState(13);
				match(ALPHANUMERIC);
				setState(15); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(14);
					match(WHITESPACE);
					}
					}
					setState(17); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==WHITESPACE );
				setState(19);
				match(ATTRIBUTE);
				setState(20);
				match(ALPHANUMERIC);
				}
				break;
			case 2:
				{
				setState(21);
				match(ATTRIBUTE);
				setState(22);
				match(ALPHANUMERIC);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NookContext extends ParserRuleContext {
		public TerminalNode NOOK() { return getToken(hanabiParser.NOOK, 0); }
		public List<Nook_initContext> nook_init() {
			return getRuleContexts(Nook_initContext.class);
		}
		public Nook_initContext nook_init(int i) {
			return getRuleContext(Nook_initContext.class,i);
		}
		public List<DirectiveContext> directive() {
			return getRuleContexts(DirectiveContext.class);
		}
		public DirectiveContext directive(int i) {
			return getRuleContext(DirectiveContext.class,i);
		}
		public List<TerminalNode> WHITESPACE() { return getTokens(hanabiParser.WHITESPACE); }
		public TerminalNode WHITESPACE(int i) {
			return getToken(hanabiParser.WHITESPACE, i);
		}
		public NookContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nook; }
	}

	public final NookContext nook() throws RecognitionException {
		NookContext _localctx = new NookContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_nook);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(25);
			match(NOOK);
			setState(29);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==INITIALIZE) {
				{
				{
				setState(26);
				nook_init();
				}
				}
				setState(31);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(41); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				setState(41);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
				case 1:
					{
					setState(32);
					directive();
					setState(34); 
					_errHandler.sync(this);
					_la = _input.LA(1);
					do {
						{
						{
						setState(33);
						match(WHITESPACE);
						}
						}
						setState(36); 
						_errHandler.sync(this);
						_la = _input.LA(1);
					} while ( _la==WHITESPACE );
					setState(38);
					directive();
					}
					break;
				case 2:
					{
					setState(40);
					directive();
					}
					break;
				}
				}
				setState(43); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << AND) | (1L << OR) | (1L << XOR) | (1L << GREATER) | (1L << LESSER) | (1L << PLUS) | (1L << MINUS))) != 0) );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DirectiveContext extends ParserRuleContext {
		public OperationContext operation() {
			return getRuleContext(OperationContext.class,0);
		}
		public List<ValueContext> value() {
			return getRuleContexts(ValueContext.class);
		}
		public ValueContext value(int i) {
			return getRuleContext(ValueContext.class,i);
		}
		public DirectiveContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_directive; }
	}

	public final DirectiveContext directive() throws RecognitionException {
		DirectiveContext _localctx = new DirectiveContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_directive);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(45);
			operation();
			setState(46);
			value();
			setState(47);
			value();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ValueContext extends ParserRuleContext {
		public TerminalNode NUMBER() { return getToken(hanabiParser.NUMBER, 0); }
		public TerminalNode STRING() { return getToken(hanabiParser.STRING, 0); }
		public ValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_value; }
	}

	public final ValueContext value() throws RecognitionException {
		ValueContext _localctx = new ValueContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_value);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(49);
			_la = _input.LA(1);
			if ( !(_la==STRING || _la==NUMBER) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class OperationContext extends ParserRuleContext {
		public TerminalNode PLUS() { return getToken(hanabiParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(hanabiParser.MINUS, 0); }
		public TerminalNode AND() { return getToken(hanabiParser.AND, 0); }
		public TerminalNode OR() { return getToken(hanabiParser.OR, 0); }
		public TerminalNode XOR() { return getToken(hanabiParser.XOR, 0); }
		public TerminalNode GREATER() { return getToken(hanabiParser.GREATER, 0); }
		public TerminalNode LESSER() { return getToken(hanabiParser.LESSER, 0); }
		public OperationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_operation; }
	}

	public final OperationContext operation() throws RecognitionException {
		OperationContext _localctx = new OperationContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_operation);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(51);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << AND) | (1L << OR) | (1L << XOR) | (1L << GREATER) | (1L << LESSER) | (1L << PLUS) | (1L << MINUS))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\378\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\3\2\3\2\3\2\3\2\3\2\6\2\22\n\2\r\2\16\2\23"+
		"\3\2\3\2\3\2\3\2\5\2\32\n\2\3\3\3\3\7\3\36\n\3\f\3\16\3!\13\3\3\3\3\3"+
		"\6\3%\n\3\r\3\16\3&\3\3\3\3\3\3\6\3,\n\3\r\3\16\3-\3\4\3\4\3\4\3\4\3\5"+
		"\3\5\3\6\3\6\3\6\2\2\7\2\4\6\b\n\2\4\4\2\n\n\r\r\4\2\3\7\16\17\28\2\f"+
		"\3\2\2\2\4\33\3\2\2\2\6/\3\2\2\2\b\63\3\2\2\2\n\65\3\2\2\2\f\r\7\27\2"+
		"\2\r\31\7\13\2\2\16\17\7\f\2\2\17\21\7\13\2\2\20\22\7\37\2\2\21\20\3\2"+
		"\2\2\22\23\3\2\2\2\23\21\3\2\2\2\23\24\3\2\2\2\24\25\3\2\2\2\25\26\7\f"+
		"\2\2\26\32\7\13\2\2\27\30\7\f\2\2\30\32\7\13\2\2\31\16\3\2\2\2\31\27\3"+
		"\2\2\2\32\3\3\2\2\2\33\37\7\22\2\2\34\36\5\2\2\2\35\34\3\2\2\2\36!\3\2"+
		"\2\2\37\35\3\2\2\2\37 \3\2\2\2 +\3\2\2\2!\37\3\2\2\2\"$\5\6\4\2#%\7\37"+
		"\2\2$#\3\2\2\2%&\3\2\2\2&$\3\2\2\2&\'\3\2\2\2\'(\3\2\2\2()\5\6\4\2),\3"+
		"\2\2\2*,\5\6\4\2+\"\3\2\2\2+*\3\2\2\2,-\3\2\2\2-+\3\2\2\2-.\3\2\2\2.\5"+
		"\3\2\2\2/\60\5\n\6\2\60\61\5\b\5\2\61\62\5\b\5\2\62\7\3\2\2\2\63\64\t"+
		"\2\2\2\64\t\3\2\2\2\65\66\t\3\2\2\66\13\3\2\2\2\b\23\31\37&+-";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}