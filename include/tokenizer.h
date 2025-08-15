#pragma once
#include <string>
#include <vector>

// Reads a file and splits it into lowercase words.
// Removes most punctuation except internal apostrophes/hyphens if desired.
std::vector<std::string> tokenizeFile(const std::string &filename);
