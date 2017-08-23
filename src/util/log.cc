#ifdef ROKID_LOG_ANDROID
#include <android/log.h>
#else

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <chrono>

#endif

#include <string>
#include <memory>

#include "rlog.h"

using std::shared_ptr;
using std::string;

namespace rokid {
    namespace log {

        Log *Log::instance_ = NULL;

        Log::Log() {
        }

        Log *Log::instance() {
            if (instance_ == NULL)
                instance_ = new Log();
            return instance_;
        }

        void Log::v(const char *tag, const char *fmt, ...) {
            va_list ap;
            va_start(ap, fmt);
            instance()->p(LogLevel::Verbose, tag, fmt, ap);
            va_end(ap);
        }

        void Log::d(const char *tag, const char *fmt, ...) {
            va_list ap;
            va_start(ap, fmt);
            instance()->p(LogLevel::Debug, tag, fmt, ap);
            va_end(ap);
        }

        void Log::i(const char *tag, const char *fmt, ...) {
            va_list ap;
            va_start(ap, fmt);
            instance()->p(LogLevel::Info, tag, fmt, ap);
            va_end(ap);
        }

        void Log::w(const char *tag, const char *fmt, ...) {
            va_list ap;
            va_start(ap, fmt);
            instance()->p(LogLevel::Warning, tag, fmt, ap);
            va_end(ap);
        }

        void Log::e(const char *tag, const char *fmt, ...) {
            va_list ap;
            va_start(ap, fmt);
            instance()->p(LogLevel::Error, tag, fmt, ap);
            va_end(ap);
        }

#ifdef ROKID_LOG_ANDROID
        static uint32_t AndroidLogLevels[] = {
            ANDROID_LOG_VERBOSE,
            ANDROID_LOG_DEBUG,
            ANDROID_LOG_INFO,
            ANDROID_LOG_WARN,
            ANDROID_LOG_ERROR
        };
#else
        static char PosixLogLevels[] = {
                'V',
                'D',
                'I',
                'W',
                'E'
        };
#endif

        shared_ptr<string> timestamp_str() {
            char buf[64];
            struct timeval tv;
            struct tm ltm;

            gettimeofday(&tv, NULL);
            localtime_r(&tv.tv_sec, &ltm);
            snprintf(buf, sizeof(buf), "%04d-%02d-%02d %02d:%02d:%02d.%ld",
                     ltm.tm_year + 1900, ltm.tm_mon, ltm.tm_mday,
                     ltm.tm_hour, ltm.tm_min, ltm.tm_sec,
                     tv.tv_usec);
            shared_ptr<string> res(new string(buf));
            return res;
        }

#ifdef ROKID_LOG_FILE
#define ENV_LOG_PATH "rokid_log_path"
#define LOG_FILE_PREFIX "rokid.log"
        shared_ptr<string> log_file_name() {
            const char* path = getenv(ENV_LOG_PATH);
            if (path == NULL || path[0] == '\0')
                path = ".";
            char buf[64];
            snprintf(buf, sizeof(buf), "%s/%s.%u", path, LOG_FILE_PREFIX, getpid());
            shared_ptr<string> res(new string(buf));
            return res;
        }
#endif

        void Log::p(LogLevel llevel, const char *tag, const char *fmt, va_list ap) {
            int32_t level = static_cast<int32_t>(llevel);
#ifdef ROKID_LOG_ANDROID
            __android_log_vprint(AndroidLogLevels[level], tag, fmt, ap);
#elif defined(ROKID_LOG_FILE)
            shared_ptr<string> fname = log_file_name();
            FILE* fp = fopen(fname->c_str(), "a+");
            if (fp == NULL)
                return;
            std::lock_guard<std::mutex> locker(mutex_);
            shared_ptr<string> ts = timestamp_str();
            fprintf(fp, "%c %s [%s] ",
                    PosixLogLevels[level],
                    ts->c_str(),
                    tag);
            vfprintf(fp, fmt, ap);
            fprintf(fp, "\n");
            fclose(fp);
#else  // posix log
            std::lock_guard<std::mutex> locker(mutex_);
            shared_ptr<string> ts = timestamp_str();
            printf("%c %u %s [%s] ",
                   PosixLogLevels[level],
                   getpid(),
                   ts->c_str(),
                   tag);
            vprintf(fmt, ap);
            printf("\n");
#endif
        }

    } // namespace log
} // namespace rokid
