#pragma once

#include <stdarg.h>
#include <mutex>

namespace rokid {
namespace log {

enum class LogLevel {
	Verbose,
	Debug,
	Info,
	Warning,
	Error,
	MaxLogLevel
};

class Log {
public:
	static void v(const char* tag, const char* fmt, ...);

	static void d(const char* tag, const char* fmt, ...);

	static void i(const char* tag, const char* fmt, ...);

	static void w(const char* tag, const char* fmt, ...);

	static void e(const char* tag, const char* fmt, ...);

private:
	Log();

	static Log* instance();

	void p(LogLevel level, const char* tag, const char* fmt, va_list ap);

private:
	static Log* instance_;
	std::mutex mutex_;
};

} // namespace log
} // namespace rokid

#define KLOGV(tag, fmt, ...) rokid::log::Log::v(tag, fmt, ##__VA_ARGS__)

#define KLOGD(tag, fmt, ...) rokid::log::Log::d(tag, fmt, ##__VA_ARGS__)

#define KLOGI(tag, fmt, ...) rokid::log::Log::i(tag, fmt, ##__VA_ARGS__)

#define KLOGW(tag, fmt, ...) rokid::log::Log::w(tag, fmt, ##__VA_ARGS__)

#define KLOGE(tag, fmt, ...) rokid::log::Log::e(tag, fmt, ##__VA_ARGS__)

