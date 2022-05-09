#ifndef BUNNY_H
#define BUNNY_H

#include <iostream>

enum colour{white, brown, black, spotted};

class Bunny
{
    private:
    bool isMale;
    int age;
    std::string name;
    bool RadioActive;
    colour bunnyColour; //instance of enum

    public:
    Bunny();
    Bunny(colour);
    const std::string randNames[10] = {"Vince","Hershey","Hunter","Egor","Freckles",
                                       "Danni","Apollo","Napoleon","Ginny","Gucci"};
    
    void incrementAge();
    void setRadioActive(bool);
    int getAge();
    bool isRadioActive();
    std::string getRadioActive();
    std::string getName();
    std::string getGender();
    std::string getColourAsString();
    colour getColourAsEnum();
};
#endif