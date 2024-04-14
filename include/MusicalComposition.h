#pragma once
#include <vector>
#include <string>

class MusicalComposition
{
private:
    std::string name;
    std::vector<std::string> author;
    std::vector<std::string> performer;
public:
    MusicalComposition();
    MusicalComposition(std::string name,
        std::vector<std::string>& author,
        std::vector<std::string>& performer);

    ~MusicalComposition();
    std::string getName() const;
    std::vector<std::string> getAuthor() const;
    std::vector<std::string> getPerformer() const;
    void setName(std::string& newName);
    void setAuthor(std::vector<std::string>& newAuthor);
    void setPerformer(std::vector<std::string>& newPerformer);
};

