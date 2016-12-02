#include "Logger.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cassert>

/* static */ Logger& Logger::GetDefaultLogger()
{
	static Logger defaultLogger{ std::string("rendeer.log"), true };
	return defaultLogger;
}

/* static */ std::string Logger::GetStateDescription(bool variable)
{
	return (variable) ? "enabled" : "disabled";
}

Logger::Logger()
{
}

Logger::Logger(std::string logFilePath, bool logToTerminal)
	: terminalOutputEnabled{ logToTerminal }
{
	// Set up log file output stream
	try
	{
		logFileStream.reset(new std::ofstream(logFilePath.c_str()));
		logFileStream->exceptions(std::ofstream::failbit);
	}
	catch (std::ios_base::failure& failure)
	{
		std::cout
			<< "Error: could not open log file with name: \""
			<< logFilePath << "\" (error code " << failure.what() << "). "
			<< "Reason: " << failure.what() << "."
		<< std::endl;
	}
}

Logger::~Logger()
{
}

void Logger::SetTerminalOutputEnabled(bool enabled)
{
	this->terminalOutputEnabled = enabled;
}

void Logger::SetPreferredLineLength(int length)
{
	this->preferredLineLength = length;
}

void Logger::LogHeading(std::string heading) const
{
	LogHorizontalDivider('=');
	Log(heading);
	LogHorizontalDivider('=');
}

void Logger::LogSubheading(std::string subheading) const
{
	std::stringstream formattedSubheading;

	int subheadingLength = static_cast<int>(subheading.length());
	int remainingLength = preferredLineLength - subheadingLength;
	if (remainingLength > 0)
	{
		const char paddingChar = '-';
		int paddingOnEachSide = remainingLength / 2;

		// Subtract one from padding, since there is a space as padding as well
		std::string paddingLeft = GenerateHorizontalDivider(paddingChar, paddingOnEachSide - 1);
		std::string paddingRight = paddingLeft;

		// If the subheading has an uneven length, add one extra padding character to one side
		if (subheadingLength % 2 == 0)
		{
			paddingRight += paddingChar;
		}

		formattedSubheading
			<< paddingLeft << " "
			<< subheading
			<< " " << paddingRight;
	}

	LogEmptyLine();
	Log(formattedSubheading.str());
}

void Logger::Log(std::string message) const
{
	if (terminalOutputEnabled)
	{
		std::cout << message << std::endl;
	}

	if (logFileStream)
	{
		(*logFileStream) << message << std::endl;
	}
}

void Logger::LogHorizontalDivider(char charToUse) const
{
	std::string divider = GenerateHorizontalDivider(charToUse, this->preferredLineLength);
	Log(divider);
}

void Logger::LogEmptyLine() const
{
	Log("");
}

void Logger::LogTimestamp() const
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

std::string Logger::GenerateHorizontalDivider(char charToUse, int length) const
{
	assert(length >= 0);

	std::stringstream divider;

	int charactersLeft = length;
	while (charactersLeft-- > 0)
	{
		divider << charToUse;
	}

	return divider.str();
}

