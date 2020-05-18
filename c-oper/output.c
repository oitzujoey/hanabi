#endif /* <stdio.h> included.  */

__END_DECLS

#endif
#if __USE_FORTIFY_LEVEL > 0 && defined __fortify_function
#endif
#ifdef __USE_EXTERN_INLINES
   several optimizing inline functions and macros.  */
/* If we are compiling with optimizing read this file.  It contains

#endif
   header.  It was removed in Issue 6.  GNU follows Issue 6.  */
/*  X/Open Issues 1-5 required getopt to be declared in this
#if defined __USE_XOPEN && !defined __USE_XOPEN2K && !defined __USE_GNU

#endif /* POSIX */
extern void funlockfile (FILE *__stream) __THROW;
/* Relinquish the ownership granted for STREAM.  */

extern int ftrylockfile (FILE *__stream) __THROW __wur;
   possible.  */
/* Try to acquire ownership of STREAM but do not block if it is not

extern void flockfile (FILE *__stream) __THROW;
/* Acquire ownership of STREAM.  */

/* These are defined in POSIX.1:1996.  */
#ifdef __USE_POSIX199506


#endif /* Use GNU.  */
     __THROWNL __attribute__ ((__format__ (__printf__, 2, 0)));
			    _G_va_list __args)
			    const char *__restrict __format,
extern int obstack_vprintf (struct obstack *__restrict __obstack,
     __THROWNL __attribute__ ((__format__ (__printf__, 2, 3)));
			   const char *__restrict __format, ...)
extern int obstack_printf (struct obstack *__restrict __obstack,
/* Write formatted output to an obstack.  */

struct obstack;			/* See <obstack.h>.  */
#ifdef	__USE_GNU


#endif /* Use X/Open, but not issue 6.  */
extern char *cuserid (char *__s);
/* Return the name of the current user.  */
#if (defined __USE_XOPEN && !defined __USE_XOPEN2K) || defined __USE_GNU


#endif /* Use POSIX.  */
extern char *ctermid (char *__s) __THROW;
/* Return the name of the controlling terminal.  */
#ifdef	__USE_POSIX


#endif
extern int pclose (FILE *__stream);
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Close a stream opened by popen and return the status of its child.

extern FILE *popen (const char *__command, const char *__modes) __wur;
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Create a new stream connected to a pipe running the given command.
#ifdef __USE_POSIX2


#endif
extern int fileno_unlocked (FILE *__stream) __THROW __wur;
/* Faster version when locking is not required.  */
#ifdef __USE_MISC

#endif /* Use POSIX.  */
extern int fileno (FILE *__stream) __THROW __wur;
/* Return the system file descriptor for STREAM.  */
#ifdef	__USE_POSIX


   all the necessary functionality.  */
   should not be used directly.  The `strerror' function provides
   are available on this system.  Even if available, these variables
/* Provide the declarations for `sys_errlist' and `sys_nerr' if they

extern void perror (const char *__s);
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Print a message describing the meaning of the value of errno.


#endif
extern int ferror_unlocked (FILE *__stream) __THROW __wur;
extern int feof_unlocked (FILE *__stream) __THROW __wur;
extern void clearerr_unlocked (FILE *__stream) __THROW;
/* Faster versions when locking is not required.  */
#ifdef __USE_MISC

extern int ferror (FILE *__stream) __THROW __wur;
/* Return the error indicator for STREAM.  */
extern int feof (FILE *__stream) __THROW __wur;
/* Return the EOF indicator for STREAM.  */
extern void clearerr (FILE *__stream) __THROW;
/* Clear the error and EOF indicators for STREAM.  */

#endif
extern int fsetpos64 (FILE *__stream, const fpos64_t *__pos);
extern int fgetpos64 (FILE *__restrict __stream, fpos64_t *__restrict __pos);
extern __off64_t ftello64 (FILE *__stream) __wur;
extern int fseeko64 (FILE *__stream, __off64_t __off, int __whence);
#ifdef __USE_LARGEFILE64

#endif
# endif
# else
		       (FILE *__stream, const fpos_t *__pos), fsetpos64);
extern int __REDIRECT (fsetpos,
				 fpos_t *__restrict __pos), fgetpos64);
