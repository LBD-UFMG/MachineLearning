#ifndef MACHINELEARNING_BASE_POINTS_L2R_POINT_H_
#define MACHINELEARNING_BASE_POINTS_L2R_POINT_H_
#include <string>
#include <vector>

#include "base/point.h"

/**
 * \file learning_to_rank_point.h
 * \brief Header defining the multi-dimensional point interface
 * used in Learning to Rank tasks.
 */

/**
 * Basic objects to be used by all machine learning algorithms implementing
 * ranking functionalities.
 */
namespace base {
namespace points {

/**
 * \brief Learning to rank multi-dimensional object interface.
 *
 * This interface is the primitive input data type for the learning algorithms.
 * For every new type of object we want to learn from, we must implement a
 * suitable concrete class to handle it.
 */
class L2RPoint : public ::base::Point {
 public:
  /**
   * \brief Standard destructor.
   */
  ~L2RPoint();

  /** Returns the feature indexed by the received parameter. Indexing is 1
   * based, as is standard in Learning to Rank applications.
   * \brief Returns the value of the desired coordinate. Indexing is 1 based.
   * \param feature_id The coordinate of interest.
   * \return The value of the coordinate specified in the input.
   */
  double GetFeatureValue(unsigned feature_id) const;

  /** Returns the relevance of the calling object.
   * \return The relevance of the object.
   */
  double GetLabel() const;

  /** \brief Accessor method for the object's query value.
   */
  const std::string& query() const {
    return query_;
  }

  /** Builds a parsable `std::string` object that represents the underlying
   * object. Objects produced with this method must be usable to reconstruct the
   * `Point` that produced it.
   * \brief Builds a `std::string` representation of the object.
   * \return A `std::string` representation of the object.
   * \see Point::Initialize(const std::string& source)
   */
  std::string ToString() const;

  /** Parses the content of the received `std::string` into an internal
   * representation, which is implementation specific.
   * \brief Parses the `Point` encoded in the received `std::string`.
   * \param source The string representation of the object to be parsed.
   * \see Point::ToString()
   */
  void Initialize(const std::string& source);

 protected:
  double relevance_;
  std::string query_;
  std::vector<double> features_;
};

}  // namespace points
}  // namespace base

#endif
