/*
Name: Khalid Young
Date: (06/02/2025)
Note: This is the implementation for the Creature class. 
*/

#include "Creature.hpp"

Creature::Creature(){
    this->name_ = "NAMELESS";
    this->category_ = (Category::UNKNOWN);
    this->school_ = (School::NONE);
    this->health_ = 1;
    this->level_ = 1;
    this->isHostile_ = false;
}

Creature::Creature(const std::string& name, const Category& category, const School& school, const int& health, const int& level, const bool& tame){
    this->name_ = name;
    this->category_ = category;
    this->school_ = school;
    if (health > 0){
       this->health_ = health; 
    }
    if (level > 0) {
        this->level_ = level;
    }
    this->isHostile_ = tame;
}

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

std::string Creature::getName() const{
    return name_;
}

void Creature::setCategory(const Category& category){
    this->category_ = category;
}

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

void Creature::setSchool(const School& school){
    this->school_ = school;
}

std::string Creature::getSchool() const{
    std::string status_;
    switch(school_){
        case FIRE : status_ = "FIRE"; break;
        case ICE : status_ = "ICE"; break;
        case STORM : status_ = "STORM"; break;
        case LIFE : status_ = "LIFE"; break;
        case MYTH : status_ = "MYTH"; break;
        case DEATH : status_ = "DEATH"; break;
        default : status_ = "UNKNOWN"; break;
    }
    return status_;
}

bool Creature::setHealth(const int& health){
    if(health <= 0){
        return 0;
    }else{
        this->health_ = health;
        return 1;
    }
}

int Creature::getHealth() const{
    return health_;
}

bool Creature::setLevel(const int& level){
    if(level <= 0){
        return 0;
    }else{
        this->level_ = level;
        return 1;
    }
}

int Creature::getLevel() const{
    return level_;
}

void Creature::setHostility(const bool& isHostile){
    this->isHostile_ = isHostile;
}

bool Creature::isHostile() const{
    return isHostile_;
}

void Creature::display() const{
    std::string torf;
    if(isHostile_ == true){
        torf = "TRUE";
    } else {
        torf = "FALSE";
    }
    std::cout << getName() << "\n" << "Category: " << getCategory() << "\n" << "School: " << getSchool() << "\n" << "Health: " << getHealth() << "\n" << "Level: " << getLevel() << "\n" << "Hostile: " << torf << std::endl;
}