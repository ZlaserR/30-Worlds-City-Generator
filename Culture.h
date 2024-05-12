//
// Created by zacru on 5/9/2024.
//

#ifndef INC_30_WORLDS_CITY_GENERATOR_CULTURE_H
#define INC_30_WORLDS_CITY_GENERATOR_CULTURE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include "Culture.h"
using namespace std;

class Culture {
protected:
    string name;
    string firstNameFileM;
    string firstNameFileF;
    string lastNameFile;
    string specializationsFile;

public:

    Culture();

    // Getters
    string getName() const;
    string getFirstNameFileM() const;
    string getFirstNameFileF() const;
    string getLastNameFile() const;
    string getSpecializationsFile() const;

    // Setters
    void setName(const string& newName);
    void setFirstNameFileM(const string& newFileName);
    void setFirstNameFileF(const string& newFileName);
    void setLastNameFile(const string& newFileName);
    void setSpecializationsFile(const string& newFileName)
};


#endif //INC_30_WORLDS_CITY_GENERATOR_CULTURE_H
