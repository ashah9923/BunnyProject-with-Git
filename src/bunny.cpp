#include <iostream>
#include "../include/bunny.h"

Bunny::Bunny()
{
    
    // -- SET GENDER -- //
    int randNum = rand() % 2;
    isMale = (randNum == 0);

    // if randNum
    
    // -- SET AGE -- //

    age = 0;

    // -- SET NAME -- //
    
    name = randNames[rand() % 20];

    // -- SET COLOUR -- //

    randNum = rand() % 40;

    if(randNum <= 10)
    {
        bunnyColour = colour::white;
    }
    else if(randNum > 10 && randNum <= 20)
    {
        bunnyColour = colour::brown;
    }
    else if(randNum > 20 && randNum <= 30)
    {
        bunnyColour = colour::black;
    }
    else
    {
        bunnyColour = colour::spotted;
    }

    // --RADIOACTIVE-- //
    int randNum2 = rand() % 100;

    if(randNum2 < 2)
    {
        infected = true;
    }
    else
    {
        infected = false;
    }
}

Bunny::Bunny(colour motherCol)
{
    
    // -- SET GENDER -- //
    int randNum = rand() % 2;
    isMale = (randNum == 0);

    // something  like randNum==0 ? (isMale):(false) for above
    
    // -- SET AGE -- //

    age = 0;

    // -- SET NAME -- //
    
    name = randNames[rand()%10];

    // -- SET COLOUR -- //

    bunnyColour = motherCol;
    
    // --RADIOACTIVE-- //
    int randNum2 = rand() % 100;

    if(randNum2 < 2)
    {
        infected = true;
    }
    else
    {
        infected = false;
    }
}

void Bunny::setInfected(bool radio)
{
    infected = radio;
}

bool Bunny::isInfected()
{
    return infected;
}

std::string Bunny::getInfected()
{
    return (infected) ? ("Infected") : ("Normal");
}

int Bunny::getAge()
{
    return age;
}

void Bunny::incrementAge()
{
    age++;
}

std::string Bunny::getName()
{
    return name;
}

std::string Bunny::getGender()
{
    return (isMale) ? ("Male") : ("Female");
}

std::string Bunny::getColourAsString()
{
    switch (bunnyColour)
    {
        case colour::white: {
            return "white";
        }
        case colour::brown: {
            return "brown";
        }
        case colour::black: {
            return "black";
        }
        case colour::spotted: {
            return "spotted";
        }
    }
    return "";
}

colour Bunny::getColourAsEnum()
{
    return bunnyColour;
}