/* Name: Khalid Young
Date: (06/21/2025)
This is the implementation for the Tavern class, a derived class of the Magical bag, including all necessary functions to hold creatures. */

#include "Tavern.hpp"

/**
Default constructor.
Default-initializes all private members.
Default total level count: 0
Default creature count: 0
*/
Tavern::Tavern() {
    this->totalLevel_ = 0;
    this->creatureCount_ = 0;
}

/**
@param: A creature entering the tavern
@post: If the given creature is not already in the tavern, add the creature to
the tavern and update the level sum and the creature count
@return: Returns true if the creature was successfully added to the cavern,
false otherwise
*/
bool Tavern::enterTavern(Creature* newCreature){
    if(!contains(newCreature)){
        add(newCreature);
        totalLevel_ += newCreature->getLevel();
        creatureCount_++;
        return 1;
    }
    return 0;
}

/**
@param: A creature exiting the tavern

@post: Removes the creature from the cavern, if they exist, and updates the
level sum and creature count accordingly.
@return: Returns true if the creature was successfully removed from the
cavern, false otherwise
*/
bool Tavern::exitTavern(Creature* newCreature){
    if(contains(newCreature)){
        totalLevel_ -= newCreature->getLevel();
        creatureCount_ = std::max(0, creatureCount_ - 1);
        remove(newCreature);
        return 1;
    }
    return 0;
}

/**
@return: Returns the combined level of all creatures in the tavern
*/
int Tavern::getLevelSum() const{
    return totalLevel_;
}

/**
@return: Returns the amount of creatures in the tavern
*/
int Tavern::getCreatureCount() const{
    return creatureCount_;
}

/**
@return: Returns the amount of creatures in the tavern that are hostile
*/
int Tavern::getHostileCount() const{
    int hostility = 0;
    for(int i = 0; i < getCurrentSize(); i++){
        if(items_[i]->isHostile() == 1){
            hostility++;
        }
    }
    return hostility;
}

/**
@post: Computes the percentage of hostile creatures in the tavern rounded
up to 2 decimal places
@return: Returns the percentage of all the hostile creatures in the tavern
*/
double Tavern::calculateHostilePercentage() const{
    if(getCurrentSize() == 0) {return 0.0;}
    double percent = static_cast<double>(getHostileCount()) / getCurrentSize() * 100.0;
    return std::round(percent * 100.0) / 100.0;
}

/**
@param: A string representing a creature category
@return: An integer tally of the number of creatures in the tavern of the
given category
Hint: If string parameter does not match a category, return 0
*/
int Tavern::tallyCategory(const std::string& category) const{
    bool valid_ = (category == "MAGICAL" || category == "UNDEAD" || category == "ANIMAL" || category == "HUMANOID" || category == "UNKNOWN");
    if(!valid_){return 0;}

    int tally = 0;
    for(int i = 0; i < getCurrentSize(); i++){
        if(items_[i]->getCategory() == category){
            tally++;
        } 
    }
    return tally;
}

/**
@param: A string representing a creature school
@return: An integer tally of the number of creatures in the tavern of the
given school
Hint: If string parameter does not match a school, return 0
*/
int Tavern::tallySchool(const std::string& school) const{
    bool valid_ = (school == "FIRE" || school == "ICE" || school == "STORM" || school == "LIFE" || school == "MYTH" || school == "DEATH" || school == "NONE");
    if(!valid_){return 0;}
    int s_tally = 0;
    for(int i = 0; i < getCurrentSize(); i++){
        if(items_[i]->getSchool() == school){
            s_tally++;
        } 
    }
    return s_tally;   
}

/**
@param: An integer representing the level threshold of the creatures to be
removed from the tavern, with a default value of 0
@post: Removes all creatures from the tavern whose level is less than the
given level. If no level is given, remove no creatures. Ignore negative inputs.
@return: The number of creatures removed from the tavern
*/
int Tavern::releaseCreaturesBelowLevel(const int& level){
    if(level <= 0){return 0;}
    int removed_ = 0;
    for(int i = getCurrentSize() - 1; i >= 0; --i){
        if(items_[i]->getLevel() < level){
            totalLevel_ -= items_[i]->getLevel();
            creatureCount_ = std::max(0, creatureCount_ - 1);
            remove(items_[i]);
            removed_++;
        }
    }
    return removed_;
}

