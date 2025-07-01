/*
Name: Khalid Young
Date: (06/26/2025)
Note: This is the documentation (inferface) for the Battle class, with member functions, data members, etc. 
*/

#ifndef BATTLE_HPP_
#define BATTLE_HPP_
#include "Creature.hpp"
#include "Wizard.hpp"
#include "Tavern.hpp"
#include <stack>

class Battle{
public:
    Battle(Wizard* wizard, Tavern enemies);
    void simulate();
    void buildTurnStack();
    void executeTurn(Creature* attacker);
    void removeDefeatedEnemy();
    bool isWizardAlive() const;
    bool enemiesRemain() const;
    void displayRoundStatus() const;
private:
    Wizard* wizard_;
    Tavern enemies_;
    std::stack<Creature*> turnStack_;
};
#endif