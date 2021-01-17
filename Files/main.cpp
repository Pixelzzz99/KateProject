#include <iostream>
#include "NNA.hpp"
#include "RandomConnectedGraph.hpp"
#include <vector>
#include <utility>
#include <ctime>
#include "FirstVersion.hpp"
#include "OptimizedVersion.hpp"

int main()
{
    RandomConnectedGraph* connectedGraph = new RandomConnectedGraph();
    std::cout << connectedGraph->getNew_N() << std::endl;
    std::cout << connectedGraph->getNew_M() << std::endl;
    std::vector<std::pair<std::pair<int, int>, int>> graph = connectedGraph->getNew_Graph();
   /* for (auto edge : graph)
    {
        std::cout << edge.first.first << " " << edge.first.second << " " << edge.second << std::endl;
    }*/
    std::cout<<std::endl;
    std::cout<<"SOLVE"<<std::endl;
    NNA *test1 = new NNA(new FirstVersion(connectedGraph));
    unsigned time = clock();
    test1->DoAlgorithm();
    std::cout<<"time of first version: "<<(double)(clock() - time) / 1000<<std::endl;
    std::cout << "FirstVersion excellent" << std::endl;
    
    std::cout << std::endl;
   
    NNA *test2 = new NNA(new OptimizedVersion(connectedGraph));
    time = clock();
    test2->DoAlgorithm();
    std::cout<<"time of Optimized version: " << (double)(clock() - time) / 1000<<std::endl;

    std::cout << "OptimizedVersion excellent" << std::endl;

    system("pause>nul");
    return 0;
}