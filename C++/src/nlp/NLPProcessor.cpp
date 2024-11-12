#include "NLPProcessor.h"
#include "../data/Preprocessing/TextCleaner.h"
#include "../data/Preprocessing/StopWordsRemover.h"
#include "../data/Preprocessing/Lemmatiser.h"
#include "../data/Tokeizer.h"

NLPProcessor::NLPProcessor() {}

std::vector<std::string> NLPProcessor::process_text(const std::string& text) {
    TextCleaner cleaner;
    StopWordsRemover remover;
    Lemmatiser lemmatiser;
    Tokenizer tokenizer;

    std::string cleaned = cleaner.clean_text(text);
    std::vector<std::string> tokens = tokenizer.tokenize(cleaned);
    tokens = remover.remove_stopwords(tokens);
    std::vector<std::string> lemmatized;
    for(auto &token : tokens) {
        lemmatized.push_back(lemmatiser.lemmatize(token));
    }
    return lemmatized;
}
