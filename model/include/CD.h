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
    CD();
    ~CD();
    int getCDCode() const;
    int getManufactureYear() const;
    std::string getManufacturer() const;
    std::vector<MusicalComposition> getCompositions() const;
    double getPrice() const;
    int getAmounInStock() const;

    void setCDCode(int code);
    void setManufactureYear(int year);
    void setManufacturer(std::string &newManufacturer);
    void setCompositions(std::vector<MusicalComposition> &newCompositions);
    void setPrice(double newPrice);
    void setAmounInStock(int amount);
};

