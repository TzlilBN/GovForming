#pragma once

#ifndef GRAPH
#define GRAPH
#include <vector>
#include "Party.h"

using std::vector;

class Graph
{
public:
    //Constructor
    Graph(vector<Party> vertices, vector<vector<int>> edges);

    //Getters
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    const Party &getParty(int partyId) const;
    vector<Party>& getmVertices();

    //Rule of 5
    Graph(const Graph& other);
    Graph& operator=(const Graph&  other);
    ~Graph();
    Graph(Graph&& other);
    Graph& operator=(Graph&& other); 

private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};

#endif