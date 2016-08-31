#include "util/status.h"
#include <iostream>

namespace util {

class StatusTest : public Status {
 public:
  int RunAllTests() {
    error_code_ = error::Code::OK;
    if (!ok()) {
      std::cerr << "Expected an OK, got " << error::ErrorName(error_code_)
                << std::endl;
      return 1;
    }
    error_code_ = error::Code::INVALID_ARGUMENT;
    if (error_code() != error::Code::INVALID_ARGUMENT) {
      std::cerr << "Expected INVALID_ARGUMENT, got "
                << error::ErrorName(error_code_) << std::endl;
      return 1;
    }
    error_message_ = "All tests passed";
    return 0;
  }
};
}  // namespace util

int main() {
  util::StatusTest status_test;
  return status_test.RunAllTests();
}
