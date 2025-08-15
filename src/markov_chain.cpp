#include "markov_chain.h"

void buildChain(Chain &chain, const std::vector<std::string> &words) {
    for (size_t i = 0; i + 1 < words.size(); ++i) {
        const std::string &curr = words[i];
        const std::string &next = words[i + 1];
        SuccTable &table = chain[curr];
        auto it = table.indexOf.find(next);
        if (it == table.indexOf.end()) {
            table.indexOf[next] = table.successors.size();
            table.successors.push_back(next);
            table.prefixCounts.push_back(1);
        } else {
            table.prefixCounts[it->second] += 1;
        }
    }
}

void convertToPrefixSums(Chain &chain) {
    for (auto &[word, table] : chain) {
        for (size_t i = 1; i < table.prefixCounts.size(); ++i) {
            table.prefixCounts[i] += table.prefixCounts[i - 1];
        }
    }
}
