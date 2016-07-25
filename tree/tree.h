#ifndef _TREE_H__ 
#define _TREE_H__

#include "splitter.h"

#include <vector>

namespace tree {

/**
 * Base class for all Decision Tree implementations.
 */
class Tree{

  public:

    /**
     * \brief Standard destructor.
     */
    virtual ~Tree() { }

    /**
     * Builds the Decision Tree
     * \param X              An object of Collection
     * \param sample_weight  Weight of each sample in collection
     * \param feature_weight Weight of each feature 
     */
    virtual void Build(/*Collection X,*/
                        std::vector<double> &sample_weight, std::vector<double> &feature_weight) = 0;

    /**
     * Predicts the labels of the instances of X based on the fitted model
     * \return Instance labels
     */
    virtual std::vector<int> &Predict(/*Collectiin X*/) = 0;

    /**
     *  Returns the predicted probability distribution of each instance in X
     *  over all possible classes.
     *  \return Instace probability distribution
     */
    virtual std::vector<std::vector<double> > &PredictProba(/*Collection X*/) = 0;
};

} // namespace tree

#endif