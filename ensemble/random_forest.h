#ifndef _MACHINELEARNING_ENSEMBLE_RANDOM_FOREST_H_
#define _MACHINELEARNING_ENSEMBLE_RANDOM_FOREST_H_

#include "tree/tree.h"
// #include "base/learner.h"

namespace ensemble {
/**
 * Base class for Random Forest Classification and Regression algorithms.
 */
class RandomForest /*: public base::Learner */{
  
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
     * Trains the learner with a given dataset.
     * \param X A pointer object of Collection.
     */  
    void Train(/*const Collection *X*/);

  protected:
    std::vector<std::unique_ptr<Tree> > trees_;
    int threads_;

};


} //namespace ensemble
#endif