extern int __REDIRECT (fgetpos, (FILE *__restrict __stream,
# ifdef __REDIRECT
#if defined __USE_UNIX98 || defined __USE_XOPEN2K#endifextern int fsetpos (FILE *__stream, const fpos_t *__pos);
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Set STREAM's position.
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Get STREAM's position.
#ifndef __USE_FILE_OFFSET64

#endif
# endif
#  endif
#  else
extern __off64_t __REDIRECT (ftello, (FILE *__stream), ftello64);
		       fseeko64);
		       (FILE *__stream, __off64_t __off, int __whence),
extern int __REDIRECT (fseeko,
#  ifdef __REDIRECT
# else
extern __off_t ftello (FILE *__stream) __wur;
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Return the current position of STREAM.
extern int fseeko (FILE *__stream, __off_t __off, int __whence);
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Seek to a certain position on STREAM.
# ifndef __USE_FILE_OFFSET64
#if defined __USE_LARGEFILE || defined __USE_XOPEN2K

   are originally defined in the Large File Support API.  */
   file offset.  `long int' is not the right type.  These definitions
   more adequate interface for the two functions above which deal with
/* The Single Unix Specification, Version 2, specifies an alternative,

extern void rewind (FILE *__stream);
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Rewind to the beginning of STREAM.
extern long int ftell (FILE *__stream) __wur;
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Return the current position of STREAM.
extern int fseek (FILE *__stream, long int __off, int __whence);
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Seek to a certain position on STREAM.


#endif
			       size_t __n, FILE *__restrict __stream);
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
			      size_t __n, FILE *__restrict __stream) __wur;
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
   therefore not marked with __THROW.  */
   or due to the implementation they are cancellation points and
   cancellation point.  But due to similarity with an POSIX interface
   These functions are not part of POSIX and therefore no official

/* Faster versions when locking is not necessary.
#ifdef __USE_MISC

#endif
			   FILE *__restrict __stream);
extern int fputs_unlocked (const char *__restrict __s,
   therefore not marked with __THROW.  */
   or due to the implementation it is a cancellation point and
   cancellation point.  But due to similarity with an POSIX interface
   This function is not part of POSIX and therefore no official

/* This function does the same as `fputs' but does not lock the stream.
#ifdef __USE_GNU

		      size_t __n, FILE *__restrict __s);
extern size_t fwrite (const void *__restrict __ptr, size_t __size,
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Write chunks of generic data to STREAM.
		     size_t __n, FILE *__restrict __stream) __wur;
extern size_t fread (void *__restrict __ptr, size_t __size,
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Read chunks of generic data from STREAM.


extern int ungetc (int __c, FILE *__stream);
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Push a character back onto the input buffer of STREAM.


extern int puts (const char *__s);
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Write a string, followed by a newline, to stdout.

extern int fputs (const char *__restrict __s, FILE *__restrict __stream);
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Write a string to STREAM.


#endif
			    FILE *__restrict __stream) __wur;
			    size_t *__restrict __n,
extern _IO_ssize_t getline (char **__restrict __lineptr,
   therefore not marked with __THROW.  */
   or due to the implementation it is a cancellation point and
   cancellation point.  But due to similarity with an POSIX interface
   This function is not part of POSIX and therefore no official

/* Like `getdelim', but reads up to a newline.

			     FILE *__restrict __stream) __wur;
			     size_t *__restrict __n, int __delimiter,
extern _IO_ssize_t getdelim (char **__restrict __lineptr,
			       FILE *__restrict __stream) __wur;
			       size_t *__restrict __n, int __delimiter,
extern _IO_ssize_t __getdelim (char **__restrict __lineptr,
   therefore not marked with __THROW.  */
   or due to the implementation they are cancellation points and
   cancellation point.  But due to similarity with an POSIX interface
   These functions are not part of POSIX and therefore no official

   null terminator), or -1 on error or EOF.
   necessary.  Returns the number of characters read (not including the
   NULL), pointing to *N characters of space.  It is realloc'd as
   (and null-terminate it). *LINEPTR is a pointer returned from malloc (or
/* Read up to (and including) a DELIMITER from STREAM into *LINEPTR
#if defined __USE_XOPEN2K8 || __GLIBC_USE (LIB_EXT2)


#endif
			     FILE *__restrict __stream) __wur;
extern char *fgets_unlocked (char *__restrict __s, int __n,
   therefore not marked with __THROW.  */
   or due to the implementation it is a cancellation point and
   cancellation point.  But due to similarity with an POSIX interface
   This function is not part of POSIX and therefore no official

/* This function does the same as `fgets' but does not lock the stream.
#ifdef __USE_GNU

#endif
extern char *gets (char *__s) __wur __attribute_deprecated__;
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

   explicitly using an old ISO C, Unix, or POSIX standard.
   from the _GNU_SOURCE feature list.  It remains available when
   removed from ISO C11 and ISO C++14, and we have also removed it
   This function is impossible to use safely.  It has been officially

/* Get a newline-terminated string from stdin, removing the newline.
#if __GLIBC_USE (DEPRECATED_GETS)

     __wur;
extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Get a newline-terminated string of finite length from STREAM.


#endif
extern int putw (int __w, FILE *__stream);
/* Write a word (int) to STREAM.  */

extern int getw (FILE *__stream);
/* Get a word (int) from STREAM.  */
    || (defined __USE_XOPEN && !defined __USE_XOPEN2K)
#if defined __USE_MISC \


#endif /* Use POSIX.  */
extern int putchar_unlocked (int __c);
extern int putc_unlocked (int __c, FILE *__stream);
   marked with __THROW.  */
   These functions are possible cancellation points and therefore not

/* These are defined in POSIX.1:1996.
#ifdef __USE_POSIX199506

#endif /* Use MISC.  */
extern int fputc_unlocked (int __c, FILE *__stream);
   therefore not marked with __THROW.  */
   or due to the implementation it is a cancellation point and
   cancellation point.  But due to similarity with an POSIX interface
   This function is not part of POSIX and therefore no official

/* Faster version when locking is not necessary.
#ifdef __USE_MISC

   so we always do the optimization for it.  */
/* The C standard explicitly says this can be a macro,

extern int putchar (int __c);
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Write a character to stdout.

extern int putc (int __c, FILE *__stream);
extern int fputc (int __c, FILE *__stream);
   marked with __THROW.  */
   These functions is a possible cancellation point and therefore not

   marked with __THROW.
   These functions are possible cancellation points and therefore not

/* Write a character to STREAM.


#endif /* Use MISC.  */
extern int fgetc_unlocked (FILE *__stream);
   therefore not marked with __THROW.  */
   or due to the implementation it is a cancellation point and
   cancellation point.  But due to similarity with an POSIX interface
   This function is not part of POSIX and therefore no official

/* Faster version when locking is not necessary.
#ifdef __USE_MISC

#endif /* Use POSIX.  */
extern int getchar_unlocked (void);
extern int getc_unlocked (FILE *__stream);
   marked with __THROW.  */
   These functions are possible cancellation points and therefore not

/* These are defined in POSIX.1:1996.
#ifdef __USE_POSIX199506

   optimization for it.  */
/* The C standard explicitly says this is a macro, so we always do the

extern int getchar (void);
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Read a character from stdin.

extern int getc (FILE *__stream);
extern int fgetc (FILE *__stream);
   marked with __THROW.  */
   These functions are possible cancellation points and therefore not

/* Read a character from STREAM.


#endif /* Use ISO C9x.  */
# endif
#  endif
			     _G_va_list __arg) __THROW;
			     const char *__restrict __format,
extern int __isoc99_vsscanf (const char *__restrict __s,
			    _G_va_list __arg) __wur;
extern int __isoc99_vscanf (const char *__restrict __format,
			     _G_va_list __arg) __wur;
			     const char *__restrict __format,
extern int __isoc99_vfscanf (FILE *__restrict __s,
#  else
     __attribute__ ((__format__ (__scanf__, 2, 0)));
			    _G_va_list __arg), __isoc99_vsscanf)
			    const char *__restrict __format,
			   (const char *__restrict __s,
extern int __REDIRECT_NTH (vsscanf,
     __attribute__ ((__format__ (__scanf__, 1, 0))) __wur;
				_G_va_list __arg), __isoc99_vscanf)
