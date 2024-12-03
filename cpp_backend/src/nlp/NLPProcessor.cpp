#include "NLPProcessor.h"
#include <fstream>
#include <sstream>

NLPProcessor::NLPProcessor() : config("../config/config.json") {
    build_vocabulary();
}

void NLPProcessor::build_vocabulary() {
    // Load vocabulary from file or build from dataset
    std::string vocab_path = config.get<std::string>("vocabulary_path");
    std::ifstream infile(vocab_path);
    if (!infile.is_open()) {
        // Handle error or build vocabulary from data
        return;
    }
    std::string line;
    int index = 0;
    while (std::getline(infile, line)) {
        vocabulary[line] = index++;
    }
    infile.close();
}

std::vector<std::string> NLPProcessor::process_text(const std::string& text) {
    std::string cleaned = cleaner.clean_text(text);
    std::vector<std::string> tokens = tokenizer.tokenize(cleaned);
    tokens = stopwords_remover.remove_stopwords(tokens);
    for(auto &token : tokens) {
        token = lemmatiser.lemmatize(token);
    }
    return tokens;
}

int NLPProcessor::get_token_id(const std::string& token) {
    auto it = vocabulary.find(token);
    if (it != vocabulary.end()) {
        return it->second;
    } else {
        // Handle unknown token
        return vocabulary.size(); // Return a special index for unknown tokens
    }
}
