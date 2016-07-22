#ifndef _TREE_SPLITTER_RECORD_H__
#define _TREE_SPLITTER_RECORD_H__

namespace tree{

/**
 * Information regarding the split of a given node.
 * This will be used by the tree during its construction.
 */
class SplitterRecord{
  public:

    /**
     * \brief Standard destructor.
     */
    virtual ~SplitterRecord();
};

}

#endif