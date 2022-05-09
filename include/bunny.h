#ifndef BUNNY_H
#define BUNNY_H

#include <iostream>
#include <vector>

enum colour{white, brown, black, spotted};

class Bunny
{
    private:
    bool isMale;
    int age;
    std::string name;
    bool infected;
    colour bunnyColour; //instance of enum
    const std::string randNames[20] = {"Vince","Hershey","Hunter","Egor","Freckles",
                                        "Danni","Apollo","Napoleon","Ginny","Gucci",
                                        "Fudge", "Cupcake", "Butternut", "Amore", "Nellie", 
                                        "Precious", "Vanilla", "Noisette", "Paisley", "Brie"};
    public:
    Bunny();
    explicit Bunny(colour);
    void incrementAge();
    void setInfected(bool);
    int getAge();
    bool isInfected();
    std::string getInfected();
    std::string getName();
    std::string getGender();
    std::string getColourAsString();
    colour getColourAsEnum();
};
#endif