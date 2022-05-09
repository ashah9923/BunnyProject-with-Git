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

