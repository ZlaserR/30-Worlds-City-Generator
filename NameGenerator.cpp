//
// Created by zacru on 5/9/2024.
//

#include "NameGenerator.h"
using namespace std;



NameGenerator::NameGenerator() {
    name = "none";
    sex = "none";
}

NameGenerator::NameGenerator(Culture pCulture, string pSex) {
    name = "none";
    sex = pSex;
    setCulture(pCulture);
}

// Getters
string NameGenerator::getName() const {
    return name;
}

// Setters
void NameGenerator::setName(const string &newName) {
    name = newName;
}

Culture NameGenerator::getCulture() const {
    return culture;
}

void NameGenerator::setCulture(const Culture &newCulture) {
    culture = newCulture;
}

string NameGenerator::getSex() const {
    return sex;
}

void NameGenerator::setSex(const string &newSex) {
    sex = newSex;
}

void NameGenerator::make_name() {
    srand(time(0));
    string First_Name_Input;
    if (getSex() == "Male") {
        First_Name_Input = culture.getFirstNameFileM();
    } else {
        First_Name_Input = culture.getFirstNameFileF();
    }
    string Last_Name_Input = culture.getLastNameFile();

    int LN_Syl_Max = 3;
    int LN_Syl_CharMin = 0;
    int FN_Min = 2;
    int LN_Min = 1;

    vector<std::string> NameF, NameL;
    string Name;
    int Syl_Num_Start = 2; // Initial value in Python code was 2
    int Syl_NumF = Syl_Num_Start;
    int Syl_NumL = rand() % LN_Syl_Max + 1;
    while (Syl_NumF != 0) {
        string New_Syl = get_Syls(First_Name_Input);
        while (New_Syl.length() <= FN_Min) {
            New_Syl = get_Syls(Last_Name_Input);
        }
        NameF.push_back(New_Syl);
        --Syl_NumF;
    }
    string concatenatedF;
    for (const auto& syl : NameF) {
        concatenatedF += syl;
    }
    string NameF_string = concatenatedF;
    NameF_string[0] = toupper(NameF_string[0]);
    while (Syl_NumL != 0) {
        string New_Syl = get_Syls(Last_Name_Input);
        if (Syl_NumL != 1 && New_Syl.length() <= LN_Syl_CharMin) {
            NameL.push_back(New_Syl);
        } else {
            while (New_Syl.length() <= LN_Min) {
                New_Syl = get_Syls(Last_Name_Input);
            }
            NameL.push_back(New_Syl);
            --Syl_NumL;
        }
    }
    string concatenatedL;
    for (const auto& syl : NameL) {
        concatenatedL += syl;
    }
    string NameL_string = concatenatedL;
    NameL_string[0] = toupper(NameL_string[0]);
    Name.append(NameF_string);
    Name.append(" ");
    Name.append(NameL_string);
    setName(Name);

}

string NameGenerator::get_Syls(const string &Input_File) {
    vector<string> Syl_List;
    int Num_of_Syls = 0;
    ifstream Reading_File(Input_File.c_str());
    string line;
    while (getline(Reading_File, line)) {
        Syl_List.push_back(line);
        Num_of_Syls += 1;
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
