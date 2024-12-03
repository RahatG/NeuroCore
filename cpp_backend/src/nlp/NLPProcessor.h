#ifndef NLPPROCESSOR_H
#define NLPPROCESSOR_H

#include <string>
#include <vector>
#include <unordered_map>
#include "../data/Preprocessing/TextCleaner.h"
#include "../data/Preprocessing/StopWordsRemover.h"
#include "../data/Preprocessing/Lemmatiser.h"
#include "../data/Tokenizer.h"
#include "../utils/Config.h"

class NLPProcessor {
public:
    NLPProcessor();
    std::vector<std::string> process_text(const std::string& text);
    int get_token_id(const std::string& token);

private:
    TextCleaner cleaner;
    StopWordsRemover stopwords_remover;
    Lemmatiser lemmatiser;
    Tokenizer tokenizer;
    std::unordered_map<std::string, int> vocabulary;
    Config config;

    void build_vocabulary();
};

#endif // NLPPROCESSOR_H
