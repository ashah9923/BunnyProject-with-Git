#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <time.h>
#include "../include/manager.h"

int main()
{
    system("cls"); 
    //below fixes clear screen for debugger
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    fflush(stdout);
    srand(time(NULL));

    Manager bM;
    std::this_thread::sleep_for (std::chrono::seconds(2));
    char userInput;
    std::cout << "Press q to exit" << std::endl;

    do
    {
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
        fflush(stdout);
        bM.ageAllBunnies();
        bM.turnBunnyRadioActive(bM.numOfRadioActive());
        std::this_thread::sleep_for (std::chrono::seconds(1));
        if(bM.isBreedableMale())
        {
            bM.createBabies();
        };
        std::this_thread::sleep_for (std::chrono::seconds(1));
        bM.cullHalfBunnies();
        std::cout << std::endl;
        bM.showBunnies();
        std::this_thread::sleep_for (std::chrono::seconds(2));

    }while(!bM.isBunnyListEmpty());

    return 0;
}