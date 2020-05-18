/* Define ISO C stdio on top of C++ iostreams.
   Copyright (C) 1991-2019 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/*
 *        ISO C99 Standard: 7.19 Input/output        <stdio.h>
 */
#ifndef _STDIO_H
#define _STDIO_H        1
#ifndef	_FEATURES_H
#define	_FEATURES_H	1
/* These are defined by the user (or the compiler)
   to specify the desired environment:
   __STRICT_ANSI__	ISO Standard C.
   _ISOC99_SOURCE	Extensions to ISO C89 from ISO C99.
   _ISOC11_SOURCE	Extensions to ISO C99 from ISO C11.
   __STDC_WANT_LIB_EXT2__
			Extensions to ISO C99 from TR 27431-2:2010.
   __STDC_WANT_IEC_60559_BFP_EXT__
			Extensions to ISO C11 from TS 18661-1:2014.
   __STDC_WANT_IEC_60559_FUNCS_EXT__
			Extensions to ISO C11 from TS 18661-4:2015.
   __STDC_WANT_IEC_60559_TYPES_EXT__
			Extensions to ISO C11 from TS 18661-3:2015.
   _POSIX_SOURCE	IEEE Std 1003.1.
   _POSIX_C_SOURCE	If ==1, like _POSIX_SOURCE; if >=2 add IEEE Std 1003.2;
			if >=199309L, add IEEE Std 1003.1b-1993;
			if >=199506L, add IEEE Std 1003.1c-1995;
			if >=200112L, all of IEEE 1003.1-2004
			if >=200809L, all of IEEE 1003.1-2008
   _XOPEN_SOURCE	Includes POSIX and XPG things.  Set to 500 if
			Single Unix conformance is wanted, to 600 for the
			sixth revision, to 700 for the seventh revision.
   _XOPEN_SOURCE_EXTENDED XPG things and X/Open Unix extensions.
   _LARGEFILE_SOURCE	Some more functions for correct standard I/O.
   _LARGEFILE64_SOURCE	Additional functionality from LFS for large files.
   _FILE_OFFSET_BITS=N	Select default filesystem interface.
   _ATFILE_SOURCE	Additional *at interfaces.
   _GNU_SOURCE		All of the above, plus GNU extensions.
   _DEFAULT_SOURCE	The default set of features (taking precedence over
			__STRICT_ANSI__).
   _FORTIFY_SOURCE	Add security hardening to many library functions.
			Set to 1 or 2; 2 performs stricter checks than 1.
   _REENTRANT, _THREAD_SAFE
			Obsolete; equivalent to _POSIX_C_SOURCE=199506L.
   The `-ansi' switch to the GNU C compiler, and standards conformance
   options such as `-std=c99', define __STRICT_ANSI__.  If none of
   these are defined, or if _DEFAULT_SOURCE is defined, the default is
   to have _POSIX_SOURCE set to one and _POSIX_C_SOURCE set to
   200809L, as well as enabling miscellaneous functions from BSD and
   SVID.  If more than one of these are defined, they accumulate.  For
   example __STRICT_ANSI__, _POSIX_SOURCE and _POSIX_C_SOURCE together
   give you ISO C, 1003.1, and 1003.2, but nothing else.
   These are defined by this file and are used by the
   header files to decide what to declare or define:
   __GLIBC_USE (F)	Define things from feature set F.  This is defined
			to 1 or 0; the subsequent macros are either defined
			or undefined, and those tests should be moved to
			__GLIBC_USE.
   __USE_ISOC11		Define ISO C11 things.
   __USE_ISOC99		Define ISO C99 things.
   __USE_ISOC95		Define ISO C90 AMD1 (C95) things.
   __USE_ISOCXX11	Define ISO C++11 things.
   __USE_POSIX		Define IEEE Std 1003.1 things.
   __USE_POSIX2		Define IEEE Std 1003.2 things.
   __USE_POSIX199309	Define IEEE Std 1003.1, and .1b things.
   __USE_POSIX199506	Define IEEE Std 1003.1, .1b, .1c and .1i things.
   __USE_XOPEN		Define XPG things.
   __USE_XOPEN_EXTENDED	Define X/Open Unix things.
   __USE_UNIX98		Define Single Unix V2 things.
   __USE_XOPEN2K        Define XPG6 things.
   __USE_XOPEN2KXSI     Define XPG6 XSI things.
   __USE_XOPEN2K8       Define XPG7 things.
   __USE_XOPEN2K8XSI    Define XPG7 XSI things.
   __USE_LARGEFILE	Define correct standard I/O things.
   __USE_LARGEFILE64	Define LFS things with separate names.
   __USE_FILE_OFFSET64	Define 64bit interface as default.
   __USE_MISC		Define things from 4.3BSD or System V Unix.
   __USE_ATFILE		Define *at interfaces and AT_* constants for them.
   __USE_GNU		Define GNU extensions.
   __USE_FORTIFY_LEVEL	Additional security measures used, according to level.
   The macros `__GNU_LIBRARY__', `__GLIBC__', and `__GLIBC_MINOR__' are
   defined by this file unconditionally.  `__GNU_LIBRARY__' is provided
   only for compatibility.  All new code should use the other symbols
   to test for features.
   All macros listed above as possibly being defined by this file are
   explicitly undefined if they are not explicitly defined.
   Feature-test macros that are not defined by the user or compiler
   but are implied by the other feature-test macros defined (or by the
   lack of any definitions) are defined by the file.
   ISO C feature test macros depend on the definition of the macro
   when an affected header is included, not when the first system
   header is included, and so they are handled in
   <bits/libc-header-start.h>, which does not have a multiple include
   guard.  Feature test macros that can be handled from the first
   system header included are handled here.  */
/* Undefine everything, so we get a clean slate.  */
#undef	__USE_ISOC11
#undef	__USE_ISOC99
#undef	__USE_ISOC95
#undef	__USE_ISOCXX11
#undef	__USE_POSIX
#undef	__USE_POSIX2
#undef	__USE_POSIX199309
#undef	__USE_POSIX199506
#undef	__USE_XOPEN
#undef	__USE_XOPEN_EXTENDED
#undef	__USE_UNIX98
#undef	__USE_XOPEN2K
#undef	__USE_XOPEN2KXSI
#undef	__USE_XOPEN2K8
#undef	__USE_XOPEN2K8XSI
#undef	__USE_LARGEFILE
#undef	__USE_LARGEFILE64
#undef	__USE_FILE_OFFSET64
#undef	__USE_MISC
#undef	__USE_ATFILE
#undef	__USE_GNU
#undef	__USE_FORTIFY_LEVEL
#undef	__KERNEL_STRICT_NAMES
#undef	__GLIBC_USE_DEPRECATED_GETS
/* Suppress kernel-name space pollution unless user expressedly asks
   for it.  */
#ifndef _LOOSE_KERNEL_NAMES
# define __KERNEL_STRICT_NAMES
#endif
/* Convenience macro to test the version of gcc.
   Use like this:
   #if __GNUC_PREREQ (2,8)
   ... code requiring gcc 2.8 or later ...
   #endif
   Note: only works for GCC 2.0 and later, because __GNUC_MINOR__ was
   added in 2.0.  */
#if defined __GNUC__ && defined __GNUC_MINOR__
# define __GNUC_PREREQ(maj, min) \
	((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
#else
# define __GNUC_PREREQ(maj, min) 0
#endif
/* Similarly for clang.  Features added to GCC after version 4.2 may
   or may not also be available in clang, and clang's definitions of
   __GNUC(_MINOR)__ are fixed at 4 and 2 respectively.  Not all such
   features can be queried via __has_extension/__has_feature.  */
#if defined __clang_major__ && defined __clang_minor__
# define __glibc_clang_prereq(maj, min) \
  ((__clang_major__ << 16) + __clang_minor__ >= ((maj) << 16) + (min))
#else
# define __glibc_clang_prereq(maj, min) 0
#endif
/* Whether to use feature set F.  */
#define __GLIBC_USE(F)	__GLIBC_USE_ ## F
/* _BSD_SOURCE and _SVID_SOURCE are deprecated aliases for
   _DEFAULT_SOURCE.  If _DEFAULT_SOURCE is present we do not
   issue a warning; the expectation is that the source is being
   transitioned to use the new macro.  */
#if (defined _BSD_SOURCE || defined _SVID_SOURCE) \
    && !defined _DEFAULT_SOURCE
# warning "_BSD_SOURCE and _SVID_SOURCE are deprecated, use _DEFAULT_SOURCE"
# undef  _DEFAULT_SOURCE
# define _DEFAULT_SOURCE	1
#endif
/* If _GNU_SOURCE was defined by the user, turn on all the other features.  */
#ifdef _GNU_SOURCE
# undef  _ISOC95_SOURCE
# define _ISOC95_SOURCE	1
# undef  _ISOC99_SOURCE
# define _ISOC99_SOURCE	1
# undef  _ISOC11_SOURCE
# define _ISOC11_SOURCE	1
# undef  _POSIX_SOURCE
# define _POSIX_SOURCE	1
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE	200809L
# undef  _XOPEN_SOURCE
# define _XOPEN_SOURCE	700
# undef  _XOPEN_SOURCE_EXTENDED
# define _XOPEN_SOURCE_EXTENDED	1
# undef	 _LARGEFILE64_SOURCE
# define _LARGEFILE64_SOURCE	1
# undef  _DEFAULT_SOURCE
# define _DEFAULT_SOURCE	1
# undef  _ATFILE_SOURCE
# define _ATFILE_SOURCE	1
#endif
/* If nothing (other than _GNU_SOURCE and _DEFAULT_SOURCE) is defined,
   define _DEFAULT_SOURCE.  */
#if (defined _DEFAULT_SOURCE					\
     || (!defined __STRICT_ANSI__				\
	 && !defined _ISOC99_SOURCE && !defined _ISOC11_SOURCE	\
	 && !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE	\
	 && !defined _XOPEN_SOURCE))
# undef  _DEFAULT_SOURCE
# define _DEFAULT_SOURCE	1
#endif
/* This is to enable the ISO C11 extension.  */
#if (defined _ISOC11_SOURCE \
     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 201112L))
# define __USE_ISOC11	1
#endif
/* This is to enable the ISO C99 extension.  */
#if (defined _ISOC99_SOURCE || defined _ISOC11_SOURCE \
     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L))
# define __USE_ISOC99	1
#endif
/* This is to enable the ISO C90 Amendment 1:1995 extension.  */
#if (defined _ISOC99_SOURCE || defined _ISOC11_SOURCE \
     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199409L))
# define __USE_ISOC95	1
#endif
#ifdef __cplusplus
/* This is to enable compatibility for ISO C++17.  */
# if __cplusplus >= 201703L
#  define __USE_ISOC11	1
# endif
/* This is to enable compatibility for ISO C++11.
   Check the temporary macro for now, too.  */
# if __cplusplus >= 201103L || defined __GXX_EXPERIMENTAL_CXX0X__
#  define __USE_ISOCXX11	1
#  define __USE_ISOC99	1
# endif
#endif
/* If none of the ANSI/POSIX macros are defined, or if _DEFAULT_SOURCE
   is defined, use POSIX.1-2008 (or another version depending on
   _XOPEN_SOURCE).  */
#ifdef _DEFAULT_SOURCE
# if !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE
#  define __USE_POSIX_IMPLICITLY	1
# endif
# undef  _POSIX_SOURCE
# define _POSIX_SOURCE	1
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE	200809L
#endif
#if ((!defined __STRICT_ANSI__					\
      || (defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) >= 500))	\
     && !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE)
# define _POSIX_SOURCE	1
# if defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 500
#  define _POSIX_C_SOURCE	2
# elif defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 600
#  define _POSIX_C_SOURCE	199506L
# elif defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 700
#  define _POSIX_C_SOURCE	200112L
# else
#  define _POSIX_C_SOURCE	200809L
# endif
# define __USE_POSIX_IMPLICITLY	1
#endif
/* Some C libraries once required _REENTRANT and/or _THREAD_SAFE to be
   defined in all multithreaded code.  GNU libc has not required this
   for many years.  We now treat them as compatibility synonyms for
   _POSIX_C_SOURCE=199506L, which is the earliest level of POSIX with
   comprehensive support for multithreaded code.  Using them never
   lowers the selected level of POSIX conformance, only raises it.  */
#if ((!defined _POSIX_C_SOURCE || (_POSIX_C_SOURCE - 0) < 199506L) \
     && (defined _REENTRANT || defined _THREAD_SAFE))
# define _POSIX_SOURCE   1
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE 199506L
#endif
#if (defined _POSIX_SOURCE					\
     || (defined _POSIX_C_SOURCE && _POSIX_C_SOURCE >= 1)	\
     || defined _XOPEN_SOURCE)
# define __USE_POSIX	1
#endif
#if defined _POSIX_C_SOURCE && _POSIX_C_SOURCE >= 2 || defined _XOPEN_SOURCE
# define __USE_POSIX2	1
#endif
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 199309L
# define __USE_POSIX199309	1
#endif
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 199506L
# define __USE_POSIX199506	1
#endif
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 200112L
# define __USE_XOPEN2K		1
# undef __USE_ISOC95
# define __USE_ISOC95		1
# undef __USE_ISOC99
# define __USE_ISOC99		1
#endif
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 200809L
# define __USE_XOPEN2K8		1
# undef  _ATFILE_SOURCE
# define _ATFILE_SOURCE	1
#endif
#ifdef	_XOPEN_SOURCE
# define __USE_XOPEN	1
# if (_XOPEN_SOURCE - 0) >= 500
#  define __USE_XOPEN_EXTENDED	1
#  define __USE_UNIX98	1
#  undef _LARGEFILE_SOURCE
#  define _LARGEFILE_SOURCE	1
#  if (_XOPEN_SOURCE - 0) >= 600
#   if (_XOPEN_SOURCE - 0) >= 700
#    define __USE_XOPEN2K8	1
#    define __USE_XOPEN2K8XSI	1
#   endif
#   define __USE_XOPEN2K	1
#   define __USE_XOPEN2KXSI	1
#   undef __USE_ISOC95
#   define __USE_ISOC95		1
#   undef __USE_ISOC99
#   define __USE_ISOC99		1
#  endif
# else
#  ifdef _XOPEN_SOURCE_EXTENDED
#   define __USE_XOPEN_EXTENDED	1
#  endif
# endif
#endif
#ifdef _LARGEFILE_SOURCE
# define __USE_LARGEFILE	1
#endif
#ifdef _LARGEFILE64_SOURCE
# define __USE_LARGEFILE64	1
#endif
#if defined _FILE_OFFSET_BITS && _FILE_OFFSET_BITS == 64
# define __USE_FILE_OFFSET64	1
#endif
#if defined _DEFAULT_SOURCE
# define __USE_MISC	1
#endif
#ifdef	_ATFILE_SOURCE
# define __USE_ATFILE	1
#endif
#ifdef	_GNU_SOURCE
# define __USE_GNU	1
#endif
#if defined _FORTIFY_SOURCE && _FORTIFY_SOURCE > 0
# if !defined __OPTIMIZE__ || __OPTIMIZE__ <= 0
#  warning _FORTIFY_SOURCE requires compiling with optimization (-O)
# elif !__GNUC_PREREQ (4, 1)
#  warning _FORTIFY_SOURCE requires GCC 4.1 or later
# elif _FORTIFY_SOURCE > 1
#  define __USE_FORTIFY_LEVEL 2
# else
#  define __USE_FORTIFY_LEVEL 1
# endif
#endif
#ifndef __USE_FORTIFY_LEVEL
# define __USE_FORTIFY_LEVEL 0
#endif
/* The function 'gets' existed in C89, but is impossible to use
   safely.  It has been removed from ISO C11 and ISO C++14.  Note: for
   compatibility with various implementations of <cstdio>, this test
   must consider only the value of __cplusplus when compiling C++.  */
#if defined __cplusplus ? __cplusplus >= 201402L : defined __USE_ISOC11
# define __GLIBC_USE_DEPRECATED_GETS 0
#else
# define __GLIBC_USE_DEPRECATED_GETS 1
#endif
/* Get definitions of __STDC_* predefined macros, if the compiler has
   not preincluded this header automatically.  */
#ifndef	_STDC_PREDEF_H
#define	_STDC_PREDEF_H	1
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
#ifdef __GCC_IEC_559
# if __GCC_IEC_559 > 0
#  define __STDC_IEC_559__		1
# endif
#else
# define __STDC_IEC_559__		1
#endif
#ifdef __GCC_IEC_559_COMPLEX
# if __GCC_IEC_559_COMPLEX > 0
#  define __STDC_IEC_559_COMPLEX__	1
# endif
#else
# define __STDC_IEC_559_COMPLEX__	1
#endif
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
#define __STDC_ISO_10646__		201706L
#endif
/* This macro indicates that the installed library is the GNU C Library.
   For historic reasons the value now is 6 and this will stay from now
   on.  The use of this variable is deprecated.  Use __GLIBC__ and
   __GLIBC_MINOR__ now (see below) when you want to test for a specific
   GNU C library version and use the values in <gnu/lib-names.h> to get
   the sonames of the shared libraries.  */
#undef  __GNU_LIBRARY__
#define __GNU_LIBRARY__ 6
/* Major and minor version number of the GNU C library package.  Use
   these macros to test for features in specific releases.  */
#define	__GLIBC__	2
#define	__GLIBC_MINOR__	28
#define __GLIBC_PREREQ(maj, min) \
	((__GLIBC__ << 16) + __GLIBC_MINOR__ >= ((maj) << 16) + (min))
/* This is here only because every header file already includes this one.  */
#ifndef __ASSEMBLER__
# ifndef _SYS_CDEFS_H
#ifndef        _SYS_CDEFS_H
#define        _SYS_CDEFS_H        1
/* We are almost always included from features.h. */
#ifndef _FEATURES_H
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
#ifndef	_FEATURES_H
#define	_FEATURES_H	1
/* These are defined by the user (or the compiler)
   to specify the desired environment:
   __STRICT_ANSI__	ISO Standard C.
   _ISOC99_SOURCE	Extensions to ISO C89 from ISO C99.
   _ISOC11_SOURCE	Extensions to ISO C99 from ISO C11.
   __STDC_WANT_LIB_EXT2__
			Extensions to ISO C99 from TR 27431-2:2010.
   __STDC_WANT_IEC_60559_BFP_EXT__
			Extensions to ISO C11 from TS 18661-1:2014.
   __STDC_WANT_IEC_60559_FUNCS_EXT__
			Extensions to ISO C11 from TS 18661-4:2015.
   __STDC_WANT_IEC_60559_TYPES_EXT__
			Extensions to ISO C11 from TS 18661-3:2015.
   _POSIX_SOURCE	IEEE Std 1003.1.
   _POSIX_C_SOURCE	If ==1, like _POSIX_SOURCE; if >=2 add IEEE Std 1003.2;
			if >=199309L, add IEEE Std 1003.1b-1993;
			if >=199506L, add IEEE Std 1003.1c-1995;
			if >=200112L, all of IEEE 1003.1-2004
			if >=200809L, all of IEEE 1003.1-2008
   _XOPEN_SOURCE	Includes POSIX and XPG things.  Set to 500 if
			Single Unix conformance is wanted, to 600 for the
			sixth revision, to 700 for the seventh revision.
   _XOPEN_SOURCE_EXTENDED XPG things and X/Open Unix extensions.
   _LARGEFILE_SOURCE	Some more functions for correct standard I/O.
   _LARGEFILE64_SOURCE	Additional functionality from LFS for large files.
   _FILE_OFFSET_BITS=N	Select default filesystem interface.
   _ATFILE_SOURCE	Additional *at interfaces.
   _GNU_SOURCE		All of the above, plus GNU extensions.
   _DEFAULT_SOURCE	The default set of features (taking precedence over
			__STRICT_ANSI__).
   _FORTIFY_SOURCE	Add security hardening to many library functions.
			Set to 1 or 2; 2 performs stricter checks than 1.
   _REENTRANT, _THREAD_SAFE
			Obsolete; equivalent to _POSIX_C_SOURCE=199506L.
   The `-ansi' switch to the GNU C compiler, and standards conformance
   options such as `-std=c99', define __STRICT_ANSI__.  If none of
   these are defined, or if _DEFAULT_SOURCE is defined, the default is
   to have _POSIX_SOURCE set to one and _POSIX_C_SOURCE set to
   200809L, as well as enabling miscellaneous functions from BSD and
   SVID.  If more than one of these are defined, they accumulate.  For
   example __STRICT_ANSI__, _POSIX_SOURCE and _POSIX_C_SOURCE together
   give you ISO C, 1003.1, and 1003.2, but nothing else.
   These are defined by this file and are used by the
   header files to decide what to declare or define:
   __GLIBC_USE (F)	Define things from feature set F.  This is defined
			to 1 or 0; the subsequent macros are either defined
			or undefined, and those tests should be moved to
			__GLIBC_USE.
   __USE_ISOC11		Define ISO C11 things.
   __USE_ISOC99		Define ISO C99 things.
   __USE_ISOC95		Define ISO C90 AMD1 (C95) things.
   __USE_ISOCXX11	Define ISO C++11 things.
   __USE_POSIX		Define IEEE Std 1003.1 things.
   __USE_POSIX2		Define IEEE Std 1003.2 things.
   __USE_POSIX199309	Define IEEE Std 1003.1, and .1b things.
   __USE_POSIX199506	Define IEEE Std 1003.1, .1b, .1c and .1i things.
   __USE_XOPEN		Define XPG things.
   __USE_XOPEN_EXTENDED	Define X/Open Unix things.
   __USE_UNIX98		Define Single Unix V2 things.
   __USE_XOPEN2K        Define XPG6 things.
   __USE_XOPEN2KXSI     Define XPG6 XSI things.
   __USE_XOPEN2K8       Define XPG7 things.
   __USE_XOPEN2K8XSI    Define XPG7 XSI things.
   __USE_LARGEFILE	Define correct standard I/O things.
   __USE_LARGEFILE64	Define LFS things with separate names.
   __USE_FILE_OFFSET64	Define 64bit interface as default.
   __USE_MISC		Define things from 4.3BSD or System V Unix.
   __USE_ATFILE		Define *at interfaces and AT_* constants for them.
   __USE_GNU		Define GNU extensions.
   __USE_FORTIFY_LEVEL	Additional security measures used, according to level.
   The macros `__GNU_LIBRARY__', `__GLIBC__', and `__GLIBC_MINOR__' are
   defined by this file unconditionally.  `__GNU_LIBRARY__' is provided
   only for compatibility.  All new code should use the other symbols
   to test for features.
   All macros listed above as possibly being defined by this file are
   explicitly undefined if they are not explicitly defined.
   Feature-test macros that are not defined by the user or compiler
   but are implied by the other feature-test macros defined (or by the
   lack of any definitions) are defined by the file.
   ISO C feature test macros depend on the definition of the macro
   when an affected header is included, not when the first system
   header is included, and so they are handled in
   <bits/libc-header-start.h>, which does not have a multiple include
   guard.  Feature test macros that can be handled from the first
   system header included are handled here.  */
/* Undefine everything, so we get a clean slate.  */
#undef	__USE_ISOC11
#undef	__USE_ISOC99
#undef	__USE_ISOC95
#undef	__USE_ISOCXX11
#undef	__USE_POSIX
#undef	__USE_POSIX2
#undef	__USE_POSIX199309
#undef	__USE_POSIX199506
#undef	__USE_XOPEN
#undef	__USE_XOPEN_EXTENDED
#undef	__USE_UNIX98
#undef	__USE_XOPEN2K
#undef	__USE_XOPEN2KXSI
#undef	__USE_XOPEN2K8
#undef	__USE_XOPEN2K8XSI
#undef	__USE_LARGEFILE
#undef	__USE_LARGEFILE64
#undef	__USE_FILE_OFFSET64
#undef	__USE_MISC
#undef	__USE_ATFILE
#undef	__USE_GNU
#undef	__USE_FORTIFY_LEVEL
#undef	__KERNEL_STRICT_NAMES
#undef	__GLIBC_USE_DEPRECATED_GETS
/* Suppress kernel-name space pollution unless user expressedly asks
   for it.  */
#ifndef _LOOSE_KERNEL_NAMES
# define __KERNEL_STRICT_NAMES
#endif
/* Convenience macro to test the version of gcc.
   Use like this:
   #if __GNUC_PREREQ (2,8)
   ... code requiring gcc 2.8 or later ...
   #endif
   Note: only works for GCC 2.0 and later, because __GNUC_MINOR__ was
   added in 2.0.  */