extern int __REDIRECT (vscanf, (const char *__restrict __format,
     __attribute__ ((__format__ (__scanf__, 2, 0))) __wur;
		       __isoc99_vfscanf)
			const char *__restrict __format, _G_va_list __arg),
		       (FILE *__restrict __s,
extern int __REDIRECT (vfscanf,
   s, S or [.  */
   GNU extension which conflicts with valid %a followed by letter
/* For strict ISO C99 or POSIX compliance disallow %as, %aS and %a[
#  ifdef __REDIRECT
     && (defined __STRICT_ANSI__ || defined __USE_XOPEN2K)
     && (!defined __LDBL_COMPAT || !defined __REDIRECT) \
# if !defined __USE_GNU \

     __THROW __attribute__ ((__format__ (__scanf__, 2, 0)));
		    const char *__restrict __format, _G_va_list __arg)
extern int vsscanf (const char *__restrict __s,
/* Read formatted input from S into argument list ARG.  */

     __attribute__ ((__format__ (__scanf__, 1, 0))) __wur;
extern int vscanf (const char *__restrict __format, _G_va_list __arg)
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Read formatted input from stdin into argument list ARG.

     __attribute__ ((__format__ (__scanf__, 2, 0))) __wur;
		    _G_va_list __arg)
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Read formatted input from S into argument list ARG.
#ifdef	__USE_ISOC99

#endif
# endif
			    const char *__restrict __format, ...) __THROW;
extern int __isoc99_sscanf (const char *__restrict __s,
extern int __isoc99_scanf (const char *__restrict __format, ...) __wur;
			    const char *__restrict __format, ...) __wur;
extern int __isoc99_fscanf (FILE *__restrict __stream,
# else
			   __isoc99_sscanf);
				    const char *__restrict __format, ...),
