#pragma once
#include <string>
#include <vector>
#include <unordered_map>

struct SuccTable {
    std::vector<std::string> successors;
    std::vector<int> prefixCounts;  // raw counts during build, converted to prefix sums later
    std::unordered_map<std::string, size_t> indexOf;
};

using Chain = std::unordered_map<std::string, SuccTable>;

// You can also declare build/processing functions here:
void buildChain(Chain &chain, const std::vector<std::string> &words);
void convertToPrefixSums(Chain &chain);