#if defined __GNUC__ && defined __GNUC_MINOR__
# define __GNUC_PREREQ(maj, min) \
	((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
#else
# define __GNUC_PREREQ(maj, min) 0
#endif
/* Similarly for clang.  Features added to GCC after version 4.2 may
   or may not also be available in clang, and clang's definitions of
   __GNUC(_MINOR)__ are fixed at 4 and 2 respectively.  Not all such
   features can be queried via __has_extension/__has_feature.  */
#if defined __clang_major__ && defined __clang_minor__
# define __glibc_clang_prereq(maj, min) \
  ((__clang_major__ << 16) + __clang_minor__ >= ((maj) << 16) + (min))
#else
# define __glibc_clang_prereq(maj, min) 0
#endif
/* Whether to use feature set F.  */
#define __GLIBC_USE(F)	__GLIBC_USE_ ## F
/* _BSD_SOURCE and _SVID_SOURCE are deprecated aliases for
   _DEFAULT_SOURCE.  If _DEFAULT_SOURCE is present we do not
   issue a warning; the expectation is that the source is being
   transitioned to use the new macro.  */
#if (defined _BSD_SOURCE || defined _SVID_SOURCE) \
    && !defined _DEFAULT_SOURCE
# warning "_BSD_SOURCE and _SVID_SOURCE are deprecated, use _DEFAULT_SOURCE"
# undef  _DEFAULT_SOURCE
# define _DEFAULT_SOURCE	1
#endif
/* If _GNU_SOURCE was defined by the user, turn on all the other features.  */
#ifdef _GNU_SOURCE
# undef  _ISOC95_SOURCE
# define _ISOC95_SOURCE	1
# undef  _ISOC99_SOURCE
# define _ISOC99_SOURCE	1
# undef  _ISOC11_SOURCE
# define _ISOC11_SOURCE	1
# undef  _POSIX_SOURCE
# define _POSIX_SOURCE	1
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE	200809L
# undef  _XOPEN_SOURCE
# define _XOPEN_SOURCE	700
# undef  _XOPEN_SOURCE_EXTENDED
# define _XOPEN_SOURCE_EXTENDED	1
# undef	 _LARGEFILE64_SOURCE
# define _LARGEFILE64_SOURCE	1
# undef  _DEFAULT_SOURCE
# define _DEFAULT_SOURCE	1
# undef  _ATFILE_SOURCE
# define _ATFILE_SOURCE	1
#endif
/* If nothing (other than _GNU_SOURCE and _DEFAULT_SOURCE) is defined,
   define _DEFAULT_SOURCE.  */
#if (defined _DEFAULT_SOURCE					\
     || (!defined __STRICT_ANSI__				\
	 && !defined _ISOC99_SOURCE && !defined _ISOC11_SOURCE	\
	 && !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE	\
	 && !defined _XOPEN_SOURCE))
# undef  _DEFAULT_SOURCE
# define _DEFAULT_SOURCE	1
#endif
/* This is to enable the ISO C11 extension.  */
#if (defined _ISOC11_SOURCE \
     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 201112L))
# define __USE_ISOC11	1
#endif
/* This is to enable the ISO C99 extension.  */
#if (defined _ISOC99_SOURCE || defined _ISOC11_SOURCE \
     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L))
# define __USE_ISOC99	1
#endif
/* This is to enable the ISO C90 Amendment 1:1995 extension.  */
#if (defined _ISOC99_SOURCE || defined _ISOC11_SOURCE \
     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199409L))
# define __USE_ISOC95	1
#endif
#ifdef __cplusplus
/* This is to enable compatibility for ISO C++17.  */
# if __cplusplus >= 201703L
#  define __USE_ISOC11	1
# endif
/* This is to enable compatibility for ISO C++11.
   Check the temporary macro for now, too.  */
# if __cplusplus >= 201103L || defined __GXX_EXPERIMENTAL_CXX0X__
#  define __USE_ISOCXX11	1
#  define __USE_ISOC99	1
# endif
#endif
/* If none of the ANSI/POSIX macros are defined, or if _DEFAULT_SOURCE
   is defined, use POSIX.1-2008 (or another version depending on
   _XOPEN_SOURCE).  */
#ifdef _DEFAULT_SOURCE
# if !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE
#  define __USE_POSIX_IMPLICITLY	1
# endif
# undef  _POSIX_SOURCE
# define _POSIX_SOURCE	1
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE	200809L
#endif
#if ((!defined __STRICT_ANSI__					\
      || (defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) >= 500))	\
     && !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE)
# define _POSIX_SOURCE	1
# if defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 500
#  define _POSIX_C_SOURCE	2
# elif defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 600
#  define _POSIX_C_SOURCE	199506L
# elif defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 700
#  define _POSIX_C_SOURCE	200112L
# else
#  define _POSIX_C_SOURCE	200809L
# endif
# define __USE_POSIX_IMPLICITLY	1
#endif
/* Some C libraries once required _REENTRANT and/or _THREAD_SAFE to be
   defined in all multithreaded code.  GNU libc has not required this
   for many years.  We now treat them as compatibility synonyms for
   _POSIX_C_SOURCE=199506L, which is the earliest level of POSIX with
   comprehensive support for multithreaded code.  Using them never
   lowers the selected level of POSIX conformance, only raises it.  */
#if ((!defined _POSIX_C_SOURCE || (_POSIX_C_SOURCE - 0) < 199506L) \
     && (defined _REENTRANT || defined _THREAD_SAFE))
# define _POSIX_SOURCE   1
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE 199506L
#endif
#if (defined _POSIX_SOURCE					\
     || (defined _POSIX_C_SOURCE && _POSIX_C_SOURCE >= 1)	\
     || defined _XOPEN_SOURCE)
# define __USE_POSIX	1
#endif
#if defined _POSIX_C_SOURCE && _POSIX_C_SOURCE >= 2 || defined _XOPEN_SOURCE
# define __USE_POSIX2	1
#endif
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 199309L
# define __USE_POSIX199309	1
#endif
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 199506L
# define __USE_POSIX199506	1
#endif
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 200112L
# define __USE_XOPEN2K		1
# undef __USE_ISOC95
# define __USE_ISOC95		1
# undef __USE_ISOC99
# define __USE_ISOC99		1
#endif
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 200809L
# define __USE_XOPEN2K8		1
# undef  _ATFILE_SOURCE
# define _ATFILE_SOURCE	1
#endif
#ifdef	_XOPEN_SOURCE
# define __USE_XOPEN	1
# if (_XOPEN_SOURCE - 0) >= 500
#  define __USE_XOPEN_EXTENDED	1
#  define __USE_UNIX98	1
#  undef _LARGEFILE_SOURCE
#  define _LARGEFILE_SOURCE	1
#  if (_XOPEN_SOURCE - 0) >= 600
#   if (_XOPEN_SOURCE - 0) >= 700
#    define __USE_XOPEN2K8	1
#    define __USE_XOPEN2K8XSI	1
#   endif
#   define __USE_XOPEN2K	1
#   define __USE_XOPEN2KXSI	1
#   undef __USE_ISOC95
#   define __USE_ISOC95		1
#   undef __USE_ISOC99
#   define __USE_ISOC99		1
#  endif
# else
#  ifdef _XOPEN_SOURCE_EXTENDED
#   define __USE_XOPEN_EXTENDED	1
#  endif
# endif
#endif
#ifdef _LARGEFILE_SOURCE
# define __USE_LARGEFILE	1
#endif
#ifdef _LARGEFILE64_SOURCE
# define __USE_LARGEFILE64	1
#endif
#if defined _FILE_OFFSET_BITS && _FILE_OFFSET_BITS == 64
# define __USE_FILE_OFFSET64	1
#endif
#if defined _DEFAULT_SOURCE
# define __USE_MISC	1
#endif
#ifdef	_ATFILE_SOURCE
# define __USE_ATFILE	1
#endif
#ifdef	_GNU_SOURCE
# define __USE_GNU	1
#endif
#if defined _FORTIFY_SOURCE && _FORTIFY_SOURCE > 0
# if !defined __OPTIMIZE__ || __OPTIMIZE__ <= 0
#  warning _FORTIFY_SOURCE requires compiling with optimization (-O)
# elif !__GNUC_PREREQ (4, 1)
#  warning _FORTIFY_SOURCE requires GCC 4.1 or later
# elif _FORTIFY_SOURCE > 1
#  define __USE_FORTIFY_LEVEL 2
# else
#  define __USE_FORTIFY_LEVEL 1
# endif
#endif
#ifndef __USE_FORTIFY_LEVEL
# define __USE_FORTIFY_LEVEL 0
#endif
/* The function 'gets' existed in C89, but is impossible to use
   safely.  It has been removed from ISO C11 and ISO C++14.  Note: for
   compatibility with various implementations of <cstdio>, this test
   must consider only the value of __cplusplus when compiling C++.  */
#if defined __cplusplus ? __cplusplus >= 201402L : defined __USE_ISOC11
# define __GLIBC_USE_DEPRECATED_GETS 0
#else
# define __GLIBC_USE_DEPRECATED_GETS 1
#endif
/* Get definitions of __STDC_* predefined macros, if the compiler has
   not preincluded this header automatically.  */
#ifndef	_STDC_PREDEF_H
#define	_STDC_PREDEF_H	1
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
#ifdef __GCC_IEC_559
# if __GCC_IEC_559 > 0
#  define __STDC_IEC_559__		1
# endif
#else
# define __STDC_IEC_559__		1
#endif
#ifdef __GCC_IEC_559_COMPLEX
# if __GCC_IEC_559_COMPLEX > 0
#  define __STDC_IEC_559_COMPLEX__	1
# endif
#else
# define __STDC_IEC_559_COMPLEX__	1
#endif
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
#define __STDC_ISO_10646__		201706L
#endif
/* This macro indicates that the installed library is the GNU C Library.
   For historic reasons the value now is 6 and this will stay from now
   on.  The use of this variable is deprecated.  Use __GLIBC__ and
   __GLIBC_MINOR__ now (see below) when you want to test for a specific
   GNU C library version and use the values in <gnu/lib-names.h> to get
   the sonames of the shared libraries.  */
#undef  __GNU_LIBRARY__
#define __GNU_LIBRARY__ 6
/* Major and minor version number of the GNU C library package.  Use
   these macros to test for features in specific releases.  */
#define	__GLIBC__	2
#define	__GLIBC_MINOR__	28
#define __GLIBC_PREREQ(maj, min) \
	((__GLIBC__ << 16) + __GLIBC_MINOR__ >= ((maj) << 16) + (min))
/* This is here only because every header file already includes this one.  */
#ifndef __ASSEMBLER__
# ifndef _SYS_CDEFS_H
#ifndef        _SYS_CDEFS_H
#define        _SYS_CDEFS_H        1
/* We are almost always included from features.h. */
#ifndef _FEATURES_H
#ifndef	_FEATURES_H
#define	_FEATURES_H	1
/* These are defined by the user (or the compiler)
   to specify the desired environment:
   __STRICT_ANSI__	ISO Standard C.
   _ISOC99_SOURCE	Extensions to ISO C89 from ISO C99.
   _ISOC11_SOURCE	Extensions to ISO C99 from ISO C11.
   __STDC_WANT_LIB_EXT2__
			Extensions to ISO C99 from TR 27431-2:2010.
   __STDC_WANT_IEC_60559_BFP_EXT__
			Extensions to ISO C11 from TS 18661-1:2014.
   __STDC_WANT_IEC_60559_FUNCS_EXT__
			Extensions to ISO C11 from TS 18661-4:2015.
   __STDC_WANT_IEC_60559_TYPES_EXT__
			Extensions to ISO C11 from TS 18661-3:2015.
   _POSIX_SOURCE	IEEE Std 1003.1.
   _POSIX_C_SOURCE	If ==1, like _POSIX_SOURCE; if >=2 add IEEE Std 1003.2;
			if >=199309L, add IEEE Std 1003.1b-1993;
			if >=199506L, add IEEE Std 1003.1c-1995;
			if >=200112L, all of IEEE 1003.1-2004
			if >=200809L, all of IEEE 1003.1-2008
   _XOPEN_SOURCE	Includes POSIX and XPG things.  Set to 500 if
			Single Unix conformance is wanted, to 600 for the
			sixth revision, to 700 for the seventh revision.
   _XOPEN_SOURCE_EXTENDED XPG things and X/Open Unix extensions.
   _LARGEFILE_SOURCE	Some more functions for correct standard I/O.
   _LARGEFILE64_SOURCE	Additional functionality from LFS for large files.
   _FILE_OFFSET_BITS=N	Select default filesystem interface.
   _ATFILE_SOURCE	Additional *at interfaces.
   _GNU_SOURCE		All of the above, plus GNU extensions.
   _DEFAULT_SOURCE	The default set of features (taking precedence over
			__STRICT_ANSI__).
   _FORTIFY_SOURCE	Add security hardening to many library functions.
			Set to 1 or 2; 2 performs stricter checks than 1.
   _REENTRANT, _THREAD_SAFE
			Obsolete; equivalent to _POSIX_C_SOURCE=199506L.
   The `-ansi' switch to the GNU C compiler, and standards conformance
   options such as `-std=c99', define __STRICT_ANSI__.  If none of
   these are defined, or if _DEFAULT_SOURCE is defined, the default is
   to have _POSIX_SOURCE set to one and _POSIX_C_SOURCE set to
   200809L, as well as enabling miscellaneous functions from BSD and
   SVID.  If more than one of these are defined, they accumulate.  For
   example __STRICT_ANSI__, _POSIX_SOURCE and _POSIX_C_SOURCE together
   give you ISO C, 1003.1, and 1003.2, but nothing else.
   These are defined by this file and are used by the
   header files to decide what to declare or define:
   __GLIBC_USE (F)	Define things from feature set F.  This is defined
			to 1 or 0; the subsequent macros are either defined
			or undefined, and those tests should be moved to
			__GLIBC_USE.
   __USE_ISOC11		Define ISO C11 things.
   __USE_ISOC99		Define ISO C99 things.
   __USE_ISOC95		Define ISO C90 AMD1 (C95) things.
   __USE_ISOCXX11	Define ISO C++11 things.
   __USE_POSIX		Define IEEE Std 1003.1 things.
   __USE_POSIX2		Define IEEE Std 1003.2 things.
   __USE_POSIX199309	Define IEEE Std 1003.1, and .1b things.
   __USE_POSIX199506	Define IEEE Std 1003.1, .1b, .1c and .1i things.
   __USE_XOPEN		Define XPG things.
   __USE_XOPEN_EXTENDED	Define X/Open Unix things.
   __USE_UNIX98		Define Single Unix V2 things.
   __USE_XOPEN2K        Define XPG6 things.
   __USE_XOPEN2KXSI     Define XPG6 XSI things.
   __USE_XOPEN2K8       Define XPG7 things.
   __USE_XOPEN2K8XSI    Define XPG7 XSI things.
   __USE_LARGEFILE	Define correct standard I/O things.
   __USE_LARGEFILE64	Define LFS things with separate names.
   __USE_FILE_OFFSET64	Define 64bit interface as default.
   __USE_MISC		Define things from 4.3BSD or System V Unix.
   __USE_ATFILE		Define *at interfaces and AT_* constants for them.
   __USE_GNU		Define GNU extensions.
   __USE_FORTIFY_LEVEL	Additional security measures used, according to level.
   The macros `__GNU_LIBRARY__', `__GLIBC__', and `__GLIBC_MINOR__' are
   defined by this file unconditionally.  `__GNU_LIBRARY__' is provided
   only for compatibility.  All new code should use the other symbols
   to test for features.
   All macros listed above as possibly being defined by this file are
   explicitly undefined if they are not explicitly defined.
   Feature-test macros that are not defined by the user or compiler
   but are implied by the other feature-test macros defined (or by the
   lack of any definitions) are defined by the file.
   ISO C feature test macros depend on the definition of the macro
   when an affected header is included, not when the first system
   header is included, and so they are handled in
   <bits/libc-header-start.h>, which does not have a multiple include
   guard.  Feature test macros that can be handled from the first
   system header included are handled here.  */
/* Undefine everything, so we get a clean slate.  */
#undef	__USE_ISOC11
#undef	__USE_ISOC99
#undef	__USE_ISOC95
#undef	__USE_ISOCXX11
#undef	__USE_POSIX
#undef	__USE_POSIX2
#undef	__USE_POSIX199309
#undef	__USE_POSIX199506
#undef	__USE_XOPEN
#undef	__USE_XOPEN_EXTENDED
#undef	__USE_UNIX98
#undef	__USE_XOPEN2K
#undef	__USE_XOPEN2KXSI
#undef	__USE_XOPEN2K8
#undef	__USE_XOPEN2K8XSI
#undef	__USE_LARGEFILE
#undef	__USE_LARGEFILE64
#undef	__USE_FILE_OFFSET64
#undef	__USE_MISC
#undef	__USE_ATFILE
#undef	__USE_GNU
#undef	__USE_FORTIFY_LEVEL
#undef	__KERNEL_STRICT_NAMES
#undef	__GLIBC_USE_DEPRECATED_GETS
/* Suppress kernel-name space pollution unless user expressedly asks
   for it.  */
#ifndef _LOOSE_KERNEL_NAMES
# define __KERNEL_STRICT_NAMES
#endif
/* Convenience macro to test the version of gcc.
   Use like this:
   #if __GNUC_PREREQ (2,8)
   ... code requiring gcc 2.8 or later ...
   #endif
   Note: only works for GCC 2.0 and later, because __GNUC_MINOR__ was
   added in 2.0.  */
#if defined __GNUC__ && defined __GNUC_MINOR__
# define __GNUC_PREREQ(maj, min) \
	((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
#else
# define __GNUC_PREREQ(maj, min) 0
#endif
/* Similarly for clang.  Features added to GCC after version 4.2 may
   or may not also be available in clang, and clang's definitions of
   __GNUC(_MINOR)__ are fixed at 4 and 2 respectively.  Not all such
   features can be queried via __has_extension/__has_feature.  */
#if defined __clang_major__ && defined __clang_minor__
# define __glibc_clang_prereq(maj, min) \
  ((__clang_major__ << 16) + __clang_minor__ >= ((maj) << 16) + (min))
#else
# define __glibc_clang_prereq(maj, min) 0
#endif
/* Whether to use feature set F.  */
#define __GLIBC_USE(F)	__GLIBC_USE_ ## F
/* _BSD_SOURCE and _SVID_SOURCE are deprecated aliases for
   _DEFAULT_SOURCE.  If _DEFAULT_SOURCE is present we do not
   issue a warning; the expectation is that the source is being
   transitioned to use the new macro.  */
#if (defined _BSD_SOURCE || defined _SVID_SOURCE) \
    && !defined _DEFAULT_SOURCE
# warning "_BSD_SOURCE and _SVID_SOURCE are deprecated, use _DEFAULT_SOURCE"
# undef  _DEFAULT_SOURCE
# define _DEFAULT_SOURCE	1
#endif
/* If _GNU_SOURCE was defined by the user, turn on all the other features.  */
#ifdef _GNU_SOURCE
# undef  _ISOC95_SOURCE
# define _ISOC95_SOURCE	1
# undef  _ISOC99_SOURCE
# define _ISOC99_SOURCE	1
# undef  _ISOC11_SOURCE
# define _ISOC11_SOURCE	1
# undef  _POSIX_SOURCE
# define _POSIX_SOURCE	1
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE	200809L
# undef  _XOPEN_SOURCE
# define _XOPEN_SOURCE	700
# undef  _XOPEN_SOURCE_EXTENDED
# define _XOPEN_SOURCE_EXTENDED	1
# undef	 _LARGEFILE64_SOURCE
# define _LARGEFILE64_SOURCE	1
# undef  _DEFAULT_SOURCE
# define _DEFAULT_SOURCE	1
# undef  _ATFILE_SOURCE
# define _ATFILE_SOURCE	1
#endif
/* If nothing (other than _GNU_SOURCE and _DEFAULT_SOURCE) is defined,
   define _DEFAULT_SOURCE.  */
#if (defined _DEFAULT_SOURCE					\
     || (!defined __STRICT_ANSI__				\
	 && !defined _ISOC99_SOURCE && !defined _ISOC11_SOURCE	\
	 && !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE	\
	 && !defined _XOPEN_SOURCE))
# undef  _DEFAULT_SOURCE
# define _DEFAULT_SOURCE	1
#endif
/* This is to enable the ISO C11 extension.  */
#if (defined _ISOC11_SOURCE \
     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 201112L))
# define __USE_ISOC11	1
#endif
/* This is to enable the ISO C99 extension.  */
#if (defined _ISOC99_SOURCE || defined _ISOC11_SOURCE \
     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L))
# define __USE_ISOC99	1
#endif
/* This is to enable the ISO C90 Amendment 1:1995 extension.  */
#if (defined _ISOC99_SOURCE || defined _ISOC11_SOURCE \
     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199409L))
# define __USE_ISOC95	1
#endif
#ifdef __cplusplus
/* This is to enable compatibility for ISO C++17.  */
# if __cplusplus >= 201703L
#  define __USE_ISOC11	1
# endif
/* This is to enable compatibility for ISO C++11.
   Check the temporary macro for now, too.  */
# if __cplusplus >= 201103L || defined __GXX_EXPERIMENTAL_CXX0X__
#  define __USE_ISOCXX11	1
#  define __USE_ISOC99	1
# endif
#endif
/* If none of the ANSI/POSIX macros are defined, or if _DEFAULT_SOURCE
   is defined, use POSIX.1-2008 (or another version depending on
   _XOPEN_SOURCE).  */
#ifdef _DEFAULT_SOURCE
# if !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE
#  define __USE_POSIX_IMPLICITLY	1
# endif
# undef  _POSIX_SOURCE
# define _POSIX_SOURCE	1
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE	200809L
#endif
#if ((!defined __STRICT_ANSI__					\
      || (defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) >= 500))	\
     && !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE)
# define _POSIX_SOURCE	1
# if defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 500
#  define _POSIX_C_SOURCE	2
# elif defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 600
#  define _POSIX_C_SOURCE	199506L
# elif defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 700
#  define _POSIX_C_SOURCE	200112L
# else
#  define _POSIX_C_SOURCE	200809L
# endif
# define __USE_POSIX_IMPLICITLY	1
#endif
/* Some C libraries once required _REENTRANT and/or _THREAD_SAFE to be
   defined in all multithreaded code.  GNU libc has not required this
   for many years.  We now treat them as compatibility synonyms for
   _POSIX_C_SOURCE=199506L, which is the earliest level of POSIX with
   comprehensive support for multithreaded code.  Using them never
   lowers the selected level of POSIX conformance, only raises it.  */
#if ((!defined _POSIX_C_SOURCE || (_POSIX_C_SOURCE - 0) < 199506L) \
     && (defined _REENTRANT || defined _THREAD_SAFE))
# define _POSIX_SOURCE   1
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE 199506L
#endif
#if (defined _POSIX_SOURCE					\
     || (defined _POSIX_C_SOURCE && _POSIX_C_SOURCE >= 1)	\
     || defined _XOPEN_SOURCE)
