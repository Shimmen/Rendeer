#pragma once

#include <string>
#include <memory>
#include <fstream>

namespace Logger
{
	void Log(const char *format, ...);
	void Log(const std::string& message);

	void LogPadded(const char *message, char padding);
	void LogPadded(const std::string& message, char padding);

	void Heading(const std::string& heading);
	void Subheading(const std::string& subheading);

	void HorizontalDivider(char charToUse);
	void EmptyLine();
	void LogTimestamp();


	const char *BoolToString(bool variable);

	void SetTerminalOutputEnabled(bool enabled);
	void SetLogFileOutputEnabled(bool enabled);


};

