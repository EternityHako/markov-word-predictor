#include "tokenizer.h"
#include "markov_chain.h"
#include "generator.h"

#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <textfile.txt> <wordcount | all>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string countArg = argv[2];

    try {
        // Stage 1: Tokenize input file
        auto words = tokenizeFile(filename);
        if (words.empty()) {
            std::cerr << "Error: file contained no valid words.\n";
            return 1;
        }

        // Stage 2: Build and process Markov chain
        Chain chain;
        buildChain(chain, words);
        convertToPrefixSums(chain);

        // Stage 3: Generate text
        Generator gen(chain);

        size_t wordCount = 0;
        if (countArg == "all" || countArg == "entire") {
            wordCount = words.size();
        } else {
            wordCount = std::stoul(countArg);
        }

        std::string output = gen.generate(wordCount);
        std::cout << output << "\n";
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
