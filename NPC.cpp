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

// Function to check if an input exists in vectors
bool NPC::hasPersonalityTrait(const string& trait) const {
    for (const string& t : personalityTraits) {
        if (t == trait) {
            return true;
        }
    }
    return false;
}

bool NPC::hasIdeal(const string& ideal) const {
    for (const string& i : ideals) {
        if (i == ideal) {
            return true;
        }
    }
    return false;
}

bool NPC::hasBond(const string& bond) const {
    for (const string& b : bonds) {
        if (b == bond) {
            return true;
        }
    }
    return false;
}

bool NPC::hasFlaw(const string& flaw) const {
    for (const string& f : flaws) {
        if (f == flaw) {
            return true;
        }
    }
    return false;
}

// Generate Functions
void NPC::generate_NPC() {

    generate_wealthLevel();
    generate_occupation();
    generate_traits();
    generate_ideals();
    generate_bonds();
    generate_flaws();
    generate_sex();
}

void NPC::generate_wealthLevel() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 200);
    int randNumber = distribution(gen);
    double randWealthLevel = static_cast<double>(randNumber) / 10;
    setWealthLevel(randWealthLevel);
}

void NPC::generate_occupation() {
    random_device rd;
    mt19937 gen(rd());
    string inputFile = culture.getOccupationFile();

    // Get list of Occupations
    vector<string> rawOccupList = get_file_info(inputFile);

    // Translating occupation list into comparable information
    vector<vector<string>> occupList;
    vector<string> occupData;
    for (const auto &occup: rawOccupList) {
        if (occup != "") {
            occupData = split_string(occup, ',');
            occupList.push_back(occupData);
        }
    }
    int foundOccup = 0;
    int loopTracker = 0;
    while (foundOccup == 0) {
        uniform_int_distribution<int> distribution(0, occupList.size() - 1);
        int randNumber = distribution(gen);
        vector<string> newOccup = occupList[randNumber];
        double wMax = stod(newOccup[1]);
        double wMin = stod(newOccup[2]);
        string occupName = newOccup[0];

        uniform_int_distribution<int> distributionA(1, 3);
        int randNumberA = distributionA(gen);
        if (randNumberA == 3) {
            if (wMax >= 17) {
                wMax = wMax - 3;
            } else if (wMax >= 10) {
                wMax = wMax - 2;
            } else if (wMax > 1) {
                wMax--;
            }

            if (wMin >= 17) {
                wMin = wMin - 10;
            } else if (wMin >= 8) {
                wMin = wMin - 3;
            } else if (wMin >= 1) {
                wMin = wMin-0.9;
            }

            occupName += "’s Assistant";
        }

        if (wMax >= getWealthLevel() && wMin <= getWealthLevel()) {
            setOccupation(occupName);
            foundOccup = 1;
        }
        loopTracker++;
    }
}

void NPC::generate_background() {

}

void NPC::generate_traits() {
    random_device rd;
    mt19937 gen(rd());
    string inputFile = "../BaseNPCFiles/Default Personality Trait List.txt";

    // Get list of traits
    vector<string> traitList = get_file_info(inputFile);

    // Get rand int 2-4
    uniform_int_distribution<int> distribution(2, 4);
    int randNumber = distribution(gen);

    // Choose int-rand # of traits from list and add them to traits
    while (randNumber > 0) {
        uniform_int_distribution<int> distribution(0, traitList.size());
        int randTraitNumber = distribution(gen);
        string trait = traitList[randTraitNumber];

        if (!hasPersonalityTrait(trait)) {
            addPersonalityTrait(trait);
            randNumber--;
        }
    }

}

void NPC::generate_ideals() {
    random_device rd;
    mt19937 gen(rd());
    string inputFile = "../BaseNPCFiles/Default Ideals List.txt";

    // Get list of traits
    vector<string> idealList = get_file_info(inputFile);

    // Get rand int 2-4
    uniform_int_distribution<int> distribution(1, 3);
    int randNumber = distribution(gen);

    // Choose int-rand # of traits from list and add them to traits
    while (randNumber > 0) {
        uniform_int_distribution<int> distribution(0, idealList.size());
        int randTraitNumber = distribution(gen);
        string trait = idealList[randTraitNumber];
        if (!hasIdeal(trait)) {
            addIdeal(trait);
            randNumber--;
        }
    }
}

void NPC::generate_bonds() {
    random_device rd;
    mt19937 gen(rd());
    string inputFile = "../BaseNPCFiles/Default Bonds List.txt";

    // Get list of traits
    vector<string> bondList = get_file_info(inputFile);

    // Get rand int 2-4
    uniform_int_distribution<int> distribution(1, 3);
    int randNumber = distribution(gen);

    // Choose int-rand # of traits from list and add them to traits
    while (randNumber > 0) {
        uniform_int_distribution<int> distribution(0, bondList.size());
        int randTraitNumber = distribution(gen);
        string trait = bondList[randTraitNumber];
        if (!hasBond(trait)) {
            addBond(trait);
            randNumber--;
        }
    }
}

void NPC::generate_flaws() {
    random_device rd;
    mt19937 gen(rd());
    string inputFile = "../BaseNPCFiles/Default Flaws List.txt";

    // Get list of traits
    vector<string> flawList = get_file_info(inputFile);

    // Get rand int 2-4
    uniform_int_distribution<int> distribution(1, 3);
    int randNumber = distribution(gen);

    // Choose int-rand # of traits from list and add them to traits
    while (randNumber > 0) {
        uniform_int_distribution<int> distribution(0, flawList.size());
        int randTraitNumber = distribution(gen);
        string flaw = flawList[randTraitNumber];
        if (!hasFlaw(flaw)) {
            addFlaw(flaw);
            randNumber--;
        }
    }
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

vector<string> NPC::split_string(const string &input, char del) {
    vector<string> result;
    istringstream stream(input);
    string token;

    while (getline(stream, token, del)) {
        result.push_back(token);
    }

    return result;
}


