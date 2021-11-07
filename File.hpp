#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>

const extern std::string kWhiteSpace;

std::string ltrim(const std::string &s);
std::string rtrim(const std::string &s);
std::string trim(const std::string &s);

class FileReader
{
    std::ifstream file;

public:
    FileReader(const std::string &);
    ~FileReader();
    std::string readNext();
    std::string readLine();
    bool isEnd();
};

#endif
