#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    //Got and Dont need
    const vector<Agent> &getAgents() const; //NOT TO USE!!!!

    //Actions
    void step();
    bool shouldTerminate() const;
    void createLumps();

    //Getters
    vector<Agent>* getAgentsP();
    vector<Party>* getParties();
    vector<Lump>* getLumps();
    const Party &getParty(int partyId) const; //USE PARTIES IN SIM!!!!
    const Graph &getGraph() const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    Graph& getGraphNOconst();
    Party& getPatyNOconst(int partyId);
    Lump& getLump(int lumpId);

    //Rule of 5
    Simulation(const Simulation& other);
    Simulation& operator=(const Simulation& other);
    ~Simulation();
    Simulation(Simulation&& other);
    Simulation& operator=(Simulation&& other);

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Agent>* mAgentsP;
    vector<Party>* mPartyP;
    vector<Lump>* mLumpsP;
};
