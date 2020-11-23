#include <iostream>
#include "OptimizedVersion.hpp"
#include "FirstVersion.hpp"
#include "RandomConnectedGraph.hpp"

int main()
{
    RandomConnectedGraph connectedGraph;

    FirstVersion* test1 = new FirstVersion(connectedGraph);
    test1->solve();
    system("pause>nul");
    return 0;
}