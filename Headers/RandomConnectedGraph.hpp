#pragma once
#include "Edge.hpp"
#include <vector>
#include <random>
#include <map>
#include <utility>

class RandomConnectedGraph
{
private:
    int MIN_COUNT = 1;
    int MAX_COUNT = 10;
    int new_n;
    int new_m;
    std::vector<std::pair<std::pair<int, int>, int>> new_Graph;
    int Randomizator(int min, int max);
    void GenerateGraph();

public:
    int getNew_N();
    int getNew_M();
    std::vector<std::pair<std::pair<int, int>, int>> getNew_Graph();
    RandomConnectedGraph();
    ~RandomConnectedGraph() = default;
};

