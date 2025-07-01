/* Name: Khalid Young
Date: (06/10/2025)
This is the implentation for the Firecat class, an inherted class from the Creature one, with getter, setters, data members, etc. */

#include "Firecat.hpp"
#include "Wizard.hpp"

/**
Default constructor.
Default-initializes all private members.
Default Firecat category: ANIMAL
Default Firecat school: FIRE
Default Firecat flame color: ORANGE
Default Firecat flame intensity: 1
Booleans are default-initialized to False
*/
Firecat::Firecat() {
    setCategory(ANIMAL);
    setSchool(FIRE);
    setHealth(1);
    setLevel(1);
    setSpeed(1);
    this->flameColor_ = ORANGE;
    this->flameIntensity_ = 1;
    this->arsonist_ = 0;
    setHostility(0);
}

/**
Parameterized constructor.
@param: The name of the Firecat (a string)
@param: The category of the Firecat (a Category enum) with a default value
ANIMAL

@param: The school of the Firecat (a School enum) with a default value
FIRE
@param: The health of the Firecat (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The level of the Firecat (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The hostility of the Firecat (a boolean) with default value of False
@param: The flame color of the Firecat (an FlameColor enum) with a
default value ORANGE
@param: The flame intensity of the Firecat (an integer) with default value 1
if not provided, or if the value provided is 0 or negative
@param: A flag indicating whether the Firecat is an arsonist, with default
value False
*/
Firecat::Firecat(const std::string& name, const Category& category, const School& school, const int& health, const int& level, const int& speed, const bool& isHostile, const FlameColor& flameColor, const int& flameIntensity, const bool& arsonist) : Creature(name, category, school, health, level, speed, isHostile) {
    setName(name);
    setCategory(category);
    setSchool(school);
    setHealth(health);
    setLevel(level);
    setSpeed(speed);
    setHostility(isHostile);
    setFlameColor(flameColor);
    setFlameIntensity(flameIntensity);
    setArsonist(arsonist);
}

/**
@param: The flame color of the Firecat (an enum)
@post: Sets the Firecat’s flame color to the value of the parameter
*/
void Firecat::setFlameColor(const FlameColor& flameColor){
    this->flameColor_ = flameColor;
}

/**
@return: The flame color of the Firecat (in string form)
*/
std::string Firecat::getFlameColor() const{
    std::string temp;
    switch(flameColor_){
        case RED: temp = "RED"; break;
        case BLUE: temp = "BLUE"; break;
        case WHITE: temp = "WHITE"; break;
        default: temp = "ORANGE"; break;
    }
    return temp;
}

/**
@param: An integer that represents the Firecat’s flame intensity
@pre: Parameter must be greater than 0, if not, do nothing
@post: Sets the flame intensity private member to the value of the parameter
@return: true if the flame intensity was set, false otherwise
*/
bool Firecat::setFlameIntensity(const int& flameIntensity){
    if(flameIntensity <= 0){
        return 0;
    }else{
        this->flameIntensity_ = flameIntensity;
    }
    return 1;
}

/**
@return: The flame intensity of the Firecat
*/
int Firecat::getFlameIntensity() const{
    return flameIntensity_;
}

/**
@param: A boolean value of whether or not the Firecat is an arsonist
@post: Sets the arsonist flag to the value of the parameter
*/
void Firecat::setArsonist(const bool& arsonist){
    this->arsonist_ = arsonist;
}

/**
@return: true if the Firecat is an arsonist, false otherwise
Note: This is still an accessor function and must follow the same
conventions as all accessor functions even if it not called getArsonist()
*/
bool Firecat::isArsonist() const{
    return arsonist_;
}

/**
@post: Displays Firecat data in the form:
“[NAME]\n
Category: [CATEGORY]\n
School: [SCHOOL]\n
Flame Color: [FLAME COLOR]\n
Flame Intensity: [FLAME INTENSITY]\n
Health: [HEALTH]\n
Level: [LEVEL]\n
Arsonist: [TRUE/FALSE]\n
Hostile: [TRUE/FALSE]”
*/
void Firecat::display() const{
    std::string torf;
    std::string arson_;

    if(isHostile() == true){
        torf = "TRUE";
    } else {
        torf = "FALSE";
    }

    if(isArsonist() == true){
        arson_ = "TRUE";
    } else {
        arson_ = "FALSE";
    }
    std::cout << getName() << "\n" << "Category: " << getCategory() << "\n" << "School: " << getSchool() << "\n" << "Flame Color: " << getFlameColor() << "\n" << "Flame Intensity: " << getFlameIntensity() << "\n" << "Health: " << getHealth() << "\n" << "Level: " << getLevel() << "\n" << "Speed: " << getSpeed() << "\n" << "Arsonist: " << arson_ << "\n" << "Hostile: " << torf << "\n";
}

/**
@post: Checks to see if two firecats are equal
@post: Checks names, flame color, and if they are both arsonists
*/
bool operator==(const Firecat& firecat1, const Firecat& firecat2){
    return (firecat1.getName() == firecat2.getName() && firecat1.getFlameColor() == firecat2.getFlameColor() && firecat1.isArsonist() == firecat2.isArsonist());
}

void Firecat::attack(Wizard* wizard) const{
    std::cout << "The FireCat releases a torrent of flames burning hotter than a SuperNova... " << "\n" << "It burns a hole cloak on your favorite cloak..." 
    << "\n" << "Emotional Damage - 10" << "\n";
    wizard->setHealth(wizard->getHealth() - 10);
}