# define __USE_POSIX	1
#endif
#if defined _POSIX_C_SOURCE && _POSIX_C_SOURCE >= 2 || defined _XOPEN_SOURCE
# define __USE_POSIX2	1
#endif
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 199309L
# define __USE_POSIX199309	1
#endif
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 199506L
# define __USE_POSIX199506	1
#endif
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 200112L
# define __USE_XOPEN2K		1
# undef __USE_ISOC95
# define __USE_ISOC95		1
# undef __USE_ISOC99
# define __USE_ISOC99		1
#endif
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 200809L
# define __USE_XOPEN2K8		1
# undef  _ATFILE_SOURCE
# define _ATFILE_SOURCE	1
#endif
#ifdef	_XOPEN_SOURCE
# define __USE_XOPEN	1
# if (_XOPEN_SOURCE - 0) >= 500
#  define __USE_XOPEN_EXTENDED	1
#  define __USE_UNIX98	1
#  undef _LARGEFILE_SOURCE
#  define _LARGEFILE_SOURCE	1
#  if (_XOPEN_SOURCE - 0) >= 600
#   if (_XOPEN_SOURCE - 0) >= 700
#    define __USE_XOPEN2K8	1
#    define __USE_XOPEN2K8XSI	1
#   endif
#   define __USE_XOPEN2K	1
#   define __USE_XOPEN2KXSI	1
#   undef __USE_ISOC95
#   define __USE_ISOC95		1
#   undef __USE_ISOC99
#   define __USE_ISOC99		1
#  endif
# else
#  ifdef _XOPEN_SOURCE_EXTENDED
#   define __USE_XOPEN_EXTENDED	1
#  endif
# endif
#endif
#ifdef _LARGEFILE_SOURCE
# define __USE_LARGEFILE	1
#endif
#ifdef _LARGEFILE64_SOURCE
# define __USE_LARGEFILE64	1
#endif
#if defined _FILE_OFFSET_BITS && _FILE_OFFSET_BITS == 64
# define __USE_FILE_OFFSET64	1
#endif
#if defined _DEFAULT_SOURCE
# define __USE_MISC	1
#endif
#ifdef	_ATFILE_SOURCE
# define __USE_ATFILE	1
#endif
#ifdef	_GNU_SOURCE
# define __USE_GNU	1
#endif
#if defined _FORTIFY_SOURCE && _FORTIFY_SOURCE > 0
# if !defined __OPTIMIZE__ || __OPTIMIZE__ <= 0
#  warning _FORTIFY_SOURCE requires compiling with optimization (-O)
# elif !__GNUC_PREREQ (4, 1)
#  warning _FORTIFY_SOURCE requires GCC 4.1 or later
# elif _FORTIFY_SOURCE > 1
#  define __USE_FORTIFY_LEVEL 2
# else
#  define __USE_FORTIFY_LEVEL 1
# endif
#endif
#ifndef __USE_FORTIFY_LEVEL
# define __USE_FORTIFY_LEVEL 0
#endif
/* The function 'gets' existed in C89, but is impossible to use
   safely.  It has been removed from ISO C11 and ISO C++14.  Note: for
   compatibility with various implementations of <cstdio>, this test
   must consider only the value of __cplusplus when compiling C++.  */
#if defined __cplusplus ? __cplusplus >= 201402L : defined __USE_ISOC11
# define __GLIBC_USE_DEPRECATED_GETS 0
#else
# define __GLIBC_USE_DEPRECATED_GETS 1
#endif
/* Get definitions of __STDC_* predefined macros, if the compiler has
   not preincluded this header automatically.  */
#include <stdc-predef.h>
/* This macro indicates that the installed library is the GNU C Library.
   For historic reasons the value now is 6 and this will stay from now
   on.  The use of this variable is deprecated.  Use __GLIBC__ and
   __GLIBC_MINOR__ now (see below) when you want to test for a specific
   GNU C library version and use the values in <gnu/lib-names.h> to get
   the sonames of the shared libraries.  */
#undef  __GNU_LIBRARY__
#define __GNU_LIBRARY__ 6
/* Major and minor version number of the GNU C library package.  Use
   these macros to test for features in specific releases.  */
#define	__GLIBC__	2
#define	__GLIBC_MINOR__	28
#define __GLIBC_PREREQ(maj, min) \
	((__GLIBC__ << 16) + __GLIBC_MINOR__ >= ((maj) << 16) + (min))
/* This is here only because every header file already includes this one.  */
#ifndef __ASSEMBLER__
# ifndef _SYS_CDEFS_H
#  include <sys/cdefs.h>
# endif
/* If we don't have __REDIRECT, prototypes will be missing if
   __USE_FILE_OFFSET64 but not __USE_LARGEFILE[64]. */
# if defined __USE_FILE_OFFSET64 && !defined __REDIRECT
#  define __USE_LARGEFILE	1
#  define __USE_LARGEFILE64	1
# endif
#endif	/* !ASSEMBLER */
/* Decide whether we can define 'extern inline' functions in headers.  */
#if __GNUC_PREREQ (2, 7) && defined __OPTIMIZE__ \
    && !defined __OPTIMIZE_SIZE__ && !defined __NO_INLINE__ \
    && defined __extern_inline
# define __USE_EXTERN_INLINES	1
#endif
/* This is here only because every header file already includes this one.
   Get the definitions of all the appropriate `__stub_FUNCTION' symbols.
   <gnu/stubs.h> contains `#define __stub_FUNCTION' when FUNCTION is a stub
   that will always return failure (and set errno to ENOSYS).  */
#include <gnu/stubs.h>
#endif	/* features.h  */
#endif
/* The GNU libc does not support any K&R compilers or the traditional mode
   of ISO C compilers anymore.  Check for some of the combinations not
   anymore supported.  */
#if defined __GNUC__ && !defined __STDC__
# error "You need a ISO C conforming compiler to use the glibc headers"
#endif
/* Some user header file might have defined this before.  */
#undef        __P
#undef        __PMT
#ifdef __GNUC__
/* All functions, except those with callbacks or those that
   synchronize memory, are leaf functions.  */
# if __GNUC_PREREQ (4, 6) && !defined _LIBC
#  define __LEAF , __leaf__
#  define __LEAF_ATTR __attribute__ ((__leaf__))
# else
#  define __LEAF
#  define __LEAF_ATTR
# endif
/* GCC can always grok prototypes.  For C++ programs we add throw()
   to help it optimize the function calls.  But this works only with
   gcc 2.8.x and egcs.  For gcc 3.2 and up we even mark C functions
   as non-throwing using a function attribute since programs can use
   the -fexceptions options for C code as well.  */
# if !defined __cplusplus && __GNUC_PREREQ (3, 3)
#  define __THROW        __attribute__ ((__nothrow__ __LEAF))
#  define __THROWNL        __attribute__ ((__nothrow__))
#  define __NTH(fct)        __attribute__ ((__nothrow__ __LEAF)) fct
#  define __NTHNL(fct)  __attribute__ ((__nothrow__)) fct
# else
#  if defined __cplusplus && __GNUC_PREREQ (2,8)
#   define __THROW        throw ()
#   define __THROWNL        throw ()
#   define __NTH(fct)        __LEAF_ATTR fct throw ()
#   define __NTHNL(fct) fct throw ()
#  else
#   define __THROW
#   define __THROWNL
#   define __NTH(fct)        fct
#   define __NTHNL(fct) fct
#  endif
# endif
#else        /* Not GCC.  */
# if (defined __cplusplus                                                \
      || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L))
#  define __inline        inline
# else
#  define __inline                /* No inline functions.  */
# endif
# define __THROW
# define __THROWNL
# define __NTH(fct)        fct
#endif        /* GCC.  */
/* Compilers that are not clang may object to
       #if defined __clang__ && __has_extension(...)
   even though they do not need to evaluate the right-hand side of the &&.  */
#if defined __clang__ && defined __has_extension
# define __glibc_clang_has_extension(ext) __has_extension (ext)
#else
# define __glibc_clang_has_extension(ext) 0
#endif
/* These two macros are not used in glibc anymore.  They are kept here
   only because some other projects expect the macros to be defined.  */
#define __P(args)        args
#define __PMT(args)        args
/* For these things, GCC behaves the ANSI way normally,
   and the non-ANSI way under -traditional.  */
#define __CONCAT(x,y)        x ## y
#define __STRING(x)        #x
/* This is not a typedef so `const __ptr_t' does the right thing.  */
#define __ptr_t void *
/* C++ needs to know that types and declarations are C, not C++.  */
#ifdef        __cplusplus
# define __BEGIN_DECLS        extern "C" {
# define __END_DECLS        }
#else
# define __BEGIN_DECLS
# define __END_DECLS
#endif
/* Fortify support.  */
#define __bos(ptr) __builtin_object_size (ptr, __USE_FORTIFY_LEVEL > 1)
#define __bos0(ptr) __builtin_object_size (ptr, 0)
#if __GNUC_PREREQ (4,3)
# define __warndecl(name, msg) \
  extern void name (void) __attribute__((__warning__ (msg)))
# define __warnattr(msg) __attribute__((__warning__ (msg)))
# define __errordecl(name, msg) \
  extern void name (void) __attribute__((__error__ (msg)))
#else
# define __warndecl(name, msg) extern void name (void)
# define __warnattr(msg)
# define __errordecl(name, msg) extern void name (void)
#endif
/* Support for flexible arrays.
   Headers that should use flexible arrays only if they're "real"
   (e.g. only if they won't affect sizeof()) should test
   #if __glibc_c99_flexarr_available.  */
#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
# define __flexarr        []
# define __glibc_c99_flexarr_available 1
#elif __GNUC_PREREQ (2,97)
/* GCC 2.97 supports C99 flexible array members as an extension,
   even when in C89 mode or compiling C++ (any version).  */
# define __flexarr        []
# define __glibc_c99_flexarr_available 1
#elif defined __GNUC__
/* Pre-2.97 GCC did not support C99 flexible arrays but did have
   an equivalent extension with slightly different notation.  */
# define __flexarr        [0]
# define __glibc_c99_flexarr_available 1
#else
/* Some other non-C99 compiler.  Approximate with [1].  */
# define __flexarr        [1]
# define __glibc_c99_flexarr_available 0
#endif
/* __asm__ ("xyz") is used throughout the headers to rename functions
   at the assembly language level.  This is wrapped by the __REDIRECT
   macro, in order to support compilers that can do this some other
   way.  When compilers don't support asm-names at all, we have to do
   preprocessor tricks instead (which don't have exactly the right
   semantics, but it's the best we can do).
   Example:
   int __REDIRECT(setpgrp, (__pid_t pid, __pid_t pgrp), setpgid); */
