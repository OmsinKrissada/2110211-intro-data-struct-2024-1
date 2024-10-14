#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

#include <map>
#include <set>
// Your code here

using namespace std;

class SparseGraph {
   public:
    SparseGraph() : flipped(false) {
        // Your code here
    }

    SparseGraph(int n_in) : flipped(false) {
        // Your code here
    }

    SparseGraph(const SparseGraph& G) {
        // Your code here
        edges = G.edges;  // copy
        flipped = G.flipped;
    }

    void AddEdge(int a, int b) {
        // Your code here
        if (!flipped)
            edges.insert({a, b});
        else
            edges.insert({b, a});
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        if (!flipped)
            edges.erase({a, b});
        else
            edges.erase({b, a});
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        if (!flipped) return edges.count({a, b});
        return edges.count({b, a});
    }

    SparseGraph Transpose() const {
        // Your code here
        SparseGraph g(*this);

        g.flipped = !flipped;
        return g;
    }

   protected:
    // Your code here
    bool flipped;
    set<pair<int, int>> edges;
};
#endif  // __SPARSE_GRAPH_H__
