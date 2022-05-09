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

    return 0;
}