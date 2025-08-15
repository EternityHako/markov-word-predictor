#pragma once
#include <string>
#include <vector>
#include "markov_chain.h"  // for Chain

class Generator {
public:
    Generator(const Chain &chain);
    std::string generate(size_t wordCount, const std::string &startWord = "");

private:
    const Chain &chain;
    std::string weightedRandomNext(const SuccTable &table);
};