extern int __REDIRECT_NTH (sscanf, (const char *__restrict __s,
		       __isoc99_scanf) __wur;
extern int __REDIRECT (scanf, (const char *__restrict __format, ...),
		       __isoc99_fscanf) __wur;
				const char *__restrict __format, ...),
extern int __REDIRECT (fscanf, (FILE *__restrict __stream,
   s, S or [.  */
   GNU extension which conflicts with valid %a followed by letter
/* For strict ISO C99 or POSIX compliance disallow %as, %aS and %a[
# ifdef __REDIRECT
    && (defined __STRICT_ANSI__ || defined __USE_XOPEN2K)
    && (!defined __LDBL_COMPAT || !defined __REDIRECT) \
#if defined __USE_ISOC99 && !defined __USE_GNU \

		   const char *__restrict __format, ...) __THROW;
extern int sscanf (const char *__restrict __s,
/* Read formatted input from S.  */
extern int scanf (const char *__restrict __format, ...) __wur;
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Read formatted input from stdin.
		   const char *__restrict __format, ...) __wur;
extern int fscanf (FILE *__restrict __stream,
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Read formatted input from STREAM.


#endif
     __attribute__ ((__format__ (__printf__, 2, 3)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 0)));
		     _G_va_list __arg)
extern int vdprintf (int __fd, const char *__restrict __fmt,
/* Write formatted output to a file descriptor.  */
#ifdef __USE_XOPEN2K8

#endif
     __THROWNL __attribute__ ((__format__ (__printf__, 2, 3))) __wur;
		     const char *__restrict __fmt, ...)
extern int asprintf (char **__restrict __ptr,
     __THROWNL __attribute__ ((__format__ (__printf__, 2, 3))) __wur;
		       const char *__restrict __fmt, ...)
extern int __asprintf (char **__restrict __ptr,
     __THROWNL __attribute__ ((__format__ (__printf__, 2, 0))) __wur;
		      _G_va_list __arg)
extern int vasprintf (char **__restrict __ptr, const char *__restrict __f,
   Store the address of the string in *PTR.  */
/* Write formatted output to a string dynamically allocated with `malloc'.
#if __GLIBC_USE (LIB_EXT2)

#endif
     __THROWNL __attribute__ ((__format__ (__printf__, 3, 0)));
		      const char *__restrict __format, _G_va_list __arg)
extern int vsnprintf (char *__restrict __s, size_t __maxlen,

     __THROWNL __attribute__ ((__format__ (__printf__, 3, 4)));
		     const char *__restrict __format, ...)
extern int snprintf (char *__restrict __s, size_t __maxlen,
/* Maximum chars of output to write in MAXLEN.  */
#if defined __USE_ISOC99 || defined __USE_UNIX98

		     _G_va_list __arg) __THROWNL;
extern int vsprintf (char *__restrict __s, const char *__restrict __format,
/* Write formatted output to S from argument list ARG.  */
extern int vprintf (const char *__restrict __format, _G_va_list __arg);
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Write formatted output to stdout from argument list ARG.
		     _G_va_list __arg);
extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Write formatted output to S from argument list ARG.

		    const char *__restrict __format, ...) __THROWNL;
