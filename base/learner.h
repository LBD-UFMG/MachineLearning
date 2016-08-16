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
     * Train the learner with a given dataset.
     * \param X A pointer object of Collection.
     */
    virtual void Train(/*const Collection *X*/);

    /**
     * Predicts the labels of the instances of X based on the fitted model.
     * \param X           A pointer object of Collection.
     * \param prediction  Instances prediction.
     */
    virtual void Predict(/*const Collection *X,*/ std::vector<double> *prediction) = 0;

     /**
     * Predicts the labels of a point based on the fitted model.
     * \param point         A pointer object of Point.
     * \param prediction    Point prediction.
     */
    virtual double Predict(/*const Point *point,*/) const = 0;

    /**
     *  Returns the predicted probability distribution of each instance in X
     *  over all possible classes.
     *  \param X            A pointer object of Collection.
     *  \param distribution Instances probability distribution.
     */
    virtual void PredictProbability(/*const Collection *X,*/
                              std::vector<std::vector<double> > *distribution) = 0;

    /**
     *  Returns the predicted probability distribution of an point
     *  over all possible classes.
     *  \param point          A pointer object of Point.
     *  \param distribution   Point probability distribution.
     */
    virtual void PredictProbability(/*const Point *point,*/
                                  std::vector<double> *distribution) = 0;
};

} // namespace base

#endif