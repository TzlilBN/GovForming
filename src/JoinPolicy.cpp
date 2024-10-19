#include "JoinPolicy.h"

#include "Lump.h"
#include "Simulation.h"


Lump* MandatesJoinPolicy::chooseLumpByPolicy(vector<int>* offers, Simulation& s)
{
    vector<Lump>* lumps = s.getLumps();
    Lump* chosen = nullptr;
    int maxMan = 0;
    for (int lumpId: *offers)
    {
        if (lumps->at(lumpId).getMandatesSum() > maxMan)
        {
            maxMan = lumps->at(lumpId).getMandatesSum();
            chosen = &lumps->at(lumpId);
        }
    }
    return chosen;
}

MandatesJoinPolicy* MandatesJoinPolicy::clone()
{
    return new MandatesJoinPolicy();
}


Lump* LastOfferJoinPolicy::chooseLumpByPolicy(vector<int>* offers, Simulation& s)
{
    vector<Lump>* lumps = s.getLumps();
    int chosen = offers->back();
    return &lumps->at(chosen);
}

LastOfferJoinPolicy* LastOfferJoinPolicy::clone()
{
    return new LastOfferJoinPolicy();
}
