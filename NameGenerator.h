//
// Created by zacru on 5/9/2024.
//

#ifndef INC_30_WORLDS_CITY_GENERATOR_NAMEGENERATOR_H
#define INC_30_WORLDS_CITY_GENERATOR_NAMEGENERATOR_H

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

class NameGenerator {
protected:
    string name;
    Culture culture;
    string sex;

public:
    NameGenerator();

    ~NameGenerator() = default;

    explicit NameGenerator(Culture pCulture, string pSex);

    string getName() const;
    Culture getCulture() const;
    string getSex() const;

    void setCulture(const Culture& newCulture);
    void setName(const string& newName);
    void setSex(const string& newSex);

    void make_name();

    string get_valid_answer(vector<string> vecAnswers);

    static string get_Syls(const string& Input_File);

};


#endif //INC_30_WORLDS_CITY_GENERATOR_NAMEGENERATOR_H
