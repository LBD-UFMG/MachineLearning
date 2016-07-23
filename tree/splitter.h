#ifndef _TREE_SPLITTER_H__
#define _TREE_SPLITTER_H__

#include "splitter_record.h"

namespace tree{

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
    virtual SplitterRecord Split(/* Node t */) = 0;
    
    /**
     * Impurity of a node.
     * \param t  Node.
     * \return Imputity measurement.
     */
    virtual double Impurity(/* Node t */) = 0;
};

} // namespace tree

#endif
