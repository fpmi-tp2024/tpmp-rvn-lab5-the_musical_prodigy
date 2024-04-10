#pragma once
#include "MusicalComposition.h"
#include <iostream>
#include <string>
#include <vector>

class CD
{
private:
    int CDCode;
    int manufactureYear;
    std::string manufacturer;
    std::vector<MusicalComposition> compositions;
    double price;
    int amountInStock;
public:
    CD(/* args */);
    ~CD();
};

