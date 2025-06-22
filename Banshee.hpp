/* Name: Khalid Young
Date: (06/10/2025)
This is the interface for the Banshee class, an inherted class from the Creature one, with getter, setters, data members, etc. */

#ifndef BANSHEE_HPP_
#define BANSHEE_HPP_
#include "Creature.hpp"


class Banshee: public Creature {
public:
    enum Aura{RED, BLUE, GRAY, GREEN}; 
    Banshee();
    Banshee(const std::string& name, const Category& category = UNDEAD, const School& school = DEATH, const int& health = 1, const int& level = 1, const bool& isHostile = 0, const Aura& spectralAura = RED, const int& screamVolume = 1, const bool& fearInducing = 0);
    void setAura(const Aura& spectralAura);
    std::string getAura() const;
    bool setScreamVolume(const int& screamVolume);
    int getScreamVolume() const;
    void setFearInducing(const bool& fearInducing);
    bool isFearInducing() const;
    void display() const override;
    friend bool operator==(const Banshee& banshee1, const Banshee& banshee2);

private:
    Aura spectralAura_;
    int screamVolume_;
    bool fearInducing_;
};

#endif