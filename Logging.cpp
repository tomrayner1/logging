#include "Logging.h"

namespace logging {

  template <typename... Args>
  void Info(const LoggingTemplate& temp, const Args&... args) {
    
  }

  template <typename... Args>
  void Warn(const LoggingTemplate& temp, const Args&... args) {

  }

  template <typename... Args>
  void Error(const LoggingTemplate& temp, const Args&... args) {

  }

  template <typename... Args>
  void Debug(const LoggingTemplate& temp, const Args&... args) {

  }

  namespace internal {
    void concatenate(std::ostringstream& oss) {}

    template <typename T>
    std::string toString(const T& value) {
      std::ostringstream oss;
      oss << value;
      return oss.str();
    }

    template <typename T, typename... Args>
    void concatenate(std::ostringstream& oss, const T& first, const Args&... args) {
      oss << logging::internal::toString(first);
      logging::internal::concatenate(oss, args...);
    }
  } // namespace internal

} // namespace logging