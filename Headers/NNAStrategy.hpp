#pragma once

class NNAStrategy
{
private:
    int countOfVertex_N;
    int countOfEdges_M;
public:
    int getCountOfVertex_N();
    void setCountOfVertex_N(int newCountOfVertex_N);

    int getCountOfEdges_M();
    void setCountOfEdges_M(int newCountOfEdges_M);

    virtual ~NNAStrategy() = default;
    virtual void solve() = 0;
};