#pragma once
#include <vector>
#include "NNAStrategy.hpp"

class NNA
{
private:
    
    NNAStrategy *strategy_;

public:
    NNA(NNAStrategy *strategy = nullptr);
    ~NNA();

    void set_strategy(NNAStrategy *strategy);
    
    int getCountOfVertex_N();
    void setCountOfVertex_N(int newCountOfVertex_M);

    int getCountOfEdges_M();
    void setCountOfEdges_M(int newCountOfEdges_M);

    void DoAlgorithm();
};