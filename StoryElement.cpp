#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <time.h>

#include "StoryElement.hpp"
#include "File.hpp"

const int kSleepTime = 25;
const int kLineSleepTime = 300;

const std::string kFolderPath = "Story/";
const std::string kFileExtension = ".txt";

StoryElement::StoryElement(std::string curr) : curr(curr), end(false)
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    srand(time(NULL));
    parseCurr();
}

void StoryElement::parseCurr()
{
    if (curr == "END_ALL")
    {
        end = true;
        return;
    }

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
                choices[std::stoi(line)] = reader.readNext();
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
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    if (choices.find(option) != choices.end())
    {
        curr = choices[option];
        parseCurr();
    }
    else
    {
        std::cout << "\n\nINVALID INPUT PLEASE TRY AGAIN\n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        parseCurr();
    }
}

bool StoryElement::isFinished()
{
    return end;
}

void StoryElement::printLine(std::string next)
{
    for (char i : next)
    {
        std::cout << i;

        if (i == '\n'|| i == '?' || i == '.' || i == '!')
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(kLineSleepTime));
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(kSleepTime));
        }     
    }

    std::cout << '\n' << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(kLineSleepTime)); 
}