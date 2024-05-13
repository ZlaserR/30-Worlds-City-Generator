//
// Created by zacru on 5/13/2024.
//

#ifndef INC_30_WORLDS_CITY_GENERATOR_NOTABLELOCATION_H
#define INC_30_WORLDS_CITY_GENERATOR_NOTABLELOCATION_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include <sstream>
#include "Culture.h"
#include "District.h"
#include "NPC.h"
using namespace std;

class NotableLocation {
protected:
    string locationName;
    string locationType;
    string locationOccupation;
    District district;
    NPC importantNPC;
    vector<NPC> relevantNPCs;
    double wealthLevel;
    Culture culture;

public:

    NotableLocation();

    explicit NotableLocation(const District& pDistrict, double pWealthLevel);

    ~NotableLocation() = default;

    // Getters
    string getLocationName() const;
    string getLocationType() const;
    District getDistrict() const;
    NPC getImportantNPC() const;
    double getWealthLevel() const;
    vector<NPC> getRelevantNPCs() const;
    Culture getCulture() const;
    string getLocationOccupation() const;

    // Setters
    void setLocationName(const string& newName);
    void setLocationType(const string& newType);
    void setDistrict(const District& newDistrict);
    void setImportantNPC(const NPC& newNPC);
    void setWealthLevel(double newWealthLevel);
    void setRelevantNPCs(const vector<NPC>& newNPCs);
    void setCulture(const Culture& newCulture);
    void setLocationOccupation(const string& newLocatOccup);

    void addRelevantNPC(const NPC& newNPC);
    void clearRelevantNPCs();

    // Generate Functions
    void generate_location();

    void generate_locationType();

    void generate_importantNPC();

    void generate_relevantNPCs();

    void generate_locationName();

    void generate_wealthLevel();

    // Other Functions
    void print() const;

    vector<string> get_file_info(const string& Input_File);

    virtual vector<string> split_string(const string& input, char del);
};


#endif //INC_30_WORLDS_CITY_GENERATOR_NOTABLELOCATION_H
