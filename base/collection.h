

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
  virtual const Point* GetPoint(unsigned int point_id) const = 0;

  /** Creates a std::vector with all the possible values of
   * the labels in the collection.
   * \param feature_values A `std::vector` structure that will
   * store all possible label values in the collection.
   */
  virtual void GetLabels(std::vector<double> *label_values) const = 0;

  /** Returns the label value of the specified point
   * the labels in the collection.
   * \param point_id The point of interest.
   * \return Label value of the desired point.
   */
  virtual double GetLabel(unsigned int point_id) const = 0;
};

}  // namespace base

#endif
