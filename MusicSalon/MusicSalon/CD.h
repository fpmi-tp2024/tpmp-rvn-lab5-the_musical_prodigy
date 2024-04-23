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
    CD(int code,
        std::vector<MusicalComposition>& compositions,
        int year = 2000,
        std::string manufacturer = "Belarus",
        double price = 10.0,
        int amount = 100);

    ~CD();
    int getCDCode() const;
    int getManufactureYear() const;
    std::string getManufacturer() const;
    std::vector<MusicalComposition> getCompositions() const;
    double getPrice() const;
    int getAmounInStock() const;

    void setCDCode(int code);
    void setManufactureYear(int year);
    void setManufacturer(std::string& newManufacturer);
    void setCompositions(std::vector<MusicalComposition>& newCompositions);
    void setPrice(double newPrice);
    void setAmounInStock(int amount);
};

/*#pragma once
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
    CD(int code,
        std::vector<MusicalComposition>& compositions,
        int year = 2000,
        std::string manufacturer = "Belarus",
        double price = 10.0,
        int amount = 100);

    ~CD();
    int getCDCode() const;
    int getManufactureYear() const;
    std::string getManufacturer() const;
    std::vector<MusicalComposition> getCompositions() const;
    double getPrice() const;
    int getAmounInStock() const;

    void setCDCode(int code);
    void setManufactureYear(int year);
    void setManufacturer(std::string& newManufacturer);
    void setCompositions(std::vector<MusicalComposition>& newCompositions);
    void setPrice(double newPrice);
    void setAmounInStock(int amount);
};*/

/*#pragma once
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
    CD(int code,
        std::vector<MusicalComposition>& compositions,
        int year = 2000,
        std::string manufacturer = "Belarus",
        double price = 10.0,
        int amount = 100);

    ~CD();
    int getCDCode() const;
    int getManufactureYear() const;
    std::string getManufacturer() const;
    std::vector<MusicalComposition> getCompositions() const;
    double getPrice() const;
    int getAmounInStock() const;

    void setCDCode(int code);
    void setManufactureYear(int year);
    void setManufacturer(std::string& newManufacturer);
    void setCompositions(std::vector<MusicalComposition>& newCompositions);
    void setPrice(double newPrice);
    void setAmounInStock(int amount);
};*/
