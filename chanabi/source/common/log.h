
#ifndef LOG_H
#define LOG_H

void log_info(const char *function, const char *fmt, ...);
void log_warning(const char *function, const char *fmt, ...);
void log_error(const char *function, const char *fmt, ...);
void log_critical_error(const char *function, const char *fmt, ...);

#define info(fmt, ...) log_info(__func__, fmt, __VA_ARGS__)
#define warning(fmt, ...) log_warning(__func__, fmt, __VA_ARGS__)
#define error(fmt, ...) log_error(__func__, fmt, __VA_ARGS__)
#define critical_error(fmt, ...) log_critical_error(__func__, fmt, __VA_ARGS__)

#endif
