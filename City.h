//
// Created by zacru on 5/13/2024.
//

#ifndef INC_30_WORLDS_CITY_GENERATOR_CITY_H
#define INC_30_WORLDS_CITY_GENERATOR_CITY_H
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
#include "District.h"

class City {
protected:
    string cityName;
    vector<District> districts;
    string sizeCategory;
    int size;
    double wealthLevel;
    Culture primaryCulture;
    vector<Culture> cultureGroups;
    vector<string> localResources;

public:

    City();

    ~City() = default;

    // Getters
    string getCityName() const;
    vector<District> getDistricts() const;
    string getSizeCategory() const;
    int getSize() const;
    double getWealthLevel() const;
    Culture getPrimaryCulture() const;
    vector<Culture> getCultureGroups() const;
    vector<string> getLocalResources() const;

    // Setters
    void setCityName(const string& newName);
    void setDistricts(const vector<District>& newDistricts);
    void setSizeCategory(const string& newSizeCategory);
    void setSize(int newSize);
    void setWealthLevel(double newWealthLevel);
    void setPrimaryCulture(const Culture& newPrimaryCulture);
    void setCultureGroups(const vector<Culture>& newCultureGroups);
    void setLocalResources(const vector<string>& newLocalResources);

    // Functions to add elements to vectors and clear them
    void addDistrict(const District& newDistrict);
    void clearDistricts();

    void addCultureGroup(const Culture& newCulture);
    void clearCultureGroups();

    void addLocalResource(const string& newResource);
    void clearLocalResources();

    // Generate Functions
    void generate_city();

    void generate_size();

    void generate_districts();

    // Other Functions
    void print() const;

    vector<string> get_file_info(const string& Input_File);

    virtual vector<string> split_string(const string& input, char del);

};


#endif //INC_30_WORLDS_CITY_GENERATOR_CITY_H
