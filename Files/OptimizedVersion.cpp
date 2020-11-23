#include "OptimizedVersion.hpp"
#include <algorithm>
#include <iostream>

OptimizedVersion::OptimizedVersion(RandomConnectedGraph randomTask)
{
    setCountOfVertex_N(randomTask.getNew_N());
    setCountOfEdges_M(randomTask.getNew_M());
    resizeUsed(getCountOfVertex_N());
    setGraph(randomTask.getNew_Graph());
    sortGraph();

}

OptimizedVersion::OptimizedVersion(int n, int m, std::vector<std::pair<std::pair<int, int>, int>> graph)
{
    setCountOfVertex_N(n);
    setCountOfEdges_M(m);
    resizeUsed(getCountOfVertex_N());
    setGraph(graph);
    sortGraph();
}


void OptimizedVersion::resizeUsed(int size)
{
    _used.resize(size + 1);
    _graph.resize(size + 1);
}

void OptimizedVersion::setGraph(std::vector<std::pair<std::pair<int, int>, int>> graph)
{
    for (int i = 0; i < getCountOfEdges_M(); i++)
    {
        int u = graph[i].first.first;
        int v = graph[i].first.second;
        int length = graph[i].second;
        this->_graph[v].push_back({u, length});
        this->_graph[u].push_back({v, length});
    }
}

void OptimizedVersion::sortGraph()
{
    for (int i = 1; i <= getCountOfVertex_N(); i++)
    {
        sort(_graph[i].begin(), _graph[i].end(), compareEdges);
    }
}

bool OptimizedVersion::compareEdges(Edge a, Edge b)
{
    return a.len < b.len;
}

void OptimizedVersion::solve()
{
    for (int i = 1; i <= getCountOfVertex_N(); i++)
    {
        clearWay();
        std::cout << "If we star from vertex of: " << i << std::endl;
        NearestNeighbourAlgorithm(i);
        std::cout << "Count of visited of vertex" << _way.size() << std::endl;
        for (int x : _way)
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
}

void OptimizedVersion::clearWay()
{
    for (int i : _way)
    {
        _used[_way[i]] = false;
    }
    _way.clear();
}

void OptimizedVersion::NearestNeighbourAlgorithm(int s)
{
    _way.push_back(s);
    _used[s] = true;
    for (Edge edge : _graph[s])
    {
        if (_used[edge.to])
        {
            continue;
        }
        NearestNeighbourAlgorithm(edge.to);
    }
}