#include "tree.h"

namespace tree {

Tree::Tree(Splitter *splitter, /*Criterion *criterion, Sampler *sampler,*/ float max_features,
            int max_depth, int max_leaf_nodes, int min_samples_leaf, int min_samples_split){
    // code here
}

Tree::~Tree(){
  // code here
}

void Tree::Build(/*const Collection *X,*/
            const std::vector<double> *sample_weight,
            const std::vector<double> *feature_weight) {
  // code here
}

void Tree::Traverse(/*const Collection *X, std::vector<Node*> &leafs*/){
  // code here
}

} // namespace tree