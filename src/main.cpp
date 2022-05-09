#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <time.h>
#include <conio.h>
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
        if(bM.getBunnyListSize() > 1000)
        {
            bM.cullHalfBunnies();
        }
        std::cout << std::endl;
        bM.showBunnies();
        
        std::cout << "Press k to kill half bunnies" << std::endl;
        float timer = 0;
        while(timer < 2)
        {
            if(_kbhit())
            {
                char userInput = getch();
                if(userInput == 'k' || userInput == 'K')
                {
                    bM.cullHalfBunnies();
                }
                timer = 2;
            }
            else 
            {
                std::this_thread::sleep_for (std::chrono::milliseconds(100));
                timer += 0.1;
            }
        }
    }while(!bM.isBunnyListEmpty());

    return 0;
}