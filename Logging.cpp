#include "Logging.h"

namespace logging {

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
  } // namespace logging::internal

  template <typename... Args>
  void Info(const LoggingTemplate& temp, const Args&... args) {
    std::ostringstream oss;
    internal::concatenate(oss, args...);

    std::string log = oss.str();

    std::cout << log << '\n';
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

} // namespace logging