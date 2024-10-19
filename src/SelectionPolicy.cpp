#include "SelectionPolicy.h"

#include "Party.h"
#include "Graph.h"
#include "Simulation.h"
#include "Lump.h"


int MandatesSelectionPolicy::choosePartyByPolicy(int LumpId, int PartyId ,Graph& graph, Simulation& sim)
{
    int max = 0;
    int ret = -1;
    for (int i = 0; i < sim.getParties()->size(); i++)
    {
        Party temp = sim.getParty(i);
            if(temp.getState() == Waiting || temp.getState() == CollectingOffers)
                if(graph.getEdgeWeight(PartyId, i) > 0)
                {
                    if (temp.getMandates() > max)
                    {
                        bool found = false;
                        for (int lump: *temp.getOffers())
                        {
                            if (lump == LumpId)
                                found = true;
                        }
                        if (!found)
                        {
                            max = temp.getMandates();
                            ret = i;
                        }
                    }
                }
    }
    return ret;
}

MandatesSelectionPolicy* MandatesSelectionPolicy::clone()
{
    return new MandatesSelectionPolicy();
}

int EdgeWeightSelectionPolicy::choosePartyByPolicy(int LumpId, int PartyId ,Graph& graph, Simulation& sim)
{
    int max = -1;
    int ret = -1;
    for (int i = 0; i < sim.getParties()->size(); i++)
    {
        Party temp = sim.getParty(i);
            if(temp.getState() == Waiting || temp.getState() == CollectingOffers)
                if(graph.getEdgeWeight(PartyId, i) > 0 & graph.getEdgeWeight(PartyId, i) > max)
                {
                    bool found = false;
                        for (int lump: *temp.getOffers())
                        {
                            if (lump == LumpId)
                                found = true;
                        }
                        if (!found)
                        {
                            max = graph.getEdgeWeight(PartyId, i);
                            ret = i;
                        }
                }

    }
    return ret;
}

EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone()
{
    return new EdgeWeightSelectionPolicy();
}