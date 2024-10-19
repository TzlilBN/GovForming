#include "Lump.h"

#include "Agent.h"
#include <vector>
#include "Party.h"

using std::vector;

//Constructor
Lump::Lump(int Id, int Mandates, Agent TempAgent): mId(Id), mNumOfMan(0), TemplateAgent(new Agent(TempAgent)), mParties(new vector<int>())
{
}

//Getters
int Lump::getId() const
{
    return mId;
}
int Lump::getMandatesSum() const
{  
    return mNumOfMan;
}

Agent* Lump::getTemplateAgent()
{
    return TemplateAgent;
}

vector<int>* Lump::getParties()
{
    return mParties;
}    

//Actions
Agent Lump::duplicateTemplateAgent()
{
    return Agent(*TemplateAgent);
}

vector<int> Lump::endgame()
{
    return *mParties;
}

void Lump::AddPartytoMe(Party& party)
{
    mNumOfMan = mNumOfMan + party.getMandates();
    mParties->push_back(party.getId());
}

void Lump::AddFirstParty(Party& party)
{
    mNumOfMan = mNumOfMan + party.getMandates();
    mParties->push_back(party.getId());
}

    //Rule of 5
        Lump::Lump(const Lump& other): mId(other.mId), mNumOfMan(other.mNumOfMan), TemplateAgent(new Agent(*other.TemplateAgent)), mParties(new vector<int>(*other.mParties))
        {
        }

        Lump& Lump::operator=(const Lump& other)
        {
            if (&other != this)
            {
                delete TemplateAgent;
                mParties->clear();
                delete mParties;
                mId = other.mId;
                mNumOfMan = other.mNumOfMan;
                TemplateAgent = new Agent(*other.TemplateAgent);
                mParties = new vector<int>(*other.mParties);
            }
        }

        Lump::~Lump()
        {

            delete TemplateAgent;
            mParties->clear();
            delete mParties;
        }

        Lump::Lump(Lump&& other): mId(other.mId), mNumOfMan(other.mNumOfMan)
        {
            TemplateAgent = other.TemplateAgent;
            other.TemplateAgent = nullptr;
            mParties = other.mParties;
            other.mParties = nullptr;
        } 

        Lump& Lump::operator=(Lump&& other)
        {
            delete TemplateAgent;
            mParties->clear();
            delete mParties;
            mId = other.mId;
            mNumOfMan = other.mNumOfMan;
            TemplateAgent = other.TemplateAgent;
            other.TemplateAgent = nullptr;
            mParties = other.mParties;
            other.mParties = nullptr;
        }