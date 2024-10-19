#include "Simulation.h"

#include "Lump.h"
#include "Agent.h"


//Constructor
Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // You can change the implementation of the constructor, but not the signature!
    mAgentsP = new vector<Agent>(agents);
    mPartyP = new vector<Party>(graph.getmVertices());
    mLumpsP = new vector<Lump>();
    createLumps();
}


//NO USE
const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}


//Actions
void Simulation::step()
{
    // TODO: implement this method
    for (Party& party: *mPartyP)
        party.step(*this);
    for (Agent agent: *mAgentsP)
        agent.step(*this);
    if (mAgents.size() != mAgentsP->size())
        {
            for (int i = mAgents.size(); i< mAgentsP->size(); i++)
                mAgents.push_back(mAgentsP->at(i));
        }
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    if (mAgentsP->size() == mPartyP->size())
        return true;
    for (Lump lump: *mLumpsP)
        if(lump.getMandatesSum() > 60)
            return true;
    return false;
}

void Simulation::createLumps()
{
    for (Agent& agent: *mAgentsP)
    {
        agent.setLId(agent.getId());
        Lump temp = Lump(agent.getId(), 0, agent);
        temp.AddFirstParty(getPatyNOconst(agent.getPartyId()));
        mLumpsP->push_back(temp);
    }
}


//Getters
vector<Agent>* Simulation::getAgentsP()
{
    return mAgentsP;
}

vector<Party>* Simulation::getParties()
{
    return mPartyP;
}

vector<Lump>* Simulation::getLumps()
{
    return mLumpsP;
}

const Party &Simulation::getParty(int partyId) const
{
    return (*(mPartyP))[partyId];
}


const Graph &Simulation::getGraph() const
{
    return mGraph;
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    vector<vector<int>> output = vector<vector<int>>();
    for (Lump lump: *mLumpsP)
        output.push_back(lump.endgame());
    return output;
}

Graph& Simulation::getGraphNOconst()
{
    return mGraph;
}

Party& Simulation::getPatyNOconst(int partyId)
{
    return (*mPartyP)[partyId];
}




//Rule of 5
    Simulation::Simulation(const Simulation& other): mGraph(other.mGraph), mAgents(other.mAgents), mAgentsP(new vector<Agent>(*other.mAgentsP)), mPartyP(new vector<Party>(*other.mPartyP)), mLumpsP(new vector<Lump>(*other.mLumpsP))
    {
    }

    Simulation& Simulation::operator=(const Simulation& other)
    {
        if (&other != this)
        {
            mGraph = other.mGraph;
            mAgents = vector<Agent>();
            for (Agent a: other.mAgents)
                mAgents.push_back(Agent(a));
            mAgentsP->clear();
            mPartyP->clear();
            mLumpsP->clear();
            delete mAgentsP;
            delete mPartyP;
            delete mLumpsP;
            mAgentsP = new vector<Agent>(*other.mAgentsP);
            mPartyP = new vector<Party>(*other.mPartyP);
            mLumpsP = new vector<Lump>(*other.mLumpsP);
        }
    }

    Simulation::~Simulation()
    {
        mAgentsP->clear();
        mPartyP->clear();
        mLumpsP->clear();
        delete mAgentsP;
        delete mPartyP;
        delete mLumpsP;
    }

    Simulation::Simulation(Simulation&& other): mGraph(other.mGraph), mAgents(other.mAgents)
    {
        mAgentsP = other.mAgentsP;
        mPartyP = other.mPartyP;
        mLumpsP = other.mLumpsP;
        other.mAgentsP = nullptr;
        other.mPartyP = nullptr;
        other.mLumpsP = nullptr;
    }

    Simulation& Simulation::operator=(Simulation&& other)
    {
        mGraph = other.mGraph;
        mAgents = vector<Agent>();
            for (Agent a: other.mAgents)
                mAgents.push_back(Agent(a));
        mAgentsP->clear();
        mPartyP->clear();
        mLumpsP->clear();
        delete mAgentsP;
        delete mPartyP;
        delete mLumpsP;
        mAgentsP = other.mAgentsP;
        mPartyP = other.mPartyP;
        mLumpsP = other.mLumpsP;
        other.mAgentsP = nullptr;
        other.mPartyP = nullptr;
        other.mLumpsP = nullptr;

    }