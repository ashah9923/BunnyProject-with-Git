#ifndef BUNNYMANAGER_H
#define BUNNYMANAGER_H

#include <iostream>
#include <list>
#include <memory>
#include "bunny.h"

const int MAX_NORMAL_BUNNY_AGE = 10;
const int MAX_INFECTED_BUNNY_AGE = 50;
const int MIN_BREEDABLE_AGE = 2;


class Manager
{
    private:
    std::list<std::shared_ptr<Bunny>> bunnyList; 
    public:
        Manager();
        void addBunny();
        void showBunnies();
        void ageAllBunnies();
        bool isBreedableMale();
        void createBabies();
        void addBunny(colour);
        int numOfInfected();
        void turnBunnyInfected(int);
        void cullHalfBunnies();
        bool isBunnyListEmpty();
        int getBunnyListSize();
        void runProgramme();
};
#endif