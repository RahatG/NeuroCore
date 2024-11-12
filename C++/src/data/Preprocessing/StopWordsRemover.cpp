#include "StopWordsRemover.h"

StopWordsRemover::StopWordsRemover() {
    load_stopwords();
}

void StopWordsRemover::load_stopwords() {
    stopwords = {"a", "an", "the", "and", "or", "but", "if", "while", "with", "to", "of"};
}

std::vector<std::string> StopWordsRemover::remove_stopwords(const std::vector<std::string>& words) {
    std::vector<std::string> filtered;
    for (const auto& word : words) {
        if (stopwords.find(word) == stopwords.end()) {
            filtered.push_back(word);
        }
    }
    return filtered;
}
