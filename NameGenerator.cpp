//
// Created by zacru on 5/9/2024.
//

#include "NameGenerator.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
using namespace std;

const int ZERO = 0;
const int ONE = 1;


NameGenerator::NameGenerator() {

}

string NameGenerator::get_Syls(const string &Input_File) {
    vector<string> Syl_List;
    int Num_of_Syls = 0;
    ifstream Reading_File(Input_File.c_str());
    string line;
    while (getline(Reading_File, line)) {
        Syl_List.push_back(line);
        Num_of_Syls += ONE;
    }
    Reading_File.close();
    int Choice_Num = rand() % Num_of_Syls;
    string Syl = Syl_List[Choice_Num];
    return Syl;
}

string NameGenerator::get_valid_answer(vector<string> vecAnswers) {
    string strAnswer;
    for (const auto& str : vecAnswers) {
        strAnswer += str;
        strAnswer += ", ";
    }

    string inputChar;
    // correct variable used to ensure that the while loop still runs until a correct input has been entered
    int correct = 0;
    while (correct == 0) {
        // Getting the input from the user
        getline(cin, inputChar);
        auto inputVal = find(vecAnswers.begin(), vecAnswers.end(), inputChar);
        if (inputVal == vecAnswers.end()) { // corrected condition
            cout << "Invalid input. Enter " << strAnswer << "\n Enter: ";
        } else if (inputChar == "" || inputChar == " ") { // If the input is white space or nothing then will reprompt the user
            cout << "No input. Enter " << strAnswer << "\n Enter: ";
        } else { // Marking as the input being within the correct parameters the loop then exits
            correct = 1;
        }
    }
    return inputChar;
}
