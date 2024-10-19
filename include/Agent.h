#pragma once

#ifndef AGENT
#define AGENT
#include "Graph.h"

class Lump;

class SelectionPolicy;

class Agent
{
public:
    //Constructor
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    //Getters
    int getId() const;
    int getPartyId() const;
    int getLumpId() const;
    SelectionPolicy* getSelectionPolicy() const;

    //Actions
    void step(Simulation &);
    void setAId(int aId);
    void setPId(int PId);
    void setLId(int LId);
    Agent clone();

    //Rule of 5
    Agent(const Agent& other);
    Agent& operator=(Agent& other);
    ~Agent();
    Agent(Agent&& other);
    Agent& operator=(Agent&& other);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mLumpId;
};
#endif