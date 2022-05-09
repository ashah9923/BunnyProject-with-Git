#include <iostream>
#include <memory>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "../include/manager.h"

Manager::Manager()
{
    addBunny();
    addBunny();
    addBunny();
    addBunny();
    addBunny();
}

void Manager::addBunny()
{
    Bunny newBunny = Bunny();
    std::cout << "A " << newBunny.getRadioActive() << " "<< newBunny.getColourAsString() << " " << newBunny.getGender() << " bunny named " << newBunny.getName() << " was created" << std::endl;
    bunnyList.push_back(newBunny);
}

void Manager::addBunny(colour bunnyMotherCol)
{
    Bunny newBunny = Bunny(bunnyMotherCol);
    std::cout << "A " << newBunny.getRadioActive() << " "<< newBunny.getColourAsString() << " " << newBunny.getGender() << " bunny named " << newBunny.getName() << " was created" << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(1));
    bunnyList.push_back(newBunny);
}



void Manager::ageAllBunnies()
{
    std::list<Bunny>::iterator bunny = bunnyList.begin();
    while(bunny != bunnyList.end()) 
    {
        bunny->incrementAge();
        if((bunny->getAge() > MAX_NORMAL_BUNNY_AGE && !bunny->isRadioActive()) || bunny->getAge() > MAX_RADIOACTIVE_BUNNY_AGE)
        {
            std::cout << "A " << bunny->getRadioActive() << " "<< bunny->getColourAsString() << " " << bunny->getGender() << " bunny named " << bunny->getName() << " has died " << std::endl;
            bunnyList.erase(bunny++);           //erases bunny then moves to next bunny 
        }
        else{
            ++bunny;
        }
    }

}

void Manager::showBunnies()
{
    std::list<Bunny>::iterator bunny;
    for(bunny = bunnyList.begin(); bunny != bunnyList.end(); ++bunny) // iterator is a pointer, reset l.begin in for loop after inserting new elements
    {
         std::cout << "A " << bunny->getRadioActive() << " " << 
         bunny->getAge() << " yr old " << 
         bunny->getColourAsString() << " " << 
         bunny->getGender() << " bunny named " << 
         bunny->getName() << std::endl;
    }
}

bool Manager::isBreedableMale()
{
    std::list<Bunny>::iterator bunny = bunnyList.begin();
    while(bunny != bunnyList.end()) // iterator is a pointer, reset l.begin in for loop after inserting new elements
    {
        if((bunny->getAge() >= MIN_BREEDABLE_AGE && !bunny->isRadioActive()) && bunny->getGender() == "Male" )
        {
            return true;           //i.e bunny is breedable male 
        }
        ++bunny;
    }
    return false;
}

void Manager::createBabies()
{
    std::list<Bunny>::iterator bunny;
    for(bunny = bunnyList.begin(); bunny != bunnyList.end(); ++bunny)
    {
        if((bunny->getAge() >= MIN_BREEDABLE_AGE && !bunny->isRadioActive()) && bunny->getGender() == "Female")
        {
            addBunny(bunny->getColourAsEnum());
        }
    }
}

int Manager::numOfRadioActive()
{
    int numOfRadioAcive = 0;
    std::list<Bunny>::iterator bunny;
    for(bunny = bunnyList.begin(); bunny != bunnyList.end(); ++bunny)
    {
        if((bunny->isRadioActive()))
        {
            numOfRadioAcive++;
        }
    }
    return numOfRadioAcive;
}

void Manager::turnBunnyRadioActive(int radioActiveNum)
{
    int turnedBunnies = 0;
    std::list<Bunny>::iterator bunny;
    for(bunny = bunnyList.begin(); bunny != bunnyList.end(); ++bunny)
    {
        if(turnedBunnies == radioActiveNum)
        {
            return;
        }
        else if((!bunny->isRadioActive()))
        {
            bunny->setRadioActive(true);
            turnedBunnies++;
        }
    }
}
