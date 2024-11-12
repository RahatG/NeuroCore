// Lemmatiser.cpp
#include "Lemmatiser.h"
#include <algorithm>

Lemmatiser::Lemmatiser() {
    // Initialize lemmatizer with a simple dictionary
    lemma_dict = {
            {"running", "run"},
            {"jumps", "jump"},
            {"easily", "easy"},
            // Add more word-lemma pairs as needed
    };
}

std::string Lemmatiser::lemmatize(const std::string& word) const {
    std::string lower_word = word;
    std::transform(lower_word.begin(), lower_word.end(), lower_word.begin(), ::tolower);

    auto it = lemma_dict.find(lower_word);
    if (it != lemma_dict.end()) {
        return it->second;
    }
    return lower_word;
}

void Lemmatiser::addLemma(const std::string& word, const std::string& lemma) {
    std::string lower_word = word;
    std::transform(lower_word.begin(), lower_word.end(), lower_word.begin(), ::t