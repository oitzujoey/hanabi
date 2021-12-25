# Hanabi language mini-specification

Hanabi is a C-like programming language with Lisp macros. Hanabi is C, *not* Lisp, though much of the syntax is based on Lisp with a bit of Forth mixed in.

Everything in this document is subject to change.

## Special characters and character sequences

```txt
(   Start function call
)   End function call
//  Single line comment
/*  Start multi-line comment
*/  End multi-line comment
```

Unicode characters (or any other characters for that matter) are not currently supported.

## Syntax

Hanabi has Lisp syntax to the extreme. As of right now, no reader macros are planned (not even quoting reader macros) due to the potential difficulty of implementation. They will only be added to the language if it is determined that they are practical to implement.  

```lisp
(print (* 1 2 3))  // Print "6"
```

```lisp
(print (quote print))  // Print "print"
```

```lisp
(print (' print))  // Print "print"
```

```lisp
(print 'print)  // Syntax error
```

This may seem ironic after that last paragraph, but…  
Parentheses are typically optional.  

```lisp
(print * + 1 2 3)  // Equal to (print (* (+ 1 2) 3))
```

This does add complexity to the compiler, but it will hopefully make well-written code easier to understand. To keep code unambiguous, every function must have a default number of arguments. Since most functions have a fixed number of arguments, this is something that the programmer should not need to pay much more attention to, but variable argument functions must declare a default number of arguments. When an unparenthesized function is encountered, the default number of tokens is consumed as arguments.

`print` accepts one argument by default.

```lisp
print 5  // Print "5"
```

```lisp
print 5 6  // Syntax error. Print only accepts one argument, so 6 is treated as a function.
```

```lisp
print * + 1 2 3  // Equal to (print (* (+ 1 2) 3))
```

If a function needs more than the default number of arguments, then parentheses are required.

```lisp
(print * 2 3 * 4 5)  // Print now has two args. Equivalent to (print (* 2 3) (* 4 5))
```

## Evaluation

Macro expansion is performed left-to-right and then outside-in.  
Expressions execution is performed left-to-right and then inside-out unless marked otherwise.  
All constants are self-evaluating.

## Comments

```c
// Single line comment.
Not a comment.
/*
Multi-line comment.
*/
Not a comment.
/*
/*
Nested multi-line comment.
*/
Multi-line comment.
*/
Not a comment.
```

## Constants

### Integers

```c
5
-5
```

Integer type suffixes may be added.

### Floats

```c
1.0
1e0
1.0e1
-4e3
3e-7
-0.6e10
```

Float type suffixes may be added.

### Arrays

```lisp
[1 2 3 14]
```

### Strings

```C
"Hello, world!"
```

String constants are arrays

### Structures

```json
{a:4 b: "I <3 Kako" c: -1.568e-127}
```

## Data types

### Integer types

```txt
uint8   Unsigned 8-bit integer
sint8   Signed 8-bit integer
uint16  Unsigned 16-bit integer
sint16  Signed 16-bit integer
...     Larger [un]signed integers
```

#### Character types

Any character types are aliases of integer types.

### Float types

Floating point types are not required to conform to any standard. It is recommended to implement IEEE 754 compliant floats when possible.

### Pointer types

These will likely be exactly the same as C pointers. Void pointers might not be added to the language.  

A *function pointer* is a pointer to a function.  
A *variable pointer* is a pointer to a variable.  
A *constant data pointer* is a pointer to a constant value in data memory.  
A *constant program pointer* is a pointer to a constant value in program memory.  

Any function pointer may be cast to any other function pointer. A pointer to a program constant is the same size as a pointer to a function. Function pointers and program constant pointers may be referred to as *program pointers*. Not every Hanabi implementation will have program constants.  
Any variable pointer may be cast to any other variable pointer. A pointer to a data constant is the same size as a pointer to a variable. Variable pointers and data constant pointers may be referred to as *data pointers*.  

The reason for this distinction between program pointers and data pointers is that some computers (such as microcontrollers) use a Harvard Architecture that is unable transfer data between program and data memories. In the case of a Modified Harvard Architecture, it may be possible to transfer data between the two memories, but the address sizes may be different. It is conceivable that a microcontroller could have a 16-bit program pointer width, but only have an 8-bit data pointer width.

### Array types

Array types are pointer types with a length. Like in C, this length is calculated and may be retrieved at compile time. C99 variable length arrays are not currently supported.  

An alternative array type might be added which allows length to change at runtime. This form of array is a struct containing an array and its length.

### Struct types

Struct types are similar to array types, but the fields are variable length and keys must be specified at compile time.
Structs may be unpacked or packed. An unpacked struct may have padding in between its members. A packed struct does not have padding in between its members, but is not guaranteed to be supported on all architectures without forcing. Packed structs may be forced so that members may be accessed on any architecture, even if there is a high performance cost. Access of forced packed structs are guaranteed not to throw hardware exceptions.

### String type

Strings are structs containing a character array and the length of that array. Strings are **not** null-terminated.

### Unions

Unions are variables that may be interpreted as multiple types. The size of a union is the size of its largest type.

### Bit fields

Not yet part of the language.

### Enums

Not yet part of the language, but shouldn't be hard to create using a macro.

### Symbols

Symbols can be thought of as constants in a single enum created by the compiler to keep track of variables and other identifiers. Every identifier in a program is a symbol. Every symbol name is mapped to exactly one unsigned integer. The size of this integer must remain the same for every run. Different compilers may use different size symbols.

