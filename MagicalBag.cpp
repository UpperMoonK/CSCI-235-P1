/* Name: Khalid Young
Date: (06/10/2025)
This is the implementation for the MagicalBag template class, with getter, setters, data members, etc. */

#include "MagicalBag.hpp"

/**
Default Constructor
*/
template<class T>
MagicalBag<T>::MagicalBag(){
    this->item_count_ = 0;
} 

/**
@return: the current number of items
*/
template<class T>
int MagicalBag<T>::getCurrentSize() const{
    return item_count_;
}

/**
@return: true if our bag is empty, false otherwise
*/
template<class T>
bool MagicalBag<T>::isEmpty() const{
    if(item_count_ == 0){
        return 1;
    }
    return 0;
}

/**
@post: If entry exists in bag, do nothing
@return: true if newEntry was successfully added to our array, false
otherwise
*/
template<class T> 
bool MagicalBag<T>::add(const T& newEntry){
    bool has_space = (item_count_ < DEFAULT_CAPACITY);
    if(has_space){
        items_[item_count_] = newEntry;
        item_count_++;
    }
    return has_space;
}

/**
@return: true if anEntry was successfully removed from our array, false
otherwise
*/
template<class T>
bool MagicalBag<T>::remove(const T& anEntry){
    for(int i = 0; i < item_count_; i++){
        if(items_[i] == anEntry){
            item_count_--;
            items_[i] = items_[item_count_];
            return 1;
        }
    }
    return 0;
}

/**
@post: clears bag
*/
template<class T>
void MagicalBag<T>::clear(){
    item_count_ = 0;
}

/**
@return: true if anEntry is found in our array, false otherwise
*/
template<class T>
bool MagicalBag<T>::contains(const T& target) {
    for(int i = 0; i < item_count_; i++){
        if(items_[i] == target){
            return 1;
        }
    }
    return 0;
}

/**
@return: Helper to put the full MagicalBag contents in a readable array form
*/
template<class T>
std::vector<T> MagicalBag<T>::toVector() const{
    std::vector<T> battlers_;
    for(int i = 0; i < item_count_; i++){
        battlers_.push_back(items_[i]);
    }
    return battlers_;
}



