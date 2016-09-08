#ifndef MACHINELEARNING_BASE_COLLECTION_H_
#define MACHINELEARNING_BASE_COLLECTION_H_
#include <string>
#include <vector>
#include "point.h"


/**
 * \file collection.h
 * \brief Header defining the collection interface.
 */

/**
 * Basic objects to be used by all machine learning algorithms.
 */
namespace base {

/**
 * \brief Base class that defines methods to handle the input dataset
 *
 * This interface provides some methods to handle the input datasets.
 * For every new type of dataset we want to use, we must implement a
 * suitable concrete class to handle it.
 */
class Collection {
 public:
  /**
   * \brief Standard destructor.
   */
  virtual ~Collection();

  /** General accessor method for each point of the collection.
   * \param point_id The point of interest. Indexing is implementation
   * specific.
   * \return A pointer for the specified point in the collection.
   */
//  virtual *Point GetPoint(unsigned int point_id) const = 0;

  /** General accessor method for a `std::string` representation of 
   * each point of the collection.
   * \param point_id The point of interest. 
   * \return A `std::string` representation of the specified point.
   */
  virtual std::string GetStringPoint(unsigned int point_id) const = 0;

  /** Returns the value of a specified feature from a specified 
   * point of the collection.
   * \param point_id The point of interest. 
   * \param feature_id The feature of interest. 
   * \return The value of the feature of the specified point
   */
  virtual double GetPointFeatureValue(unsigned int point_id,
                   unsigned int feature_id) const = 0;

  /** Creates a std::vector with all the possible values of
   * the specified feature in the collection.
   * \param feature_id The point of interest. 
   * \param feature_values A `std::vector` structure that will
   * store all possible feature values in the collection.
   */
  virtual void GetFeatureValues(unsigned int feature_id, 
                 std::vector<double> *feature_values) const = 0;

  /**
   * \brief Returns the numbers of points in the collection.
   * \return Number of points.
   */
  virtual unsigned int GetPointsNumber() const = 0;

  /**
   * \brief Returns the numbers of features in the collection.
   * \return Number of features.
   */
  virtual unsigned int GetFeaturesNumber() const = 0;
};

}  // namespace base

#endif
