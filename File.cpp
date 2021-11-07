#include "File.hpp"

#include <string>
#include <fstream>

const std::string kWhitespace = " \n\r\t\f\v ";

std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(kWhitespace);
    return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(kWhitespace);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string &s)
{
    return rtrim(ltrim(s));
}

FileReader::FileReader(const std::string &path) : file(path) {}

FileReader::~FileReader()
{
    file.close();
}

std::string FileReader::readNext()
{
    std::string next;
    file >> next;

    return trim(next);
}

std::string FileReader::readLine()
{
    std::string next;
    std::getline(file, next);

    return trim(next);
}

bool FileReader::isEnd()
{
    file.peek();
    return file.eof() || !file.good();
}