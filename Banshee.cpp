/* Name: Khalid Young
Date: (06/10/2025)
This is the interface for the Banshee class, an inherted class from the Creature one, with getter, setters, data members, etc. */

#include "Banshee.hpp"

/**
Default constructor.
Default-initializes all private members.
Default Banshee category: UNDEAD
Default Banshee school: DEATH
Default Banshee aura: RED
Default Banshee scream volume: 1
Booleans are default-initialized to False
*/
Banshee::Banshee() {
    setCategory(UNDEAD);
    setSchool(DEATH);
    setHealth(1);
    setLevel(1);
    setSpeed(1);
    this->spectralAura_ = RED;
    this->screamVolume_ = 1;
    this->fearInducing_ = 0;
    setHostility(0);
}

/**
Parameterized constructor.
@param: The name of the Banshee (a string)
@param: The category of the Banshee (a Category enum) with a default
value UNDEAD

@param: The school of the Banshee (a School enum) with a default value
DEATH
@param: The health of the Banshee (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The level of the Banshee (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The hostility of the Banshee (a boolean) with default value of
False
@param: The spectral aura of the Banshee (an Aura enum) with a default
value RED
@param: The decibel level of the Banshee (an integer) with default value 1
if not provided, or if the value provided is 0 or negative
@param: A flag indicating whether the Banshee can induce fear, with
default value False
*/
Banshee::Banshee(const std::string& name, const Category& category, const School& school, const int& health, const int& level, const int& speed, const bool& isHostile, const Aura& spectralAura, const int& screamVolume, const bool& fearInducing): Creature(name, category, school, health, level, speed, isHostile) {
    setName(name);
    setCategory(category);
    setSchool(school);
    setHealth(health);
    setLevel(level);
    setSpeed(speed);
    setHostility(isHostile);
    this->spectralAura_ = spectralAura;
    setScreamVolume(screamVolume);
    this->fearInducing_ = fearInducing;
}

/**
@param: The aura of the Banshee (an enum)
@post: Sets the Banshee’s aura to the value of the parameter
*/
void Banshee::setAura(const Aura& spectralAura){
    this->spectralAura_ = spectralAura;
}

/**
@return: The aura of the Banshee (in string form)
*/
std::string Banshee::getAura() const{
    std::string temp_;
    switch(spectralAura_){
        case BLUE: temp_ = "BLUE"; break;
        case GRAY: temp_ = "GRAY"; break;
        case GREEN: temp_ = "GREEN"; break;
        default: temp_ = "RED"; break;
    }
    return temp_;
}

/**
@param: An integer that represents the Banshee’s decibel level
@pre: Parameter must be greater than 0, if not, do nothing
@post: Sets the scream volume private member to the value of the parameter
@return: true if the scream volume was set, false otherwise
*/
bool Banshee::setScreamVolume(const int& screamVolume){
    if(screamVolume <= 0){
        return 0;
    } else{
        this->screamVolume_ = screamVolume;
    }
    return 1;
}

/**
@return: The scream volume of the Banshee
*/
int Banshee::getScreamVolume() const{
    return screamVolume_;
}

/**
@param: A boolean value of whether or not the Banshee is fear inducing
@post: Sets the fear inducing flag to the value of the parameter
*/
void Banshee::setFearInducing(const bool& fearInducing){
    this->fearInducing_ = fearInducing;
}

/**
@return: true if the Banshee is fear inducing, false otherwise
Note: This is still an accessor function and must follow the same
conventions as all accessor functions even if it not called getFearInducing()
*/
bool Banshee::isFearInducing() const{
    return fearInducing_;
}

/**
@post: Displays Banshee data in the form:
“[NAME]\n
Category: [CATEGORY]\n
School: [SCHOOL]\n
Aura Color: [AURA]\n
Scream Level: [SCREAM LEVEL]\n
Health: [HEALTH]\n
Level: [LEVEL]\n
Fear Inducing: [TRUE/FALSE]\n
Hostile: [TRUE/FALSE]”
*/
void Banshee::display() const{
    std::string torf;
    std::string feartf;

    if(isHostile() == true){
        torf = "TRUE";
    } else {
        torf = "FALSE";
    }

    if(isFearInducing() == true){
        feartf = "TRUE";
    } else {
        feartf = "FALSE";
    }
    std::cout << getName() << "\n" << "Category: " << getCategory() << "\n" << "School: " << getSchool() << "\n" << "Aura Color: " << getAura() << "\n" << "Scream Level: " << getScreamVolume() << "\n" << "Health: " << getHealth() << "\n" << "Level: " << getLevel() << "\n" << "Speed: " << getSpeed() << "\n" << "Fear Inducing: " << feartf << "\n" << "Hostile: " << torf << "\n";
}

/**
@post: Checks to see if two banshees are equal
@post: Checks names, aura color, and fear inducing qualities
*/
bool operator==(const Banshee& banshee1, const Banshee& banshee2){
    return (banshee1.getName() == banshee2.getName() && banshee1.getAura() == banshee2.getAura() && banshee1.isFearInducing() == banshee2.isFearInducing());
}