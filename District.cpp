
#include "District.h"
#include "NotableLocation.h"
#include "City.h"

District::District() {
    districtName = "none";
    districtSpecialization = "none";
    size = 0;
    wealthLevel = 0.0;
    clearNotableLocations();
}

District::District(const City& pCity, const Culture& pCulture, double pWealthLevel, int pSize) {
    districtName = "none";
    districtSpecialization = "none";
    size = pSize;
    wealthLevel = pWealthLevel;
    clearNotableLocations();
    setCity(pCity);
    setCulture(pCulture);
}

// Getters
string District::getDistrictName() const {
    return districtName;
}

string District::getDistrictSpecialization() const {
    return districtSpecialization;
}

int District::getSize() const {
    return size;
}

double District::getWealthLevel() const {
    return wealthLevel;
}

City District::getCity() const {
    return city;
}

Culture District::getCulture() const {
    return culture;
}

vector<NotableLocation> District::getNotableLocations() const {
    return notableLocations;
}

// Setters
void District::setDistrictName(const string& newName) {
    districtName = newName;
}

void District::setDistrictSpecialization(const string& newSpecialization) {
    districtSpecialization = newSpecialization;
}

void District::setSize(int newSize) {
    size = newSize;
}

void District::setWealthLevel(double newWealthLevel) {
    wealthLevel = newWealthLevel;
}

void District::setCity(const City& newCity) {
    city = newCity;
}

void District::setCulture(const Culture& newCulture) {
    culture = newCulture;
}

void District::setNotableLocations(const vector<NotableLocation>& newLocations) {
    notableLocations = newLocations;
}

// Functions to add elements to notableLocations and clear it
void District::addNotableLocation(const NotableLocation& newLocation) {
    notableLocations.push_back(newLocation);
}

void District::clearNotableLocations() {
    notableLocations.clear();
}

// Generate Functions
void District::generate_district() {

}

void District::generate_specialization() {

}

void District::generate_notableLocations() {

}

void District::generate_name() {

}

void District::generate_wealthLevel() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 200);
    int randNumber = distribution(gen);
    double randWealthLevel = static_cast<double>(randNumber) / 10;
    setWealthLevel(randWealthLevel);
}

// Other Functions
void District::print() const {

}

vector<string> District::get_file_info(const string &Input_File) {
    vector<string> item_List;
    ifstream Reading_File(Input_File.c_str());
    string line;
    while (getline(Reading_File, line)) {
        item_List.push_back(line);
    }
    Reading_File.close();
    return item_List;
}

vector<string> District::split_string(const string &input, char del) {
    vector<string> result;
    istringstream stream(input);
    string token;

    while (getline(stream, token, del)) {
        result.push_back(token);
    }
    return result;
}