### Functions

Functions may accept a fixed or variable number of parameters depending on how they are defined. Functions may only return a fixed number of values, though this may eventually be added to the language.

## Scoping

Function and variable namespaces are separate. Take *that* Schemers!  

In Hanabi, the term *static* has one meaning. The variable is persistent for the entire duration of program execution. From the hardware's standpoint statics are the same as globals. The only difference between the two is that globals are statics that exist in the outermost lexical scope of the program.  
Static variables have full lexical scope.  
All functions are static.  
Every function that contains a static will have a struct-like variable that can be used to retrieve that variable from outer scopes. Code inside functions may access statics in parent scopes and parent scopes' children.

Local variables are create on entrance to a scope and are destroyed on exit from a scope.

## Built-in functions

### `progn`

Evaluate all arguments in a new scope and return the value of the last argument.

The empty expression is an alias for `progn`, except when the first argument is a lambda or constant. If the first argument can be evaluated as a function, it will be. First arguments that meet this requirement are constants, lambdas, and unparenthesized functions.

```lisp
(progn
  (println "First")
  (println "Second")
  (println "Third"))
```

```lisp
(
  (println "First")
  (println "Second")
  (println "Third"))
```

### `quote`

Quote a section of code. Attempting to store, retrieve, or otherwise manipulate a quoted syntax tree at runtime will result in a compile error.  

`quote` accepts one argument by default.

`'` is an alias for `quote`.

```lisp
(quote (+ 1 2 3))  // Returns (+ 1 2 3)
(' (+ 1 2 3))  // Returns (+ 1 2 3)
```

### `backquote`

Quote a section of code, but allow it to be unquoted using `unquote`. Attempting to store, retrieve, or otherwise manipulate a quoted syntax tree at runtime will result in a compile error.  

`backquote` accepts one argument by default.  

\` is an alias for `backquote`.  

```lisp
(backquote (print (unquote (+ 1 2 3))))  // Returns (print 6)
(` (print (, (+ 1 2 3)))))  // Returns (print 6)
` (print , (+ 1 2 3))  // Returns (print 6)
```

### `unquote`

Unquote a section of code quoted using `backquote`.  

`unquote` accepts one argument by default.  

`,` is an alias for `unquote`.  

```lisp
(backquote (print (unquote (+ 1 2 3))))  // Returns (print 6)
(` (print (, (+ 1 2 3)))))  // Returns (print 6)
` (print , (+ 1 2 3))  // Returns (print 6)
```

### `if`

`if condition if-branch &rest else-branch`  

Evaluate `if-branch` if `condition` is true, else, evaluate all expressions in `else-branch`.  

`if` accepts three arguments by default.

```lisp
(if (= (% x 2) 0)
  (println "x is even.")
  (println "x is odd.")
  (println "x is still odd."))
```

```lisp
if (= (% x 2) 0)
 ((println "True")
  (println x))
 ((println "False")
  (println x))
```

### `when`

`when condition &rest if-branch`  

Evaluate `if-branch` if `condition` is true, else, return 0.  

`when` accepts two arguments by default.

```lisp
(when (= (% x 2) 0)
  (println "x is even."))
```

```lisp
when (= (% x 2) 0)
 ((println "True")
  (println x))
```

### `unless`

`unless condition &rest else-branch`  

Evaluate `else-branch` if `condition` is false, else, return 0.  

`unless` accepts two arguments by default.

```lisp
(unless (= (% x 2) 0)
  (println "x is odd."))
```

```lisp
unless (= (% x 2) 0)
 ((println "False")
  (println x))
```

### `let`

`let &rest symbol type value`  
`let (&rest (symbol type &rest value)) &rest body`  

#### Form #1

Declare a local variable with name given by `symbol` and type given by `type`, and initialize to `value` if present. Multiple variables may be declared. All locals are destroyed when the program exits the current scope.

```lisp
(let x uint8 1)
(let y uint16 12
     z sint16 -13)
```

This form may be removed due to limited usefulness and problems with stack allocation.

#### Form #2

Create a new scope and declare local variables from list with names given by each `symbol` and type given by each `type`. Initialize each variable to `value` if present. Evaluate all expressions in `body`. Destroy scope.

#### Both forms

Variables might not be defined and initialized left-to-right. If this is needed, use `let*`.

`let` accepts two arguments by default.

```lisp
(let ((x uint8 1)
      (y uint16)
	  (z sint16 -13))
  (set y 12)
  (* (cast-sint16 x) (cast-sint16 y) z))  // Returns -156
(print x)  // Scope error
```

### `let*`

`let* (&rest (symbol type &rest value)) &rest body`  

`let*` is the same as `let` except that arguments are declared and initialized from left to right.

`let*` accepts two arguments by default.

```lisp
(let ((x uint8 1)
      (y uint16 (* (cast-uint16 x) 12))
	  (z sint16 (* (cast-sint16 y) -13)))
  z)  // Returns -156
(print x)  // Scope error
```

### `lambda`

`lambda symbol (&rest args) &rest body`

Creates an anonymous function. Keep in mind that anonymous functions are still static.

`lambda` accepts two arguments by default.

```lisp
(lambda (x y)
  (+ x y))
```

Lambda definition will change after it is determined how function types are specified.
