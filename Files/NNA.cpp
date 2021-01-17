#include "NNA.hpp"

NNA::NNA(NNAStrategy *strategy) : strategy_(strategy)
{}

NNA::~NNA()
{
    delete this->strategy_;
}

void NNA::set_strategy(NNAStrategy *strategy)
{
    delete this->strategy_;
    this->strategy_ = strategy;
}

int NNA::getCountOfVertex_N()
{
    return strategy_->getCountOfVertex_N();
}

void NNA::setCountOfVertex_N(int newCountOfVertex_N)
{
    this->strategy_->setCountOfVertex_N(newCountOfVertex_N);
}

int NNA::getCountOfEdges_M()
{
     return strategy_->getCountOfEdges_M();
}

void NNA::setCountOfEdges_M(int newCountOfEdges_M)
{
    this->strategy_->setCountOfEdges_M(newCountOfEdges_M);
}

void NNA::DoAlgorithm()
{
    strategy_->solve();
}