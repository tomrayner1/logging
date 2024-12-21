#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace logging {

  struct LoggingTemplate {
    std::string filename;
    bool logToFile = false;
    std::string prefix;
  };

namespace globals {

  inline LoggingTemplate g_DefaultLoggingTemplate{};

} // namespace globals

namespace internal {
  template <typename T>
  std::string toString(const T& value);

  void concatenate(std::ostringstream& oss) {}

  template <typename T, typename... Args>
  void concatenate(std::ostringstream& oss, const T& first, const Args&... args);
} // namespace internal

  template <typename... Args>
  void Info(const LoggingTemplate& temp=globals::g_DefaultLoggingTemplate, const Args&... args);

  template <typename... Args>
  void Warn(const LoggingTemplate& temp=globals::g_DefaultLoggingTemplate, const Args&... args);

  template <typename... Args>
  void Error(const LoggingTemplate& temp=globals::g_DefaultLoggingTemplate, const Args&... args);

  template <typename... Args>
  void Debug(const LoggingTemplate& temp=globals::g_DefaultLoggingTemplate, const Args&... args);

} // namespace logging