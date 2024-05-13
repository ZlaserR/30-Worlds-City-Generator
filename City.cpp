#include "City.h"

City::City() {

}

// Getters
string City::getCityName() const {
    return cityName;
}

vector<District> City::getDistricts() const {
    return districts;
}

string City::getSizeCategory() const {
    return sizeCategory;
}

int City::getSize() const {
    return size;
}

double City::getWealthLevel() const {
    return wealthLevel;
}

Culture City::getPrimaryCulture() const {
    return primaryCulture;
}

vector<Culture> City::getCultureGroups() const {
    return cultureGroups;
}


vector<string> City::getLocalResources() const {
    return localResources;
}

// Setters
void City::setCityName(const string& newName) {
    cityName = newName;
}

void City::setDistricts(const vector<District>& newDistricts) {
    districts = newDistricts;
}

void City::setSizeCategory(const string& newSizeCategory) {
    sizeCategory = newSizeCategory;
}

void City::setSize(int newSize) {
    size = newSize;
}

void City::setWealthLevel(double newWealthLevel) {
    wealthLevel = newWealthLevel;
}

void City::setPrimaryCulture(const Culture& newPrimaryCulture) {
    primaryCulture = newPrimaryCulture;
}

void City::setCultureGroups(const vector<Culture>& newCultureGroups) {
    cultureGroups = newCultureGroups;
}


void City::setLocalResources(const vector<string>& newLocalResources) {
    localResources = newLocalResources;
}

// Functions to add elements to vectors and clear them
void City::addDistrict(const District& newDistrict) {
    districts.push_back(newDistrict);
}

void City::clearDistricts() {
    districts.clear();
}

void City::addCultureGroup(const Culture& newCulture) {
    cultureGroups.push_back(newCulture);
}

void City::clearCultureGroups() {
    cultureGroups.clear();
}

void City::addLocalResource(const string& newResource) {
    localResources.push_back(newResource);
}

void City::clearLocalResources() {
    localResources.clear();
}

// Generate Functions
void City::generate_city() {

}

void City::generate_size() {

}

void City::generate_districts() {

}


// Other Functions
void City::print() const {

}

vector<string> City::get_file_info(const string &Input_File) {
    vector<string> item_List;
    ifstream Reading_File(Input_File.c_str());
    string line;
    while (getline(Reading_File, line)) {
        item_List.push_back(line);
    }
    Reading_File.close();
    return item_List;
}

vector<string> City::split_string(const string &input, char del) {
    vector<string> result;
    istringstream stream(input);
    string token;

    while (getline(stream, token, del)) {
        result.push_back(token);
    }
    return result;
}
