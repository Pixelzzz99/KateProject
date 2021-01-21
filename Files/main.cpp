#include <iostream>
#include "NNA.hpp"
#include "RandomConnectedGraph.hpp"
#include <vector>
#include <utility>
#include <ctime>
#include "FirstVersion.hpp"
#include "OptimizedVersion.hpp"
#include <fstream>
int main()
{
    int n = 5000;
    int m = n * (n - 1) / 2;
    std::ofstream first;
    std::ofstream second;
    first.open("D:\\projects\\KateProject\\GraphsPython\\FirstVersion.txt", std::ios::app);
    second.open("D:\\projects\\KateProject\\GraphsPython\\SecondVersion.txt", std::ios::app);
    while (n != 11000)
    {
        RandomConnectedGraph *connectedGraph = new RandomConnectedGraph(n, m);
        std::cout << connectedGraph->getNew_N() << std::endl;
        std::cout << connectedGraph->getNew_M() << std::endl;
        std::vector<std::pair<std::pair<int, int>, int>> graph = connectedGraph->getNew_Graph();

        std::cout << std::endl;
        std::cout << "SOLVE" << std::endl;
        NNA *test1 = new NNA(new FirstVersion(connectedGraph));
        unsigned int time = clock();
        test1->DoAlgorithm();
        
        double time_end = (double)(clock() - time) / CLOCKS_PER_SEC;

        std::cout << "time of first version: " << time_end << std::endl;
        std::cout << "FirstVersion excellent" << std::endl;

        std::cout << std::endl;

        NNA *test2 = new NNA(new OptimizedVersion(connectedGraph));
        unsigned int time1 = clock();
        test2->DoAlgorithm();
        
        double time1_end = (double)(clock() - time1) / CLOCKS_PER_SEC;

        std::cout << "time of Optimized version: " << time1_end << std::endl;
        std::cout << "OptimizedVersion excellent" << std::endl;

        if (first.is_open())
        {
            first << connectedGraph->getNew_N() << std::endl;
            first << connectedGraph->getNew_M() << std::endl;
            first << time_end << std::endl;
        }

        if (first.is_open())
        {
            second << connectedGraph->getNew_N() << std::endl;
            second << connectedGraph->getNew_M() << std::endl;
            second << time1_end << std::endl;
        }
        n += 500;
        m = n * (n - 1) / 2;
    }
    first.close();
    second.close();
    system("pause>nul");
    return 0;
}