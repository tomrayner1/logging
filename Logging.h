#pragma once

#include <iostream>
// #include <fstream>
#include <sstream>
#include <string>

namespace logging {

  // Allows for applications to create their own "loggers" which can be saved
  // to files independantly and can use a custom prefix.
  struct LoggingTemplate {
    std::string filename;
    bool logToFile = false;
    std::string prefix;
  };

namespace globals {

  // Serves as a default template that all logging functions wil use by default.
  // Can be changed by the application if wanted.
  //
  inline LoggingTemplate g_DefaultLoggingTemplate{};

} // namespace logging::globals

  template <typename... Args>
  void Info(const LoggingTemplate& temp=globals::g_DefaultLoggingTemplate, const Args&... args);

  template <typename... Args>
  void Warn(const LoggingTemplate& temp=globals::g_DefaultLoggingTemplate, const Args&... args);

  template <typename... Args>
  void Error(const LoggingTemplate& temp=globals::g_DefaultLoggingTemplate, const Args&... args);

  template <typename... Args>
  void Debug(const LoggingTemplate& temp=globals::g_DefaultLoggingTemplate, const Args&... args);

} // namespace logging