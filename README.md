### Notes

- Hanabi is in a Pre-Alpha state. There are no execution functions, and very few functions are indeed active. Updates will come as need be.

# Hanabi Programming Language

![](https://github.com/EHowardHill/hanabi/blob/master/img/sticker01.png?raw=true)

Introduction
=============

Hanabi is a loosely typed, general purpose programming language aimed at compability with older processor architectures. It is designed to be an easy introduction to Assembly programming and a functional alternative to procedural low-level programming languages, such as C and Rust.

Goals
-------------

###Platforms

Hanabi is aimed to have stable compatibility with the following operating systems and processor architectures:

- Apple ][ (6502)
- Nintendo Entertainment System (6502)
- MS-DOS 2.0 or older (x86)
- MARS MIPS Emulation software

###Current Status

Hanabi is in pre-alpha. Some commands compile successfully for MIPS and 6502 Assembly, but much more progress is needed before an Alpha release will be possible.

Basic Introduction
-------------

#### Hello, World

	; Ahoy!
	nook hshc "Hello, sheep! Hello, cup of tea!"
	say hshc

Here are available commands:

| Command  | Function  |
| ------------ | ------------ |
| nook  | Initializes a "nook". This may include a register, variable, or mapped memory location.  |
| spot | A spot is anywhere that the cursor may travel to. If a label is provided, it may be accessed specifically. |
| back | Tells the cursor to travel to the most recent spot without a back statement, or with additional context, any spot with a label. |
| hop | Travel to any labeled spot under provided circumstances. If no context is provided, it will travel to the specified spot as long as every preceding value is equal. |
| pocket | Unless nooks are explicitly provided, all registers are offloaded to the stack and restored at the end of the pocket. |
| sandbox | Provides a sandboxed runtime, similar to a pocket, save that external nooks are invisible unless explicitly specified. |
| friend | Directly injects code from an external source, similar to an #include function in C. Automatically relabels nooks to ensure compatibility and reduce ambiguity. |
| say | A generic console-out command. Operates differently depending on target system. |
| listen | A generic console-in command. |
| memory | Directly access a memory location. |
| ; | Comment marker. Anything after a semicolon is ignored. |

More keywords will exist as development continues.

Coding Conventions
-------------

Hanabi features dynamic register allocation, automatic garbage collection, dynamic typing, and compiler directives. What it does not include by design are true functions or "if" statements. Major concepts in the language are pre-ordering, context, single-line commands, and "logic, not syntax" errors. In short:

**GLaDOS: "This statement is false."
Hanabi: "...No, it isn`t."**

#### Pre-Ordering

In-Order calculations feature an operator in-between the appointed values, such as in "3 + 5 = 8". In Hanabi, all operators come between appropriate values. For example,

	nook t 0
	= t (+ t 1)
	
This code initializes the nook "t" and sets it equal to 0. In the second statement, "t" is set equal to "t + 1".

#### Context

If a value cannot be specified, it will infer value based on context. For example,

	nook t 0
	= t (+ t 1)
	say

The "say" command requires a value to follow it in order to properly function. As none is provided, it will output the value of the most previously altered nook, which is "t". The compiler will instead see the code as if it were so:

	nook int t 0
	nook int t1 t
	+ t1 1
	= t t1
	say t

#### Single-Line Commands

Only one command is allowed per-line. This can be bypassed somewhat by using the subcommands, which are delimited using parenthesis. For example,

	say ("Hello, sheep! Hello, cup of tea!")
	
Will first be processed as:

	"Hello, sheep! Hello, cup of tea!"
	
on its own. The Hanabi compiler realizes that this is a string and has a link to the previous command, and therefore compiles it as if you had entered the following code:

	nook t1 "Hello, sheep! Hello, cup of tea!"
	say t1
	
#### Logic, Not Syntax

The end goal of this philosophy is that Hanabi **will never return a Syntax error**. **All errors are exclusively reserved to being logic errors**, as it will use context to retroactively compile code in such a way that will be able to successfully compile.
