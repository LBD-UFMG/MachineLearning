#ifndef MACHINELEARNING_TREE_CRITERION_HPP
#define MACHINELEARNING_TREE_CRITERION_HPP

#include <math.h>

namespace tree {

/**
 * @brief Base class that defines the many criterious of splitting.
 *
 * This interface provides some methods that are used to compute the impurity of a given Node object.
 * Some impurity measures are Gini, Entrophy and Missclassification Error Rate for classification problens and MSE for regression
 * problems.
 */
class CriterionInterface {
protected:
  /**
   * @brief default constructor.
   */
  CriterionInterface() {}

  /**
   * @brief Compute the Gini index impurity measure for the given node.
   * @param node contains the representation of points that will be used to compute the impurity.
   * @return the impurity of the data in the given node.
   */
  virtual double GiniImpurityMeasure(const Node & node) const = 0;

  /**
   * @brief Compute the Entropy measure error given the data of a given node.
   * @param node is the data representation of points used to compute the impurity measure.
   * @return the impurity of the data in the given node.
   */
  virtual double EntropyImpurityMeasure(const Node & node) const = 0;

  /**
   * @brief Compute the Miss Classification Error as the impurity measure of a given node.
   * @param node is the data representation of points used to compute the impurity measure.
   * @return the impurity of the data in the given node.
   */
  virtual double MissClassificationError(const Node & node) const = 0;

  /**
   * @brief Compute the Information Gain, which is the maximization of the gain using Entropy as the impurity measure.
   * @param node is the data representation of points used to compute the impurity measure.
   * @return the gain of information using entropy for the given node.
   */
  virtual double InformationGain(const Node & node) const = 0;

  /**
   * @brief Compute the Gain using the Weighted Average Gini Index, which is the maximization using gini as the impurity
   * measure.
   * @param node is the data representation of points used to compute the impurity measure.
   * @return the gain using weighted average gini index for the given node.
   */
  virtual double WeightedAverageGiniIndex(const Node & node) const = 0;

  /**
   * @brief Compute the maximization of the gain when considering the maximization of Weighted Average Miss.
   * Classification Error.
   * @param node is the data representation of poinst used to compute the impurity measure.
   * @return the gain using weighted average miss classification error for the given node.
   */
  virtual double WeightedAverageMissClassificationError(const Node & node) const = 0;

};

} // namespace tree

#endif //MACHINELEARNING_TREE_CRITERION_HPP
