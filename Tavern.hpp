/* Name: Khalid Young
Date: (06/21/2025)
This is the interface for the Tavern class, a derived class of the Magical bag, along with getters and setters, data members and functions, etc */

#ifndef TAVERN_HPP_
#define TAVERN_HPP_
#include "MagicalBag.hpp"

class Tavern : public MagicalBag<Creature*> {
public:
    Tavern();
    bool enterTavern(Creature* newCreature);
    bool exitTavern(Creature* newCreature);
    int getLevelSum() const;
    int getCreatureCount() const;
    int getHostileCount() const;
    double calculateHostilePercentage() const;
    int tallyCategory(const std::string& category) const;
    int tallySchool(const std::string& school) const;
    int releaseCreaturesBelowLevel(const int& level);
    int releaseCreaturesOfCategory(const std::string& category);
    int releaseCreaturesOfSchool(const std::string& school);
    void tavernReport() const;
    void displayCreatures() const;
private:
    //The combined level of all creatures in the Tavern
    int totalLevel_;
    //The total number of creatures in the Tavern
    int creatureCount_;
};
#endif

