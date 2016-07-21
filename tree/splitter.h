#ifndef _TREE_SPLITTER_H__
#define _TREE_SPLITTER_H__

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

    /**
     * \brief Standard destructor.
     */
    virtual ~Splitter();

    /**
     * Returns the split of a given node.
     * \param t   Node.
     * \return SplitterRecord.
     */
    virtual SplitterRecord NodeSplit(/* Node t */) = 0;
    
    /**
     * Impurity of a node.
     * \param t  Node.
     * \return Imputity measurement.
     */
    virtual double NodeImpurity(/* Node t */) = 0;
};

#endif
