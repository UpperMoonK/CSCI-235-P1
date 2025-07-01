/*
Name: Khalid Young
Date: (06/26/2025)
Note: This is the documentation (inferface) for the Wizard class derived from Creature, with member functions, data members, etc. 
*/

#ifndef WIZARD_HPP_
#define WIZARD_HPP_
#include "Creature.hpp"

class Wizard: public Creature {
public: 
    Wizard();
    Wizard(const std::string& name, const Category& category = HUMANOID, const School& school = DEATH, const int& health = 100, const int& level = 1, const int& speed = 10, const bool& isHostile = false);
    void attackSpell(Creature* target);
    void healSpell();
};
#endif