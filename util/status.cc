#include "status.h"

#include <sstream>

namespace util {

namespace error {
// Please keep this method updated.
std::string ErrorName(const Code& code) {
  switch (code) {
    case Code::OK:
      return "OK";
    case Code::UNKNOWN:
      return "UNKNOWN";
    case Code::INVALID_ARGUMENT:
      return "INVALID_ARGUMENT";
    default:
      return "UNKNOWN_ERROR_CODE";
  }
}
}  // namespace error

Status::Status() : Status(error::Code::OK, std::string()) {
}

Status::Status(error::Code error_code, const std::string& error_message)
    : error_code_(error_code), error_message_(error_message) {
}

Status::Status(const Status& status)
    : Status(status.error_code(), status.error_message()) {
}

const std::string Status::ToString() const {
  std::stringstream str_stream;
  str_stream << error::ErrorName(error_code_) << ", " << error_message_;
  return str_stream.str();
}

}  // namespace util
