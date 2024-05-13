#include "Culture.h"

Culture::Culture() {
    name = "Default";
    firstNameFileM = "../CultureFiles/Default/FirstNamesM.txt";
    firstNameFileF = "../CultureFiles/Default/FirstNamesF.txt";
    lastNameFile = "../CultureFiles/Default/LastNames.txt";
    specializationsFile = "../CultureFiles/Default/DistrictSpecialization.txt";
    occupationFile = "../CultureFiles/Default/Occupation.txt";
    notableLocationsFile = "../CultureFiles/Default/NotableLocationsTypes.txt";
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

string Culture::getOccupationFile() const {
    return occupationFile;
}

string Culture::getNotableLocationsFile() const {
    return notableLocationsFile;
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

void Culture::setOccupationFile(const string& newFileName) {
    occupationFile = newFileName;
}

void Culture::setNotableLocationsFile(const string &newFileName) {
    notableLocationsFile = newFileName;
}
