#include <iostream>

#include "StoryElement.hpp"

int main()
{
    StoryElement story("Start");

    while (!story.isFinished())
    {
        int val;
        std::cin >> val;
        
        story.choose(val);
    }
}