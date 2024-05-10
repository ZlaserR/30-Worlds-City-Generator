//
// Created by zacru on 5/9/2024.
//

#ifndef INC_30_WORLDS_CITY_GENERATOR_NPC_H
#define INC_30_WORLDS_CITY_GENERATOR_NPC_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include "Culture.h"
using namespace std;

class NPC {
protected:
    string name;
    string sex;
    string occupation;
    vector<string> personalityTraits;
    vector<string> ideals;
    vector<string> bonds;
    vector<string> flaws;
    string background;
    Culture culture;
    double wealthLevel;

public:
    // Getters
    string getName() const;
    string getSex() const;
    string getOccupation() const;
    vector<string> getPersonalityTraits() const;
    vector<string> getIdeals() const;
    vector<string> getBonds() const;
    vector<string> getFlaws() const;
    string getBackground() const;
    Culture getCulture() const;
    double getWealthLevel() const;

    // Setters
    void setName(const string& newName);
    void setSex(const string& newSex);
    void setOccupation(const string& newOccupation);
    void setPersonalityTraits(const vector<string>& newTraits);
    void setIdeals(const vector<string>& newIdeals);
    void setBonds(const vector<string>& newBonds);
    void setFlaws(const vector<string>& newFlaws);
    void setBackground(const string& newBackground);
    void setCulture(const Culture& newCulture);
    void setWealthLevel(double newWealthLevel);

    // Functions to add elements to vectors
    void addPersonalityTrait(const string& trait);
    void addIdeal(const string& ideal);
    void addBond(const string& bond);
    void addFlaw(const string& flaw);

    // Function to clear vectors
    void clearPersonalityTraits();
    void clearIdeals();
    void clearBonds();
    void clearFlaws();

    // Generate Functions


};


#endif //INC_30_WORLDS_CITY_GENERATOR_NPC_H
