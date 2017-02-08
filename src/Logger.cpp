#include "Logger.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cassert>

#include "Window.h"

static bool terminalOutputEnabled{ true };
static bool logfileOutputEnabled{ true };

#define PREFERRED_LINE_LENGTH (80)

void Logger::Log(const char *format, ...)
{
	static char lineBuffer[1024] = {0};
	va_list arg;
	va_start(arg, format);
	vsprintf(lineBuffer, format, arg);
	va_end(arg);

	if (terminalOutputEnabled)
	{
		std::cout << lineBuffer << std::endl;
	}

	if (logfileOutputEnabled)
	{
		static std::ofstream logFile{ "rendeer.log" };
		logFile << lineBuffer << std::endl;
	}
}

void Logger::Log(const std::string& message)
{
	Log(message.c_str());
}

void Logger::LogPadded(const char *message, char padding)
{
	static char line[PREFERRED_LINE_LENGTH + 1] = {0};

	std::memset(line, padding, PREFERRED_LINE_LENGTH);

	int length = static_cast<int>(strlen(message));
	assert(length < 80);
	int start = (PREFERRED_LINE_LENGTH / 2) - (length / 2);
	int end = start + length;

	for (int i = start; i != end; ++i)
	{
		line[i] = message[i - start];
	}

	if (start > 1) line[start - 1] = ' ';
	if (end < PREFERRED_LINE_LENGTH - 1) line[end] = ' ';

	Log(line);
}

void Logger::LogPadded(const std::string& message, char padding)
{
	LogPadded(message.c_str(), padding);
}

void Logger::Heading(const std::string& heading)
{
	HorizontalDivider('=');
	LogPadded(heading, '-');
	HorizontalDivider('=');
}

void Logger::Subheading(const std::string& subheading)
{
	EmptyLine();
	LogPadded(subheading, '-');
}

void Logger::HorizontalDivider(char charToUse)
{
	static char divider[PREFERRED_LINE_LENGTH + 1] = {0};
	std::memset(divider, charToUse, PREFERRED_LINE_LENGTH);
	Log(divider);
}

void Logger::EmptyLine()
{
	Log("");
}

void Logger::LogTimestamp()
{
	// TODO: When a timer exists, also measure milliseconds, etc.
	time_t currentTime = time(0);
	tm *localTime = localtime(&currentTime);
	
	std::stringstream timestream;
	timestream
		<< "Current time: "
		<< std::setfill('0') << std::setw(2) << (localTime->tm_hour) << ":"
		<< std::setfill('0') << std::setw(2) << (localTime->tm_min) << ":"
		<< std::setfill('0') << std::setw(2) << (localTime->tm_sec);

	Log(timestream.str());
}

const char *Logger::BoolToString(bool variable)
{
	return (variable) ? "enabled" : "disabled";
}

void Logger::SetTerminalOutputEnabled(bool enabled)
{
	terminalOutputEnabled = enabled;
}

void Logger::SetLogFileOutputEnabled(bool enabled)
{
	logfileOutputEnabled = enabled;
}
