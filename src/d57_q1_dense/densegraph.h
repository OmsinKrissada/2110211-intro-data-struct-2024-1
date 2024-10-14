#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
using namespace std;
class DenseGraph {
   public:
    DenseGraph() : DenseGraph(3) {
        // Your code here
    }

    DenseGraph(int n_in) : flipped(false) {
        // Your code here
        adj.resize(n_in);
        for (auto& e : adj) e.resize(n_in);
    }

    DenseGraph(const DenseGraph& G) {
        // Your code here
        adj = G.adj;  // copy
        flipped = G.flipped;
    }

    void AddEdge(int a, int b) {
        // Your code here
        if (!flipped)
            adj[a][b] = true;
        else
            adj[b][a] = true;
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        if (!flipped)
            adj[a][b] = false;
        else
            adj[b][a] = false;
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        if (!flipped) return adj[a][b];
        return adj[b][a];
    }

    DenseGraph Transpose() const {
        // Your code here
        DenseGraph g(*this);
        g.flipped = !flipped;
        return g;
    }

   protected:
    int n;
    bool flipped;

    vector<vector<bool>> adj;
    // Your code here
};
#endif  // __DENSE_GRAPH_H__
