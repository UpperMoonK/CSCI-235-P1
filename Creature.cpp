/*
Name: Khalid Young
Date: (06/02/2025)
Note: This is the implementation for the Creature class. 
*/

#include "Creature.hpp"
#include "Wizard.hpp"

/**
Default constructor.
Default-initializes all private members.
Default creature name: “NAMELESS”
Default creature category: UNKNOWN
Default creature school: UNKNOWN
Default creature health: 1
Default creature level: 1
Booleans are default-initialized to False
*/

Creature::Creature(){
    this->name_ = "NAMELESS";
    this->category_ = (Category::UNKNOWN);
    this->school_ = (School::NONE);
    this->health_ = 1;
    this->level_ = 1;
    this->isHostile_ = false;
}

/**
Parameterized constructor.
@param: The name of the creature (a string)
@param: The category of the creature (a Category enum) with a default
value UNKNOWN

@param: The school of the creature (a School enum) with a default value
UNKNOWN
@param: The health of the creature (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The level of the creature (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The hostility of the creature (a boolean) with default value of False
*/

Creature::Creature(const std::string& name, const Category& category, const School& school, const int& health, const int& level, const int& speed, const bool& tame){
    this->name_ = name;
    this->category_ = category;
    this->school_ = school;
    if (health <= 0){
       this->health_ = 1; 
    } else{
        this->health_ = health;
    }
    if (level > 0) {
        this->level_ = level;
    }
    if (speed > 0){
        this->speed_ = speed;
    }
    this->isHostile_ = tame;
}

/**
@param: The name of the creature (a string)
@post: Sets the Creature’s name to the value of the parameter in
UPPERCASE (convert any lowercase character to uppercase)
@post: Only alphabetical characters are allowed. If the input contains
non-alphabetic characters, do nothing
@return: true if the name was set, false otherwise
*/

bool Creature::setName(const std::string& name){
    std::string temp_ = name;
    for(int i = 0; i < temp_.length(); i++){
        if(!isalpha(temp_[i])){
            return 0;
        }
        if(!isupper(temp_[i])){
            temp_[i] = toupper(temp_[i]);
        }
    }
    this->name_ = temp_;
    return 1;
}

/**
@return: The name of the Creature
*/

std::string Creature::getName() const{
    return name_;
}

/**
@param: The category of the Creature (an enum)
@post: Sets the Creature’s category to the value of the parameter
*/

void Creature::setCategory(const Category& category){
    this->category_ = category;
}

/**
@return: The category of the Creature (in string form)
*/

std::string Creature::getCategory() const{
    std::string status_;
    switch(category_){
        case MAGICAL : status_ = "MAGICAL"; break;
        case UNDEAD : status_ = "UNDEAD"; break;
        case ANIMAL : status_ = "ANIMAL"; break;
        case HUMANOID : status_ = "HUMANOID"; break;
        default : status_ = "UNKNOWN"; break;
    }
    return status_;
}

/**
@param: The school of the Creature (an enum)
@post: Sets the Creature’s school to the value of the parameter
*/
void Creature::setSchool(const School& school){
    this->school_ = school;
}

/**
@return: The school of the Creature (in string form)
*/

std::string Creature::getSchool() const{
    std::string status_;
    switch(school_){
        case FIRE : status_ = "FIRE"; break;
        case ICE : status_ = "ICE"; break;
        case STORM : status_ = "STORM"; break;
        case LIFE : status_ = "LIFE"; break;
        case MYTH : status_ = "MYTH"; break;
        case DEATH : status_ = "DEATH"; break;
        default : status_ = "NONE"; break;
    }
    return status_;
}

/**
@param: An integer that represents the creature’s health
@pre: Parameter must be greater than 0, if not, do nothing
@post: Sets the health private member to the value of the parameter
@return: true if the health was set, false otherwise
*/

bool Creature::setHealth(const int& health){
    if(health <= 0){
        this->health_ = 0;
        return 0;
    }else{
        this->health_ = health;
        return 1;
    }
}

/**
@return: The health of the Creature
*/

int Creature::getHealth() const{
    return health_;
}

/**
@param: An integer that represents the creature’s level
@pre: Parameter must be greater than 0, if not, do nothing
@post: Sets the health private member to the value of the parameter
@return: true if the level was set, false otherwise
*/

bool Creature::setLevel(const int& level){
    if(level <= 0){
        return 0;
    }else{
        this->level_ = level;
        return 1;
    }
}

/**
@return: The level of the Creature
*/
int Creature::getLevel() const{
    return level_;
}

/**
@param: An integer that represents the creature’s speed
@pre: Parameter must be greater than 0, if not, do nothing
@post: Sets the speed private member to the value of the parameter
@return: true if the speed was set, false otherwise
*/
bool Creature::setSpeed(const int& speed){
    if(speed <= 0){
        return 0;
    }else{
        this->speed_ = speed;
        return 1;
    }
}

/** 
@return: The speed of the creature
*/
int Creature::getSpeed() const{
    return speed_;
}

/**
@param: A boolean value of whether or not the Creature is hostile
@post: Sets the isHostile flag to the value of the parameter
*/

void Creature::setHostility(const bool& isHostile){
    this->isHostile_ = isHostile;
}

/**
@return: true if the Creature is hostile, false otherwise
Note: This is still an accessor function and must follow the same
conventions as all accessor functions even if it not called getHostile()
*/

bool Creature::isHostile() const{
    return isHostile_;
}

/**
@post: Displays Creature data in the form:
“[NAME]\n
Category: [CATEGORY]\n
School: [SCHOOL]\n
Health: [HEALTH]\n
Level: [LEVEL]\n
Hostile: [TRUE/FALSE]”
*/

void Creature::display() const{
    std::string torf;
    if(isHostile_ == true){
        torf = "TRUE";
    } else {
        torf = "FALSE";
    }
    std::cout << getName() << "\n" << "Category: " << getCategory() << "\n" << "School: " << getSchool() << "\n" << "Health: " << getHealth() << "\n" << "Level: " << getLevel() << "\n" << "Speed: " << getSpeed() << "\n" << "Hostile: " << torf << "\n";
}

void Creature::attack(Wizard* wizard) const{
    std::cout << "The Creature does something weird that gets on your nerves for the rest of the day" << "\n";
    wizard->setHealth(wizard->getHealth() - 10);
}