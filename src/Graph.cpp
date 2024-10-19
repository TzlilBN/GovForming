#include "Graph.h"

//Constructor
Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

//Getters
int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

vector<Party>& Graph::getmVertices()
{
    return mVertices;
}

    //Rule of 5
    Graph::Graph(const Graph& other): mVertices(other.mVertices), mEdges(other.mEdges)
    {
    }

    Graph& Graph::operator=(const Graph&  other)
    {
        if(&other != this)
        {
            mVertices.clear();
            mEdges.clear();
            mVertices = other.mVertices;
            mEdges = other.mEdges;
        }
    }

    Graph::~Graph()
    {
        mVertices.clear();
        mEdges.clear();
    }

    Graph::Graph(Graph&& other):  mVertices(other.mVertices), mEdges(other.mEdges)
    {
    }

    Graph& Graph::operator=(Graph&& other)
    {
        mVertices.clear();
        mEdges.clear();
        mVertices = other.mVertices;
        mEdges = other.mEdges;
    } 
