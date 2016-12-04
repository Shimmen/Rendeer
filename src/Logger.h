#pragma once

#include <string>
#include <memory>
#include <fstream>

class Logger
{
public:

	static Logger& GetDefaultLogger();

	static std::string GetStateDescription(bool variable);

public:
	
	Logger(std::string logFilePath, bool logToTerminal);
	Logger();

	~Logger();

	void SetTerminalOutputEnabled(bool enabled);
	void SetPreferredLineLength(int length);

	void LogHeading(std::string heading) const;
	void LogSubheading(std::string subheading) const;
	void Log(std::string message) const;
	void LogHorizontalDivider(char charToUse) const;
	void LogEmptyLine() const;
	void LogTimestamp() const;

private:

	std::string GenerateHorizontalDivider(char charToUse, int length) const;

	// The output file stream, or null if not used by this instance
	std::unique_ptr<std::ofstream> logFileStream;

	bool terminalOutputEnabled{ true };
	int preferredLineLength{ 79 };

};

