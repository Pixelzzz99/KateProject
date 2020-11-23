#include <iostream>
#include "OptimizedVersion.hpp"
#include "FirstVersion.hpp"
#include "RandomConnectedGraph.hpp"

int main()
{
    RandomConnectedGraph connectedGraph;
    std::cout<<connectedGraph.getNew_N()<<std::endl;
    std::cout<<connectedGraph.getNew_M()<<std::endl;
    std::cout<<std::endl;
    FirstVersion* test1 = new FirstVersion(connectedGraph);
    test1->solve();
    std::cout<<"FirstVersion excellent"<<std::endl;
    std::cout<<std::endl;
    OptimizedVersion* test2 = new OptimizedVersion(connectedGraph);
    test2->solve();
    std::cout<<"OptimizedVersion excellent"<<std::endl;

    
    system("pause>nul");
    return 0;
}