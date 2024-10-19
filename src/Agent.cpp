#include "Agent.h"
#include "SelectionPolicy.h"

#include "Simulation.h"
#include "Lump.h"

//Constructor
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mLumpId(-1)
{
    // You can change the implementation of the constructor, but not the signature!
}


//Getters
int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

int Agent::getLumpId() const
{
    return mLumpId;
}

SelectionPolicy* Agent::getSelectionPolicy() const
{
    return mSelectionPolicy;
}

//Actions
void Agent::step(Simulation &sim)
{
    // TODO: implement this method
    int chosen = mSelectionPolicy->choosePartyByPolicy(mAgentId, mPartyId, sim.getGraphNOconst(), sim);
    if (chosen > -1)
    {
        Party* temp = &(sim.getPatyNOconst(chosen));
        temp->insertOffer(sim.getLumps()->at(getLumpId()).getId());
    }
}

void Agent::setAId(int aId)
{
    mAgentId = aId;
}

void Agent::setPId(int PId)
{
    mPartyId = PId;
}

void Agent::setLId(int LId)
{
    mLumpId = LId;
}

Agent Agent::clone()
{
    return Agent(*this);
}

    //Rule of 5
    Agent::Agent(const Agent& other): mAgentId(other.mAgentId), mPartyId(other.mPartyId), mLumpId(other.mLumpId)
    {
        mSelectionPolicy = other.getSelectionPolicy()->clone();
    }

    Agent& Agent::operator=(Agent& other)
    {
        if (&other != this)
        {
            mAgentId = other.mAgentId;
            mPartyId = other.mPartyId;
            mLumpId = other.mLumpId;
            delete mSelectionPolicy;
            mSelectionPolicy = other.getSelectionPolicy()->clone();
        }
    }

    Agent::~Agent()
    {
        delete mSelectionPolicy;
    }

    Agent::Agent(Agent&& other):  mAgentId(other.mAgentId), mPartyId(other.mPartyId), mLumpId(other.mLumpId)
    {
        mSelectionPolicy = other.mSelectionPolicy;
        other.mSelectionPolicy = nullptr;
    }

    Agent& Agent::operator=(Agent&& other)
    {
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mLumpId = other.mLumpId;
        delete mSelectionPolicy;
        mSelectionPolicy = other.mSelectionPolicy;
        other.mSelectionPolicy = nullptr;
    }
