#include "NPC.h"

NPC::NPC() {
    name = "none";
    sex = "none";
    occupation = "none";
    background = "none";
    wealthLevel = 0.0;
}

// Getters
string NPC::getName() const {
    return name;
}

string NPC::getSex() const {
    return sex;
}

string NPC::getOccupation() const {
    return occupation;
}

vector<string> NPC::getPersonalityTraits() const {
    return personalityTraits;
}

vector<string> NPC::getIdeals() const {
    return ideals;
}

vector<string> NPC::getBonds() const {
    return bonds;
}

vector<string> NPC::getFlaws() const {
    return flaws;
}

string NPC::getBackground() const {
    return background;
}

Culture NPC::getCulture() const {
    return culture;
}

double NPC::getWealthLevel() const {
    return wealthLevel;
}

// Setters
void NPC::setName(const string& newName) {
    name = newName;
}

void NPC::setSex(const string& newSex) {
    sex = newSex;
}

void NPC::setOccupation(const string& newOccupation) {
    occupation = newOccupation;
}

void NPC::setPersonalityTraits(const vector<string>& newTraits) {
    personalityTraits = newTraits;
}

void NPC::setIdeals(const vector<string>& newIdeals) {
    ideals = newIdeals;
}

void NPC::setBonds(const vector<string>& newBonds) {
    bonds = newBonds;
}

void NPC::setFlaws(const vector<string>& newFlaws) {
    flaws = newFlaws;
}

void NPC::setBackground(const string& newBackground) {
    background = newBackground;
}

void NPC::setCulture(const Culture& newCulture) {
    culture = newCulture;
}

void NPC::setWealthLevel(double newWealthLevel) {
    wealthLevel = newWealthLevel;
}

// Functions to add elements to vectors
void NPC::addPersonalityTrait(const string& trait) {
    personalityTraits.push_back(trait);
}

void NPC::addIdeal(const string& ideal) {
    ideals.push_back(ideal);
}

void NPC::addBond(const string& bond) {
    bonds.push_back(bond);
}

void NPC::addFlaw(const string& flaw) {
    flaws.push_back(flaw);
}

// Function to clear vectors
void NPC::clearPersonalityTraits() {
    personalityTraits.clear();
}

void NPC::clearIdeals() {
    ideals.clear();
}

void NPC::clearBonds() {
    bonds.clear();
}

void NPC::clearFlaws() {
    flaws.clear();
}

// Generate Functions
void NPC::generate_NPC() {

}

void NPC::generate_occupation() {

}

void NPC::generate_background() {

}

void NPC::generate_traits() {
    // Get list of traits

    // Get rand int 2-4

    // Choose int-rand # of traits from list and add them to traits

}

void NPC::generate_ideals() {

}

void NPC::generate_bonds() {

}

void NPC::generate_flaws() {

}

void NPC::generate_sex() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 2);
    int sexRand = distribution(gen);
    if (sexRand == 1) {
        setSex("Male");
    } else {
        setSex("Female");
    }
}

void NPC::generate_name() {

}

// Other Functions
void NPC::print() const {

}

vector<string> NPC::get_file_info(const string &Input_File) {
    vector<string> item_List;
    ifstream Reading_File(Input_File.c_str());
    string line;
    while (getline(Reading_File, line)) {
        item_List.push_back(line);
    }
    Reading_File.close();
    return item_List;
}
