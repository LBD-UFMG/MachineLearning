#ifndef  _MACHINELEARNING_TREE_TREE_H__ 
#define  _MACHINELEARNING_TREE_TREE_H__

#include "splitter.h"
//#include "criterion.h"

#include <vector>

namespace tree {

/**
 * Base class for all Decision Tree implementations.
 */
class Tree{

  public:

    /**
     * Tree class constructor.
     * \param splitter      Splitter object.
     * \param criterion     Criterion object.
     * \param max_features    The maximum number of features used to create the tree.
     * \param max_depth     The maximum depth of the tree.
     * \param max_leaf_nodes  The maximum number of leaf nodes of the tree.
     * \param min_samples_leaf  The minimum number of samples per leaf.
     * \param min_samples_split The minimum number of samples per node in order to be splitted in two.
     */
    Tree(Splitter *splitter, /*Criterion *criterion,*/ float max_features,
       int max_depth, int max_leaf_nodes, int min_samples_leaf, int min_samples_split);

    /**
     * \brief Standard destructor.
     */
    ~Tree();

    /**
     * Builds the Decision Tree.
     * \param X        An object of Collection.
     * \param sample_weight  Weight of each sample in collection.
     * \param feature_weight Weight of each feature .
     */
    void Build(/*const Collection *X,*/
          const std::vector<double> &sample_weight, const std::vector<double> &feature_weight);

    
    /**
     * Returns the leafs which each instance belongs to.
     * \param X     An object of Collection.
     * \param leafs Vector of leafs where the instances laid down.
     */
    void Traverse(/*const Collection *X, std::vector<Node*> *leafs*/);

  protected:

    Splitter *splitter; 
    /*Criterion *criterion;*/
    /*Sampler *sampler;*/ 
    float max_features;
    int max_depth;
    int max_leaf_nodes;
    int min_samples_leaf;
    int min_samples_split;
    /*Node* root;*/

};

} // namespace tree

#endif