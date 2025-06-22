/* Name: Khalid Young
Date: (06/10/2025)
This is the interface for the CatThug class, an inherted class from the Creature one, with getter, setters, data members, etc. */

#include "CatThug.hpp"
/**
Default constructor.
Default-initializes all private members.
Default Cat Thug category: HUMANOID
Default Cat Thug school: MYTH
Default Cat Thug weapons: {}
Default Cat Thug notoriety: ROOKIE

Booleans are default-initialized to False
*/
CatThug::CatThug(){
    setCategory(HUMANOID);
    setSchool(MYTH);
    setHealth(1);
    setLevel(1);
    this->weapons_ = {};
    this->noterietyLevel_ = ROOKIE;
    this->isWanted_ = 0;
    setHostility(0);
}

/**
Parameterized constructor.
@param: The name of the Cat Thug (a string)
@param: The category of the Cat Thug (a Category enum) with a default
value HUMANOID
@param: The school of the Cat Thug (a School enum) with a default value
MYTH
@param: The health of the Cat Thug (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The level of the Cat Thug (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The hostility of the Cat Thug (a boolean) with default value of
False
@param: The weapons of the Cat Thug (a vector of Weapons) with a default
value {}
@param: The notoriety of the Cat Thug (a Notoriety enum) with default
value ROOKIE
@param: A flag indicating whether the Cat Thug is wanted, with default
value False
*/
CatThug::CatThug(const std::string& name, const Category& category, const School& school, const int& health, const int& level, const bool& isHostile, const std::vector<Weapon>& weapons, const Notoriety& noterietyLevel, const bool& isWanted) : Creature(name, category, school, health, level, isHostile){
    setName(name);
    setCategory(category);
    setSchool(school);
    setHealth(health);
    setLevel(level);
    setHostility(isHostile);
    this->weapons_ = weapons;
    this->noterietyLevel_ = noterietyLevel;
    this->isWanted_ = isWanted;
}

/**
@param: The weapons of a Cat Thug
@post: Sets the Cat Thug’s weapons to the value of the parameter
*/
void CatThug::setWeapons(const std::vector<Weapon>& weapons){
    this->weapons_ = weapons;
}

/**
@return: The weapons (a vector of Weapon structs)
*/
std::vector<CatThug::Weapon> CatThug::getWeapons() const{
    return weapons_;
}

/**
@param: A weapon to be added to the vector
@post: Adds the weapon to the vector only if the weapon does not exist in
the vector
@post: if weapon exists, update the damage of the weapon in the vector with
the higher damage number
@return: true if weapon was added, false otherwise
Hint: bat and BAT are the same weapon
*/
bool CatThug::addWeapon(const Weapon& weapon){
    for(int i = 0; i < weapons_.size(); i++){
        if(weapons_[i].alias_ == weapon.alias_){
            if(weapons_[i].damage_ < weapon.damage_){
                weapons_[i].damage_ = weapon.damage_;
            }
            return 0;
        }
    }
    weapons_.push_back(weapon);
    return 1;
}

/**
@param: A weapon to be removed from the vector
@post: Removes the weapon from the vector only if the weapon exists
@return: true if weapon was removed, false otherwise
Hint: bat and BAT are the same weapon
*/
bool CatThug::removeWeapon(const Weapon& weapon){
    for(int i = 0; i < weapons_.size(); i++){
        if(weapons_[i].alias_ == weapon.alias_){
            weapons_.erase(weapons_.begin() + i);
            return 1;
        }
    }
    return 0;
}

/**
@param: The notoriety of the Cat Thug (an enum)
@post: Sets the Cat Thug’s notoriety to the value of the parameter
*/
void CatThug::setNotoriety(const Notoriety& noterietyLevel){
    this->noterietyLevel_ = noterietyLevel;
}

/**
@return: The notoriety of the Cat Thug (in string form)
*/
std::string CatThug::getNotoriety() const{
    std::string temp_;
    switch(noterietyLevel_){
        case THIEF: temp_ = "THIEF"; break;
        case ENFORCER: temp_ = "ENFORCER"; break;
        case MOB_BOSS: temp_ = "MOB_BOSS"; break;
        default: temp_ = "ROOKIE"; break;
    }
    return temp_;
}

/**
@param: A boolean value of whether or not the Cat Thug is wanted by the
authorities
@post: Sets the is wanted flag to the value of the parameter
*/
void CatThug::setIsWanted(const bool& isWanted){
    this->isWanted_ = isWanted;
}

/**
@return: true if the Cat Thug is wanted, false otherwise
Note: This is still an accessor function and must follow the same
conventions as all accessor functions even if it not called getIsWanted()
*/
bool CatThug::isWanted() const{
    return isWanted_;
}

/**
@post: Displays Cat Thug data in the form:
“[NAME]\n
Category: [CATEGORY]\n
School: [SCHOOL]\n
Weapons: [WEAPON NAME]: [DAMAGE], [RANGED/NOT RANGED]\n
Notoriety: [NOTORIETY]\n
Health: [HEALTH]\n
Level: [LEVEL]\n
Is Wanted: [TRUE/FALSE]\n
Hostile: [TRUE/FALSE]”
*/
void CatThug::display() const{
    std::string torf;
    std::string real_thug;

    if(isHostile() == true){
        torf = "TRUE";
    } else {
        torf = "FALSE";
    }

    if(isWanted() == true){
        real_thug = "TRUE";
    } else {
        real_thug = "FALSE";
    }

    std::cout << getName() << "\n" << "Category: " << getCategory() << "\n" << "School: " << getSchool() << "\n";
    for(int i = 0; i < weapons_.size(); i++){
        std::cout << weapons_[i].alias_ << ": " << weapons_[i].damage_ << ", " << (weapons_[i].isRanged_ ? "RANGED":"NOT RANGED") << "\n";
    }
    std::cout<< "Noteriety: " << getNotoriety() << "\n" << "Health: " << getHealth() << "\n" << "Level: " << getLevel() << "\n" << "Is Wanted: " << real_thug << "\n" << "Hostile: " << torf << "\n";
}

/**
@post: Checks to see if two cat thugs are equal
@post: Checks names, notoriety, and is wanted
*/
bool operator==(const CatThug& catthug1, const CatThug& catthug2){
    return (catthug1.getName() == catthug2.getName() && catthug1.getNotoriety() == catthug2.getNotoriety() && catthug1.isWanted() == catthug2.isWanted());
}
