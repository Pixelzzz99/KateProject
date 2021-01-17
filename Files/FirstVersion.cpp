#include "FirstVersion.hpp"

FirstVersion::FirstVersion(RandomConnectedGraph *randomTask)
{
    setCountOfVertex_N(randomTask.getNew_N());
    setCountOfEdges_M(randomTask.getNew_M());
    resizeGraph(getCountOfVertex_N());
    setGraph(randomTask.getNew_Graph());
}

FirstVersion::FirstVersion(int n, int m, std::vector<std::pair<std::pair<int, int>, int>> graph)
{
    setCountOfVertex_N(n);
    setCountOfEdges_M(m);
    resizeGraph(getCountOfVertex_N());
    setGraph(graph);
}

void FirstVersion::resizeGraph(int size)
{
    _used.resize(size + 1);
    _graph.resize(size + 1);
    for (int i = 0; i <= size; i++)
    {
        _graph[i].resize(size + 1);
    }
}

void FirstVersion::setGraph(std::vector<std::pair<std::pair<int, int>, int>> graph)
{
    for (int i = 1; i <= getCountOfVertex_N(); i++)
    {
        for (int j = 1; j <= getCountOfVertex_N(); j++)
        {
            if (i != j)
            {
                _graph[i][j] = -INF;
            }
        }
    }

    for (int i = 0; i < getCountOfEdges_M(); i++)
    {
        int u = graph[i].first.first;
        int v = graph[i].first.second;
        int length = graph[i].second;
        this->_graph[u][v] = length;
        this->_graph[v][u] = length;
    }
}

void FirstVersion::solve()
{
    for (int i = 1; i <= getCountOfVertex_N(); i++)
    {
        clearWay();
        //std::cout << "IF WE START FROM VERTEX OF: " << i << std::endl;
        NearestNeighbourAlgorithm(i);
        //std::cout << "Count of visited of vertex " << _way.size() << std::endl;
        /*
        for(int x : _way) 
        {
            std::cout<<x<<" ";
        }
        */
        //std::cout<<std::endl;
    }
}

void FirstVersion::clearWay()
{
    for(auto i : _way)
    {
        _used[i] = false;
    }
    _way.clear();
}

void FirstVersion::NearestNeighbourAlgorithm(int s)
{
    _way.push_back(s);
    _used[s] = true;
    int mn = INF, id_mn = 0;
    for (int i = 1; i <= getCountOfVertex_N(); i++)
    {
        if(_graph[s][i] == -INF || _used[i]) continue;
        if (_graph[s][i] < mn)
        {
            mn = _graph[s][i];
            id_mn = i;
        }
    }
    if(!id_mn) return;
    NearestNeighbourAlgorithm(id_mn);    
}

