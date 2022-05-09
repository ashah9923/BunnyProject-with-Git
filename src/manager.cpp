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