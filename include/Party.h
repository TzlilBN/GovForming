#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;

class JoinPolicy;
class Simulation;

class Lump;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    //Getters
    int getId() const;
    const string &getName() const;
    int getMandates() const;
    JoinPolicy* getJoinPolicy() const;
    State getState() const;
    int getCounter() const;
    vector<int>* getOffers();

    //Actions
    void setState(State state);
    void step(Simulation &s);
    void insertOffer(int lumpId);

    //Rule of 5
    Party(const Party& other);
    Party& operator=(const Party& other);
    ~Party();
    Party(Party&& other);
    Party& operator=(Party&& other);

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int mCounter;
    vector<int>* moffers;
};
