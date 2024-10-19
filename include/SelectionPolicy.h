#pragma once

class Graph;
class Simulation;

class SelectionPolicy
{
     public:
        SelectionPolicy() = default;
        virtual ~SelectionPolicy() = default;
        virtual int choosePartyByPolicy(int LumpId, int PartyId ,Graph& graph, Simulation& sim)=0;
        virtual SelectionPolicy* clone() = 0;
};

class MandatesSelectionPolicy: public SelectionPolicy
{
    public:
        MandatesSelectionPolicy() = default;
        virtual ~MandatesSelectionPolicy() = default;
        virtual int choosePartyByPolicy(int LumpId, int PartyId ,Graph& graph, Simulation& sim);
        virtual MandatesSelectionPolicy* clone();
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{
    public:
        EdgeWeightSelectionPolicy() = default;
        virtual ~EdgeWeightSelectionPolicy() = default;
        virtual int choosePartyByPolicy(int LumpId, int PartyId ,Graph& graph, Simulation& sim);
        virtual EdgeWeightSelectionPolicy* clone();
};