/**
@param: A string representing a creature category to be removed from the
tavern, with a default value of “ALL”
@post: Removes all creatures from the tavern whose category matches the
given category. If no category is given, remove all creatures. Ignore invalid
inputs.
@return: The number of creatures removed from the tavern
*/
int Tavern::releaseCreaturesOfCategory(const std::string& category){
    int removed_ = 0;
    bool valid_ = (category == "MAGICAL" || category == "UNDEAD" || category == "ANIMAL" || category == "HUMANOID" || category == "UNKNOWN");
    
    if (!valid_) {
        for (int i = getCurrentSize() - 1; i >= 0; --i) {
            totalLevel_ -= items_[i]->getLevel();
            creatureCount_ = std::max(0, creatureCount_ - 1);
            remove(items_[i]);
            removed_++;
        }
        return removed_;
    }

    for(int i = getCurrentSize() - 1; i >= 0; --i){
        if(items_[i]->getCategory() == category){
            totalLevel_ -= items_[i]->getLevel();
            creatureCount_ = std::max(0, creatureCount_ - 1);
            remove(items_[i]);
            removed_++;
        }
    }
    return removed_;
}

/**
@param: A string representing a creature school to be removed from the
tavern, with a default value of “ALL”

@post: Removes all creatures from the tavern whose school matches the
given school . If no school is given, remove all creatures. Ignore invalid
inputs.
@return: The number of creatures removed from the tavern
*/
int Tavern::releaseCreaturesOfSchool(const std::string& school){
    int removed_ = 0;
    bool valid_ = (school == "FIRE" || school == "ICE" || school == "STORM" || school == "LIFE" || school == "MYTH" || school == "DEATH" || school == "NONE");
    
    if (!valid_) {
        for (int i = getCurrentSize() - 1; i >= 0; --i) {
            totalLevel_ -= items_[i]->getLevel();
            creatureCount_ = std::max(0, creatureCount_ - 1);
            remove(items_[i]);
            removed_++;
        }
        return removed_;
    }

    for(int i = getCurrentSize() - 1; i >= 0; --i){
        if(items_[i]->getSchool() == school){
            totalLevel_ -= items_[i]->getLevel();
            creatureCount_ = std::max(0, creatureCount_ - 1);
            remove(items_[i]);
            removed_++;
        }
    }
    return removed_;
}

/**
@post: Outputs a report of the creatures current in the tavern in the form:
CATEGORY COUNT:
MAGICAL: [INTEGER]
UNDEAD: [INTEGER]
ANIMAL: [INTEGER]
HUMANOID: [INTEGER]
CATEGORY_UNKNOWN: [INTEGER]
SCHOOL COUNT:
FIRE: [INTEGER]
ICE: [INTEGER]
STORM: [INTEGER]
LIFE: [INTEGER]
MYTH: [INTEGER]
DEATH: [INTEGER]
SCHOOL_UNKNOWN: [INTEGER]
AVERAGE LEVEL: [INTEGER]
HOSTILE: [DOUBLE]
*/
void Tavern::tavernReport() const{
    std::cout << "CATEGORY COUNT: " << "\n" << "MAGICAL: " << tallyCategory("MAGICAL") << "\n" << "UNDEAD: " << tallyCategory("UNDEAD") << "\n" << "ANIMAL: " << tallyCategory("ANIMAL") << "\n"
    << "HUMANOID: " << tallyCategory("HUMANOID") << "\n" << "CATEGORY_UNKNOWN: " << tallyCategory("UNKNOWN") << "\n" << "SCHOOL COUNT: " << "\n" 
    << "FIRE: " << tallySchool("FIRE") << "\n" << "ICE: " << tallySchool("ICE") << "\n" << "STORM: " << tallySchool("STORM") << "\n" << "LIFE: " << tallySchool("LIFE") << "\n" 
    << "MYTH: " << tallySchool("MYTH") << "\n" << "DEATH: " << tallySchool("DEATH") << "\n" << "SCHOOL_UNKNOWN: " << tallySchool("NONE") << "\n" << "AVERAGE LEVEL: " << getLevelSum() << "\n"
    << "HOSTILE: " << calculateHostilePercentage() << "\n";
}

/**
@post: For every creature in the tavern, display each creature’s information
*/
void Tavern::displayCreatures() const{
    for(int i = 0; i < getCurrentSize(); i++){
        items_[i]->display();
        std::cout << "\n";
    }
}

