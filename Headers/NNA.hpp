#pragma once
#include <vector>

class NNA
{
private:
    int countOfVertex_N;
    int countOfEdges_M;
    

public:

    int getCountOfVertex_N();
    void setCountOfVertex_N(int newCountOfVertex_M);

    int getCountOfEdges_M();
    void setCountOfEdges_M(int newCountOfEdges_M);

    virtual void solve() = 0;
    
    ~NNA() = default;
};