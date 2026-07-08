#include "log.h"
#include <time.h>

static int log_level = LOG_TRACE;
static const char* level_names[] = {"TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"};

void log_set_level(int level){
    log_level = level;
}

void log_log(int level, const char *file, int line, const char *fmt, ...) {
    if(level < log_level) return;

    // 获取系统时间
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char time_buf[20];
    strftime(time_buf, sizeof(time_buf), "%H:%M:%S", t);

    // 格式化输出日志
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "%s %-5s %s:%d: ", time_buf, level_names[level], file, line);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    va_end(ap);
}