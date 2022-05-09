#ifndef BUNNYMANAGER_H
#define BUNNYMANAGER_H

#include <iostream>
#include <list>
#include <memory>
#include "bunny.h"

const int MAX_NORMAL_BUNNY_AGE = 10;
const int MAX_RADIOACTIVE_BUNNY_AGE = 50;
const int MIN_BREEDABLE_AGE = 2;


class Manager
{
    private:
    std::list<Bunny> bunnyList; 
    public:
        Manager();
        void addBunny();
        void showBunnies();
        void ageAllBunnies();
        bool isBreedableMale();
        void createBabies();
        void addBunny(colour);
        int numOfRadioActive();
        void turnBunnyRadioActive(int);
};
#endif