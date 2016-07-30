#ifndef  _MACHINELEARNING_BASE_LEARNER_H_ 
#define  _MACHINELEARNING_BASE_LEARNER_H_

#include <vector>

namespace base {

/**
 * Base class for all learning algorithm implementations.
 */
class Learner{

  public:

    /**
     * \brief Standard destructor.
     */
    virtual ~Learner();

    /**
     * Train the learner with a given dataset
     * \param X A pointer object of Collection
     */
    virtual void Train(/*const Collection *X*/);

    /**
     * Predicts the labels of the instances of X based on the fitted model
     * \return Instance labels
     */
    virtual void Predict(/*const Collection *X,*/ std::vector<double> &prediction) = 0;

    /**
     *  Returns the predicted probability distribution of each instance in X
     *  over all possible classes.
     *  \param X
     *  \param distribution
     */
    virtual void PredictProbability(/*const Collection *X,*/
                              std::vector<std::vector<double> > &distribution) = 0;
};

} // namespace base

#endif