#ifndef STORYELEMENT_H
#define STORYELEMENT_H

#include <vector>
#include <map>
#include <string>

const extern int kSleepTime;
const extern std::string kFolderPath;
const extern std::string kFileExtension;

class StoryElement
{
    std::string curr;
    std::map<int, std::string> choices;

    void parseCurr();
    void printLine(std::string text);

public:
    StoryElement(std::string);
    void choose(int option);
};

#endif