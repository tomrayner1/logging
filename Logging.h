#pragma once

#include <iostream>
#include <string>
#include <sstream>

// lg is quicker to type than namespace logging
namespace lg {

  struct LoggingTemplate {
    std::string       prefix;
    bool prefixLevels = true;
    bool logToFile   = false;
    std::string     filename;
  };

  namespace globals {
    inline LoggingTemplate g_DefaultTemplate{};
  } // namespace logging::globals

  template <typename T>
  inline std::string toString(const T& value);

  inline void concatenate(std::ostringstream& oss) {}

  template <typename T, typename... Args>
  inline void concatenate(std::ostringstream& oss, const T& first, const Args&... args);

  template <typename... Args>
  inline void genericOut(std::string customPrefix, const LoggingTemplate& loggingTemplate, const Args&... args);

  // TRACE, DEBUG, DEBUG_BREAK (same as debug), INFO, WARN, ERROR, FATAL

  template <typename... Args>
  void Trace(const Args&... args) {
    Trace(globals::g_DefaultTemplate, args...);
  }

  template <typename... Args>
  void Debug(const Args&... args) {
    #ifdef _DEBUG
    Debug(globals::g_DefaultTemplate, args...);
    #endif
  }

  template <typename... Args>
  void Info(const Args&... args) {
    Info(globals::g_DefaultTemplate, args...);
  }

  template <typename... Args>
  void Warn(const Args&... args) {
    Warn(globals::g_DefaultTemplate, args...);
  }

  template <typename... Args>
  void Error(const Args&... args) {
    Error(globals::g_DefaultTemplate, args...);
  }

  template <typename... Args>
  void Fatal(const Args&... args) {
    Fatal(globals::g_DefaultTemplate, args...);
  }

  template <typename... Args>
  void Trace(const LoggingTemplate& loggingTemplate, const Args&... args) {
    genericOut("[TRACE] ", loggingTemplate, args...);
  }

  template <typename... Args>
  void Debug(const LoggingTemplate& loggingTemplate, const Args&... args) {
    #ifdef _DEBUG
    genericOut("[DEBUG] ", loggingTemplate, args...);
    #endif
  }

  template <typename... Args>
  void Info(const LoggingTemplate& loggingTemplate, const Args&... args) {
    genericOut("[INFO] ", loggingTemplate, args...);
  }

  template <typename... Args>
  void Warn(const LoggingTemplate& loggingTemplate, const Args&... args) {
    genericOut("[WARN] ", loggingTemplate, args...);
  }

  template <typename... Args>
  void Error(const LoggingTemplate& loggingTemplate, const Args&... args) {
    genericOut("[ERROR] ", loggingTemplate, args...);
  }

  template <typename... Args>
  void Fatal(const LoggingTemplate& loggingTemplate, const Args&... args) {
    genericOut("[FATAL] ", loggingTemplate, args...);
  }

  template <typename... Args>
  inline void genericOut(std::string customPrefix, const LoggingTemplate& loggingTemplate, const Args&... args) {
    std::ostringstream oss;
    concatenate(oss, args...);

    std::string message = oss.str();

    std::string prefix;

    if (loggingTemplate.prefixLevels) {
      prefix.append(customPrefix);
    }

    prefix.append(loggingTemplate.prefix);

    std::cout << prefix << message << '\n';
  }

  template <typename T>
  inline std::string toString(const T& value) {
      std::ostringstream oss;
      oss << value;
      return oss.str();
  }

  template <typename T, typename... Args>
  inline void concatenate(std::ostringstream& oss, const T& first, const Args&... args) {
      oss << toString(first);
      concatenate(oss, args...);
 }

} // namespace logging