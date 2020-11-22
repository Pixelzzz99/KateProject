#include "RandomConnectedGraph.hpp"
#include <ctime>

RandomConnectedGraph::RandomConnectedGraph()
{
    new_n = Randomizator(MIN_COUNT, MAX_COUNT);
    GenerateGraph();
    new_m = new_Graph.size();
}

int RandomConnectedGraph::Randomizator(int min, int max)
{
    static std::mt19937 mt_rand(time(0));
    return mt_rand() % max + min;
}

int RandomConnectedGraph::getNew_N()
{
    return new_n;
}

int RandomConnectedGraph::getNew_M()
{
    return new_m;
}

std::vector<std::pair<std::pair<int, int>, int>> RandomConnectedGraph::getNew_Graph()
{
    return new_Graph;
}

void RandomConnectedGraph::GenerateGraph()
{
    int need = new_n-1;
    std::vector<int> vertex = {1};
    int have_v = 1;

    while (need > 0)
    {
        int len = vertex.size();
        int id = Randomizator(0, len);
        int count_edges = Randomizator(1, need);
        need -= count_edges;

        for (int i = 1; i <= count_edges; i++)
        {
            have_v++;
            vertex.push_back(have_v);
            int distance_between_vertex = Randomizator(0, 100000);
            new_Graph.push_back({{vertex[id], have_v}, distance_between_vertex});
        }
        
    }

    std::map<std::pair<int,int>, bool> has_edge;
    for (auto edge : new_Graph)
    {
        has_edge[{edge.first.first, edge.first.second}] = 1;
        has_edge[{edge.first.second, edge.first.first}] = 1;
    }

    int it = Randomizator(0, (5*new_n));

    while (it--)
    {
        int len = vertex.size();
        int id1 = Randomizator(0, len);
        int id2 = Randomizator(0, len);
        if (id1 == id2) continue;
        if (has_edge.count({vertex[id1], vertex[id2]})) continue;
        has_edge[{vertex[id1], vertex[id2]}] = has_edge[{vertex[id2], vertex[id1]}] = true;
        int distance_between_vertex = Randomizator(0, 100000);
        new_Graph.push_back({{vertex[id1], vertex[id2]}, distance_between_vertex});
    }
}  