#if defined __GNUC__ && __GNUC__ >= 2
# define __REDIRECT(name, proto, alias) name proto __asm__ (__ASMNAME (#alias))
# ifdef __cplusplus
#  define __REDIRECT_NTH(name, proto, alias) \
     name proto __THROW __asm__ (__ASMNAME (#alias))
#  define __REDIRECT_NTHNL(name, proto, alias) \
     name proto __THROWNL __asm__ (__ASMNAME (#alias))
# else
#  define __REDIRECT_NTH(name, proto, alias) \
     name proto __asm__ (__ASMNAME (#alias)) __THROW
#  define __REDIRECT_NTHNL(name, proto, alias) \
     name proto __asm__ (__ASMNAME (#alias)) __THROWNL
# endif
# define __ASMNAME(cname)  __ASMNAME2 (__USER_LABEL_PREFIX__, cname)
# define __ASMNAME2(prefix, cname) __STRING (prefix) cname
/*
#elif __SOME_OTHER_COMPILER__
# define __REDIRECT(name, proto, alias) name proto; \
        _Pragma("let " #name " = " #alias)
*/
#endif
/* GCC has various useful declarations that can be made with the
   `__attribute__' syntax.  All of the ways we use this do fine if
   they are omitted for compilers that don't understand it. */
#if !defined __GNUC__ || __GNUC__ < 2
# define __attribute__(xyz)        /* Ignore */
#endif
/* At some point during the gcc 2.96 development the `malloc' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */
#if __GNUC_PREREQ (2,96)
# define __attribute_malloc__ __attribute__ ((__malloc__))
#else
# define __attribute_malloc__ /* Ignore */
#endif
/* Tell the compiler which arguments to an allocation function
   indicate the size of the allocation.  */
#if __GNUC_PREREQ (4, 3)
# define __attribute_alloc_size__(params) \
  __attribute__ ((__alloc_size__ params))
#else
# define __attribute_alloc_size__(params) /* Ignore.  */
#endif
/* At some point during the gcc 2.96 development the `pure' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */
#if __GNUC_PREREQ (2,96)
# define __attribute_pure__ __attribute__ ((__pure__))
#else
# define __attribute_pure__ /* Ignore */
#endif
/* This declaration tells the compiler that the value is constant.  */
#if __GNUC_PREREQ (2,5)
# define __attribute_const__ __attribute__ ((__const__))
#else
# define __attribute_const__ /* Ignore */
#endif
/* At some point during the gcc 3.1 development the `used' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */
#if __GNUC_PREREQ (3,1)
# define __attribute_used__ __attribute__ ((__used__))
# define __attribute_noinline__ __attribute__ ((__noinline__))
#else
# define __attribute_used__ __attribute__ ((__unused__))
# define __attribute_noinline__ /* Ignore */
#endif
/* Since version 3.2, gcc allows marking deprecated functions.  */
#if __GNUC_PREREQ (3,2)
# define __attribute_deprecated__ __attribute__ ((__deprecated__))
#else
# define __attribute_deprecated__ /* Ignore */
#endif
/* Since version 4.5, gcc also allows one to specify the message printed
   when a deprecated function is used.  clang claims to be gcc 4.2, but
   may also support this feature.  */
#if __GNUC_PREREQ (4,5) \
    || __glibc_clang_has_extension (__attribute_deprecated_with_message__)
# define __attribute_deprecated_msg__(msg) \
         __attribute__ ((__deprecated__ (msg)))
#else
# define __attribute_deprecated_msg__(msg) __attribute_deprecated__
#endif
/* At some point during the gcc 2.8 development the `format_arg' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.
   If several `format_arg' attributes are given for the same function, in
   gcc-3.0 and older, all but the last one are ignored.  In newer gccs,
   all designated arguments are considered.  */
#if __GNUC_PREREQ (2,8)
# define __attribute_format_arg__(x) __attribute__ ((__format_arg__ (x)))
#else
# define __attribute_format_arg__(x) /* Ignore */
#endif
/* At some point during the gcc 2.97 development the `strfmon' format
   attribute for functions was introduced.  We don't want to use it
   unconditionally (although this would be possible) since it
   generates warnings.  */
#if __GNUC_PREREQ (2,97)
# define __attribute_format_strfmon__(a,b) \
  __attribute__ ((__format__ (__strfmon__, a, b)))
#else
# define __attribute_format_strfmon__(a,b) /* Ignore */
#endif
/* The nonull function attribute allows to mark pointer parameters which
   must not be NULL.  */
#if __GNUC_PREREQ (3,3)
# define __nonnull(params) __attribute__ ((__nonnull__ params))
#else
# define __nonnull(params)
#endif
/* If fortification mode, we warn about unused results of certain
   function calls which can lead to problems.  */
#if __GNUC_PREREQ (3,4)
# define __attribute_warn_unused_result__ \
   __attribute__ ((__warn_unused_result__))
# if __USE_FORTIFY_LEVEL > 0
#  define __wur __attribute_warn_unused_result__
# endif
#else
# define __attribute_warn_unused_result__ /* empty */
#endif
#ifndef __wur
# define __wur /* Ignore */
#endif
/* Forces a function to be always inlined.  */
#if __GNUC_PREREQ (3,2)
/* The Linux kernel defines __always_inline in stddef.h (283d7573), and
   it conflicts with this definition.  Therefore undefine it first to
   allow either header to be included first.  */
# undef __always_inline
# define __always_inline __inline __attribute__ ((__always_inline__))
#else
# undef __always_inline
# define __always_inline __inline
#endif
/* Associate error messages with the source location of the call site rather
   than with the source location inside the function.  */
#if __GNUC_PREREQ (4,3)
# define __attribute_artificial__ __attribute__ ((__artificial__))
#else
# define __attribute_artificial__ /* Ignore */
#endif
/* GCC 4.3 and above with -std=c99 or -std=gnu99 implements ISO C99
   inline semantics, unless -fgnu89-inline is used.  Using __GNUC_STDC_INLINE__
   or __GNUC_GNU_INLINE is not a good enough check for gcc because gcc versions
   older than 4.3 may define these macros and still not guarantee GNU inlining
   semantics.
   clang++ identifies itself as gcc-4.2, but has support for GNU inlining
   semantics, that can be checked for by using the __GNUC_STDC_INLINE_ and
   __GNUC_GNU_INLINE__ macro definitions.  */
#if (!defined __cplusplus || __GNUC_PREREQ (4,3) \
     || (defined __clang__ && (defined __GNUC_STDC_INLINE__ \
                               || defined __GNUC_GNU_INLINE__)))
# if defined __GNUC_STDC_INLINE__ || defined __cplusplus
#  define __extern_inline extern __inline __attribute__ ((__gnu_inline__))
#  define __extern_always_inline \
  extern __always_inline __attribute__ ((__gnu_inline__))
# else
#  define __extern_inline extern __inline
#  define __extern_always_inline extern __always_inline
# endif
#endif
#ifdef __extern_always_inline
# define __fortify_function __extern_always_inline __attribute_artificial__
#endif
/* GCC 4.3 and above allow passing all anonymous arguments of an
   __extern_always_inline function to some other vararg function.  */
#if __GNUC_PREREQ (4,3)
# define __va_arg_pack() __builtin_va_arg_pack ()
# define __va_arg_pack_len() __builtin_va_arg_pack_len ()
#endif
/* It is possible to compile containing GCC extensions even if GCC is
   run in pedantic mode if the uses are carefully marked using the
   `__extension__' keyword.  But this is not generally available before
   version 2.8.  */
#if !__GNUC_PREREQ (2,8)
# define __extension__                /* Ignore */
#endif
/* __restrict is known in EGCS 1.2 and above. */
#if !__GNUC_PREREQ (2,92)
# if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
#  define __restrict        restrict
# else
#  define __restrict        /* Ignore */
# endif
#endif
/* ISO C99 also allows to declare arrays as non-overlapping.  The syntax is
     array_name[restrict]
   GCC 3.1 supports this.  */
#if __GNUC_PREREQ (3,1) && !defined __GNUG__
# define __restrict_arr        __restrict
#else
# ifdef __GNUC__
#  define __restrict_arr        /* Not supported in old GCC.  */
# else
#  if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
#   define __restrict_arr        restrict
#  else
/* Some other non-C99 compiler.  */
#   define __restrict_arr        /* Not supported.  */
#  endif
# endif
#endif
#if __GNUC__ >= 3
# define __glibc_unlikely(cond)        __builtin_expect ((cond), 0)
# define __glibc_likely(cond)        __builtin_expect ((cond), 1)
#else
# define __glibc_unlikely(cond)        (cond)
# define __glibc_likely(cond)        (cond)
#endif
#ifdef __has_attribute
# define __glibc_has_attribute(attr)        __has_attribute (attr)
#else
# define __glibc_has_attribute(attr)        0
#endif
#if (!defined _Noreturn \
     && (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) < 201112 \
     &&  !__GNUC_PREREQ (4,7))
# if __GNUC_PREREQ (2,8)
#  define _Noreturn __attribute__ ((__noreturn__))
# else
#  define _Noreturn
# endif
#endif
#if __GNUC_PREREQ (8, 0)
/* Describes a char array whose address can safely be passed as the first
   argument to strncpy and strncat, as the char array is not necessarily
   a NUL-terminated string.  */
# define __attribute_nonstring__ __attribute__ ((__nonstring__))
#else
# define __attribute_nonstring__
#endif
/* Undefine (also defined in libc-symbols.h).  */
#undef __attribute_copy__
#if __GNUC_PREREQ (9, 0)
/* Copies attributes from the declaration or type referenced by
   the argument.  */
# define __attribute_copy__(arg) __attribute__ ((__copy__ (arg)))
#else
# define __attribute_copy__(arg)
#endif
#if (!defined _Static_assert && !defined __cplusplus \
     && (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) < 201112 \
     && (!__GNUC_PREREQ (4, 6) || defined __STRICT_ANSI__))
# define _Static_assert(expr, diagnostic) \
    extern int (*__Static_assert_function (void)) \
      [!!sizeof (struct { int __error_if_negative: (expr) ? 2 : -1; })]
#endif
#include <bits/wordsize.h>
#include <bits/long-double.h>
#if defined __LONG_DOUBLE_MATH_OPTIONAL && defined __NO_LONG_DOUBLE_MATH
# define __LDBL_COMPAT 1
# ifdef __REDIRECT
#  define __LDBL_REDIR1(name, proto, alias) __REDIRECT (name, proto, alias)
#  define __LDBL_REDIR(name, proto) \
  __LDBL_REDIR1 (name, proto, __nldbl_##name)
#  define __LDBL_REDIR1_NTH(name, proto, alias) __REDIRECT_NTH (name, proto, alias)
#  define __LDBL_REDIR_NTH(name, proto) \
  __LDBL_REDIR1_NTH (name, proto, __nldbl_##name)
#  define __LDBL_REDIR1_DECL(name, alias) \
  extern __typeof (name) name __asm (__ASMNAME (#alias));
#  define __LDBL_REDIR_DECL(name) \
  extern __typeof (name) name __asm (__ASMNAME ("__nldbl_" #name));
#  define __REDIRECT_LDBL(name, proto, alias) \
  __LDBL_REDIR1 (name, proto, __nldbl_##alias)
#  define __REDIRECT_NTH_LDBL(name, proto, alias) \
  __LDBL_REDIR1_NTH (name, proto, __nldbl_##alias)
# endif
#endif
#if !defined __LDBL_COMPAT || !defined __REDIRECT
# define __LDBL_REDIR1(name, proto, alias) name proto
# define __LDBL_REDIR(name, proto) name proto
# define __LDBL_REDIR1_NTH(name, proto, alias) name proto __THROW
# define __LDBL_REDIR_NTH(name, proto) name proto __THROW
# define __LDBL_REDIR_DECL(name)
# ifdef __REDIRECT
#  define __REDIRECT_LDBL(name, proto, alias) __REDIRECT (name, proto, alias)
#  define __REDIRECT_NTH_LDBL(name, proto, alias) \
  __REDIRECT_NTH (name, proto, alias)
# endif
#endif
/* __glibc_macro_warning (MESSAGE) issues warning MESSAGE.  This is
   intended for use in preprocessor macros.
   Note: MESSAGE must be a _single_ string; concatenation of string
   literals is not supported.  */
#if __GNUC_PREREQ (4,8) || __glibc_clang_prereq (3,5)
# define __glibc_macro_warning1(message) _Pragma (#message)
# define __glibc_macro_warning(message) \
  __glibc_macro_warning1 (GCC warning message)
#else
# define __glibc_macro_warning(msg)
#endif
/* Generic selection (ISO C11) is a C-only feature, available in GCC
   since version 4.9.  Previous versions do not provide generic
   selection, even though they might set __STDC_VERSION__ to 201112L,
   when in -std=c11 mode.  Thus, we must check for !defined __GNUC__
   when testing __STDC_VERSION__ for generic selection support.
   On the other hand, Clang also defines __GNUC__, so a clang-specific
   check is required to enable the use of generic selection.  */
#if !defined __cplusplus \
    && (__GNUC_PREREQ (4, 9) \
        || __glibc_clang_has_extension (c_generic_selections) \
        || (!defined __GNUC__ && defined __STDC_VERSION__ \
            && __STDC_VERSION__ >= 201112L))
# define __HAVE_GENERIC_SELECTION 1
#else
# define __HAVE_GENERIC_SELECTION 0
#endif
#endif         /* sys/cdefs.h */
# endif
/* If we don't have __REDIRECT, prototypes will be missing if
   __USE_FILE_OFFSET64 but not __USE_LARGEFILE[64]. */
# if defined __USE_FILE_OFFSET64 && !defined __REDIRECT
#  define __USE_LARGEFILE	1
#  define __USE_LARGEFILE64	1
# endif
#endif	/* !ASSEMBLER */
/* Decide whether we can define 'extern inline' functions in headers.  */
#if __GNUC_PREREQ (2, 7) && defined __OPTIMIZE__ \
    && !defined __OPTIMIZE_SIZE__ && !defined __NO_INLINE__ \
    && defined __extern_inline
# define __USE_EXTERN_INLINES	1
#endif
/* This is here only because every header file already includes this one.
   Get the definitions of all the appropriate `__stub_FUNCTION' symbols.
   <gnu/stubs.h> contains `#define __stub_FUNCTION' when FUNCTION is a stub
   that will always return failure (and set errno to ENOSYS).  */
#if !defined __x86_64__
#ifdef _LIBC
 #error Applications may not define the macro _LIBC
#endif

#define __stub___kernel_rem_pio2l
#define __stub_chflags
#define __stub_fattach
#define __stub_fchflags
#define __stub_fdetach
#define __stub_futimens
#define __stub_gtty
#define __stub_lchmod
#define __stub_lutimes
#define __stub_revoke
#define __stub_setlogin
#define __stub_sigreturn
#define __stub_sstk
#define __stub_stty
#define __stub_sync_file_range
#define __stub_utimensat
#endif
#if defined __x86_64__ && defined __LP64__
#ifdef _LIBC
 #error Applications may not define the macro _LIBC
#endif
#define __stub___compat_bdflush
#define __stub_chflags
#define __stub_fattach
#define __stub_fchflags
#define __stub_fdetach
#define __stub_getmsg
#define __stub_gtty
#define __stub_lchmod
#define __stub_putmsg
#define __stub_revoke
#define __stub_setlogin
#define __stub_sigreturn
#define __stub_sstk
#define __stub_stty
#endif
#if defined __x86_64__ && defined __ILP32__
#ifdef _LIBC
 #error Applications may not define the macro _LIBC
#endif

#define __stub___compat_bdflush
#define __stub___compat_create_module
#define __stub___compat_get_kernel_syms
#define __stub___compat_nfsservctl
#define __stub___compat_query_module
#define __stub___compat_uselib
#define __stub_chflags
#define __stub_fchflags
#define __stub_gtty
#define __stub_lchmod
#define __stub_revoke
#define __stub_setlogin
#define __stub_sigreturn
#define __stub_sstk
#define __stub_stty
#endif
#endif	/* features.h  */
#endif
/* The GNU libc does not support any K&R compilers or the traditional mode
   of ISO C compilers anymore.  Check for some of the combinations not
   anymore supported.  */
#if defined __GNUC__ && !defined __STDC__
# error "You need a ISO C conforming compiler to use the glibc headers"
#endif
/* Some user header file might have defined this before.  */
#undef        __P
#undef        __PMT
#ifdef __GNUC__
/* All functions, except those with callbacks or those that
   synchronize memory, are leaf functions.  */
# if __GNUC_PREREQ (4, 6) && !defined _LIBC
#  define __LEAF , __leaf__
#  define __LEAF_ATTR __attribute__ ((__leaf__))
# else
#  define __LEAF
#  define __LEAF_ATTR
# endif
/* GCC can always grok prototypes.  For C++ programs we add throw()
   to help it optimize the function calls.  But this works only with
   gcc 2.8.x and egcs.  For gcc 3.2 and up we even mark C functions
   as non-throwing using a function attribute since programs can use
   the -fexceptions options for C code as well.  */
# if !defined __cplusplus && __GNUC_PREREQ (3, 3)
#  define __THROW        __attribute__ ((__nothrow__ __LEAF))
#  define __THROWNL        __attribute__ ((__nothrow__))
#  define __NTH(fct)        __attribute__ ((__nothrow__ __LEAF)) fct
#  define __NTHNL(fct)  __attribute__ ((__nothrow__)) fct
# else
#  if defined __cplusplus && __GNUC_PREREQ (2,8)
#   define __THROW        throw ()
#   define __THROWNL        throw ()
#   define __NTH(fct)        __LEAF_ATTR fct throw ()
#   define __NTHNL(fct) fct throw ()
#  else
#   define __THROW
#   define __THROWNL
#   define __NTH(fct)        fct
#   define __NTHNL(fct) fct
#  endif
# endif
#else        /* Not GCC.  */
# if (defined __cplusplus                                                \
      || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L))
#  define __inline        inline
# else
#  define __inline                /* No inline functions.  */
# endif
# define __THROW
# define __THROWNL
# define __NTH(fct)        fct
#endif        /* GCC.  */
/* Compilers that are not clang may object to
       #if defined __clang__ && __has_extension(...)
   even though they do not need to evaluate the right-hand side of the &&.  */
#if defined __clang__ && defined __has_extension
# define __glibc_clang_has_extension(ext) __has_extension (ext)
#else
# define __glibc_clang_has_extension(ext) 0
#endif
/* These two macros are not used in glibc anymore.  They are kept here
   only because some other projects expect the macros to be defined.  */
#define __P(args)        args
#define __PMT(args)        args
/* For these things, GCC behaves the ANSI way normally,
   and the non-ANSI way under -traditional.  */
#define __CONCAT(x,y)        x ## y
#define __STRING(x)        #x
/* This is not a typedef so `const __ptr_t' does the right thing.  */
#define __ptr_t void *
/* C++ needs to know that types and declarations are C, not C++.  */
#ifdef        __cplusplus
# define __BEGIN_DECLS        extern "C" {
# define __END_DECLS        }
#else
# define __BEGIN_DECLS
# define __END_DECLS
#endif
/* Fortify support.  */
#define __bos(ptr) __builtin_object_size (ptr, __USE_FORTIFY_LEVEL > 1)
#define __bos0(ptr) __builtin_object_size (ptr, 0)
#if __GNUC_PREREQ (4,3)
# define __warndecl(name, msg) \
  extern void name (void) __attribute__((__warning__ (msg)))
# define __warnattr(msg) __attribute__((__warning__ (msg)))
# define __errordecl(name, msg) \
  extern void name (void) __attribute__((__error__ (msg)))
#else
# define __warndecl(name, msg) extern void name (void)
# define __warnattr(msg)
# define __errordecl(name, msg) extern void name (void)
#endif
/* Support for flexible arrays.
   Headers that should use flexible arrays only if they're "real"
   (e.g. only if they won't affect sizeof()) should test
   #if __glibc_c99_flexarr_available.  */
#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
# define __flexarr        []
# define __glibc_c99_flexarr_available 1
#elif __GNUC_PREREQ (2,97)
/* GCC 2.97 supports C99 flexible array members as an extension,
   even when in C89 mode or compiling C++ (any version).  */
# define __flexarr        []
# define __glibc_c99_flexarr_available 1
#elif defined __GNUC__
/* Pre-2.97 GCC did not support C99 flexible arrays but did have
   an equivalent extension with slightly different notation.  */
# define __flexarr        [0]
# define __glibc_c99_flexarr_available 1
#else
/* Some other non-C99 compiler.  Approximate with [1].  */
# define __flexarr        [1]
# define __glibc_c99_flexarr_available 0
#endif
/* __asm__ ("xyz") is used throughout the headers to rename functions
   at the assembly language level.  This is wrapped by the __REDIRECT
   macro, in order to support compilers that can do this some other
   way.  When compilers don't support asm-names at all, we have to do
   preprocessor tricks instead (which don't have exactly the right
   semantics, but it's the best we can do).
   Example:
   int __REDIRECT(setpgrp, (__pid_t pid, __pid_t pgrp), setpgid); */
#if defined __GNUC__ && __GNUC__ >= 2
# define __REDIRECT(name, proto, alias) name proto __asm__ (__ASMNAME (#alias))
# ifdef __cplusplus
#  define __REDIRECT_NTH(name, proto, alias) \
     name proto __THROW __asm__ (__ASMNAME (#alias))
#  define __REDIRECT_NTHNL(name, proto, alias) \
     name proto __THROWNL __asm__ (__ASMNAME (#alias))
# else
#  define __REDIRECT_NTH(name, proto, alias) \
     name proto __asm__ (__ASMNAME (#alias)) __THROW
#  define __REDIRECT_NTHNL(name, proto, alias) \
     name proto __asm__ (__ASMNAME (#alias)) __THROWNL
# endif
# define __ASMNAME(cname)  __ASMNAME2 (__USER_LABEL_PREFIX__, cname)
# define __ASMNAME2(prefix, cname) __STRING (prefix) cname
/*
#elif __SOME_OTHER_COMPILER__
# define __REDIRECT(name, proto, alias) name proto; \
        _Pragma("let " #name " = " #alias)
*/
#endif
/* GCC has various useful declarations that can be made with the
   `__attribute__' syntax.  All of the ways we use this do fine if
   they are omitted for compilers that don't understand it. */
#if !defined __GNUC__ || __GNUC__ < 2
# define __attribute__(xyz)        /* Ignore */
#endif
/* At some point during the gcc 2.96 development the `malloc' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */
#if __GNUC_PREREQ (2,96)
# define __attribute_malloc__ __attribute__ ((__malloc__))
#else
# define __attribute_malloc__ /* Ignore */
#endif
/* Tell the compiler which arguments to an allocation function
   indicate the size of the allocation.  */
#if __GNUC_PREREQ (4, 3)
# define __attribute_alloc_size__(params) \
  __attribute__ ((__alloc_size__ params))
#else
# define __attribute_alloc_size__(params) /* Ignore.  */
#endif
/* At some point during the gcc 2.96 development the `pure' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */
#if __GNUC_PREREQ (2,96)
# define __attribute_pure__ __attribute__ ((__pure__))
#else
# define __attribute_pure__ /* Ignore */
#endif
/* This declaration tells the compiler that the value is constant.  */
#if __GNUC_PREREQ (2,5)
# define __attribute_const__ __attribute__ ((__const__))
#else
# define __attribute_const__ /* Ignore */
#endif
/* At some point during the gcc 3.1 development the `used' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */
#if __GNUC_PREREQ (3,1)
# define __attribute_used__ __attribute__ ((__used__))
# define __attribute_noinline__ __attribute__ ((__noinline__))
#else
# define __attribute_used__ __attribute__ ((__unused__))
# define __attribute_noinline__ /* Ignore */
#endif
/* Since version 3.2, gcc allows marking deprecated functions.  */
#if __GNUC_PREREQ (3,2)
# define __attribute_deprecated__ __attribute__ ((__deprecated__))
#else
# define __attribute_deprecated__ /* Ignore */
#endif
/* Since version 4.5, gcc also allows one to specify the message printed
   when a deprecated function is used.  clang claims to be gcc 4.2, but
   may also support this feature.  */
#if __GNUC_PREREQ (4,5) \
    || __glibc_clang_has_extension (__attribute_deprecated_with_message__)
# define __attribute_deprecated_msg__(msg) \
         __attribute__ ((__deprecated__ (msg)))
#else
# define __attribute_deprecated_msg__(msg) __attribute_deprecated__
#endif
/* At some point during the gcc 2.8 development the `format_arg' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.
   If several `format_arg' attributes are given for the same function, in
   gcc-3.0 and older, all but the last one are ignored.  In newer gccs,
   all designated arguments are considered.  */
#if __GNUC_PREREQ (2,8)
# define __attribute_format_arg__(x) __attribute__ ((__format_arg__ (x)))
#else
# define __attribute_format_arg__(x) /* Ignore */
#endif
/* At some point during the gcc 2.97 development the `strfmon' format
   attribute for functions was introduced.  We don't want to use it
   unconditionally (although this would be possible) since it
   generates warnings.  */
#if __GNUC_PREREQ (2,97)
# define __attribute_format_strfmon__(a,b) \
  __attribute__ ((__format__ (__strfmon__, a, b)))
#else
# define __attribute_format_strfmon__(a,b) /* Ignore */
#endif
/* The nonull function attribute allows to mark pointer parameters which
   must not be NULL.  */
#if __GNUC_PREREQ (3,3)
# define __nonnull(params) __attribute__ ((__nonnull__ params))
#else
# define __nonnull(params)
#endif
/* If fortification mode, we warn about unused results of certain
   function calls which can lead to problems.  */
#if __GNUC_PREREQ (3,4)
# define __attribute_warn_unused_result__ \
   __attribute__ ((__warn_unused_result__))
# if __USE_FORTIFY_LEVEL > 0
#  define __wur __attribute_warn_unused_result__
# endif
#else
# define __attribute_warn_unused_result__ /* empty */
#endif
#ifndef __wur
# define __wur /* Ignore */
#endif
/* Forces a function to be always inlined.  */
#if __GNUC_PREREQ (3,2)
/* The Linux kernel defines __always_inline in stddef.h (283d7573), and
   it conflicts with this definition.  Therefore undefine it first to
   allow either header to be included first.  */
# undef __always_inline
# define __always_inline __inline __attribute__ ((__always_inline__))
#else
# undef __always_inline
# define __always_inline __inline
#endif
/* Associate error messages with the source location of the call site rather
   than with the source location inside the function.  */
#if __GNUC_PREREQ (4,3)
# define __attribute_artificial__ __attribute__ ((__artificial__))
#else
# define __attribute_artificial__ /* Ignore */
#endif
/* GCC 4.3 and above with -std=c99 or -std=gnu99 implements ISO C99
   inline semantics, unless -fgnu89-inline is used.  Using __GNUC_STDC_INLINE__
   or __GNUC_GNU_INLINE is not a good enough check for gcc because gcc versions
   older than 4.3 may define these macros and still not guarantee GNU inlining
   semantics.
   clang++ identifies itself as gcc-4.2, but has support for GNU inlining
   semantics, that can be checked for by using the __GNUC_STDC_INLINE_ and
   __GNUC_GNU_INLINE__ macro definitions.  */
#if (!defined __cplusplus || __GNUC_PREREQ (4,3) \
     || (defined __clang__ && (defined __GNUC_STDC_INLINE__ \
                               || defined __GNUC_GNU_INLINE__)))
# if defined __GNUC_STDC_INLINE__ || defined __cplusplus
#  define __extern_inline extern __inline __attribute__ ((__gnu_inline__))
#  define __extern_always_inline \
  extern __always_inline __attribute__ ((__gnu_inline__))
# else
#  define __extern_inline extern __inline
#  define __extern_always_inline extern __always_inline
# endif
#endif
#ifdef __extern_always_inline
# define __fortify_function __extern_always_inline __attribute_artificial__
#endif
/* GCC 4.3 and above allow passing all anonymous arguments of an
   __extern_always_inline function to some other vararg function.  */
#if __GNUC_PREREQ (4,3)
# define __va_arg_pack() __builtin_va_arg_pack ()
# define __va_arg_pack_len() __builtin_va_arg_pack_len ()
#endif
/* It is possible to compile containing GCC extensions even if GCC is
   run in pedantic mode if the uses are carefully marked using the
   `__extension__' keyword.  But this is not generally available before
   version 2.8.  */
#if !__GNUC_PREREQ (2,8)
# define __extension__                /* Ignore */
#endif
/* __restrict is known in EGCS 1.2 and above. */
#if !__GNUC_PREREQ (2,92)
# if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
#  define __restrict        restrict
# else
#  define __restrict        /* Ignore */
# endif
#endif
/* ISO C99 also allows to declare arrays as non-overlapping.  The syntax is
     array_name[restrict]
   GCC 3.1 supports this.  */
#if __GNUC_PREREQ (3,1) && !defined __GNUG__
# define __restrict_arr        __restrict
#else
# ifdef __GNUC__
#  define __restrict_arr        /* Not supported in old GCC.  */
# else
#  if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
#   define __restrict_arr        restrict
#  else
/* Some other non-C99 compiler.  */
#   define __restrict_arr        /* Not supported.  */
#  endif
# endif
#endif
#if __GNUC__ >= 3
# define __glibc_unlikely(cond)        __builtin_expect ((cond), 0)
# define __glibc_likely(cond)        __builtin_expect ((cond), 1)
#else
# define __glibc_unlikely(cond)        (cond)
# define __glibc_likely(cond)        (cond)
#endif
#ifdef __has_attribute
# define __glibc_has_attribute(attr)        __has_attribute (attr)
#else
# define __glibc_has_attribute(attr)        0
#endif
#if (!defined _Noreturn \
     && (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) < 201112 \
     &&  !__GNUC_PREREQ (4,7))
# if __GNUC_PREREQ (2,8)
#  define _Noreturn __attribute__ ((__noreturn__))
# else
#  define _Noreturn
# endif
#endif
#if __GNUC_PREREQ (8, 0)
/* Describes a char array whose address can safely be passed as the first
   argument to strncpy and strncat, as the char array is not necessarily
   a NUL-terminated string.  */
# define __attribute_nonstring__ __attribute__ ((__nonstring__))
#else
# define __attribute_nonstring__
#endif
/* Undefine (also defined in libc-symbols.h).  */
#undef __attribute_copy__
#if __GNUC_PREREQ (9, 0)
/* Copies attributes from the declaration or type referenced by
   the argument.  */
# define __attribute_copy__(arg) __attribute__ ((__copy__ (arg)))
#else
# define __attribute_copy__(arg)
#endif
#if (!defined _Static_assert && !defined __cplusplus \
     && (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) < 201112 \
     && (!__GNUC_PREREQ (4, 6) || defined __STRICT_ANSI__))
# define _Static_assert(expr, diagnostic) \
    extern int (*__Static_assert_function (void)) \
      [!!sizeof (struct { int __error_if_negative: (expr) ? 2 : -1; })]
#endif
#if defined __x86_64__ && !defined __ILP32__
# define __WORDSIZE        64
#else
# define __WORDSIZE        32
#define __WORDSIZE32_SIZE_ULONG                0
#define __WORDSIZE32_PTRDIFF_LONG        0
#endif
#ifdef __x86_64__
# define __WORDSIZE_TIME64_COMPAT32        1
/* Both x86-64 and x32 use the 64-bit system call interface.  */
# define __SYSCALL_WORDSIZE                64
#else
# define __WORDSIZE_TIME64_COMPAT32        0
#endif
/* This header is included by <sys/cdefs.h>.
   If long double is ABI-compatible with double, it should define
   __NO_LONG_DOUBLE_MATH to 1; otherwise, it should leave
   __NO_LONG_DOUBLE_MATH undefined.
   If this build of the GNU C Library supports both long double
   ABI-compatible with double and some other long double format not
   ABI-compatible with double, it should define
   __LONG_DOUBLE_MATH_OPTIONAL to 1; otherwise, it should leave
   __LONG_DOUBLE_MATH_OPTIONAL undefined.
   If __NO_LONG_DOUBLE_MATH is already defined, this header must not
   define anything; this is needed to work with the definition of
   __NO_LONG_DOUBLE_MATH in nldbl-compat.h.  */
/* In the default version of this header, long double is
   ABI-compatible with double.  */
#ifndef __NO_LONG_DOUBLE_MATH
# define __NO_LONG_DOUBLE_MATH        1
#endif
#if defined __LONG_DOUBLE_MATH_OPTIONAL && defined __NO_LONG_DOUBLE_MATH
# define __LDBL_COMPAT 1
# ifdef __REDIRECT
#  define __LDBL_REDIR1(name, proto, alias) __REDIRECT (name, proto, alias)
#  define __LDBL_REDIR(name, proto) \
  __LDBL_REDIR1 (name, proto, __nldbl_##name)
#  define __LDBL_REDIR1_NTH(name, proto, alias) __REDIRECT_NTH (name, proto, alias)
#  define __LDBL_REDIR_NTH(name, proto) \
  __LDBL_REDIR1_NTH (name, proto, __nldbl_##name)
#  define __LDBL_REDIR1_DECL(name, alias) \
  extern __typeof (name) name __asm (__ASMNAME (#alias));
#  define __LDBL_REDIR_DECL(name) \
  extern __typeof (name) name __asm (__ASMNAME ("__nldbl_" #name));
#  define __REDIRECT_LDBL(name, proto, alias) \
  __LDBL_REDIR1 (name, proto, __nldbl_##alias)
#  define __REDIRECT_NTH_LDBL(name, proto, alias) \
  __LDBL_REDIR1_NTH (name, proto, __nldbl_##alias)
# endif
#endif
#if !defined __LDBL_COMPAT || !defined __REDIRECT
# define __LDBL_REDIR1(name, proto, alias) name proto
# define __LDBL_REDIR(name, proto) name proto
# define __LDBL_REDIR1_NTH(name, proto, alias) name proto __THROW
# define __LDBL_REDIR_NTH(name, proto) name proto __THROW
# define __LDBL_REDIR_DECL(name)
# ifdef __REDIRECT
#  define __REDIRECT_LDBL(name, proto, alias) __REDIRECT (name, proto, alias)
#  define __REDIRECT_NTH_LDBL(name, proto, alias) \
  __REDIRECT_NTH (name, proto, alias)
# endif
#endif
/* __glibc_macro_warning (MESSAGE) issues warning MESSAGE.  This is
   intended for use in preprocessor macros.
   Note: MESSAGE must be a _single_ string; concatenation of string
   literals is not supported.  */
#if __GNUC_PREREQ (4,8) || __glibc_clang_prereq (3,5)
# define __glibc_macro_warning1(message) _Pragma (#message)
# define __glibc_macro_warning(message) \
  __glibc_macro_warning1 (GCC warning message)
#else
# define __glibc_macro_warning(msg)
#endif
/* Generic selection (ISO C11) is a C-only feature, available in GCC
   since version 4.9.  Previous versions do not provide generic
   selection, even though they might set __STDC_VERSION__ to 201112L,
   when in -std=c11 mode.  Thus, we must check for !defined __GNUC__
   when testing __STDC_VERSION__ for generic selection support.
   On the other hand, Clang also defines __GNUC__, so a clang-specific
   check is required to enable the use of generic selection.  */
#if !defined __cplusplus \
    && (__GNUC_PREREQ (4, 9) \
        || __glibc_clang_has_extension (c_generic_selections) \
        || (!defined __GNUC__ && defined __STDC_VERSION__ \
            && __STDC_VERSION__ >= 201112L))
# define __HAVE_GENERIC_SELECTION 1
#else
# define __HAVE_GENERIC_SELECTION 0
#endif
#endif         /* sys/cdefs.h */
# endif
/* If we don't have __REDIRECT, prototypes will be missing if
   __USE_FILE_OFFSET64 but not __USE_LARGEFILE[64]. */
# if defined __USE_FILE_OFFSET64 && !defined __REDIRECT
#  define __USE_LARGEFILE	1
#  define __USE_LARGEFILE64	1
# endif
#endif	/* !ASSEMBLER */
/* Decide whether we can define 'extern inline' functions in headers.  */
#if __GNUC_PREREQ (2, 7) && defined __OPTIMIZE__ \
    && !defined __OPTIMIZE_SIZE__ && !defined __NO_INLINE__ \
    && defined __extern_inline
# define __USE_EXTERN_INLINES	1
#endif
/* This is here only because every header file already includes this one.
   Get the definitions of all the appropriate `__stub_FUNCTION' symbols.
   <gnu/stubs.h> contains `#define __stub_FUNCTION' when FUNCTION is a stub
   that will always return failure (and set errno to ENOSYS).  */
#if !defined __x86_64__
/* This file is automatically generated.
   It defines a symbol `__stub_FUNCTION' for each function
   in the C library which is a stub, meaning it will fail
   every time called, usually setting errno to ENOSYS.  */

#ifdef _LIBC
 #error Applications may not define the macro _LIBC
#endif

#define __stub___kernel_rem_pio2l
#define __stub_chflags
#define __stub_fattach
#define __stub_fchflags
#define __stub_fdetach
#define __stub_futimens
#define __stub_gtty
#define __stub_lchmod
#define __stub_lutimes
#define __stub_revoke
#define __stub_setlogin
#define __stub_sigreturn
#define __stub_sstk
#define __stub_stty
#define __stub_sync_file_range
#define __stub_utimensat
#endif
#if defined __x86_64__ && defined __LP64__
#ifdef _LIBC
 #error Applications may not define the macro _LIBC
#endif
#define __stub___compat_bdflush
#define __stub_chflags
#define __stub_fattach
#define __stub_fchflags
#define __stub_fdetach
#define __stub_getmsg
#define __stub_gtty
#define __stub_lchmod
#define __stub_putmsg
#define __stub_revoke
#define __stub_setlogin
#define __stub_sigreturn
#define __stub_sstk
#define __stub_stty
#endif
#if defined __x86_64__ && defined __ILP32__
#ifdef _LIBC
 #error Applications may not define the macro _LIBC
#endif

#define __stub___compat_bdflush
#define __stub___compat_create_module
#define __stub___compat_get_kernel_syms
#define __stub___compat_nfsservctl
#define __stub___compat_query_module
#define __stub___compat_uselib
#define __stub_chflags
#define __stub_fchflags
#define __stub_gtty
#define __stub_lchmod
#define __stub_revoke
#define __stub_setlogin
#define __stub_sigreturn
#define __stub_sstk
#define __stub_stty
#endif
#endif	/* features.h  */

/* ISO/IEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__
   macro.  */
#undef __GLIBC_USE_LIB_EXT2
#if (defined __USE_GNU                                                        \
     || (defined __STDC_WANT_LIB_EXT2__ && __STDC_WANT_LIB_EXT2__ > 0))
# define __GLIBC_USE_LIB_EXT2 1
#else
# define __GLIBC_USE_LIB_EXT2 0
#endif
/* ISO/IEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__
   macro.  */
#undef __GLIBC_USE_IEC_60559_BFP_EXT
#if defined __USE_GNU || defined __STDC_WANT_IEC_60559_BFP_EXT__
# define __GLIBC_USE_IEC_60559_BFP_EXT 1
#else
# define __GLIBC_USE_IEC_60559_BFP_EXT 0
#endif
/* ISO/IEC TS 18661-4:2015 defines the
   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro.  */
#undef __GLIBC_USE_IEC_60559_FUNCS_EXT
#if defined __USE_GNU || defined __STDC_WANT_IEC_60559_FUNCS_EXT__
# define __GLIBC_USE_IEC_60559_FUNCS_EXT 1
#else
# define __GLIBC_USE_IEC_60559_FUNCS_EXT 0
#endif
/* ISO/IEC TS 18661-3:2015 defines the
   __STDC_WANT_IEC_60559_TYPES_EXT__ macro.  */
#undef __GLIBC_USE_IEC_60559_TYPES_EXT
#if defined __USE_GNU || defined __STDC_WANT_IEC_60559_TYPES_EXT__
# define __GLIBC_USE_IEC_60559_TYPES_EXT 1
#else
# define __GLIBC_USE_IEC_60559_TYPES_EXT 0
#endif

__BEGIN_DECLS
#define __need_size_t
#define __need_NULL

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */
#if (!defined(_STDDEF_H) && !defined(_STDDEF_H_) && !defined(_ANSI_STDDEF_H) \
     && !defined(__STDDEF_H__)) \
    || defined(__need_wchar_t) || defined(__need_size_t) \
    || defined(__need_ptrdiff_t) || defined(__need_NULL) \
    || defined(__need_wint_t)

/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
#if (!defined(__need_wchar_t) && !defined(__need_size_t)	\
     && !defined(__need_ptrdiff_t) && !defined(__need_NULL)	\
     && !defined(__need_wint_t))
#define _STDDEF_H
#define _STDDEF_H_
/* snaroff@next.com says the NeXT needs this.  */
#define _ANSI_STDDEF_H
#endif

#ifndef __sys_stdtypes_h
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

#if defined(__NetBSD__)
#include <machine/ansi.h>
#endif

#if defined (__FreeBSD__)
#include <sys/_types.h>
#endif

#if defined(__NetBSD__)
#if !defined(_SIZE_T_) && !defined(_BSD_SIZE_T_)
#define _SIZE_T
#endif
#if !defined(_PTRDIFF_T_) && !defined(_BSD_PTRDIFF_T_)
#define _PTRDIFF_T
#endif
/* On BSD/386 1.1, at least, machine/ansi.h defines _BSD_WCHAR_T_
   instead of _WCHAR_T_. */
#if !defined(_WCHAR_T_) && !defined(_BSD_WCHAR_T_)
#ifndef _BSD_WCHAR_T_
#define _WCHAR_T
#endif
#endif
/* Undef _FOO_T_ if we are supposed to define foo_t.  */
#if defined (__need_ptrdiff_t) || defined (_STDDEF_H_)
#undef _PTRDIFF_T_
#undef _BSD_PTRDIFF_T_
#endif
#if defined (__need_size_t) || defined (_STDDEF_H_)
#undef _SIZE_T_
#undef _BSD_SIZE_T_
#endif
#if defined (__need_wchar_t) || defined (_STDDEF_H_)
#undef _WCHAR_T_
#undef _BSD_WCHAR_T_
#endif
#endif /* defined(__NetBSD__) */

/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */
#if defined (__sequent__) && defined (_PTRDIFF_T_)
#undef _PTRDIFF_T_
#endif

/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
#if defined (_TYPE_ptrdiff_t) && (defined (__need_ptrdiff_t) || defined (_STDDEF_H_))
_TYPE_ptrdiff_t;
#undef _TYPE_ptrdiff_t
#endif
#if defined (_TYPE_size_t) && (defined (__need_size_t) || defined (_STDDEF_H_))
_TYPE_size_t;
#undef _TYPE_size_t
#endif
#if defined (_TYPE_wchar_t) && (defined (__need_wchar_t) || defined (_STDDEF_H_))
_TYPE_wchar_t;
#undef _TYPE_wchar_t
#endif

/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
#if defined (_STDDEF_H) || defined (__need_ptrdiff_t)
#ifndef _PTRDIFF_T	/* in case <sys/types.h> has defined it. */
#ifndef _T_PTRDIFF_
#ifndef _T_PTRDIFF
#ifndef __PTRDIFF_T
#ifndef _PTRDIFF_T_
#ifndef _BSD_PTRDIFF_T_
#ifndef ___int_ptrdiff_t_h
#ifndef _GCC_PTRDIFF_T
#ifndef _PTRDIFF_T_DECLARED /* DragonFly */
#define _PTRDIFF_T
#define _T_PTRDIFF_
#define _T_PTRDIFF
#define __PTRDIFF_T
#define _PTRDIFF_T_
#define _BSD_PTRDIFF_T_
#define ___int_ptrdiff_t_h
#define _GCC_PTRDIFF_T
#define _PTRDIFF_T_DECLARED
#ifndef __PTRDIFF_TYPE__
#define __PTRDIFF_TYPE__ long int
#endif
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#endif /* _PTRDIFF_T_DECLARED */
#endif /* _GCC_PTRDIFF_T */
#endif /* ___int_ptrdiff_t_h */
#endif /* _BSD_PTRDIFF_T_ */
#endif /* _PTRDIFF_T_ */
#endif /* __PTRDIFF_T */
#endif /* _T_PTRDIFF */
#endif /* _T_PTRDIFF_ */
#endif /* _PTRDIFF_T */

/* If this symbol has done its job, get rid of it.  */
#undef	__need_ptrdiff_t

#endif /* _STDDEF_H or __need_ptrdiff_t.  */

/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
#if defined (_STDDEF_H) || defined (__need_size_t)
#ifndef __size_t__	/* BeOS */
#ifndef __SIZE_T__	/* Cray Unicos/Mk */
#ifndef _SIZE_T	/* in case <sys/types.h> has defined it. */
#ifndef _SYS_SIZE_T_H
#ifndef _T_SIZE_
#ifndef _T_SIZE
#ifndef __SIZE_T
#ifndef _SIZE_T_
#ifndef _BSD_SIZE_T_
#ifndef _SIZE_T_DEFINED_
#ifndef _SIZE_T_DEFINED
#ifndef _BSD_SIZE_T_DEFINED_	/* Darwin */
#ifndef _SIZE_T_DECLARED	/* FreeBSD 5 */
#ifndef ___int_size_t_h
#ifndef _GCC_SIZE_T
#ifndef _SIZET_
#ifndef __size_t
#define __size_t__	/* BeOS */
#define __SIZE_T__	/* Cray Unicos/Mk */
#define _SIZE_T
#define _SYS_SIZE_T_H
#define _T_SIZE_
#define _T_SIZE
#define __SIZE_T
#define _SIZE_T_
#define _BSD_SIZE_T_
#define _SIZE_T_DEFINED_
#define _SIZE_T_DEFINED
#define _BSD_SIZE_T_DEFINED_	/* Darwin */
#define _SIZE_T_DECLARED	/* FreeBSD 5 */
#define ___int_size_t_h
#define _GCC_SIZE_T
#define _SIZET_
#if defined (__FreeBSD__) \
  || defined(__DragonFly__) \
  || defined(__FreeBSD_kernel__) \
  || defined(__VMS__)
/* __size_t is a typedef, must not trash it.  */
#else
#define __size_t
#endif
#ifndef __SIZE_TYPE__
#define __SIZE_TYPE__ long unsigned int
#endif
#if !(defined (__GNUG__) && defined (size_t))
typedef __SIZE_TYPE__ size_t;
#ifdef __BEOS__
typedef long ssize_t;
#endif /* __BEOS__ */
#endif /* !(defined (__GNUG__) && defined (size_t)) */
#endif /* __size_t */
#endif /* _SIZET_ */
#endif /* _GCC_SIZE_T */
#endif /* ___int_size_t_h */
#endif /* _SIZE_T_DECLARED */
#endif /* _BSD_SIZE_T_DEFINED_ */
#endif /* _SIZE_T_DEFINED */
#endif /* _SIZE_T_DEFINED_ */
#endif /* _BSD_SIZE_T_ */
#endif /* _SIZE_T_ */
#endif /* __SIZE_T */
#endif /* _T_SIZE */
#endif /* _T_SIZE_ */
#endif /* _SYS_SIZE_T_H */
#endif /* _SIZE_T */
#endif /* __SIZE_T__ */
#endif /* __size_t__ */
#undef	__need_size_t
#endif /* _STDDEF_H or __need_size_t.  */


/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
#if defined (_STDDEF_H) || defined (__need_wchar_t)
#ifndef __wchar_t__	/* BeOS */
#ifndef __WCHAR_T__	/* Cray Unicos/Mk */
#ifndef _WCHAR_T
#ifndef _T_WCHAR_
#ifndef _T_WCHAR
#ifndef __WCHAR_T
#ifndef _WCHAR_T_
#ifndef _BSD_WCHAR_T_
#ifndef _BSD_WCHAR_T_DEFINED_    /* Darwin */
#ifndef _BSD_RUNE_T_DEFINED_	/* Darwin */
#ifndef _WCHAR_T_DECLARED /* FreeBSD 5 */
#ifndef _WCHAR_T_DEFINED_
#ifndef _WCHAR_T_DEFINED
#ifndef _WCHAR_T_H
#ifndef ___int_wchar_t_h
#ifndef __INT_WCHAR_T_H
#ifndef _GCC_WCHAR_T
#define __wchar_t__	/* BeOS */
#define __WCHAR_T__	/* Cray Unicos/Mk */
#define _WCHAR_T
#define _T_WCHAR_
#define _T_WCHAR
#define __WCHAR_T
#define _WCHAR_T_
#define _BSD_WCHAR_T_
#define _WCHAR_T_DEFINED_
#define _WCHAR_T_DEFINED
#define _WCHAR_T_H
#define ___int_wchar_t_h
#define __INT_WCHAR_T_H
#define _GCC_WCHAR_T
#define _WCHAR_T_DECLARED

/* On BSD/386 1.1, at least, machine/ansi.h defines _BSD_WCHAR_T_
   instead of _WCHAR_T_, and _BSD_RUNE_T_ (which, unlike the other
   symbols in the _FOO_T_ family, stays defined even after its
   corresponding type is defined).  If we define wchar_t, then we
   must undef _WCHAR_T_; for BSD/386 1.1 (and perhaps others), if
   we undef _WCHAR_T_, then we must also define rune_t, since 
   headers like runetype.h assume that if machine/ansi.h is included,
   and _BSD_WCHAR_T_ is not defined, then rune_t is available.
   machine/ansi.h says, "Note that _WCHAR_T_ and _RUNE_T_ must be of
   the same type." */
#ifdef _BSD_WCHAR_T_
#undef _BSD_WCHAR_T_
#ifdef _BSD_RUNE_T_
#if !defined (_ANSI_SOURCE) && !defined (_POSIX_SOURCE)
typedef _BSD_RUNE_T_ rune_t;
#define _BSD_WCHAR_T_DEFINED_
#define _BSD_RUNE_T_DEFINED_	/* Darwin */
#if defined (__FreeBSD__) && (__FreeBSD__ < 5)
/* Why is this file so hard to maintain properly?  In contrast to
   the comment above regarding BSD/386 1.1, on FreeBSD for as long
   as the symbol has existed, _BSD_RUNE_T_ must not stay defined or
   redundant typedefs will occur when stdlib.h is included after this file. */
#undef _BSD_RUNE_T_
#endif
#endif
#endif
#endif
/* FreeBSD 5 can't be handled well using "traditional" logic above
   since it no longer defines _BSD_RUNE_T_ yet still desires to export
   rune_t in some cases... */
#if defined (__FreeBSD__) && (__FreeBSD__ >= 5)
#if !defined (_ANSI_SOURCE) && !defined (_POSIX_SOURCE)
#if __BSD_VISIBLE
#ifndef _RUNE_T_DECLARED
typedef __rune_t        rune_t;
#define _RUNE_T_DECLARED
#endif
#endif
#endif
#endif

#ifndef __WCHAR_TYPE__
#define __WCHAR_TYPE__ int
#endif
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif /* _WCHAR_T_DECLARED */
#endif /* _BSD_RUNE_T_DEFINED_ */
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif /* __WCHAR_T__ */
#endif /* __wchar_t__ */
#undef	__need_wchar_t
#endif /* _STDDEF_H or __need_wchar_t.  */

#if defined (__need_wint_t)
#ifndef _WINT_T
#define _WINT_T

#ifndef __WINT_TYPE__
#define __WINT_TYPE__ unsigned int
#endif
typedef __WINT_TYPE__ wint_t;
#endif
#undef __need_wint_t
#endif

#if defined(__NetBSD__)
/*  The references to _GCC_PTRDIFF_T_, _GCC_SIZE_T_, and _GCC_WCHAR_T_
    are probably typos and should be removed before 2.8 is released.  */
#ifdef _GCC_PTRDIFF_T_
#undef _PTRDIFF_T_
#undef _BSD_PTRDIFF_T_
#endif
#ifdef _GCC_SIZE_T_
#undef _SIZE_T_
#undef _BSD_SIZE_T_
#endif
#ifdef _GCC_WCHAR_T_
#undef _WCHAR_T_
#undef _BSD_WCHAR_T_
#endif
/*  The following ones are the real ones.  */
#ifdef _GCC_PTRDIFF_T
#undef _PTRDIFF_T_
#undef _BSD_PTRDIFF_T_
#endif
#ifdef _GCC_SIZE_T
#undef _SIZE_T_
#undef _BSD_SIZE_T_
#endif
#ifdef _GCC_WCHAR_T
#undef _WCHAR_T_
#undef _BSD_WCHAR_T_
#endif
#endif /* __NetBSD__ */

#endif /* __sys_stdtypes_h */

/* A null pointer constant.  */

#if defined (_STDDEF_H) || defined (__need_NULL)
#undef NULL		/* in case <stdio.h> has defined it. */
#ifdef __GNUG__
#define NULL __null
#else   /* G++ */
#ifndef __cplusplus
#define NULL ((void *)0)
#else   /* C++ */
#define NULL 0
#endif  /* C++ */
#endif  /* G++ */
#endif	/* NULL not defined and <stddef.h> or need NULL.  */
#undef	__need_NULL

#ifdef _STDDEF_H

/* Offset of member MEMBER in a struct of type TYPE. */
#define offsetof(TYPE, MEMBER) __builtin_offsetof (TYPE, MEMBER)

#if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112L) \
  || (defined(__cplusplus) && __cplusplus >= 201103L)
#ifndef _GCC_MAX_ALIGN_T
#define _GCC_MAX_ALIGN_T
/* Type whose alignment is supported in every context and is at least
   as great as that of any standard type not using alignment
   specifiers.  */
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
  /* _Float128 is defined as a basic type, so max_align_t must be
     sufficiently aligned for it.  This code must work in C++, so we
     use __float128 here; that is only available on some
     architectures, but only on i386 is extra alignment needed for
     __float128.  */
#ifdef __i386__
  __float128 __max_align_f128 __attribute__((__aligned__(__alignof(__float128))));
#endif
} max_align_t;
#endif
#endif /* C11 or C++11.  */

#if defined(__cplusplus) && __cplusplus >= 201103L
#ifndef _GXX_NULLPTR_T
#define _GXX_NULLPTR_T
  typedef decltype(nullptr) nullptr_t;
#endif
#endif /* C++11.  */

#endif /* _STDDEF_H was defined this time */

#endif /* !_STDDEF_H && !_STDDEF_H_ && !_ANSI_STDDEF_H && !__STDDEF_H__
	  || __need_XXX was not defined before */

#define __need___va_list

#ifndef _STDARG_H
#ifndef _ANSI_STDARG_H_
#ifndef __need___va_list
#define _STDARG_H
#define _ANSI_STDARG_H_
#endif /* not __need___va_list */
#undef __need___va_list

/* Define __gnuc_va_list.  */

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
typedef __builtin_va_list __gnuc_va_list;
#endif

/* Define the standard macros for the user,
   if this invocation was from the user program.  */
#ifdef _STDARG_H

#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)
#define va_arg(v,l)	__builtin_va_arg(v,l)
#if !defined(__STRICT_ANSI__) || __STDC_VERSION__ + 0 >= 199900L \
    || __cplusplus + 0 >= 201103L
#define va_copy(d,s)	__builtin_va_copy(d,s)
#endif
#define __va_copy(d,s)	__builtin_va_copy(d,s)

/* Define va_list, if desired, from __gnuc_va_list. */
/* We deliberately do not define va_list when called from
   stdio.h, because ANSI C says that stdio.h is not supposed to define
   va_list.  stdio.h needs to have access to that data type, 
   but must not use that name.  It should use the name __gnuc_va_list,
   which is safe because it is reserved for the implementation.  */

#ifdef _BSD_VA_LIST
#undef _BSD_VA_LIST
#endif

#if defined(__svr4__) || (defined(_SCO_DS) && !defined(__VA_LIST))
/* SVR4.2 uses _VA_LIST for an internal alias for va_list,
   so we must avoid testing it and setting it here.
   SVR4 uses _VA_LIST as a flag in stdarg.h, but we should
   have no conflict with that.  */
#ifndef _VA_LIST_
#define _VA_LIST_
#ifdef __i860__
#ifndef _VA_LIST
#define _VA_LIST va_list
#endif
#endif /* __i860__ */
typedef __gnuc_va_list va_list;
#ifdef _SCO_DS
#define __VA_LIST
#endif
#endif /* _VA_LIST_ */
#else /* not __svr4__ || _SCO_DS */

/* The macro _VA_LIST_ is the same thing used by this file in Ultrix.
   But on BSD NET2 we must not test or define or undef it.
   (Note that the comments in NET 2's ansi.h
   are incorrect for _VA_LIST_--see stdio.h!)  */
#if !defined (_VA_LIST_) || defined (__BSD_NET2__) || defined (____386BSD____) || defined (__bsdi__) || defined (__sequent__) || defined (__FreeBSD__) || defined(WINNT)
/* The macro _VA_LIST_DEFINED is used in Windows NT 3.5  */
#ifndef _VA_LIST_DEFINED
/* The macro _VA_LIST is used in SCO Unix 3.2.  */
#ifndef _VA_LIST
/* The macro _VA_LIST_T_H is used in the Bull dpx2  */
#ifndef _VA_LIST_T_H
/* The macro __va_list__ is used by BeOS.  */
#ifndef __va_list__
typedef __gnuc_va_list va_list;
#endif /* not __va_list__ */
#endif /* not _VA_LIST_T_H */
#endif /* not _VA_LIST */
#endif /* not _VA_LIST_DEFINED */
#if !(defined (__BSD_NET2__) || defined (____386BSD____) || defined (__bsdi__) || defined (__sequent__) || defined (__FreeBSD__))
#define _VA_LIST_
#endif
#ifndef _VA_LIST
#define _VA_LIST
#endif
#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
#endif
#ifndef _VA_LIST_T_H
#define _VA_LIST_T_H
#endif
#ifndef __va_list__
#define __va_list__
#endif

#endif /* not _VA_LIST_, except on certain systems */

#endif /* not __svr4__ */

#endif /* _STDARG_H */

#endif /* not _ANSI_STDARG_H_ */
#endif /* not _STDARG_H */

#ifndef        _BITS_TYPES_H
#define        _BITS_TYPES_H        1
#ifndef	_FEATURES_H
#define	_FEATURES_H	1
/* These are defined by the user (or the compiler)
   to specify the desired environment:
   __STRICT_ANSI__	ISO Standard C.
   _ISOC99_SOURCE	Extensions to ISO C89 from ISO C99.
   _ISOC11_SOURCE	Extensions to ISO C99 from ISO C11.
   __STDC_WANT_LIB_EXT2__
			Extensions to ISO C99 from TR 27431-2:2010.
   __STDC_WANT_IEC_60559_BFP_EXT__
			Extensions to ISO C11 from TS 18661-1:2014.
   __STDC_WANT_IEC_60559_FUNCS_EXT__
			Extensions to ISO C11 from TS 18661-4:2015.
   __STDC_WANT_IEC_60559_TYPES_EXT__
			Extensions to ISO C11 from TS 18661-3:2015.
   _POSIX_SOURCE	IEEE Std 1003.1.
   _POSIX_C_SOURCE	If ==1, like _POSIX_SOURCE; if >=2 add IEEE Std 1003.2;
			if >=199309L, add IEEE Std 1003.1b-1993;
			if >=199506L, add IEEE Std 1003.1c-1995;
			if >=200112L, all of IEEE 1003.1-2004
			if >=200809L, all of IEEE 1003.1-2008
   _XOPEN_SOURCE	Includes POSIX and XPG things.  Set to 500 if
			Single Unix conformance is wanted, to 600 for the
			sixth revision, to 700 for the seventh revision.
   _XOPEN_SOURCE_EXTENDED XPG things and X/Open Unix extensions.
   _LARGEFILE_SOURCE	Some more functions for correct standard I/O.
   _LARGEFILE64_SOURCE	Additional functionality from LFS for large files.
   _FILE_OFFSET_BITS=N	Select default filesystem interface.
   _ATFILE_SOURCE	Additional *at interfaces.
   _GNU_SOURCE		All of the above, plus GNU extensions.
   _DEFAULT_SOURCE	The default set of features (taking precedence over
			__STRICT_ANSI__).
   _FORTIFY_SOURCE	Add security hardening to many library functions.
			Set to 1 or 2; 2 performs stricter checks than 1.
   _REENTRANT, _THREAD_SAFE
			Obsolete; equivalent to _POSIX_C_SOURCE=199506L.
   The `-ansi' switch to the GNU C compiler, and standards conformance
   options such as `-std=c99', define __STRICT_ANSI__.  If none of
   these are defined, or if _DEFAULT_SOURCE is defined, the default is
   to have _POSIX_SOURCE set to one and _POSIX_C_SOURCE set to
   200809L, as well as enabling miscellaneous functions from BSD and
   SVID.  If more than one of these are defined, they accumulate.  For
   example __STRICT_ANSI__, _POSIX_SOURCE and _POSIX_C_SOURCE together
   give you ISO C, 1003.1, and 1003.2, but nothing else.
   These are defined by this file and are used by the
   header files to decide what to declare or define:
   __GLIBC_USE (F)	Define things from feature set F.  This is defined
			to 1 or 0; the subsequent macros are either defined
			or undefined, and those tests should be moved to
			__GLIBC_USE.
   __USE_ISOC11		Define ISO C11 things.
   __USE_ISOC99		Define ISO C99 things.
   __USE_ISOC95		Define ISO C90 AMD1 (C95) things.
   __USE_ISOCXX11	Define ISO C++11 things.
   __USE_POSIX		Define IEEE Std 1003.1 things.
   __USE_POSIX2		Define IEEE Std 1003.2 things.
   __USE_POSIX199309	Define IEEE Std 1003.1, and .1b things.
   __USE_POSIX199506	Define IEEE Std 1003.1, .1b, .1c and .1i things.
   __USE_XOPEN		Define XPG things.
   __USE_XOPEN_EXTENDED	Define X/Open Unix things.
   __USE_UNIX98		Define Single Unix V2 things.
   __USE_XOPEN2K        Define XPG6 things.
   __USE_XOPEN2KXSI     Define XPG6 XSI things.
   __USE_XOPEN2K8       Define XPG7 things.
   __USE_XOPEN2K8XSI    Define XPG7 XSI things.
   __USE_LARGEFILE	Define correct standard I/O things.
   __USE_LARGEFILE64	Define LFS things with separate names.
   __USE_FILE_OFFSET64	Define 64bit interface as default.
   __USE_MISC		Define things from 4.3BSD or System V Unix.
   __USE_ATFILE		Define *at interfaces and AT_* constants for them.
   __USE_GNU		Define GNU extensions.
   __USE_FORTIFY_LEVEL	Additional security measures used, according to level.
   The macros `__GNU_LIBRARY__', `__GLIBC__', and `__GLIBC_MINOR__' are
   defined by this file unconditionally.  `__GNU_LIBRARY__' is provided
   only for compatibility.  All new code should use the other symbols
   to test for features.
   All macros listed above as possibly being defined by this file are
   explicitly undefined if they are not explicitly defined.
   Feature-test macros that are not defined by the user or compiler
   but are implied by the other feature-test macros defined (or by the
   lack of any definitions) are defined by the file.
   ISO C feature test macros depend on the definition of the macro
   when an affected header is included, not when the first system
   header is included, and so they are handled in
   <bits/libc-header-start.h>, which does not have a multiple include
   guard.  Feature test macros that can be handled from the first
   system header included are handled here.  */
/* Undefine everything, so we get a clean slate.  */
#undef	__USE_ISOC11
#undef	__USE_ISOC99
#undef	__USE_ISOC95
#undef	__USE_ISOCXX11
#undef	__USE_POSIX
#undef	__USE_POSIX2
#undef	__USE_POSIX199309
#undef	__USE_POSIX199506
#undef	__USE_XOPEN
#undef	__USE_XOPEN_EXTENDED
#undef	__USE_UNIX98
#undef	__USE_XOPEN2K
#undef	__USE_XOPEN2KXSI
#undef	__USE_XOPEN2K8
#undef	__USE_XOPEN2K8XSI
#undef	__USE_LARGEFILE
#undef	__USE_LARGEFILE64
#undef	__USE_FILE_OFFSET64
#undef	__USE_MISC
#undef	__USE_ATFILE
#undef	__USE_GNU
#undef	__USE_FORTIFY_LEVEL
#undef	__KERNEL_STRICT_NAMES
#undef	__GLIBC_USE_DEPRECATED_GETS
/* Suppress kernel-name space pollution unless user expressedly asks
   for it.  */
#ifndef _LOOSE_KERNEL_NAMES
# define __KERNEL_STRICT_NAMES
#endif
/* Convenience macro to test the version of gcc.
   Use like this:
   #if __GNUC_PREREQ (2,8)
   ... code requiring gcc 2.8 or later ...
   #endif
   Note: only works for GCC 2.0 and later, because __GNUC_MINOR__ was
   added in 2.0.  */
#if defined __GNUC__ && defined __GNUC_MINOR__
# define __GNUC_PREREQ(maj, min) \
	((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
#else
# define __GNUC_PREREQ(maj, min) 0
#endif
/* Similarly for clang.  Features added to GCC after version 4.2 may
   or may not also be available in clang, and clang's definitions of
   __GNUC(_MINOR)__ are fixed at 4 and 2 respectively.  Not all such
   features can be queried via __has_extension/__has_feature.  */
#if defined __clang_major__ && defined __clang_minor__
# define __glibc_clang_prereq(maj, min) \
  ((__clang_major__ << 16) + __clang_minor__ >= ((maj) << 16) + (min))
#else
# define __glibc_clang_prereq(maj, min) 0
#endif
/* Whether to use feature set F.  */
#define __GLIBC_USE(F)	__GLIBC_USE_ ## F
/* _BSD_SOURCE and _SVID_SOURCE are deprecated aliases for
   _DEFAULT_SOURCE.  If _DEFAULT_SOURCE is present we do not
   issue a warning; the expectation is that the source is being
   transitioned to use the new macro.  */
#if (defined _BSD_SOURCE || defined _SVID_SOURCE) \
    && !defined _DEFAULT_SOURCE
# warning "_BSD_SOURCE and _SVID_SOURCE are deprecated, use _DEFAULT_SOURCE"
# undef  _DEFAULT_SOURCE
# define _DEFAULT_SOURCE	1
#endif
/* If _GNU_SOURCE was defined by the user, turn on all the other features.  */
#ifdef _GNU_SOURCE
# undef  _ISOC95_SOURCE
# define _ISOC95_SOURCE	1
# undef  _ISOC99_SOURCE
# define _ISOC99_SOURCE	1
# undef  _ISOC11_SOURCE
# define _ISOC11_SOURCE	1
# undef  _POSIX_SOURCE
# define _POSIX_SOURCE	1
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE	200809L
# undef  _XOPEN_SOURCE
# define _XOPEN_SOURCE	700
# undef  _XOPEN_SOURCE_EXTENDED
# define _XOPEN_SOURCE_EXTENDED	1
# undef	 _LARGEFILE64_SOURCE
# define _LARGEFILE64_SOURCE	1
# undef  _DEFAULT_SOURCE
# define _DEFAULT_SOURCE	1
# undef  _ATFILE_SOURCE
# define _ATFILE_SOURCE	1
#endif
/* If nothing (other than _GNU_SOURCE and _DEFAULT_SOURCE) is defined,
   define _DEFAULT_SOURCE.  */
#if (defined _DEFAULT_SOURCE					\
     || (!defined __STRICT_ANSI__				\
	 && !defined _ISOC99_SOURCE && !defined _ISOC11_SOURCE	\
	 && !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE	\
	 && !defined _XOPEN_SOURCE))
# undef  _DEFAULT_SOURCE
# define _DEFAULT_SOURCE	1
#endif
/* This is to enable the ISO C11 extension.  */
#if (defined _ISOC11_SOURCE \
     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 201112L))
# define __USE_ISOC11	1
#endif
/* This is to enable the ISO C99 extension.  */
#if (defined _ISOC99_SOURCE || defined _ISOC11_SOURCE \
     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L))
# define __USE_ISOC99	1
#endif
/* This is to enable the ISO C90 Amendment 1:1995 extension.  */
#if (defined _ISOC99_SOURCE || defined _ISOC11_SOURCE \
     || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199409L))
# define __USE_ISOC95	1
#endif
#ifdef __cplusplus
/* This is to enable compatibility for ISO C++17.  */
# if __cplusplus >= 201703L
#  define __USE_ISOC11	1
# endif
/* This is to enable compatibility for ISO C++11.
   Check the temporary macro for now, too.  */
# if __cplusplus >= 201103L || defined __GXX_EXPERIMENTAL_CXX0X__
#  define __USE_ISOCXX11	1
#  define __USE_ISOC99	1
# endif
#endif
/* If none of the ANSI/POSIX macros are defined, or if _DEFAULT_SOURCE
   is defined, use POSIX.1-2008 (or another version depending on
   _XOPEN_SOURCE).  */
#ifdef _DEFAULT_SOURCE
# if !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE
#  define __USE_POSIX_IMPLICITLY	1
# endif
# undef  _POSIX_SOURCE
# define _POSIX_SOURCE	1
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE	200809L
#endif
#if ((!defined __STRICT_ANSI__					\
      || (defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) >= 500))	\
     && !defined _POSIX_SOURCE && !defined _POSIX_C_SOURCE)
# define _POSIX_SOURCE	1
# if defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 500
#  define _POSIX_C_SOURCE	2
# elif defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 600
#  define _POSIX_C_SOURCE	199506L
# elif defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) < 700
#  define _POSIX_C_SOURCE	200112L
# else
#  define _POSIX_C_SOURCE	200809L
# endif
# define __USE_POSIX_IMPLICITLY	1
#endif
/* Some C libraries once required _REENTRANT and/or _THREAD_SAFE to be
   defined in all multithreaded code.  GNU libc has not required this
   for many years.  We now treat them as compatibility synonyms for
   _POSIX_C_SOURCE=199506L, which is the earliest level of POSIX with
   comprehensive support for multithreaded code.  Using them never
   lowers the selected level of POSIX conformance, only raises it.  */
#if ((!defined _POSIX_C_SOURCE || (_POSIX_C_SOURCE - 0) < 199506L) \
     && (defined _REENTRANT || defined _THREAD_SAFE))
# define _POSIX_SOURCE   1
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE 199506L
#endif
#if (defined _POSIX_SOURCE					\
     || (defined _POSIX_C_SOURCE && _POSIX_C_SOURCE >= 1)	\
     || defined _XOPEN_SOURCE)
# define __USE_POSIX	1
#endif
#if defined _POSIX_C_SOURCE && _POSIX_C_SOURCE >= 2 || defined _XOPEN_SOURCE
# define __USE_POSIX2	1
#endif
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 199309L
# define __USE_POSIX199309	1
#endif
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 199506L
# define __USE_POSIX199506	1
#endif
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 200112L
# define __USE_XOPEN2K		1
# undef __USE_ISOC95
# define __USE_ISOC95		1
# undef __USE_ISOC99
# define __USE_ISOC99		1
#endif
#if defined _POSIX_C_SOURCE && (_POSIX_C_SOURCE - 0) >= 200809L
# define __USE_XOPEN2K8		1
# undef  _ATFILE_SOURCE
# define _ATFILE_SOURCE	1
#endif
#ifdef	_XOPEN_SOURCE
# define __USE_XOPEN	1
# if (_XOPEN_SOURCE - 0) >= 500
#  define __USE_XOPEN_EXTENDED	1
#  define __USE_UNIX98	1
#  undef _LARGEFILE_SOURCE
#  define _LARGEFILE_SOURCE	1
#  if (_XOPEN_SOURCE - 0) >= 600
#   if (_XOPEN_SOURCE - 0) >= 700
#    define __USE_XOPEN2K8	1
#    define __USE_XOPEN2K8XSI	1
#   endif
#   define __USE_XOPEN2K	1
#   define __USE_XOPEN2KXSI	1
#   undef __USE_ISOC95
#   define __USE_ISOC95		1
#   undef __USE_ISOC99
#   define __USE_ISOC99		1
#  endif
# else
#  ifdef _XOPEN_SOURCE_EXTENDED
#   define __USE_XOPEN_EXTENDED	1
#  endif
# endif
#endif
#ifdef _LARGEFILE_SOURCE
# define __USE_LARGEFILE	1
#endif
#ifdef _LARGEFILE64_SOURCE
# define __USE_LARGEFILE64	1
#endif
#if defined _FILE_OFFSET_BITS && _FILE_OFFSET_BITS == 64
# define __USE_FILE_OFFSET64	1
#endif
#if defined _DEFAULT_SOURCE
# define __USE_MISC	1
#endif
#ifdef	_ATFILE_SOURCE
# define __USE_ATFILE	1
#endif
#ifdef	_GNU_SOURCE
# define __USE_GNU	1
#endif
#if defined _FORTIFY_SOURCE && _FORTIFY_SOURCE > 0
# if !defined __OPTIMIZE__ || __OPTIMIZE__ <= 0
#  warning _FORTIFY_SOURCE requires compiling with optimization (-O)
# elif !__GNUC_PREREQ (4, 1)
#  warning _FORTIFY_SOURCE requires GCC 4.1 or later
# elif _FORTIFY_SOURCE > 1
#  define __USE_FORTIFY_LEVEL 2
# else
#  define __USE_FORTIFY_LEVEL 1
# endif
#endif
#ifndef __USE_FORTIFY_LEVEL
# define __USE_FORTIFY_LEVEL 0
#endif
/* The function 'gets' existed in C89, but is impossible to use
   safely.  It has been removed from ISO C11 and ISO C++14.  Note: for
   compatibility with various implementations of <cstdio>, this test
   must consider only the value of __cplusplus when compiling C++.  */
#if defined __cplusplus ? __cplusplus >= 201402L : defined __USE_ISOC11
# define __GLIBC_USE_DEPRECATED_GETS 0
#else
# define __GLIBC_USE_DEPRECATED_GETS 1
#endif
/* Get definitions of __STDC_* predefined macros, if the compiler has
   not preincluded this header automatically.  */
#include <stdc-predef.h>
/* This macro indicates that the installed library is the GNU C Library.
   For historic reasons the value now is 6 and this will stay from now
   on.  The use of this variable is deprecated.  Use __GLIBC__ and
   __GLIBC_MINOR__ now (see below) when you want to test for a specific
   GNU C library version and use the values in <gnu/lib-names.h> to get
   the sonames of the shared libraries.  */
#undef  __GNU_LIBRARY__
#define __GNU_LIBRARY__ 6
/* Major and minor version number of the GNU C library package.  Use
   these macros to test for features in specific releases.  */
#define	__GLIBC__	2
#define	__GLIBC_MINOR__	28
#define __GLIBC_PREREQ(maj, min) \
	((__GLIBC__ << 16) + __GLIBC_MINOR__ >= ((maj) << 16) + (min))
/* This is here only because every header file already includes this one.  */
#ifndef __ASSEMBLER__
# ifndef _SYS_CDEFS_H
#  include <sys/cdefs.h>
# endif
/* If we don't have __REDIRECT, prototypes will be missing if
   __USE_FILE_OFFSET64 but not __USE_LARGEFILE[64]. */
# if defined __USE_FILE_OFFSET64 && !defined __REDIRECT
#  define __USE_LARGEFILE	1
#  define __USE_LARGEFILE64	1
# endif
#endif	/* !ASSEMBLER */
/* Decide whether we can define 'extern inline' functions in headers.  */
#if __GNUC_PREREQ (2, 7) && defined __OPTIMIZE__ \
    && !defined __OPTIMIZE_SIZE__ && !defined __NO_INLINE__ \
    && defined __extern_inline
# define __USE_EXTERN_INLINES	1
#endif
/* This is here only because every header file already includes this one.
   Get the definitions of all the appropriate `__stub_FUNCTION' symbols.
   <gnu/stubs.h> contains `#define __stub_FUNCTION' when FUNCTION is a stub
   that will always return failure (and set errno to ENOSYS).  */
#include <gnu/stubs.h>
#endif	/* features.h  */
/* Determine the wordsize from the preprocessor defines.  */
#if defined __x86_64__ && !defined __ILP32__
# define __WORDSIZE        64
#else
# define __WORDSIZE        32
#define __WORDSIZE32_SIZE_ULONG                0
#define __WORDSIZE32_PTRDIFF_LONG        0
#endif
#ifdef __x86_64__
# define __WORDSIZE_TIME64_COMPAT32        1
/* Both x86-64 and x32 use the 64-bit system call interface.  */
# define __SYSCALL_WORDSIZE                64
#else
# define __WORDSIZE_TIME64_COMPAT32        0
#endif
/* Convenience types.  */
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
/* Fixed-size types, underlying types depend on word size and compiler.  */
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
#if __WORDSIZE == 64
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
#else
__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;
#endif
/* quad_t is also 64 bits.  */
#if __WORDSIZE == 64
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
#else
__extension__ typedef long long int __quad_t;
__extension__ typedef unsigned long long int __u_quad_t;
#endif
/* The machine-dependent file <bits/typesizes.h> defines __*_T_TYPE
   macros for each of the OS types we define below.  The definitions
   of those macros must use the following macros for underlying types.
   We define __S<SIZE>_TYPE and __U<SIZE>_TYPE for the signed and unsigned
   variants of each of the following integer types on this machine.
        16                -- "natural" 16-bit type (always short)
        32                -- "natural" 32-bit type (always int)
        64                -- "natural" 64-bit type (long or long long)
        LONG32                -- 32-bit type, traditionally long
        QUAD                -- 64-bit type, always long long
        WORD                -- natural type of __WORDSIZE bits (int or long)
        LONGWORD        -- type of __WORDSIZE bits, traditionally long
   We distinguish WORD/LONGWORD, 32/LONG32, and 64/QUAD so that the
   conventional uses of `long' or `long long' type modifiers match the
   types we define, even when a less-adorned type would be the same size.
   This matters for (somewhat) portably writing printf/scanf formats for
   these types, where using the appropriate l or ll format modifiers can
   make the typedefs and the formats match up across all GNU platforms.  If
   we used `long' when it's 64 bits where `long long' is expected, then the
   compiler would warn about the formats not matching the argument types,
   and the programmer changing them to shut up the compiler would break the
   program's portability.
   Here we assume what is presently the case in all the GCC configurations
   we support: long long is always 64 bits, long is always word/address size,
   and int is always 32 bits.  */
#define        __S16_TYPE                short int
#define __U16_TYPE                unsigned short int
#define        __S32_TYPE                int
#define __U32_TYPE                unsigned int
#define __SLONGWORD_TYPE        long int
#define __ULONGWORD_TYPE        unsigned long int
#if __WORDSIZE == 32
# define __SQUAD_TYPE                __quad_t
# define __UQUAD_TYPE                __u_quad_t
# define __SWORD_TYPE                int
# define __UWORD_TYPE                unsigned int
# define __SLONG32_TYPE                long int
# define __ULONG32_TYPE                unsigned long int
# define __S64_TYPE                __quad_t
# define __U64_TYPE                __u_quad_t
/* We want __extension__ before typedef's that use nonstandard base types
   such as `long long' in C89 mode.  */
# define __STD_TYPE                __extension__ typedef
#elif __WORDSIZE == 64
# define __SQUAD_TYPE                long int
# define __UQUAD_TYPE                unsigned long int
# define __SWORD_TYPE                long int
# define __UWORD_TYPE                unsigned long int
# define __SLONG32_TYPE                int
# define __ULONG32_TYPE                unsigned int
# define __S64_TYPE                long int
# define __U64_TYPE                unsigned long int
/* No need to mark the typedef with __extension__.   */
# define __STD_TYPE                typedef
#else
# error
#endif
/* bits/typesizes.h -- underlying types for *_t.  Linux/x86-64 version.
   Copyright (C) 2012-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
#ifndef _BITS_TYPES_H
# error "Never include <bits/typesizes.h> directly; use <sys/types.h> instead."
#endif
#ifndef        _BITS_TYPESIZES_H
#define        _BITS_TYPESIZES_H        1
/* See <bits/types.h> for the meaning of these macros.  This file exists so
   that <bits/types.h> need not vary across different GNU platforms.  */
/* X32 kernel interface is 64-bit.  */
#if defined __x86_64__ && defined __ILP32__
# define __SYSCALL_SLONG_TYPE        __SQUAD_TYPE
# define __SYSCALL_ULONG_TYPE        __UQUAD_TYPE
#else
# define __SYSCALL_SLONG_TYPE        __SLONGWORD_TYPE
# define __SYSCALL_ULONG_TYPE        __ULONGWORD_TYPE
#endif
#define __DEV_T_TYPE                __UQUAD_TYPE
#define __UID_T_TYPE                __U32_TYPE
#define __GID_T_TYPE                __U32_TYPE
#define __INO_T_TYPE                __SYSCALL_ULONG_TYPE
#define __INO64_T_TYPE                __UQUAD_TYPE
#define __MODE_T_TYPE                __U32_TYPE
#ifdef __x86_64__
# define __NLINK_T_TYPE                __SYSCALL_ULONG_TYPE
# define __FSWORD_T_TYPE        __SYSCALL_SLONG_TYPE
#else
# define __NLINK_T_TYPE                __UWORD_TYPE
# define __FSWORD_T_TYPE        __SWORD_TYPE
#endif
#define __OFF_T_TYPE                __SYSCALL_SLONG_TYPE
#define __OFF64_T_TYPE                __SQUAD_TYPE
#define __PID_T_TYPE                __S32_TYPE
#define __RLIM_T_TYPE                __SYSCALL_ULONG_TYPE
#define __RLIM64_T_TYPE                __UQUAD_TYPE
#define __BLKCNT_T_TYPE                __SYSCALL_SLONG_TYPE
#define __BLKCNT64_T_TYPE        __SQUAD_TYPE
#define __FSBLKCNT_T_TYPE        __SYSCALL_ULONG_TYPE
#define __FSBLKCNT64_T_TYPE        __UQUAD_TYPE
#define __FSFILCNT_T_TYPE        __SYSCALL_ULONG_TYPE
#define __FSFILCNT64_T_TYPE        __UQUAD_TYPE
#define __ID_T_TYPE                __U32_TYPE
#define __CLOCK_T_TYPE                __SYSCALL_SLONG_TYPE
#define __TIME_T_TYPE                __SYSCALL_SLONG_TYPE
#define __USECONDS_T_TYPE        __U32_TYPE
#define __SUSECONDS_T_TYPE        __SYSCALL_SLONG_TYPE
#define __DADDR_T_TYPE                __S32_TYPE
#define __KEY_T_TYPE                __S32_TYPE
#define __CLOCKID_T_TYPE        __S32_TYPE
#define __TIMER_T_TYPE                void *
#define __BLKSIZE_T_TYPE        __SYSCALL_SLONG_TYPE
#define __FSID_T_TYPE                struct { int __val[2]; }
#define __SSIZE_T_TYPE                __SWORD_TYPE
#define __CPU_MASK_TYPE         __SYSCALL_ULONG_TYPE
#ifdef __x86_64__
/* Tell the libc code that off_t and off64_t are actually the same type
   for all ABI purposes, even if possibly expressed as different base types
   for C type-checking purposes.  */
# define __OFF_T_MATCHES_OFF64_T        1
/* Same for ino_t and ino64_t.  */
# define __INO_T_MATCHES_INO64_T        1
#endif
/* Number of descriptors that can fit in an `fd_set'.  */
#define __FD_SETSIZE                1024
#endif /* bits/typesizes.h */        /* Defines __*_T_TYPE macros.  */
__STD_TYPE __DEV_T_TYPE __dev_t;        /* Type of device numbers.  */
__STD_TYPE __UID_T_TYPE __uid_t;        /* Type of user identifications.  */
__STD_TYPE __GID_T_TYPE __gid_t;        /* Type of group identifications.  */
__STD_TYPE __INO_T_TYPE __ino_t;        /* Type of file serial numbers.  */
__STD_TYPE __INO64_T_TYPE __ino64_t;        /* Type of file serial numbers (LFS).*/
__STD_TYPE __MODE_T_TYPE __mode_t;        /* Type of file attribute bitmasks.  */
__STD_TYPE __NLINK_T_TYPE __nlink_t;        /* Type of file link counts.  */
__STD_TYPE __OFF_T_TYPE __off_t;        /* Type of file sizes and offsets.  */
__STD_TYPE __OFF64_T_TYPE __off64_t;        /* Type of file sizes and offsets (LFS).  */
__STD_TYPE __PID_T_TYPE __pid_t;        /* Type of process identifications.  */
__STD_TYPE __FSID_T_TYPE __fsid_t;        /* Type of file system IDs.  */
__STD_TYPE __CLOCK_T_TYPE __clock_t;        /* Type of CPU usage counts.  */
__STD_TYPE __RLIM_T_TYPE __rlim_t;        /* Type for resource measurement.  */
__STD_TYPE __RLIM64_T_TYPE __rlim64_t;        /* Type for resource measurement (LFS).  */
__STD_TYPE __ID_T_TYPE __id_t;                /* General type for IDs.  */
__STD_TYPE __TIME_T_TYPE __time_t;        /* Seconds since the Epoch.  */
__STD_TYPE __USECONDS_T_TYPE __useconds_t; /* Count of microseconds.  */
__STD_TYPE __SUSECONDS_T_TYPE __suseconds_t; /* Signed count of microseconds.  */
__STD_TYPE __DADDR_T_TYPE __daddr_t;        /* The type of a disk address.  */
__STD_TYPE __KEY_T_TYPE __key_t;        /* Type of an IPC key.  */
/* Clock ID used in clock and timer functions.  */
__STD_TYPE __CLOCKID_T_TYPE __clockid_t;
/* Timer ID returned by `timer_create'.  */
__STD_TYPE __TIMER_T_TYPE __timer_t;
/* Type to represent block size.  */
__STD_TYPE __BLKSIZE_T_TYPE __blksize_t;
/* Types from the Large File Support interface.  */
/* Type to count number of disk blocks.  */
__STD_TYPE __BLKCNT_T_TYPE __blkcnt_t;
__STD_TYPE __BLKCNT64_T_TYPE __blkcnt64_t;
/* Type to count file system blocks.  */
__STD_TYPE __FSBLKCNT_T_TYPE __fsblkcnt_t;
__STD_TYPE __FSBLKCNT64_T_TYPE __fsblkcnt64_t;
/* Type to count file system nodes.  */
__STD_TYPE __FSFILCNT_T_TYPE __fsfilcnt_t;
__STD_TYPE __FSFILCNT64_T_TYPE __fsfilcnt64_t;
/* Type of miscellaneous file system fields.  */
__STD_TYPE __FSWORD_T_TYPE __fsword_t;
__STD_TYPE __SSIZE_T_TYPE __ssize_t; /* Type of a byte count, or error.  */
/* Signed long type used in system calls.  */
__STD_TYPE __SYSCALL_SLONG_TYPE __syscall_slong_t;
/* Unsigned long type used in system calls.  */
__STD_TYPE __SYSCALL_ULONG_TYPE __syscall_ulong_t;
/* These few don't really vary by system, they always correspond
   to one of the other defined types.  */
typedef __off64_t __loff_t;        /* Type of file sizes and offsets (LFS).  */
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;
/* Duplicates info from stdint.h but this is used in unistd.h.  */
__STD_TYPE __SWORD_TYPE __intptr_t;
/* Duplicate info from sys/socket.h.  */
__STD_TYPE __U32_TYPE __socklen_t;
#undef __STD_TYPE
#endif /* bits/types.h */
#ifndef _____fpos_t_defined
#define _____fpos_t_defined 1
#ifndef        _BITS_TYPES_H
#define        _BITS_TYPES_H        1
#include <features.h>
#include <bits/wordsize.h>
/* Convenience types.  */
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
/* Fixed-size types, underlying types depend on word size and compiler.  */
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
#if __WORDSIZE == 64
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
#else
__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;
#endif
/* quad_t is also 64 bits.  */
#if __WORDSIZE == 64
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
#else
__extension__ typedef long long int __quad_t;
__extension__ typedef unsigned long long int __u_quad_t;
#endif
/* The machine-dependent file <bits/typesizes.h> defines __*_T_TYPE
   macros for each of the OS types we define below.  The definitions
   of those macros must use the following macros for underlying types.
   We define __S<SIZE>_TYPE and __U<SIZE>_TYPE for the signed and unsigned
   variants of each of the following integer types on this machine.
        16                -- "natural" 16-bit type (always short)
        32                -- "natural" 32-bit type (always int)
        64                -- "natural" 64-bit type (long or long long)
        LONG32                -- 32-bit type, traditionally long
        QUAD                -- 64-bit type, always long long
        WORD                -- natural type of __WORDSIZE bits (int or long)
        LONGWORD        -- type of __WORDSIZE bits, traditionally long
   We distinguish WORD/LONGWORD, 32/LONG32, and 64/QUAD so that the
   conventional uses of `long' or `long long' type modifiers match the
   types we define, even when a less-adorned type would be the same size.
   This matters for (somewhat) portably writing printf/scanf formats for
   these types, where using the appropriate l or ll format modifiers can
   make the typedefs and the formats match up across all GNU platforms.  If
   we used `long' when it's 64 bits where `long long' is expected, then the
   compiler would warn about the formats not matching the argument types,
   and the programmer changing them to shut up the compiler would break the
   program's portability.
   Here we assume what is presently the case in all the GCC configurations
   we support: long long is always 64 bits, long is always word/address size,
   and int is always 32 bits.  */
#define        __S16_TYPE                short int
#define __U16_TYPE                unsigned short int
#define        __S32_TYPE                int
#define __U32_TYPE                unsigned int
#define __SLONGWORD_TYPE        long int
#define __ULONGWORD_TYPE        unsigned long int
#if __WORDSIZE == 32
# define __SQUAD_TYPE                __quad_t
# define __UQUAD_TYPE                __u_quad_t
# define __SWORD_TYPE                int
# define __UWORD_TYPE                unsigned int
# define __SLONG32_TYPE                long int
# define __ULONG32_TYPE                unsigned long int
# define __S64_TYPE                __quad_t
# define __U64_TYPE                __u_quad_t
/* We want __extension__ before typedef's that use nonstandard base types
   such as `long long' in C89 mode.  */
# define __STD_TYPE                __extension__ typedef
#elif __WORDSIZE == 64
# define __SQUAD_TYPE                long int
# define __UQUAD_TYPE                unsigned long int
# define __SWORD_TYPE                long int
# define __UWORD_TYPE                unsigned long int
# define __SLONG32_TYPE                int
# define __ULONG32_TYPE                unsigned int
# define __S64_TYPE                long int
# define __U64_TYPE                unsigned long int
/* No need to mark the typedef with __extension__.   */
# define __STD_TYPE                typedef
#else
# error
#endif
#include <bits/typesizes.h>        /* Defines __*_T_TYPE macros.  */
__STD_TYPE __DEV_T_TYPE __dev_t;        /* Type of device numbers.  */
__STD_TYPE __UID_T_TYPE __uid_t;        /* Type of user identifications.  */
__STD_TYPE __GID_T_TYPE __gid_t;        /* Type of group identifications.  */
__STD_TYPE __INO_T_TYPE __ino_t;        /* Type of file serial numbers.  */
__STD_TYPE __INO64_T_TYPE __ino64_t;        /* Type of file serial numbers (LFS).*/
__STD_TYPE __MODE_T_TYPE __mode_t;        /* Type of file attribute bitmasks.  */
__STD_TYPE __NLINK_T_TYPE __nlink_t;        /* Type of file link counts.  */
__STD_TYPE __OFF_T_TYPE __off_t;        /* Type of file sizes and offsets.  */
__STD_TYPE __OFF64_T_TYPE __off64_t;        /* Type of file sizes and offsets (LFS).  */
__STD_TYPE __PID_T_TYPE __pid_t;        /* Type of process identifications.  */
__STD_TYPE __FSID_T_TYPE __fsid_t;        /* Type of file system IDs.  */
__STD_TYPE __CLOCK_T_TYPE __clock_t;        /* Type of CPU usage counts.  */
__STD_TYPE __RLIM_T_TYPE __rlim_t;        /* Type for resource measurement.  */
__STD_TYPE __RLIM64_T_TYPE __rlim64_t;        /* Type for resource measurement (LFS).  */
__STD_TYPE __ID_T_TYPE __id_t;                /* General type for IDs.  */
__STD_TYPE __TIME_T_TYPE __time_t;        /* Seconds since the Epoch.  */
__STD_TYPE __USECONDS_T_TYPE __useconds_t; /* Count of microseconds.  */
__STD_TYPE __SUSECONDS_T_TYPE __suseconds_t; /* Signed count of microseconds.  */
__STD_TYPE __DADDR_T_TYPE __daddr_t;        /* The type of a disk address.  */
__STD_TYPE __KEY_T_TYPE __key_t;        /* Type of an IPC key.  */
/* Clock ID used in clock and timer functions.  */
__STD_TYPE __CLOCKID_T_TYPE __clockid_t;
/* Timer ID returned by `timer_create'.  */
__STD_TYPE __TIMER_T_TYPE __timer_t;
/* Type to represent block size.  */
__STD_TYPE __BLKSIZE_T_TYPE __blksize_t;
/* Types from the Large File Support interface.  */
/* Type to count number of disk blocks.  */
__STD_TYPE __BLKCNT_T_TYPE __blkcnt_t;
__STD_TYPE __BLKCNT64_T_TYPE __blkcnt64_t;
/* Type to count file system blocks.  */
__STD_TYPE __FSBLKCNT_T_TYPE __fsblkcnt_t;
__STD_TYPE __FSBLKCNT64_T_TYPE __fsblkcnt64_t;
/* Type to count file system nodes.  */
__STD_TYPE __FSFILCNT_T_TYPE __fsfilcnt_t;
__STD_TYPE __FSFILCNT64_T_TYPE __fsfilcnt64_t;
/* Type of miscellaneous file system fields.  */
__STD_TYPE __FSWORD_T_TYPE __fsword_t;
__STD_TYPE __SSIZE_T_TYPE __ssize_t; /* Type of a byte count, or error.  */
/* Signed long type used in system calls.  */
__STD_TYPE __SYSCALL_SLONG_TYPE __syscall_slong_t;
/* Unsigned long type used in system calls.  */
__STD_TYPE __SYSCALL_ULONG_TYPE __syscall_ulong_t;
/* These few don't really vary by system, they always correspond
   to one of the other defined types.  */
typedef __off64_t __loff_t;        /* Type of file sizes and offsets (LFS).  */
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;
/* Duplicates info from stdint.h but this is used in unistd.h.  */
__STD_TYPE __SWORD_TYPE __intptr_t;
/* Duplicate info from sys/socket.h.  */
__STD_TYPE __U32_TYPE __socklen_t;
#undef __STD_TYPE
#endif /* bits/types.h */
#ifndef ____mbstate_t_defined
#define ____mbstate_t_defined 1
/* Integral type unchanged by default argument promotions that can
   hold any value corresponding to members of the extended character
   set, as well as at least one value that does not correspond to any
   member of the extended character set.  */
#ifndef __WINT_TYPE__
# define __WINT_TYPE__ unsigned int
#endif
/* Conversion state information.  */
typedef struct
{
  int __count;
  union
  {
    __WINT_TYPE__ __wch;
    char __wchb[4];
  } __value;		/* Value so far.  */
} __mbstate_t;
#endif
/* The tag name of this struct is _G_fpos_t to preserve historic
   C++ mangled names for functions taking fpos_t arguments.
   That name should not be used in new code.  */
typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
#endif
#ifndef _____fpos64_t_defined
#define _____fpos64_t_defined 1
#ifndef        _SYS_TYPES_H
#define        _SYS_TYPES_H        1
#include <features.h>
__BEGIN_DECLS
#include <bits/types.h>
#ifdef        __USE_MISC
# ifndef __u_char_defined
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
#  define __u_char_defined
# endif
#endif
typedef __loff_t loff_t;
#ifndef __ino_t_defined
# ifndef __USE_FILE_OFFSET64
typedef __ino_t ino_t;
# else
typedef __ino64_t ino_t;
# endif
# define __ino_t_defined
#endif
#if defined __USE_LARGEFILE64 && !defined __ino64_t_defined
typedef __ino64_t ino64_t;
# define __ino64_t_defined
#endif
#ifndef __dev_t_defined
typedef __dev_t dev_t;
# define __dev_t_defined
#endif
#ifndef __gid_t_defined
typedef __gid_t gid_t;
# define __gid_t_defined
#endif
#ifndef __mode_t_defined
typedef __mode_t mode_t;
# define __mode_t_defined
#endif
#ifndef __nlink_t_defined
typedef __nlink_t nlink_t;
# define __nlink_t_defined
#endif
#ifndef __uid_t_defined
typedef __uid_t uid_t;
# define __uid_t_defined
#endif
#ifndef __off_t_defined
# ifndef __USE_FILE_OFFSET64
typedef __off_t off_t;
# else
typedef __off64_t off_t;
# endif
# define __off_t_defined
#endif
#if defined __USE_LARGEFILE64 && !defined __off64_t_defined
typedef __off64_t off64_t;
# define __off64_t_defined
#endif
#ifndef __pid_t_defined
typedef __pid_t pid_t;
# define __pid_t_defined
#endif
#if (defined __USE_XOPEN || defined __USE_XOPEN2K8) \
    && !defined __id_t_defined
typedef __id_t id_t;
# define __id_t_defined
#endif
#ifndef __ssize_t_defined
typedef __ssize_t ssize_t;
# define __ssize_t_defined
#endif
#ifdef        __USE_MISC
# ifndef __daddr_t_defined
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
#  define __daddr_t_defined
# endif
#endif
#if (defined __USE_MISC || defined __USE_XOPEN) && !defined __key_t_defined
typedef __key_t key_t;
# define __key_t_defined
#endif
#if defined __USE_XOPEN || defined __USE_XOPEN2K8
# include <bits/types/clock_t.h>
#endif
#include <bits/types/clockid_t.h>
#include <bits/types/time_t.h>
#include <bits/types/timer_t.h>
#ifdef __USE_XOPEN
# ifndef __useconds_t_defined
typedef __useconds_t useconds_t;
#  define __useconds_t_defined
# endif
# ifndef __suseconds_t_defined
typedef __suseconds_t suseconds_t;
#  define __suseconds_t_defined
# endif
#endif
#define        __need_size_t
#include <stddef.h>
#ifdef __USE_MISC
/* Old compatibility names for C types.  */
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
#endif
/* These size-specific names are used by some of the inet code.  */
#include <bits/stdint-intn.h>
#if !__GNUC_PREREQ (2, 7)
/* These were defined by ISO C without the first `_'.  */
typedef        unsigned char u_int8_t;
typedef        unsigned short int u_int16_t;
typedef        unsigned int u_int32_t;
# if __WORDSIZE == 64
typedef unsigned long int u_int64_t;
# else
__extension__ typedef unsigned long long int u_int64_t;
# endif
typedef int register_t;
#else
/* For GCC 2.7 and later, we can use specific type-size attributes.  */
# define __u_intN_t(N, MODE) \
  typedef unsigned int u_int##N##_t __attribute__ ((__mode__ (MODE)))
__u_intN_t (8, __QI__);
__u_intN_t (16, __HI__);
__u_intN_t (32, __SI__);
__u_intN_t (64, __DI__);
typedef int register_t __attribute__ ((__mode__ (__word__)));
/* Some code from BIND tests this macro to see if the types above are
   defined.  */
#endif
#define __BIT_TYPES_DEFINED__        1
#ifdef        __USE_MISC
/* In BSD <sys/types.h> is expected to define BYTE_ORDER.  */
# include <endian.h>
/* It also defines `fd_set' and the FD_* macros for `select'.  */
# include <sys/select.h>
/* BSD defines `major', `minor', and `makedev' in this header.
   However, these symbols are likely to collide with user code, so we are
   going to stop defining them here in an upcoming release.  Code that needs
   these macros should include <sys/sysmacros.h> directly.  Code that does
   not need these macros should #undef them after including this header.  */
# define __SYSMACROS_DEPRECATED_INCLUSION
# include <sys/sysmacros.h>
# undef __SYSMACROS_DEPRECATED_INCLUSION
#endif /* Use misc.  */
#if (defined __USE_UNIX98 || defined __USE_XOPEN2K8) \
    && !defined __blksize_t_defined
typedef __blksize_t blksize_t;
# define __blksize_t_defined
#endif
/* Types from the Large File Support interface.  */
#ifndef __USE_FILE_OFFSET64
# ifndef __blkcnt_t_defined
typedef __blkcnt_t blkcnt_t;         /* Type to count number of disk blocks.  */
#  define __blkcnt_t_defined
# endif
# ifndef __fsblkcnt_t_defined
typedef __fsblkcnt_t fsblkcnt_t; /* Type to count file system blocks.  */
#  define __fsblkcnt_t_defined
# endif
# ifndef __fsfilcnt_t_defined
typedef __fsfilcnt_t fsfilcnt_t; /* Type to count file system inodes.  */
#  define __fsfilcnt_t_defined
# endif
#else
# ifndef __blkcnt_t_defined
typedef __blkcnt64_t blkcnt_t;           /* Type to count number of disk blocks.  */
#  define __blkcnt_t_defined
# endif
# ifndef __fsblkcnt_t_defined
typedef __fsblkcnt64_t fsblkcnt_t; /* Type to count file system blocks.  */
#  define __fsblkcnt_t_defined
# endif
# ifndef __fsfilcnt_t_defined
typedef __fsfilcnt64_t fsfilcnt_t; /* Type to count file system inodes.  */
#  define __fsfilcnt_t_defined
# endif
#endif
#ifdef __USE_LARGEFILE64
typedef __blkcnt64_t blkcnt64_t;     /* Type to count number of disk blocks. */
typedef __fsblkcnt64_t fsblkcnt64_t; /* Type to count file system blocks.  */
typedef __fsfilcnt64_t fsfilcnt64_t; /* Type to count file system inodes.  */
#endif
/* Now add the thread types.  */
#if defined __USE_POSIX199506 || defined __USE_UNIX98
#ifndef _BITS_PTHREADTYPES_COMMON_H
# define _BITS_PTHREADTYPES_COMMON_H	1
/* For internal mutex and condition variable definitions.  */
#include <bits/thread-shared-types.h>
/* Thread identifiers.  The structure of the attribute type is not
   exposed on purpose.  */
typedef unsigned long int pthread_t;
/* Data structures for mutex handling.  The structure of the attribute
   type is not exposed on purpose.  */
typedef union
{
  char __size[__SIZEOF_PTHREAD_MUTEXATTR_T];
  int __align;
} pthread_mutexattr_t;
/* Data structure for condition variable handling.  The structure of
   the attribute type is not exposed on purpose.  */
typedef union
{
  char __size[__SIZEOF_PTHREAD_CONDATTR_T];
  int __align;
} pthread_condattr_t;
/* Keys for thread-specific data */
typedef unsigned int pthread_key_t;
/* Once-only execution */
typedef int __ONCE_ALIGNMENT pthread_once_t;
union pthread_attr_t
{
  char __size[__SIZEOF_PTHREAD_ATTR_T];
  long int __align;
};
#ifndef __have_pthread_attr_t
typedef union pthread_attr_t pthread_attr_t;
# define __have_pthread_attr_t 1
#endif
typedef union
{
  struct __pthread_mutex_s __data;
  char __size[__SIZEOF_PTHREAD_MUTEX_T];
  long int __align;
} pthread_mutex_t;
typedef union
{
  struct __pthread_cond_s __data;
  char __size[__SIZEOF_PTHREAD_COND_T];
  __extension__ long long int __align;
} pthread_cond_t;
#if defined __USE_UNIX98 || defined __USE_XOPEN2K
/* Data structure for reader-writer lock variable handling.  The
   structure of the attribute type is deliberately not exposed.  */
typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[__SIZEOF_PTHREAD_RWLOCK_T];
  long int __align;
} pthread_rwlock_t;
typedef union
{
  char __size[__SIZEOF_PTHREAD_RWLOCKATTR_T];
  long int __align;
} pthread_rwlockattr_t;
#endif
#ifdef __USE_XOPEN2K
/* POSIX spinlock data type.  */
typedef volatile int pthread_spinlock_t;
/* POSIX barriers data type.  The structure of the type is
   deliberately not exposed.  */
typedef union
{
  char __size[__SIZEOF_PTHREAD_BARRIER_T];
  long int __align;
} pthread_barrier_t;
typedef union
{
  char __size[__SIZEOF_PTHREAD_BARRIERATTR_T];
  int __align;
} pthread_barrierattr_t;
#endif
#endif
#endif
__END_DECLS
#endif /* sys/types.h */
#ifndef ____mbstate_t_defined
#define ____mbstate_t_defined 1
/* Integral type unchanged by default argument promotions that can
   hold any value corresponding to members of the extended character
   set, as well as at least one value that does not correspond to any
   member of the extended character set.  */
#ifndef __WINT_TYPE__
# define __WINT_TYPE__ unsigned int
#endif
/* Conversion state information.  */
typedef struct
{
  int __count;
  union
  {
    __WINT_TYPE__ __wch;
    char __wchb[4];
  } __value;		/* Value so far.  */
} __mbstate_t;
#endif
/* The tag name of this struct is _G_fpos64_t to preserve historic
   C++ mangled names for functions taking fpos_t and/or fpos64_t
   arguments.  That name should not be used in new code.  */
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
#endif
#ifndef ____FILE_defined
#define ____FILE_defined 1
struct _IO_FILE;
typedef struct _IO_FILE __FILE;
#endif
#ifndef __FILE_defined
#define __FILE_defined 1
struct _IO_FILE;
/* The opaque type of streams.  This is the definition used elsewhere.  */
typedef struct _IO_FILE FILE;
#endif
#ifndef __struct_FILE_defined
#define __struct_FILE_defined 1
/* Caution: The contents of this file are not part of the official
   stdio.h API.  However, much of it is part of the official *binary*
   interface, and therefore cannot be changed.  */
#if defined _IO_USE_OLD_IO_FILE && !defined _LIBC
# error "_IO_USE_OLD_IO_FILE should only be defined when building libc itself"
#endif
#if defined _IO_lock_t_defined && !defined _LIBC
# error "_IO_lock_t_defined should only be defined when building libc itself"
#endif
#include <bits/types.h>
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;
/* During the build of glibc itself, _IO_lock_t will already have been
   defined by internal headers.  */
#ifndef _IO_lock_t_defined
typedef void _IO_lock_t;
#endif
/* The tag name of this struct is _IO_FILE to preserve historic
   C++ mangled names for functions taking FILE* arguments.
   That name should not be used in new code.  */
struct _IO_FILE
{
  int _flags;                /* High-order word is _IO_MAGIC; rest is flags. */
  /* The following pointers correspond to the C++ streambuf protocol. */
  char *_IO_read_ptr;        /* Current read pointer */
  char *_IO_read_end;        /* End of get area. */
  char *_IO_read_base;        /* Start of putback+get area. */
  char *_IO_write_base;        /* Start of put area. */
  char *_IO_write_ptr;        /* Current put pointer. */
  char *_IO_write_end;        /* End of put area. */
  char *_IO_buf_base;        /* Start of reserve area. */
  char *_IO_buf_end;        /* End of reserve area. */
  /* The following fields are used to support backing up and undo. */
  char *_IO_save_base; /* Pointer to start of non-current get area. */
  char *_IO_backup_base;  /* Pointer to first valid character of backup area */
  char *_IO_save_end; /* Pointer to end of non-current get area. */
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset; /* This used to be _offset but it's too small.  */
  /* 1+column number of pbase(); 0 is unknown. */
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
#ifdef _IO_USE_OLD_IO_FILE
};
struct _IO_FILE_complete
{
  struct _IO_FILE _file;
#endif
  __off64_t _offset;
  /* Wide character stream stuff.  */
  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;
  /* Make sure we don't get into trouble again.  */
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
/* These macros are used by bits/stdio.h and internal headers.  */
#define __getc_unlocked_body(_fp)                                        \
  (__glibc_unlikely ((_fp)->_IO_read_ptr >= (_fp)->_IO_read_end)        \
   ? __uflow (_fp) : *(unsigned char *) (_fp)->_IO_read_ptr++)
#define __putc_unlocked_body(_ch, _fp)                                        \
  (__glibc_unlikely ((_fp)->_IO_write_ptr >= (_fp)->_IO_write_end)        \
   ? __overflow (_fp, (unsigned char) (_ch))                                \
   : (unsigned char) (*(_fp)->_IO_write_ptr++ = (_ch)))
#define _IO_EOF_SEEN 0x0010
#define __feof_unlocked_body(_fp) (((_fp)->_flags & _IO_EOF_SEEN) != 0)
#define _IO_ERR_SEEN 0x0020
#define __ferror_unlocked_body(_fp) (((_fp)->_flags & _IO_ERR_SEEN) != 0)
#define _IO_USER_LOCK 0x8000
/* Many more flag bits are defined internally.  */
#endif
#ifdef __USE_GNU
# include <bits/types/cookie_io_functions_t.h>
#endif
#if defined __USE_XOPEN || defined __USE_XOPEN2K8
# ifdef __GNUC__
#  ifndef _VA_LIST_DEFINED
typedef __gnuc_va_list va_list;
#   define _VA_LIST_DEFINED
#  endif
# else
#ifndef _STDARG_H
#ifndef _ANSI_STDARG_H_
#ifndef __need___va_list
#define _STDARG_H
#define _ANSI_STDARG_H_
#endif /* not __need___va_list */
#undef __need___va_list

/* Define __gnuc_va_list.  */

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
typedef __builtin_va_list __gnuc_va_list;
#endif

/* Define the standard macros for the user,
   if this invocation was from the user program.  */
#ifdef _STDARG_H

#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)
#define va_arg(v,l)	__builtin_va_arg(v,l)
#if !defined(__STRICT_ANSI__) || __STDC_VERSION__ + 0 >= 199900L \
    || __cplusplus + 0 >= 201103L
#define va_copy(d,s)	__builtin_va_copy(d,s)
#endif
#define __va_copy(d,s)	__builtin_va_copy(d,s)

/* Define va_list, if desired, from __gnuc_va_list. */
/* We deliberately do not define va_list when called from
   stdio.h, because ANSI C says that stdio.h is not supposed to define
   va_list.  stdio.h needs to have access to that data type, 
   but must not use that name.  It should use the name __gnuc_va_list,
   which is safe because it is reserved for the implementation.  */

#ifdef _BSD_VA_LIST
#undef _BSD_VA_LIST
#endif

#if defined(__svr4__) || (defined(_SCO_DS) && !defined(__VA_LIST))
/* SVR4.2 uses _VA_LIST for an internal alias for va_list,
   so we must avoid testing it and setting it here.
   SVR4 uses _VA_LIST as a flag in stdarg.h, but we should
   have no conflict with that.  */
#ifndef _VA_LIST_
#define _VA_LIST_
#ifdef __i860__
#ifndef _VA_LIST
#define _VA_LIST va_list
#endif
#endif /* __i860__ */
typedef __gnuc_va_list va_list;
#ifdef _SCO_DS
#define __VA_LIST
#endif
#endif /* _VA_LIST_ */
#else /* not __svr4__ || _SCO_DS */

/* The macro _VA_LIST_ is the same thing used by this file in Ultrix.
   But on BSD NET2 we must not test or define or undef it.
   (Note that the comments in NET 2's ansi.h
   are incorrect for _VA_LIST_--see stdio.h!)  */
#if !defined (_VA_LIST_) || defined (__BSD_NET2__) || defined (____386BSD____) || defined (__bsdi__) || defined (__sequent__) || defined (__FreeBSD__) || defined(WINNT)
/* The macro _VA_LIST_DEFINED is used in Windows NT 3.5  */
#ifndef _VA_LIST_DEFINED
/* The macro _VA_LIST is used in SCO Unix 3.2.  */
#ifndef _VA_LIST
/* The macro _VA_LIST_T_H is used in the Bull dpx2  */
#ifndef _VA_LIST_T_H
/* The macro __va_list__ is used by BeOS.  */
#ifndef __va_list__
typedef __gnuc_va_list va_list;
#endif /* not __va_list__ */
#endif /* not _VA_LIST_T_H */
#endif /* not _VA_LIST */
#endif /* not _VA_LIST_DEFINED */
#if !(defined (__BSD_NET2__) || defined (____386BSD____) || defined (__bsdi__) || defined (__sequent__) || defined (__FreeBSD__))
#define _VA_LIST_
#endif
#ifndef _VA_LIST
#define _VA_LIST
#endif
#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
#endif
#ifndef _VA_LIST_T_H
#define _VA_LIST_T_H
#endif
#ifndef __va_list__
#define __va_list__
#endif

#endif /* not _VA_LIST_, except on certain systems */

#endif /* not __svr4__ */

#endif /* _STDARG_H */

#endif /* not _ANSI_STDARG_H_ */
#endif /* not _STDARG_H */
# endif
#endif
#if defined __USE_UNIX98 || defined __USE_XOPEN2K
# ifndef __off_t_defined
# ifndef __USE_FILE_OFFSET64
typedef __off_t off_t;
# else
typedef __off64_t off_t;
# endif
# define __off_t_defined
# endif
# if defined __USE_LARGEFILE64 && !defined __off64_t_defined
typedef __off64_t off64_t;
# define __off64_t_defined
# endif
#endif
#ifdef __USE_XOPEN2K8
# ifndef __ssize_t_defined
typedef __ssize_t ssize_t;
# define __ssize_t_defined
# endif
#endif
/* The type of the second argument to `fgetpos' and `fsetpos'.  */
#ifndef __USE_FILE_OFFSET64
typedef __fpos_t fpos_t;
#else
typedef __fpos64_t fpos_t;
#endif
#ifdef __USE_LARGEFILE64
typedef __fpos64_t fpos64_t;
#endif
/* The possibilities for the third argument to `setvbuf'.  */
#define _IOFBF 0                /* Fully buffered.  */
#define _IOLBF 1                /* Line buffered.  */
#define _IONBF 2                /* No buffering.  */
/* Default buffer size.  */
#define BUFSIZ 8192
/* The value returned by fgetc and similar functions to indicate the
   end of the file.  */
#define EOF (-1)
/* The possibilities for the third argument to `fseek'.
   These values should not be changed.  */
#define SEEK_SET        0        /* Seek from beginning of file.  */
#define SEEK_CUR        1        /* Seek from current position.  */
#define SEEK_END        2        /* Seek from end of file.  */
#ifdef __USE_GNU
# define SEEK_DATA        3        /* Seek to next data.  */
# define SEEK_HOLE        4        /* Seek to next hole.  */
#endif
#if defined __USE_MISC || defined __USE_XOPEN
/* Default path prefix for `tempnam' and `tmpnam'.  */
# define P_tmpdir        "/tmp"
#endif
/* Get the values:
   L_tmpnam        How long an array of chars must be to be passed to `tmpnam'.
   TMP_MAX        The minimum number of unique filenames generated by tmpnam
                (and tempnam when it uses tmpnam's name space),
                or tempnam (the two are separate).
   L_ctermid        How long an array to pass to `ctermid'.
   L_cuserid        How long an array to pass to `cuserid'.
   FOPEN_MAX        Minimum number of files that can be open at once.
   FILENAME_MAX        Maximum length of a filename.  */
#include <bits/stdio_lim.h>
/* Standard streams.  */
extern FILE *stdin;                /* Standard input stream.  */
extern FILE *stdout;                /* Standard output stream.  */
extern FILE *stderr;                /* Standard error output stream.  */
/* C89/C99 say they're macros.  Make them happy.  */
#define stdin stdin
#define stdout stdout
#define stderr stderr
/* Remove file FILENAME.  */
extern int remove (const char *__filename) __THROW;
/* Rename file OLD to NEW.  */
extern int rename (const char *__old, const char *__new) __THROW;
#ifdef __USE_ATFILE
/* Rename file OLD relative to OLDFD to NEW relative to NEWFD.  */
extern int renameat (int __oldfd, const char *__old, int __newfd,
                     const char *__new) __THROW;
#endif
#ifdef __USE_GNU
/* Flags for renameat2.  */
# define RENAME_NOREPLACE (1 << 0)
# define RENAME_EXCHANGE (1 << 1)
# define RENAME_WHITEOUT (1 << 2)
/* Rename file OLD relative to OLDFD to NEW relative to NEWFD, with
   additional flags.  */
extern int renameat2 (int __oldfd, const char *__old, int __newfd,
                      const char *__new, unsigned int __flags) __THROW;
#endif
/* Create a temporary file and open it read/write.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
#ifndef __USE_FILE_OFFSET64
extern FILE *tmpfile (void) __wur;
#else
# ifdef __REDIRECT
extern FILE *__REDIRECT (tmpfile, (void), tmpfile64) __wur;
# else
#  define tmpfile tmpfile64
# endif
#endif
#ifdef __USE_LARGEFILE64
extern FILE *tmpfile64 (void) __wur;
#endif
/* Generate a temporary filename.  */
extern char *tmpnam (char *__s) __THROW __wur;
#ifdef __USE_MISC
/* This is the reentrant variant of `tmpnam'.  The only difference is
   that it does not allow S to be NULL.  */
extern char *tmpnam_r (char *__s) __THROW __wur;
#endif
#if defined __USE_MISC || defined __USE_XOPEN
/* Generate a unique temporary filename using up to five characters of PFX
   if it is not NULL.  The directory to put this file in is searched for
   as follows: First the environment variable "TMPDIR" is checked.
   If it contains the name of a writable directory, that directory is used.
   If not and if DIR is not NULL, that value is checked.  If that fails,
   P_tmpdir is tried and finally "/tmp".  The storage for the filename
   is allocated by `malloc'.  */
extern char *tempnam (const char *__dir, const char *__pfx)
     __THROW __attribute_malloc__ __wur;
#endif
/* Close STREAM.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fclose (FILE *__stream);
/* Flush STREAM, or all streams if STREAM is NULL.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fflush (FILE *__stream);
#ifdef __USE_MISC
/* Faster versions when locking is not required.
   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fflush_unlocked (FILE *__stream);
#endif
#ifdef __USE_GNU
/* Close all streams.
   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fcloseall (void);
#endif
#ifndef __USE_FILE_OFFSET64
/* Open a file and create a new stream for it.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern FILE *fopen (const char *__restrict __filename,
                    const char *__restrict __modes) __wur;
/* Open a file, replacing an existing stream with it.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern FILE *freopen (const char *__restrict __filename,
                      const char *__restrict __modes,
                      FILE *__restrict __stream) __wur;
#else
# ifdef __REDIRECT
extern FILE *__REDIRECT (fopen, (const char *__restrict __filename,
                                 const char *__restrict __modes), fopen64)
  __wur;
extern FILE *__REDIRECT (freopen, (const char *__restrict __filename,
                                   const char *__restrict __modes,
                                   FILE *__restrict __stream), freopen64)
  __wur;
# else
#  define fopen fopen64
#  define freopen freopen64
# endif
#endif
#ifdef __USE_LARGEFILE64
extern FILE *fopen64 (const char *__restrict __filename,
                      const char *__restrict __modes) __wur;
extern FILE *freopen64 (const char *__restrict __filename,
                        const char *__restrict __modes,
                        FILE *__restrict __stream) __wur;
#endif
#ifdef        __USE_POSIX
/* Create a new stream that refers to an existing system file descriptor.  */
extern FILE *fdopen (int __fd, const char *__modes) __THROW __wur;
#endif
#ifdef        __USE_GNU
/* Create a new stream that refers to the given magic cookie,
   and uses the given functions for input and output.  */
extern FILE *fopencookie (void *__restrict __magic_cookie,
                          const char *__restrict __modes,
                          cookie_io_functions_t __io_funcs) __THROW __wur;
#endif
#if defined __USE_XOPEN2K8 || __GLIBC_USE (LIB_EXT2)
/* Create a new stream that refers to a memory buffer.  */
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __THROW __wur;
/* Open a stream that writes into a malloc'd buffer that is expanded as
   necessary.  *BUFLOC and *SIZELOC are updated with the buffer's location
   and the number of characters written on fflush or fclose.  */
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __THROW __wur;
#endif
/* If BUF is NULL, make STREAM unbuffered.
   Else make it use buffer BUF, of size BUFSIZ.  */
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __THROW;
/* Make STREAM use buffering mode MODE.
   If BUF is not NULL, use N bytes of it for buffering;
   else allocate an internal buffer N bytes long.  */
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
                    int __modes, size_t __n) __THROW;
#ifdef        __USE_MISC
/* If BUF is NULL, make STREAM unbuffered.
   Else make it use SIZE bytes of BUF for buffering.  */
extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
                       size_t __size) __THROW;
/* Make STREAM line-buffered.  */
extern void setlinebuf (FILE *__stream) __THROW;
#endif
/* Write formatted output to STREAM.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fprintf (FILE *__restrict __stream,
                    const char *__restrict __format, ...);
/* Write formatted output to stdout.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int printf (const char *__restrict __format, ...);
/* Write formatted output to S.  */
extern int sprintf (char *__restrict __s,
                    const char *__restrict __format, ...) __THROWNL;
/* Write formatted output to S from argument list ARG.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
                     __gnuc_va_list __arg);
/* Write formatted output to stdout from argument list ARG.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);
/* Write formatted output to S from argument list ARG.  */
extern int vsprintf (char *__restrict __s, const char *__restrict __format,
                     __gnuc_va_list __arg) __THROWNL;
#if defined __USE_ISOC99 || defined __USE_UNIX98
/* Maximum chars of output to write in MAXLEN.  */
extern int snprintf (char *__restrict __s, size_t __maxlen,
                     const char *__restrict __format, ...)
     __THROWNL __attribute__ ((__format__ (__printf__, 3, 4)));
extern int vsnprintf (char *__restrict __s, size_t __maxlen,
                      const char *__restrict __format, __gnuc_va_list __arg)
     __THROWNL __attribute__ ((__format__ (__printf__, 3, 0)));
#endif
#if __GLIBC_USE (LIB_EXT2)
/* Write formatted output to a string dynamically allocated with `malloc'.
   Store the address of the string in *PTR.  */
extern int vasprintf (char **__restrict __ptr, const char *__restrict __f,
                      __gnuc_va_list __arg)
     __THROWNL __attribute__ ((__format__ (__printf__, 2, 0))) __wur;
extern int __asprintf (char **__restrict __ptr,
                       const char *__restrict __fmt, ...)
     __THROWNL __attribute__ ((__format__ (__printf__, 2, 3))) __wur;
extern int asprintf (char **__restrict __ptr,
                     const char *__restrict __fmt, ...)
     __THROWNL __attribute__ ((__format__ (__printf__, 2, 3))) __wur;
#endif
#ifdef __USE_XOPEN2K8
/* Write formatted output to a file descriptor.  */
extern int vdprintf (int __fd, const char *__restrict __fmt,
                     __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));
#endif
/* Read formatted input from STREAM.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fscanf (FILE *__restrict __stream,
                   const char *__restrict __format, ...) __wur;
/* Read formatted input from stdin.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int scanf (const char *__restrict __format, ...) __wur;
/* Read formatted input from S.  */
extern int sscanf (const char *__restrict __s,
                   const char *__restrict __format, ...) __THROW;
/* For historical reasons, the C99-compliant versions of the scanf
   functions are at alternative names.  When __LDBL_COMPAT is in
   effect, this is handled in bits/stdio-ldbl.h.  */
#if !__GLIBC_USE (DEPRECATED_SCANF) && !defined __LDBL_COMPAT
# ifdef __REDIRECT
extern int __REDIRECT (fscanf, (FILE *__restrict __stream,
                                const char *__restrict __format, ...),
                       __isoc99_fscanf) __wur;
extern int __REDIRECT (scanf, (const char *__restrict __format, ...),
                       __isoc99_scanf) __wur;
extern int __REDIRECT_NTH (sscanf, (const char *__restrict __s,
                                    const char *__restrict __format, ...),
                           __isoc99_sscanf);
# else
extern int __isoc99_fscanf (FILE *__restrict __stream,
                            const char *__restrict __format, ...) __wur;
extern int __isoc99_scanf (const char *__restrict __format, ...) __wur;
extern int __isoc99_sscanf (const char *__restrict __s,
                            const char *__restrict __format, ...) __THROW;
#  define fscanf __isoc99_fscanf
#  define scanf __isoc99_scanf
#  define sscanf __isoc99_sscanf
# endif
#endif
#ifdef        __USE_ISOC99
/* Read formatted input from S into argument list ARG.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
                    __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) __wur;
/* Read formatted input from stdin into argument list ARG.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) __wur;
/* Read formatted input from S into argument list ARG.  */
extern int vsscanf (const char *__restrict __s,
                    const char *__restrict __format, __gnuc_va_list __arg)
     __THROW __attribute__ ((__format__ (__scanf__, 2, 0)));
/* Same redirection as above for the v*scanf family.  */
# if !__GLIBC_USE (DEPRECATED_SCANF)
#  if defined __REDIRECT && !defined __LDBL_COMPAT
extern int __REDIRECT (vfscanf,
                       (FILE *__restrict __s,
                        const char *__restrict __format, __gnuc_va_list __arg),
                       __isoc99_vfscanf)
     __attribute__ ((__format__ (__scanf__, 2, 0))) __wur;
extern int __REDIRECT (vscanf, (const char *__restrict __format,
                                __gnuc_va_list __arg), __isoc99_vscanf)
     __attribute__ ((__format__ (__scanf__, 1, 0))) __wur;
extern int __REDIRECT_NTH (vsscanf,
                           (const char *__restrict __s,
                            const char *__restrict __format,
                            __gnuc_va_list __arg), __isoc99_vsscanf)
     __attribute__ ((__format__ (__scanf__, 2, 0)));
#  elif !defined __REDIRECT
extern int __isoc99_vfscanf (FILE *__restrict __s,
                             const char *__restrict __format,
                             __gnuc_va_list __arg) __wur;
extern int __isoc99_vscanf (const char *__restrict __format,
                            __gnuc_va_list __arg) __wur;
extern int __isoc99_vsscanf (const char *__restrict __s,
                             const char *__restrict __format,
                             __gnuc_va_list __arg) __THROW;
#   define vfscanf __isoc99_vfscanf
#   define vscanf __isoc99_vscanf
#   define vsscanf __isoc99_vsscanf
#  endif
# endif
#endif /* Use ISO C9x.  */
/* Read a character from STREAM.
   These functions are possible cancellation points and therefore not
   marked with __THROW.  */
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);
/* Read a character from stdin.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int getchar (void);
#ifdef __USE_POSIX199506
/* These are defined in POSIX.1:1996.
   These functions are possible cancellation points and therefore not
   marked with __THROW.  */
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
#endif /* Use POSIX.  */
#ifdef __USE_MISC
/* Faster version when locking is not necessary.
   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fgetc_unlocked (FILE *__stream);
#endif /* Use MISC.  */
/* Write a character to STREAM.
   These functions are possible cancellation points and therefore not
   marked with __THROW.
   These functions is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);
/* Write a character to stdout.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int putchar (int __c);
#ifdef __USE_MISC
/* Faster version when locking is not necessary.
   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fputc_unlocked (int __c, FILE *__stream);
#endif /* Use MISC.  */
#ifdef __USE_POSIX199506
/* These are defined in POSIX.1:1996.
   These functions are possible cancellation points and therefore not
   marked with __THROW.  */
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);
#endif /* Use POSIX.  */
#if defined __USE_MISC \
    || (defined __USE_XOPEN && !defined __USE_XOPEN2K)
/* Get a word (int) from STREAM.  */
extern int getw (FILE *__stream);
/* Write a word (int) to STREAM.  */
extern int putw (int __w, FILE *__stream);
#endif
/* Get a newline-terminated string of finite length from STREAM.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     __wur;
#if __GLIBC_USE (DEPRECATED_GETS)
/* Get a newline-terminated string from stdin, removing the newline.
   This function is impossible to use safely.  It has been officially
   removed from ISO C11 and ISO C++14, and we have also removed it
   from the _GNU_SOURCE feature list.  It remains available when
   explicitly using an old ISO C, Unix, or POSIX standard.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern char *gets (char *__s) __wur __attribute_deprecated__;
#endif
#ifdef __USE_GNU
/* This function does the same as `fgets' but does not lock the stream.
   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern char *fgets_unlocked (char *__restrict __s, int __n,
                             FILE *__restrict __stream) __wur;
#endif
#if defined __USE_XOPEN2K8 || __GLIBC_USE (LIB_EXT2)
/* Read up to (and including) a DELIMITER from STREAM into *LINEPTR
   (and null-terminate it). *LINEPTR is a pointer returned from malloc (or
   NULL), pointing to *N characters of space.  It is realloc'd as
   necessary.  Returns the number of characters read (not including the
   null terminator), or -1 on error or EOF.
   These functions are not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation they are cancellation points and
   therefore not marked with __THROW.  */
extern __ssize_t __getdelim (char **__restrict __lineptr,
                             size_t *__restrict __n, int __delimiter,
                             FILE *__restrict __stream) __wur;
extern __ssize_t getdelim (char **__restrict __lineptr,
                           size_t *__restrict __n, int __delimiter,
                           FILE *__restrict __stream) __wur;
/* Like `getdelim', but reads up to a newline.
   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) __wur;
#endif
/* Write a string to STREAM.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fputs (const char *__restrict __s, FILE *__restrict __stream);
/* Write a string, followed by a newline, to stdout.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int puts (const char *__s);
/* Push a character back onto the input buffer of STREAM.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int ungetc (int __c, FILE *__stream);
/* Read chunks of generic data from STREAM.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern size_t fread (void *__restrict __ptr, size_t __size,
                     size_t __n, FILE *__restrict __stream) __wur;
/* Write chunks of generic data to STREAM.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern size_t fwrite (const void *__restrict __ptr, size_t __size,
                      size_t __n, FILE *__restrict __s);
#ifdef __USE_GNU
/* This function does the same as `fputs' but does not lock the stream.
   This function is not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern int fputs_unlocked (const char *__restrict __s,
                           FILE *__restrict __stream);
#endif
#ifdef __USE_MISC
/* Faster versions when locking is not necessary.
   These functions are not part of POSIX and therefore no official
   cancellation point.  But due to similarity with an POSIX interface
   or due to the implementation they are cancellation points and
   therefore not marked with __THROW.  */
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
                              size_t __n, FILE *__restrict __stream) __wur;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
                               size_t __n, FILE *__restrict __stream);
#endif
/* Seek to a certain position on STREAM.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fseek (FILE *__stream, long int __off, int __whence);
/* Return the current position of STREAM.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern long int ftell (FILE *__stream) __wur;
/* Rewind to the beginning of STREAM.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern void rewind (FILE *__stream);
/* The Single Unix Specification, Version 2, specifies an alternative,
   more adequate interface for the two functions above which deal with
   file offset.  `long int' is not the right type.  These definitions
   are originally defined in the Large File Support API.  */
#if defined __USE_LARGEFILE || defined __USE_XOPEN2K
# ifndef __USE_FILE_OFFSET64
/* Seek to a certain position on STREAM.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fseeko (FILE *__stream, __off_t __off, int __whence);
/* Return the current position of STREAM.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern __off_t ftello (FILE *__stream) __wur;
# else
#  ifdef __REDIRECT
extern int __REDIRECT (fseeko,
                       (FILE *__stream, __off64_t __off, int __whence),
                       fseeko64);
extern __off64_t __REDIRECT (ftello, (FILE *__stream), ftello64);
#  else
#   define fseeko fseeko64
#   define ftello ftello64
#  endif
# endif
#endif
#ifndef __USE_FILE_OFFSET64
/* Get STREAM's position.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
/* Set STREAM's position.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int fsetpos (FILE *__stream, const fpos_t *__pos);
#else
# ifdef __REDIRECT
extern int __REDIRECT (fgetpos, (FILE *__restrict __stream,
                                 fpos_t *__restrict __pos), fgetpos64);
extern int __REDIRECT (fsetpos,
                       (FILE *__stream, const fpos_t *__pos), fsetpos64);
# else
#  define fgetpos fgetpos64
#  define fsetpos fsetpos64
# endif
#endif
#ifdef __USE_LARGEFILE64
extern int fseeko64 (FILE *__stream, __off64_t __off, int __whence);
extern __off64_t ftello64 (FILE *__stream) __wur;
extern int fgetpos64 (FILE *__restrict __stream, fpos64_t *__restrict __pos);
extern int fsetpos64 (FILE *__stream, const fpos64_t *__pos);
#endif
/* Clear the error and EOF indicators for STREAM.  */
extern void clearerr (FILE *__stream) __THROW;
/* Return the EOF indicator for STREAM.  */
extern int feof (FILE *__stream) __THROW __wur;
/* Return the error indicator for STREAM.  */
extern int ferror (FILE *__stream) __THROW __wur;
#ifdef __USE_MISC
/* Faster versions when locking is not required.  */
extern void clearerr_unlocked (FILE *__stream) __THROW;
extern int feof_unlocked (FILE *__stream) __THROW __wur;
extern int ferror_unlocked (FILE *__stream) __THROW __wur;
#endif
/* Print a message describing the meaning of the value of errno.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern void perror (const char *__s);
/* Provide the declarations for `sys_errlist' and `sys_nerr' if they
   are available on this system.  Even if available, these variables
   should not be used directly.  The `strerror' function provides
   all the necessary functionality.  */
#include <bits/sys_errlist.h>
#ifdef        __USE_POSIX
/* Return the system file descriptor for STREAM.  */
extern int fileno (FILE *__stream) __THROW __wur;
#endif /* Use POSIX.  */
#ifdef __USE_MISC
/* Faster version when locking is not required.  */
extern int fileno_unlocked (FILE *__stream) __THROW __wur;
#endif
#ifdef __USE_POSIX2
/* Create a new stream connected to a pipe running the given command.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern FILE *popen (const char *__command, const char *__modes) __wur;
/* Close a stream opened by popen and return the status of its child.
   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern int pclose (FILE *__stream);
#endif
#ifdef        __USE_POSIX
/* Return the name of the controlling terminal.  */
extern char *ctermid (char *__s) __THROW;
#endif /* Use POSIX.  */
#if (defined __USE_XOPEN && !defined __USE_XOPEN2K) || defined __USE_GNU
/* Return the name of the current user.  */
extern char *cuserid (char *__s);
#endif /* Use X/Open, but not issue 6.  */
#ifdef        __USE_GNU
struct obstack;                        /* See <obstack.h>.  */
/* Write formatted output to an obstack.  */
extern int obstack_printf (struct obstack *__restrict __obstack,
                           const char *__restrict __format, ...)
     __THROWNL __attribute__ ((__format__ (__printf__, 2, 3)));
extern int obstack_vprintf (struct obstack *__restrict __obstack,
                            const char *__restrict __format,
                            __gnuc_va_list __args)
     __THROWNL __attribute__ ((__format__ (__printf__, 2, 0)));
#endif /* Use GNU.  */
#ifdef __USE_POSIX199506
/* These are defined in POSIX.1:1996.  */
/* Acquire ownership of STREAM.  */
extern void flockfile (FILE *__stream) __THROW;
/* Try to acquire ownership of STREAM but do not block if it is not
   possible.  */
extern int ftrylockfile (FILE *__stream) __THROW __wur;
/* Relinquish the ownership granted for STREAM.  */
extern void funlockfile (FILE *__stream) __THROW;
#endif /* POSIX */
#if defined __USE_XOPEN && !defined __USE_XOPEN2K && !defined __USE_GNU
/*  X/Open Issues 1-5 required getopt to be declared in this
   header.  It was removed in Issue 6.  GNU follows Issue 6.  */
# include <bits/getopt_posix.h>
#endif
/* Slow-path routines used by the optimized inline functions in
   bits/stdio.h.  */
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);
/* If we are compiling with optimizing read this file.  It contains
   several optimizing inline functions and macros.  */
#ifdef __USE_EXTERN_INLINES
# include <bits/stdio.h>
#endif
#if __USE_FORTIFY_LEVEL > 0 && defined __fortify_function
# include <bits/stdio2.h>
#endif
#ifdef __LDBL_COMPAT
# include <bits/stdio-ldbl.h>
#endif
__END_DECLS
#endif /* <stdio.h> included.  */

int main() {
   // printf() displays the string inside quotation
   printf("Hello, World!");
   return 0;
}