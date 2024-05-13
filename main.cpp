#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include "NPC.h"
#include "Culture.h"
#include "City.h"
#include "District.h"
#include "NotableLocation.h"

using namespace std;

int main() {
    /**
    NPC testNPC;
    testNPC.generate_NPC();
    testNPC.print();
    */

    NotableLocation testLocat;
    testLocat.generate_location();

    return 0;
}