#include "generator.h"
#include <random>
#include <algorithm>
#include <sstream>

Generator::Generator(const Chain &chain) : chain(chain) {}

std::string Generator::weightedRandomNext(const SuccTable &table) {
    if (table.successors.empty()) return "";

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, table.prefixCounts.back() - 1);

    int r = dist(gen);

    // Find index via binary search on prefixCounts
    size_t idx = std::lower_bound(
        table.prefixCounts.begin(),
        table.prefixCounts.end(),
        r + 1
    ) - table.prefixCounts.begin();

    return table.successors[idx];
}

std::string Generator::generate(size_t wordCount, const std::string &startWord) {
    if (chain.empty() || wordCount == 0) return "";

    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::string current;
    if (!startWord.empty() && chain.find(startWord) != chain.end()) {
        current = startWord;
    } else {
        // Pick a random starting word from the chain
        auto it = chain.begin();
        std::uniform_int_distribution<size_t> dist(0, chain.size() - 1);
        std::advance(it, dist(gen));
        current = it->first;
    }

    std::ostringstream output;
    output << current;

    for (size_t i = 1; i < wordCount; ++i) {
        auto it = chain.find(current);
        if (it == chain.end()) break;

        std::string next = weightedRandomNext(it->second);
        if (next.empty()) break;

        output << " " << next;
        current = next;
    }

    return output.str();
}

