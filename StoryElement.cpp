#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <time.h>

#include "StoryElement.hpp"
#include "File.hpp"

const int kSleepTime = 5;

const std::string kFolderPath = "Story/";
const std::string kFileExtension = ".txt";

StoryElement::StoryElement(std::string curr) : curr(curr)
{
    srand(time(NULL));
    parseCurr();
}

void StoryElement::parseCurr()
{
    FileReader reader(kFolderPath + curr + kFileExtension);

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
        else if (line == "PRINT_LINES")
        {
            line = reader.readLine();

            while (line != "END_PRINT")
            {
                printLine(line);
                line = reader.readLine();
            }
        }
        else if (line == "PRINT_RANDOM")
        {
            line = reader.readLine();
            std::vector<std::string> randOptions;

            while (line != "END_PRINT_RANDOM")
            {
                randOptions.push_back(line);
                line = reader.readLine();
            }

            printLine(randOptions[rand() % randOptions.size()]);
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