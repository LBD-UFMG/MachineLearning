#ifndef SPLITTER_H__
#define SPLITTER_H__

/**
 * Information regarding the split of a given node.
 * This will be used by the tree during its construction.
 */
struct SplitterRecord
{
  double threshold;       /**<  Threshold to split at. */
  double improvement;     /**<  Impurity improvement given parent node. */ 
  double impurity_left;   /**<  Impurity of the left split. */
  double impurity_right;  /**<  Impurity of the right split. */
};

/**
 * Base class for all Splitters. The Splitter will be used by the tree to find
 *  the best split point considering any given criterion and the Splitter strategy.
 */
class Splitter{
  public:
    virtual ~Splitter() { }

    /**
     * Initialize the splitter (Used by Tree).
     * \param  col             An object of Collection.
     * \param  max_features    Number of features to be sampled without
     *                          replacement and considered at split time. 
     * \param  min_sample_leaf Minimum number of samples to perform the split.
     * \param  sample_weight   Weight of each sample in collection.
     * \param  feature_weight  Weight of each feature.
     */
    virtual void Init(/*Collection col,*/ int max_features, int min_sample_leaf
                    , double* sample_weight, double* feature_weight) = 0;
    /**
     * Returns the split of the given node.
     * \param t   Node.
     * \return SplitterRecord.
     */
    virtual SplitterRecord NodeSplit(/* Node t */) = 0;
    
    /**
     * Impurity of a node.
     * \param t  Node.
     * \return Imputity measurement.
     */
    virtual double NodeImputiry(/* Node t */) = 0;
};

#endif
