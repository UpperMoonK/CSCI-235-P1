/*
Name: Khalid Young
Date: (06/02/2025)
Note: This is the documentation (inferface) for the Creature class, with member functions, data members, etc. 
*/

#ifndef CREATURE_HPP_
#define CREATURE_HPP_
#include <iostream>
#include <string>


enum Category{MAGICAL, UNDEAD, ANIMAL, HUMANOID, UNKNOWN};
enum School{FIRE, ICE, STORM, LIFE, MYTH, DEATH, NONE};

class Creature {
    public:
    Creature();
    Creature(const std::string& name, const Category& category = UNKNOWN, const School& school = NONE, const int& health = 1, const int& level = 1, const bool& tame = false);
    bool setName(const std::string& name);
    std::string getName() const;
    void setCategory(const Category& category);
    std::string getCategory() const;
    void setSchool(const School& school);
    std::string getSchool() const;
    bool setHealth(const int& health);
    int getHealth() const;
    bool setLevel(const int& level);
    int getLevel() const;
    void setHostility(const bool& isHostile);
    bool isHostile() const;
    void display() const;

    private:
    std::string name_; //The name of the creature(string)
    Category category_; //The category of the creature(enum)
    School school_; //The school that the creature belongs to(enum)
    int health_; //The health of the creature (a non-zero, non-negative integer)
    int level_; //The level of the creature(a non-zero, non-negative integer))
    bool isHostile_; //Flag that indicates if the creature is hostile or not (boolean)
};

#endif