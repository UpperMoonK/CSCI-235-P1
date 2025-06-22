/* Name: Khalid Young
Date: (06/10/2025)
This is the interface for the CatThug class, an inherted class from the Creature one, with getter, setters, data members, etc. */

#ifndef CATTHUG_HPP_
#define CATTHUG_HPP_
#include "Creature.hpp"
#include <vector>

enum Notoriety{ROOKIE, THIEF, ENFORCER, MOB_BOSS};

class CatThug: public Creature{
public:
    struct Weapon{
        std::string alias_;
        int damage_;
        bool isRanged_;
    };
    enum Notoriety{ROOKIE, THIEF, ENFORCER, MOB_BOSS};
    CatThug();
    CatThug(const std::string& name, const Category& category = HUMANOID, const School& school = MYTH, const int& health = 1, const int& level = 1, const bool& isHostile = 0, const std::vector<Weapon>& weapons = {}, const Notoriety& noterietyLevel = ROOKIE, const bool& isWanted = 0);
    void setWeapons(const std::vector<Weapon>& weapons);
    std::vector<Weapon> getWeapons() const;
    bool addWeapon(const Weapon& weapon);
    bool removeWeapon(const Weapon& weapon);
    void setNotoriety(const Notoriety& noterietyLevel);
    std::string getNotoriety() const;
    void setIsWanted(const bool& isWanted);
    bool isWanted() const;
    void display() const override;
    friend bool operator==(const CatThug& catThug1, const CatThug& catThug2);

private:
    std::vector<Weapon> weapons_;
    Notoriety noterietyLevel_;
    bool isWanted_;
};
#endif