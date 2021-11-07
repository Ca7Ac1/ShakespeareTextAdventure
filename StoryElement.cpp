#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <chrono>
#include <thread>

#include "StoryElement.hpp"
#include "File.hpp"

const int kSleepTime = 5;

const std::string kFolderPath = "./Story/";

StoryElement::StoryElement(char curr) : curr(curr)
{
    parseCurr();
}

void StoryElement::parseCurr()
{
    std::string path(1, curr);
    path = kFolderPath + path;
    path += ".txt";

    FileReader reader(path);

    std::string line;

    while (!reader.isEnd())
    {
        line = reader.readLine();

        if (line == "OPTIONS")
        {
            line = reader.readNext();

            while (line != "END_OPTIONS")
            {
                choices[std::stoi(line)] = reader.readNext()[0];
                line = reader.readNext();
            }
        }
        else if (line == "PRINT LINES")
        {
            line = reader.readLine();

            while (line != "END_PRINT")
            {
                printLine(line);
                line = reader.readLine();
            }
        }
    } 
}

void StoryElement::choose(int option)
{
    curr = choices[option];
    parseCurr;
}

void StoryElement::printLine(std::string next)
{
    for (char i : next)
    {
        std::cout << i;
        std::this_thread::sleep_for(std::chrono::milliseconds(kSleepTime));
    }

    std::cout << '\n';
}