#include "tokenizer.h"
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>

static std::string cleanToken(const std::string &token) {
    std::string result;
    for (char ch : token) {
        if (std::isalpha(static_cast<unsigned char>(ch)) || ch == '\'' || ch == '-') {
            result.push_back(std::tolower(static_cast<unsigned char>(ch)));
        }
    }
    return result;
}

std::vector<std::string> tokenizeFile(const std::string &filename) {
    std::ifstream in(filename);
    if (!in) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::vector<std::string> words;
    std::string raw;

    while (in >> raw) {
        std::string cleaned = cleanToken(raw);
        if (!cleaned.empty()) {
            words.push_back(cleaned);
        }
    }
    return words;
}
