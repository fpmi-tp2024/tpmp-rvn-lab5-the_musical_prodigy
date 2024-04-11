#include "../include/MusicalComposition.h"

MusicalComposition::MusicalComposition(/* args */)
{
}

MusicalComposition::~MusicalComposition()
{
}

//Getters
std::string MusicalComposition::getName() const
{
    return this->name;
}
std::vector<std::string> MusicalComposition::getAuthor() const
{
    return this->author;
}
std::vector<std::string> MusicalComposition::getPerformer() const
{
    return this->performer;
}

//Setters
void MusicalComposition::setName(std::string& newName)
{
    this->name = newName;
}
void MusicalComposition::setAuthor(std::vector<std::string>& newAuthor)
{
    this->author = newAuthor;
}
void MusicalComposition::setPerformer(std::vector<std::string>& newPerformer)
{
    this->performer = newPerformer;
}