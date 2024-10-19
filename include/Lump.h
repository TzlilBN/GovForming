#pragma once

#include <vector>
using std::vector;

#ifndef LUMP
#define LUMP

class Agent;
class Party;

class Lump
{
    public:
        //Constructor
        Lump(int Id, int Mandates, Agent TempAgent);

        //Getters
        int getId() const;
        int getMandatesSum() const;
        Agent* getTemplateAgent();
        vector<int>* getParties();
        

        //Actions
        Agent duplicateTemplateAgent();
        vector<int> endgame();
        void AddPartytoMe(Party& party);
        void AddFirstParty(Party& party); //check if needed

        //Rule of 5
        Lump(const Lump& other);
        Lump& operator=(const Lump& other);
        ~Lump();
        Lump(Lump&& other);
        Lump& operator=(Lump&& other);

    private:
        int mId;
        int mNumOfMan;
        Agent* TemplateAgent; //not Deleted in destructor
        vector<int>* mParties;
};
#endif