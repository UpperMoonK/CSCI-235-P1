/* Name: Khalid Young
Date: (06/10/2025)
This is the interface for the Firecat class, an inherted class from the Creature one, with getter, setters, data members, etc. */

#ifndef FIRECAT_HPP_
#define FIRECAT_HPP_
#include "Creature.hpp"

class Firecat: public Creature {
public:
    enum FlameColor{RED, ORANGE, BLUE, WHITE};
    Firecat();
    Firecat(const std::string& name, const Category& category = ANIMAL, const School& school = FIRE, const int& health = 1, const int& level = 1, const bool& isHostile = 0, const FlameColor& flameColor = ORANGE, const int& flameIntensity = 1, const bool& arsonist = 0);
    void setFlameColor(const FlameColor& flameColor);
    std::string getFlameColor() const;
    bool setFlameIntensity(const int& flameIntensity);
    int getFlameIntensity() const;
    void setArsonist(const bool& arsonist);
    bool isArsonist() const;
    void display() const override;
    friend bool operator==(const Firecat& firecat1, const Firecat& firecat2);

private:
    FlameColor flameColor_;
    int flameIntensity_;
    bool arsonist_;
};
#endif