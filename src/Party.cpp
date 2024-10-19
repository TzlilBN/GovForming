#include "Party.h"

#include <vector>
using std::vector;

#include "JoinPolicy.h"
#include "Agent.h"
#include "Lump.h"
#include "Simulation.h"

//Constructor
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), mCounter(-1), moffers(new vector<int>())
{
    // You can change the implementation of the constructor, but not the signature!
}

//Getters
int Party::getId() const
{
    return mId;
}

const string & Party::getName() const
{
    return mName;
}

int Party::getMandates() const
{
    return mMandates;
}


JoinPolicy* Party::getJoinPolicy() const
{
    return mJoinPolicy;
}

State Party::getState() const
{
    return mState;
}

int Party::getCounter() const
{
    return mCounter;
}

vector<int>* Party::getOffers()
{
    return moffers;
}


//Actions
void Party::setState(State state)
{
    mState = state;
}


void Party::step(Simulation &s)
{
    // TODO: implement this method
    if (mCounter > -1)
        mCounter++;
    if (mCounter == 3)
    {
        Lump* chosen = mJoinPolicy->chooseLumpByPolicy(moffers, s);
        setState(Joined);
        chosen->AddPartytoMe(*this);
        Agent magent = chosen->duplicateTemplateAgent();
        magent.setPId(this->getId());
        magent.setAId(s.getAgentsP()->size());
        s.getAgentsP()->push_back(magent);
    }
}

void Party::insertOffer(int lumpId)
{
    moffers->push_back(lumpId);
    if (mCounter == -1)
    {
        mCounter++;
        setState(CollectingOffers);
    }
}

    //Rule of 5
        Party::Party(const Party& other): mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->clone()), mState(other.mState), mCounter(other.mCounter), moffers(new vector<int>(*other.moffers))
        {
        }

        Party& Party::operator=(const Party& other)
        {
            if (&other != this)
            {
                delete mJoinPolicy;
                moffers->clear();
                delete moffers;
                mId = other.mId;
                mName = other.mName;
                mMandates = other.mMandates;
                mJoinPolicy = other.mJoinPolicy->clone();
                mState = other.mState;
                mCounter = other.mCounter;
                moffers = new vector<int>(*other.moffers);
            }
        }

        Party::~Party()
        {
            delete mJoinPolicy;
            //moffers->clear();
            delete moffers;
        }

        Party::Party(Party&& other):  mId(other.mId), mName(other.mName), mMandates(other.mMandates), mState(other.mState), mCounter(other.mCounter)
        {
            mJoinPolicy = other.mJoinPolicy;
            other.mJoinPolicy = nullptr;
            moffers = other.moffers;
            other.moffers = nullptr;
        }

        Party& Party::operator=(Party&& other)
        {
            delete mJoinPolicy;
            moffers->clear();
            delete moffers;
            mId = other.mId;
            mName = other.mName;
            mMandates = other.mMandates;
            mJoinPolicy = other.mJoinPolicy;
            other.mJoinPolicy = nullptr;
            mState = other.mState;
            mCounter = other.mCounter;
            moffers =other.moffers;
            other.moffers = nullptr;
        }
