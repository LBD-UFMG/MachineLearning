#ifndef _MACHINELEARNING_ENSEMBLE_RANDOM_FOREST_H_
#define _MACHINELEARNING_ENSEMBLE_RANDOM_FOREST_H_

#include "tree/tree.h"

namespace ensemble {
/**
 * Base class for Random Forest Classification and Regression algorithms.
 */
class RandomForest {
 public:
  /**
   * \brief Standard destructor.
   */
  virtual ~RandomForest();

  /**
   * Compute the out-of-bag score that represents the prediction
   * for the entire set of samples in the oob.
   * \return oob score
   */
  virtual double OobScore() = 0;

  /**
   * Compute the out-of-bag score that represents the prediction 
   * for each sample in the oob.
   * \param tree_idx Index of the tree
   * \return oob score
   */
  virtual double OobScoreSample(const int tree_idx) = 0;


  /*
   * Builds the RandomForest.
   * \param thread Number of threads for paralel execution
   * \param tree Number of trees in the Forest
   */
  virtual void Build(/* Collection col, */ const int thread,
                     const int tree) = 0;

  /**
   * Predicts the labels of the instances of X based on a vote by
   * the trees of the forest, weighted by their probability estimates
   * \param Instance labels
   */
  virtual void Predict(/* Collection col, */
                       std::vector<int> *instance_label) = 0;

  /**
   * Returns the predicted probability distribution of each instance in X over
   * all possible classes. They are the mean predicted class
   * probabilities of the trees in the forest
   * \param Instance probability distribution
   */
  virtual void PredictProbability(/* Collection col, */
                                  std::vector<std::vector<double> >
                                      *instance_probability) = 0;
};

} //namespace ensemble
#endif
