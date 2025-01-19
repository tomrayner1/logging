#pragma once

#include <iostream>
#include <string>
#include <sstream>

#define TRACE(...) logging::Trace(__VA_ARGS__)
#define DEBUG(...) logging::Debug(__VA_ARGS__)
// #define DEBUGBREAK(...) logging::DebugBreak(__VA_ARGS__)
// #define DEBUG_BREAK(...) logging::DebugBreak(__VA_ARGS__)
#define INFO(...) logging::Info(__VA_ARGS__)
#define WARN(...) logging::Warn(__VA_ARGS__)
#define ERROR(...) logging::Error(__VA_ARGS__)
#define FATAL(...) logging::Fatal(__VA_ARGS__)

namespace logging {

  struct LoggingTemplate {
    std::string       prefix;
    bool prefixLevels = true;
    bool logToFile   = false;
    std::string     filename;
  };

  inline LoggingTemplate g_DefaultTemplate{};

  namespace _private {
    template <typename T>
    inline std::string toString(const T& value);

    inline void concatenate(std::ostringstream& oss) {}

    template <typename T, typename... Args>
    inline void concatenate(std::ostringstream& oss, const T& first, const Args&... args);

    template <typename... Args>
    inline void genericOut(std::string customPrefix, const LoggingTemplate& loggingTemplate, const Args&... args);
  } // namespace _private

  // TRACE, DEBUG, DEBUG_BREAK (same as debug), INFO, WARN, ERROR, FATAL

  template <typename... Args>
  void Trace(const Args&... args) {
    Trace(g_DefaultTemplate, args...);
  }

  template <typename... Args>
  void Debug(const Args&... args) {
    #ifdef _DEBUG
    Debug(g_DefaultTemplate, args...);
    #endif
  }

  template <typename... Args>
  void Info(const Args&... args) {
    Info(g_DefaultTemplate, args...);
  }

  template <typename... Args>
  void Warn(const Args&... args) {
    Warn(g_DefaultTemplate, args...);
  }

  template <typename... Args>
  void Error(const Args&... args) {
    Error(g_DefaultTemplate, args...);
  }

  template <typename... Args>
  void Fatal(const Args&... args) {
    Fatal(g_DefaultTemplate, args...);
  }

  template <typename... Args>
  void Trace(const LoggingTemplate& loggingTemplate, const Args&... args) {
    _private::genericOut("[TRACE] ", loggingTemplate, args...);
  }

  template <typename... Args>
  void Debug(const LoggingTemplate& loggingTemplate, const Args&... args) {
    #ifdef _DEBUG
    _private::genericOut("[DEBUG] ", loggingTemplate, args...);
    #endif
  }

  template <typename... Args>
  void Info(const LoggingTemplate& loggingTemplate, const Args&... args) {
    _private::genericOut("[INFO] ", loggingTemplate, args...);
  }

  template <typename... Args>
  void Warn(const LoggingTemplate& loggingTemplate, const Args&... args) {
    _private::genericOut("[WARN] ", loggingTemplate, args...);
  }

  template <typename... Args>
  void Error(const LoggingTemplate& loggingTemplate, const Args&... args) {
    _private::genericOut("[ERROR] ", loggingTemplate, args...);
  }

  template <typename... Args>
  void Fatal(const LoggingTemplate& loggingTemplate, const Args&... args) {
    _private::genericOut("[FATAL] ", loggingTemplate, args...);
  }

  namespace _private {
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
  } // namespace _private

} // namespace logging