extern int sprintf (char *__restrict __s,
/* Write formatted output to S.  */
extern int printf (const char *__restrict __format, ...);
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Write formatted output to stdout.
		    const char *__restrict __format, ...);
extern int fprintf (FILE *__restrict __stream,
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Write formatted output to STREAM.


#endif
extern void setlinebuf (FILE *__stream) __THROW;
/* Make STREAM line-buffered.  */

		       size_t __size) __THROW;
extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
   Else make it use SIZE bytes of BUF for buffering.  */
/* If BUF is NULL, make STREAM unbuffered.
#ifdef	__USE_MISC

		    int __modes, size_t __n) __THROW;
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
   else allocate an internal buffer N bytes long.  */
   If BUF is not NULL, use N bytes of it for buffering;
/* Make STREAM use buffering mode MODE.
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __THROW;
   Else make it use buffer BUF, of size BUFSIZ.  */
/* If BUF is NULL, make STREAM unbuffered.


#endif
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __THROW __wur;
   and the number of characters written on fflush or fclose.  */
   necessary.  *BUFLOC and *SIZELOC are updated with the buffer's location
/* Open a stream that writes into a malloc'd buffer that is expanded as

  __THROW __wur;
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
/* Create a new stream that refers to a memory buffer.  */
#if defined __USE_XOPEN2K8 || __GLIBC_USE (LIB_EXT2)

#endif
			  _IO_cookie_io_functions_t __io_funcs) __THROW __wur;
			  const char *__restrict __modes,
extern FILE *fopencookie (void *__restrict __magic_cookie,
   and uses the given functions for input and output.  */
/* Create a new stream that refers to the given magic cookie,
#ifdef	__USE_GNU

#endif
extern FILE *fdopen (int __fd, const char *__modes) __THROW __wur;
/* Create a new stream that refers to an existing system file descriptor.  */
#ifdef	__USE_POSIX

#endif
			FILE *__restrict __stream) __wur;
			const char *__restrict __modes,
extern FILE *freopen64 (const char *__restrict __filename,
		      const char *__restrict __modes) __wur;
extern FILE *fopen64 (const char *__restrict __filename,
#ifdef __USE_LARGEFILE64
#endif
# endif
# else
  __wur;
				   FILE *__restrict __stream), freopen64)
				   const char *__restrict __modes,
extern FILE *__REDIRECT (freopen, (const char *__restrict __filename,
  __wur;
				 const char *__restrict __modes), fopen64)
