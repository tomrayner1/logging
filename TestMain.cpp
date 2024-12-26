// Include the logging header
#include <logging.h>

int main() {
  using namespace lg;

  Trace("int main()", ';');
  Debug("debug mode is on :)");
  Info("Printing 42 as an integer: ", 42);
  Warn("Warning a boolean ", true, ", how cool.");
  Error(1.234);
  Fatal(700);

  return 0;
}