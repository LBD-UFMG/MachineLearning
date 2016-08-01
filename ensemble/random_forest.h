#ifndef _MACHINELEARNING_ENSEMBLE_RANDOM_FOREST_H_
#define _MACHINELEARNING_ENSEMBLE_RANDOM_FOREST_H_

#include "tree/tree.h"
#include "base/learner.h"

namespace ensemble {
/**
 * Base class for Random Forest Classification and Regression algorithms.
 */
class RandomForest : public base::Learner{
  
  public:
    
    /**
     * Standard Constructor.
     * \param tree_count Number of trees.
     * \param thread_count Number of threads.
     */
    RandomForest(int tree_count, int thread_count);

    /**
     * \brief Standard destructor.
     */
    ~RandomForest();

    /**
     * Train the learner with a given dataset.
     * \param X A pointer object of Collection.
     */  
    void Train(/*const Collection *X*/);

    /**
     * Compute the out-of-bag score that represents the prediction
     * for the entire set of samples in the oob.
     * \return oob score
     */
  // double OobScore();

    /**
     * Compute the out-of-bag score that represents the prediction 
     * for each sample in the oob.
     * \param document_score Score of each out-of-bag sample
     */
   // void OobScoreSample(std::map<int, double> *sample_score); 

  protected:
    std::vector<std::unique_ptr<Tree> > trees_;
    int threads_;

};


} //namespace ensemble
#endif