extern FILE *__REDIRECT (fopen, (const char *__restrict __filename,
# ifdef __REDIRECT
#if defined __USE_UNIX98 || defined __USE_XOPEN2K#endif		      FILE *__restrict __stream) __wur;
		      const char *__restrict __modes,
extern FILE *freopen (const char *__restrict __filename,
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Open a file, replacing an existing stream with it.
		    const char *__restrict __modes) __wur;
extern FILE *fopen (const char *__restrict __filename,
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Open a file and create a new stream for it.
#ifndef __USE_FILE_OFFSET64


#endif
extern int fcloseall (void);
   therefore not marked with __THROW.  */
   or due to the implementation it is a cancellation point and
   cancellation point.  But due to similarity with an POSIX interface
   This function is not part of POSIX and therefore no official

/* Close all streams.
#ifdef __USE_GNU

#endif
extern int fflush_unlocked (FILE *__stream);
   therefore not marked with __THROW.  */
   or due to the implementation it is a cancellation point and
   cancellation point.  But due to similarity with an POSIX interface
   This function is not part of POSIX and therefore no official

/* Faster versions when locking is not required.
#ifdef __USE_MISC

extern int fflush (FILE *__stream);
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Flush STREAM, or all streams if STREAM is NULL.
extern int fclose (FILE *__stream);
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Close STREAM.


#endif
     __THROW __attribute_malloc__ __wur;
extern char *tempnam (const char *__dir, const char *__pfx)
   is allocated by `malloc'.  */
   P_tmpdir is tried and finally "/tmp".  The storage for the filename
   If not and if DIR is not NULL, that value is checked.  If that fails,
   If it contains the name of a writable directory, that directory is used.
   as follows: First the environment variable "TMPDIR" is checked.
   if it is not NULL.  The directory to put this file in is searched for
/* Generate a unique temporary filename using up to five characters of PFX
#if defined __USE_MISC || defined __USE_XOPEN


#endif
extern char *tmpnam_r (char *__s) __THROW __wur;
   that it does not allow S to be NULL.  */
/* This is the reentrant variant of `tmpnam'.  The only difference is
#ifdef __USE_MISC

extern char *tmpnam (char *__s) __THROW __wur;
/* Generate a temporary filename.  */

#endif
extern FILE *tmpfile64 (void) __wur;
#ifdef __USE_LARGEFILE64

#endif
# endif
# else
extern FILE *__REDIRECT (tmpfile, (void), tmpfile64) __wur;
# ifdef __REDIRECT
#if defined __USE_UNIX98 || defined __USE_XOPEN2K#endifextern FILE *tmpfile (void) __wur;
#ifndef __USE_FILE_OFFSET64
   marked with __THROW.  */
   This function is a possible cancellation point and therefore not

/* Create a temporary file and open it read/write.

#endif
		     const char *__new) __THROW;
extern int renameat (int __oldfd, const char *__old, int __newfd,
/* Rename file OLD relative to OLDFD to NEW relative to NEWFD.  */
#ifdef __USE_ATFILE

extern int rename (const char *__old, const char *__new) __THROW;
/* Rename file OLD to NEW.  */
extern int remove (const char *__filename) __THROW;
/* Remove file FILENAME.  */

/* C89/C99 say they're macros.  Make them happy.  */
extern struct _IO_FILE *stderr;		/* Standard error output stream.  */
extern struct _IO_FILE *stdout;		/* Standard output stream.  */
extern struct _IO_FILE *stdin;		/* Standard input stream.  */
/* Standard streams.  */


   FILENAME_MAX	Maximum length of a filename.  */
   FOPEN_MAX	Minimum number of files that can be open at once.
   L_cuserid	How long an array to pass to `cuserid'.
   L_ctermid	How long an array to pass to `ctermid'.
		or tempnam (the two are separate).
		(and tempnam when it uses tmpnam's name space),
   TMP_MAX	The minimum number of unique filenames generated by tmpnam
   L_tmpnam	How long an array of chars must be to be passed to `tmpnam'.
/* Get the values:


#endif
/* Default path prefix for `tempnam' and `tmpnam'.  */
#if defined __USE_MISC || defined __USE_XOPEN


#endif
#ifdef __USE_GNU
   These values should not be changed.  */
/* The possibilities for the third argument to `fseek'.


#endif
#ifndef EOF
   Some things throughout the library rely on this being -1.  */
/* End of file character.


#endif
#ifndef BUFSIZ
/* Default buffer size.  */


/* The possibilities for the third argument to `setvbuf'.  */

#endif
typedef _G_fpos64_t fpos64_t;
#ifdef __USE_LARGEFILE64
#endif
typedef _G_fpos64_t fpos_t;
#if defined __USE_UNIX98 || defined __USE_XOPEN2K#endiftypedef _G_fpos_t fpos_t;
#ifndef __USE_FILE_OFFSET64
/* The type of the second argument to `fgetpos' and `fsetpos'.  */

#endif
# endif
typedef __ssize_t ssize_t;
# ifndef __ssize_t_defined
#ifdef __USE_XOPEN2K8

#endif
# endif
typedef __off64_t off64_t;
# if defined __USE_LARGEFILE64 && !defined __off64_t_defined
# endif
# endif
typedef __off64_t off_t;
# else
typedef __off_t off_t;
# ifndef __USE_FILE_OFFSET64
# ifndef __off_t_defined
#if defined __USE_UNIX98 || defined __USE_XOPEN2K


 */
 *	ISO C99 Standard: 7.19 Input/output	<stdio.h>
/*

   <http://www.gnu.org/licenses/>.  */
   License along with the GNU C Library; if not, see
   You should have received a copy of the GNU Lesser General Public

   Lesser General Public License for more details.
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   The GNU C Library is distributed in the hope that it will be useful,

   version 2.1 of the License, or (at your option) any later version.
   License as published by the Free Software Foundation; either
   modify it under the terms of the GNU Lesser General Public
   The GNU C Library is free software; you can redistribute it and/or

   This file is part of the GNU C Library.
   Copyright (C) 1991-2018 Free Software Foundation, Inc.
/* Define ISO C stdio on top of C++ iostreams.

int main() {
    printf("Hello, world!");
}