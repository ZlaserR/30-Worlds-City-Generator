//
// Created by zacru on 5/13/2024.
//

#ifndef INC_30_WORLDS_CITY_GENERATOR_DISTRICT_H
#define INC_30_WORLDS_CITY_GENERATOR_DISTRICT_H
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
#include "NPC.h"
#include "NotableLocation.h"
#include "City.h"

class District {
protected:
    string districtName;
    string districtSpecialization;
    int size;
    double wealthLevel;
    vector<NotableLocation> notableLocations;
    City city;
    Culture culture;

public:
    District();

    explicit District(const City& pCity, const Culture& pCulture, double pWealthLevel, int pSize);

    ~District() = default;

    // Getters
    string getDistrictName() const;
    string getDistrictSpecialization() const;
    int getSize() const;
    double getWealthLevel() const;
    vector<NotableLocation> getNotableLocations() const;
    City getCity() const;
    Culture getCulture() const;

    // Setters
    void setDistrictName(const string& newName);
    void setDistrictSpecialization(const string& newSpecialization);
    void setSize(int newSize);
    void setWealthLevel(double newWealthLevel);
    void setNotableLocations(const vector<NotableLocation>& newLocations);
    void setCity(const City& newCity);
    void setCulture(const Culture& newCulture);

    // Functions to add elements to notableLocations and clear it
    void addNotableLocation(const NotableLocation& newLocation);
    void clearNotableLocations();

    // Generate Functions
    void generate_district();

    void generate_specialization();

    void generate_notableLocations();

    void generate_name();

    void generate_wealthLevel();


    // Other Functions
    void print() const;

    vector<string> get_file_info(const string& Input_File);

    virtual vector<string> split_string(const string& input, char del);

};


#endif //INC_30_WORLDS_CITY_GENERATOR_DISTRICT_H
