#include <iostream>
#include <memory>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <conio.h>
#include "../include/manager.h"

Manager::Manager()
{
    srand(time(NULL));
    addBunny();
    addBunny();
    addBunny();
    addBunny();
    addBunny();
    std::this_thread::sleep_for (std::chrono::seconds(2));
    runProgramme();
}

void Manager::addBunny()
{
    std::shared_ptr<Bunny> newBunny(new Bunny());
    std::cout << "A " << newBunny->getRadioActive() << " "<< newBunny->getColourAsString() << " " << newBunny->getGender() << " bunny named " << newBunny->getName() << " was created" << std::endl;
    bunnyList.push_back(newBunny);
}

void Manager::addBunny(colour bunnyMotherCol)
{
    std::shared_ptr<Bunny> newBunny(new Bunny(bunnyMotherCol));
    std::cout << "A " << newBunny->getRadioActive() << " "<< newBunny->getColourAsString() << " " << newBunny->getGender() << " bunny named " << newBunny->getName() << " was created" << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(1));
    bunnyList.push_back(newBunny);
}



void Manager::ageAllBunnies()
{
    std::list<std::shared_ptr<Bunny>>::iterator bunny = bunnyList.begin();
    while(bunny != bunnyList.end()) 
    {
        (*bunny)->incrementAge();
        if(((*bunny)->getAge() > MAX_NORMAL_BUNNY_AGE && !(*bunny)->isRadioActive()) || (*bunny)->getAge() > MAX_RADIOACTIVE_BUNNY_AGE)
        {
            std::cout << "A " << (*bunny)->getRadioActive() << " "<< (*bunny)->getColourAsString() << " " << (*bunny)->getGender() << " bunny named " << (*bunny)->getName() << " has died " << std::endl;
            bunnyList.erase(bunny++);           //erases bunny then moves to next bunny 
        }
        else{
            ++bunny;
        }
    }

}

void Manager::showBunnies()
{
    std::list<std::shared_ptr<Bunny>>::iterator bunny;
    for(bunny = bunnyList.begin(); bunny != bunnyList.end(); ++bunny) // iterator is a pointer, reset l.begin in for loop after inserting new elements
    {
         std::cout << "A " << (*bunny)->getRadioActive() << " " << 
         (*bunny)->getAge() << " yr old " << 
         (*bunny)->getColourAsString() << " " << 
         (*bunny)->getGender() << " bunny named " << 
         (*bunny)->getName() << std::endl;
    }
}

bool Manager::isBreedableMale()
{
    std::list<std::shared_ptr<Bunny>>::iterator bunny = bunnyList.begin();
    while(bunny != bunnyList.end()) // iterator is a pointer, reset l.begin in for loop after inserting new elements
    {
        if(((*bunny)->getAge() >= MIN_BREEDABLE_AGE && !(*bunny)->isRadioActive()) && (*bunny)->getGender() == "Male" )
        {
            return true;           //i.e bunny is breedable male 
        }
        ++bunny;
    }
    return false;
}

void Manager::createBabies()
{
    std::list<std::shared_ptr<Bunny>>::iterator bunny;
    for(bunny = bunnyList.begin(); bunny != bunnyList.end(); ++bunny)
    {
        if(((*bunny)->getAge() >= MIN_BREEDABLE_AGE && !(*bunny)->isRadioActive()) && (*bunny)->getGender() == "Female")
        {
            addBunny((*bunny)->getColourAsEnum());
        }
    }
}

int Manager::numOfRadioActive()
{
    int numOfRadioAcive = 0;
    std::list<std::shared_ptr<Bunny>>::iterator bunny;
    for(bunny = bunnyList.begin(); bunny != bunnyList.end(); ++bunny)
    {
        if(((*bunny)->isRadioActive()))
        {
            numOfRadioAcive++;
        }
    }
    return numOfRadioAcive;
}

void Manager::turnBunnyRadioActive(int radioActiveNum)
{
    int turnedBunnies = 0;
    std::list<std::shared_ptr<Bunny>>::iterator bunny;
    for(bunny = bunnyList.begin(); bunny != bunnyList.end(); ++bunny)
    {
        if(turnedBunnies == radioActiveNum)
        {
            return;
        }
        else if((!(*bunny)->isRadioActive()))
        {
            (*bunny)->setRadioActive(true);
            turnedBunnies++;
        }
    }
}

void Manager::cullHalfBunnies()
{
    std::list<std::shared_ptr<Bunny>>::iterator bunny;
    
        for (int i = 0; i < bunnyList.size()/2; i++) 
        {
            int randomBunny = rand() % bunnyList.size();
            bunny = bunnyList.begin();
            std::advance(bunny, randomBunny);
            bunnyList.erase(bunny);
            bunny = bunnyList.begin();
            //it = nullptr;
	    }
    return;
}

bool Manager::isBunnyListEmpty()
{
    if(bunnyList.empty())
    {
        std::cout << "All bunnies have died.." << std::endl;
        return true;
    }
    return false;
}

int Manager::getBunnyListSize()
{
    return bunnyList.size();
}

void Manager::runProgramme()
{
    system("cls"); 
    //below fixes clear screen for debugger
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    fflush(stdout);
    do
    {
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
        fflush(stdout);
        
        ageAllBunnies();
        turnBunnyRadioActive(numOfRadioActive());
        std::this_thread::sleep_for (std::chrono::seconds(1));
        if(isBreedableMale())
        {
            createBabies();
        };
        std::this_thread::sleep_for (std::chrono::seconds(1));
        if(getBunnyListSize() > 1000)
        {
            cullHalfBunnies();
        }
        std::cout << std::endl;
        showBunnies();
        
        std::cout << "Press k to kill half bunnies" << std::endl;
        float timer = 0;
        while(timer < 2)
        {
            if(_kbhit())
            {
                char userInput = getch();
                if(userInput == 'k' || userInput == 'K')
                {
                    cullHalfBunnies();
                }
                timer = 2;
            }
            else 
            {
                std::this_thread::sleep_for (std::chrono::milliseconds(100));
                timer += 0.1;
            }
        }
    }while(!isBunnyListEmpty());
}