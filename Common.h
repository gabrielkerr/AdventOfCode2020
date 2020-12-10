#pragma once

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

inline std::vector<std::string> readFile(const char* filename) {
    std::ifstream inputFile{};
    inputFile.open(filename);
    if (!inputFile.is_open()) {
        throw std::runtime_error("File not found");
    }

    std::vector<std::string> out;
    std::string buffer;

    while (std::getline(inputFile, buffer)) {
        out.push_back(buffer);
    }
    return out;
}

[[nodiscard]] inline std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

inline bool isStringNumber(const std::string& s)
{
    bool isNumber = true;
    for (size_t i(0); i < s.length(); ++i)
    {
        if (!std::isdigit(s[i]))
        {
            isNumber = false;
            break;
        }
    }

    return isNumber;
}

inline bool isNumberWithinRange(const int num, const int min, const int max)
{
    return ((num >= min) && (num <= max));
}

inline void removeNumbersFromString(std::string& s)
{
    s.erase(std::remove_if(s.begin(), s.end(), &isdigit), s.end());
}

inline void removePunctuationFromString(std::string& s)
{
    s.erase(std::remove_if(s.begin(), s.end(), &ispunct), s.end());
}

// trim from start (in place)
inline void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
        }));
}

// trim from end (in place)
inline void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
        }).base(), s.end());
}
