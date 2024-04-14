#include "../include/CD.h"

CD::CD()
{
    this->CDCode = -1;
}

CD::CD(int code,
    std::vector<MusicalComposition>& compositions,
    int year,
    std::string manufacturer,
    double price,
    int amount)
{
    this->CDCode = code;
    this->manufactureYear = year;
    this->compositions = compositions;
    this->manufacturer = manufacturer;
    this->price = price;
    this->amountInStock = amount;
}

CD::~CD()
{
}

//Getters
int CD::getCDCode() const
{
    return this->CDCode;
}

int CD::getManufactureYear() const
{
    return this->manufactureYear;
}

std::string CD::getManufacturer() const
{
    return this->manufacturer;
}

std::vector<MusicalComposition> CD::getCompositions() const
{
    return this->compositions;
}

double CD::getPrice() const
{
    return this->price;
}

int CD::getAmounInStock() const
{
    return this->amountInStock;
}

// Setters
void CD::setCDCode(int code)
{
    this->CDCode = code;
}
void CD::setManufactureYear(int year)
{
    this->manufactureYear = year;
}
void CD::setManufacturer(std::string& newManufacturer)
{
    this->manufacturer = newManufacturer;
}
void CD::setCompositions(std::vector<MusicalComposition>& newCompositions)
{
    this->compositions = newCompositions;
}
void CD::setPrice(double newPrice)
{
    this->price = newPrice;
}
void CD::setAmounInStock(int amount)
{
    this->amountInStock = amount;
}