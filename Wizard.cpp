/*
Name: Khalid Young
Date: (06/26/2025)
Note: This is the implementation for the Wizard class for the constructors, member functions, data members, etc. 
*/

#include "Wizard.hpp"

/**
Default constructor.
Default-initializes all private members.
Default Wizard Category: HUMANOID
Default Wizard School: Choose what you like
*/
Wizard::Wizard(){
    setCategory(HUMANOID);
    setSchool(DEATH);
    setHealth(100);
    setLevel(1);
    setSpeed(10);
    setHostility(false);
}

/**
Parameterized constructor.
@param: The name of the wizard (a string)
@param: The category of the wizard (a Category enum) with a default value
HUMANOID
@param: The school of the wizard (a School enum) with a default value of
whatever you like
@param: The health of the wizard (an integer) with default value 100 if not
provided, or if the value provided is 0 or negative
@param: The level of the wizard (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The hostility of the wizard (a boolean) with default value of False
@param: The speed of the wizard (an integer) with default value of 10 if not
provided, or if the value provided is 0 or negative
*/
Wizard::Wizard(const std::string& name, const Category& category, const School& school, const int& health, const int& level, const int& speed, const bool& isHostile) : Creature(name, category, school, health, level, speed, isHostile){
    setName(name);
    setCategory(category);
    setSchool(school);
    setHealth(health);
    setLevel(level);
    setSpeed(speed);
    setHostility(isHostile);
}

/**
Offensive spell - attacks a target creature with magic
@param: A pointer to the creature being attacked
@post: Decreases the health of the creature being attacked by 20 and
displays a different message for the spell used based on wizard’s school:
FIRE: Fire Cat
STORM: Thunder Snake
ICE: Frost Beetle
LIFE: Imp
MYTH: Blood Bat
DEATH: Dark Sprite
<Wizard Name> casts <School spell> on <Target Name>!
*/
void Wizard::attackSpell(Creature* target){
    target->setHealth(target->getHealth() - 20);
    if(getSchool() == "FIRE"){
        std::cout << getName() << " casts Fire Cat on " << target->getName() << "!" << "\n";
    }
    if(getSchool() == "STORM"){
        std::cout << getName() << " casts Thunder Snake on " << target->getName() << "!" << "\n";
    }
    if(getSchool() == "ICE"){
        std::cout << getName() << " casts Frost Beetle on " << target->getName() << "!" << "\n";
    }
    if(getSchool() == "LIFE"){
        std::cout << getName() << " casts Imp on " << target->getName() << "!" << "\n";
    }
    if(getSchool() == "MYTH"){
        std::cout << getName() << " casts Blood Bat on " << target->getName() << "!" << "\n";
    }
    if(getSchool() == "DEATH"){
        std::cout << getName() << " casts Dark Sprite on " << target->getName() << "!" << "\n";
    }
}

/**
Defensive spell - heals the wizard
@post: Increases the wizard’s health by 15 points and displays an action
message
<Wizard Name> casts Fairy!
*/
void Wizard::healSpell() {
    setHealth(getHealth() + 15);
    std::cout << getName() << " casts a move to heal all damage acquired to his mental health,... and his cloak!" << "\n";
}