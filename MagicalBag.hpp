/* Name: Khalid Young
Date: (06/10/2025)
This is the interface for the MagicalBag template class, with getter, setters, data members, etc. */

#ifndef MAGICALBAG_HPP_
#define MAGICALBAG_HPP_
#include "Creature.hpp"

template<class T>
class MagicalBag{
public:
    MagicalBag();
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const T& newEntry);
    bool remove(const T& anEntry);
    void clear();
    bool contains(const T& target);
    std::vector<T> toVector() const;
protected:
    static const int DEFAULT_CAPACITY = 100;
    T items_[DEFAULT_CAPACITY];
    int item_count_;
};
#include "MagicalBag.cpp"
#endif