//
// Created by zacru on 5/13/2024.
//

#include "NotableLocation.h"

NotableLocation::NotableLocation() {
    locationName = "none";
    locationType = "none";
    clearRelevantNPCs();
    wealthLevel = 0.0;
}

NotableLocation::NotableLocation(const District& pDistrict, double pWealthLevel) {
    locationName = "none";
    locationType = "none";
    district = pDistrict;
    clearRelevantNPCs();
    wealthLevel = pWealthLevel;
}

// Getters
string NotableLocation::getLocationName() const {
    return locationName;
}

string NotableLocation::getLocationType() const {
    return locationType;
}

District NotableLocation::getDistrict() const {
    return district;
}

NPC NotableLocation::getImportantNPC() const {
    return importantNPC;
}

double NotableLocation::getWealthLevel() const {
    return wealthLevel;
}

vector<NPC> NotableLocation::getRelevantNPCs() const {
    return relevantNPCs;
}

Culture NotableLocation::getCulture() const {
    return culture;
}

string NotableLocation::getLocationOccupation() const {
    return locationOccupation;
}

// Setters
void NotableLocation::setLocationName(const string& newName) {
    locationName = newName;
}

void NotableLocation::setLocationType(const string& newType) {
    locationType = newType;
}

void NotableLocation::setDistrict(const District& newDistrict) {
    district = newDistrict;
}

void NotableLocation::setImportantNPC(const NPC& newNPC) {
    importantNPC = newNPC;
}

void NotableLocation::setWealthLevel(double newWealthLevel) {
    wealthLevel = newWealthLevel;
}

void NotableLocation::setRelevantNPCs(const vector<NPC>& newNPCs) {
    relevantNPCs = newNPCs;
}

void NotableLocation::setCulture(const Culture &newCulture) {
    culture = newCulture;
}

void NotableLocation::setLocationOccupation(const string &newLocatOccup) {
    locationOccupation = newLocatOccup;
}

void NotableLocation::addRelevantNPC(const NPC& newNPC) {
    relevantNPCs.push_back(newNPC);
}

void NotableLocation::clearRelevantNPCs() {
    relevantNPCs.clear();
}

// Generate Functions
void NotableLocation::generate_location() {
    generate_wealthLevel();
    generate_locationType();
}

void NotableLocation::generate_locationType() {
    random_device rd;
    mt19937 gen(rd());
    string inputFile = culture.getNotableLocationsFile();

    vector<string> rawLocatList = get_file_info(inputFile);

    // Translating occupation list into comparable information
    vector<vector<string>> locatList;
    vector<string> locatData;
    for (const auto &locat: rawLocatList) {
        if (locat != "") {
            locatData = split_string(locat, ',');
            locatList.push_back(locatData);
        }
    }

    int foundType = 0;
    while (foundType == 0) {
        uniform_int_distribution<int> distribution(0, locatList.size() - 1);
        int randNumber = distribution(gen);
        vector<string> newLocat = locatList[randNumber];
        string locatName = newLocat[0];
        string locatOccup = newLocat[1];
        string locatDist = newLocat[2];
        double wMax = stod(newLocat[3]);
        double wMin = stod(newLocat[4]);

        if (wMax >= getWealthLevel() && wMin <= getWealthLevel() && locatDist == district.getDistrictSpecialization() || locatDist == "all") {
            setLocationType(locatName);
            setLocationOccupation(locatOccup);
            foundType = 1;
        }
    }
}

void NotableLocation::generate_importantNPC() {

}

void NotableLocation::generate_relevantNPCs() {

}

void NotableLocation::generate_locationName() {

}

void NotableLocation::generate_wealthLevel() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 200);
    int randNumber = distribution(gen);
    double randWealthLevel = static_cast<double>(randNumber) / 10;
    setWealthLevel(randWealthLevel);
}

// Other Functions
void NotableLocation::print() const {

}

vector<string> NotableLocation::get_file_info(const string &Input_File) {
    vector<string> item_List;
    ifstream Reading_File(Input_File.c_str());
    string line;
    while (getline(Reading_File, line)) {
        item_List.push_back(line);
    }
    Reading_File.close();
    return item_List;
}

vector<string> NotableLocation::split_string(const string &input, char del) {
    vector<string> result;
    istringstream stream(input);
    string token;

    while (getline(stream, token, del)) {
        result.push_back(token);
    }
    return result;
}
