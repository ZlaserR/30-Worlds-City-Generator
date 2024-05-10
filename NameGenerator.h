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
using namespace std;

class NameGenerator {

    NameGenerator();

    string get_valid_answer(vector<string> vecAnswers);

    string get_Syls(const string& Input_File);

};


#endif //INC_30_WORLDS_CITY_GENERATOR_NAMEGENERATOR_H
