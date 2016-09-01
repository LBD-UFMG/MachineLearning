#ifndef MACHINELEARNING_UTIL_STATUS_H_
#define MACHINELEARNING_UTIL_STATUS_H_
#include <string>

/**
 * \file status.h
 * \brief Header defining the globally used error codes in this package.
 */

/**
 * Basic objects to be used by all machine learning algorithms.
 */
namespace util {
/** This is the namespace dedicated to error detection. In principle, it should
 * only be used here, as this is the only generic error handling structure we
 * have.
 */
namespace error {
/** \brief Global collection of error codes.
 *
 * This collection of error codes must be used to handle any possible scenario
 * that causes an otherwise unexpected execution flow. As our potential error
 * situations increase, so should this enum class. NEVER delete any error code.
 * If we decide, we will mark it as deprecated. This should keep the code from
 * getting broken by too many alterations to this list.
 */
enum class Code {
  OK = 0,      /** The only error free indicator. */
  UNKNOWN = 1, /** Something unforeseen happened. */
  INVALID_ARGUMENT =
      2, /** The provided argument is outside the method's domain. */
};

/** \brief Returns the name of the error specified by the argument.
 *  \param code the error code that needs to be translated.
 *  \return The translated name of the error code.
 */
std::string ErrorName(const Code& code);

}  // namespace error

/**
 * \brief Encapsulates error codes and messages.
 *
 * This class is a wrapper around the previous `error::Code` enum. By providing
 * default objects for common scenarios and the possibility of including error
 * messages, this should be the go to class to use wherever executions can fail
 * by any possible means. Example:
 * \code
 * Status IsSmallerThan5(int n) {
 *  if(n < 5) {
 *    return Status();
 *  }
 *  std::stringstream error_string;
 *  error_string << n << " is greater than or equal to 5";
 *  return Status(error::Code::INVALID_ARGUMENT, error_string.str());
 * }
 * \endcode
 */
class Status {
 public:
  /** Initializes a default status with OK code. */
  Status();

  /** Initializes a status object with the specified error code and message. */
  Status(error::Code error_code, const std::string& error_message);

  /** Copies the contents on the argument into the constructed object. */
  Status(const Status& status);

  /** Determines if the calling status is OK or not.
   * \return True if calling object is OK, false otherwise.
   */
  bool ok() const {
    return error_code_ == error::Code::OK;
  }

  /** \brief Accessor method for the underlying error code. */
  const error::Code error_code() const {
    return error_code_;
  }

  /** \brief Accessor method for the underlying error message. */
  const std::string& error_message() const {
    return error_message_;
  }

  /** Builds a string representation of the object.
   * \return The string representating the calling object.
   */
  const std::string ToString() const;

 protected:
  /** The error code contained by the object. */
  error::Code error_code_;
  /** The helpful error message associated with the code. */
  std::string error_message_;
};

}  // namespace util

#endif
