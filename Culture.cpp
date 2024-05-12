#include "Culture.h"

Culture::Culture() {
    name = "Default";
    firstNameFileM = "../CultureFiles/Default/FirstNamesM.txt";
    firstNameFileF = "../CultureFiles/Default/FirstNamesF.txt";
    lastNameFile = "../CultureFiles/Default/LastNames.txt";
    specializationsFile = "../CultureFiles/Default/DistrictSpecialization.txt";
}

// Getters
string Culture::getName() const {
    return name;
}

string Culture::getFirstNameFileM() const {
    return firstNameFileM;
}

string Culture::getFirstNameFileF() const {
    return firstNameFileF;
}

string Culture::getLastNameFile() const {
    return lastNameFile;
}

string Culture::getSpecializationsFile() const {
    return specializationsFile;
}

// Setters
void Culture::setName(const string& newName) {
    name = newName;
}

void Culture::setFirstNameFileM(const string& newFileName) {
    firstNameFileM = newFileName;
}

void Culture::setFirstNameFileF(const string& newFileName) {
    firstNameFileF = newFileName;
}

void Culture::setLastNameFile(const string& newFileName) {
    lastNameFile = newFileName;
}

void Culture::setSpecializationsFile(const string& newFileName) {
    specializationsFile = newFileName;
}
