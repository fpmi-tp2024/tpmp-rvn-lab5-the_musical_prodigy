#pragma once
#include <vector>

class MusicalComposition
{
private:
    std::string name;
    std::vector<std::string> author;
    std::vector<std::string> performer;
public:
    MusicalComposition(/* args */);
    ~MusicalComposition();
};

