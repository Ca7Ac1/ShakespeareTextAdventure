#ifndef STORYELEMENT_H
#define STORYELEMENT_H

#include <vector>
#include <map>
#include <string>

const extern int kSleepTime;
const extern std::string kFolderPath;

class StoryElement
{
    char curr;
    std::map<int, char> choices;

    void parseCurr();
    void printLine(std::string text);

public:
    StoryElement(char curr);
    void choose(int option);
};

#endif