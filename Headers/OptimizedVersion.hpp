#pragma once
#include "NNAStrategy.hpp"
#include "Edge.hpp"
#include "RandomConnectedGraph.hpp"
#include <vector>
#include <utility>

class OptimizedVersion : public NNAStrategy
{

private:
    std::vector<bool> _used;
    std::vector<std::vector<Edge>> _graph;
    std::vector<int> _way;
    void resizeUsed(int size);
    static bool compareEdges(Edge a, Edge b);
    void clearWay();
    void sortGraph();
    void NearestNeighbourAlgorithm(int s);
    void setGraph(std::vector<std::pair<std::pair<int, int>, int>> graph);

public:

    OptimizedVersion(RandomConnectedGraph *);
    OptimizedVersion(int n, int m, std::vector<std::pair<std::pair<int, int>, int>> graph);
    void solve() override;

};