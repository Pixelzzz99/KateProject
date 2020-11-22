#pragma once
#include "NNA.hpp"
#include <vector>
#include "RandomConnectedGraph.hpp"
#include "iostream"

class FirstVersion : NNA
{
private:
    const int INF = 1e9;
    std::vector<bool> _used;
    std::vector<std::vector<int>> _graph;
    std::vector<int> _way;
    void clearWay();
    void resizeGraph(int size);
    void NearestNeighbourAlgorithm(int s);
    void setGraph(std::vector<std::pair<std::pair<int, int>, int>> graph);

public:
    FirstVersion(RandomConnectedGraph);
    FirstVersion(int n, int m, std::vector<std::pair<std::pair<int, int>, int>> graph);
    ~FirstVersion() = default;

    void solve() override;
};