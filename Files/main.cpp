#include <iostream>
#include "OptimizedVersion.hpp"
#include "FirstVersion.hpp"
#include "RandomConnectedGraph.hpp"
#include <vector>
#include <utility>
#include <ctime>

int main()
{
    RandomConnectedGraph connectedGraph;
    std::cout << connectedGraph.getNew_N() << std::endl;
    std::cout << connectedGraph.getNew_M() << std::endl;
    std::vector<std::pair<std::pair<int, int>, int>> graph = connectedGraph.getNew_Graph();
   /* for (auto edge : graph)
    {
        std::cout << edge.first.first << " " << edge.first.second << " " << edge.second << std::endl;
    }*/
    std::cout<<std::endl;
    std::cout<<"SOLVE"<<std::endl;
    FirstVersion *test1 = new FirstVersion(connectedGraph);
    unsigned time = clock();
    test1->solve();
    std::cout<<"time of first version: "<<(double)(clock() - time) / 1000<<std::endl;
    std::cout << "FirstVersion excellent" << std::endl;
    
    std::cout << std::endl;
   
    OptimizedVersion *test2 = new OptimizedVersion(connectedGraph);
    time = clock();
    test2->solve();
    std::cout<<"time of Optimized version: "<<(double)(clock() - time) / 1000<<std::endl;

    std::cout << "OptimizedVersion excellent" << std::endl;

    system("pause>nul");
    return 0;
}