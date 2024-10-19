#pragma once

#include <vector>
using std::vector;
class Lump;
class Simulation;

class JoinPolicy
{
    public:
        JoinPolicy() = default;
        virtual ~JoinPolicy() = default;
        virtual Lump* chooseLumpByPolicy(vector<int>* offers, Simulation& s)=0;
        virtual JoinPolicy* clone() = 0;
};

class MandatesJoinPolicy : public JoinPolicy
{
    public:
        MandatesJoinPolicy() = default;
        virtual ~MandatesJoinPolicy() = default;
        virtual Lump* chooseLumpByPolicy(vector<int>* offers, Simulation& s);
        virtual MandatesJoinPolicy* clone();
};

class LastOfferJoinPolicy : public JoinPolicy 
{
    public:
        LastOfferJoinPolicy() = default;
        virtual ~LastOfferJoinPolicy() = default;
        virtual Lump* chooseLumpByPolicy(vector<int>* offers, Simulation& s);
        virtual LastOfferJoinPolicy* clone();
};