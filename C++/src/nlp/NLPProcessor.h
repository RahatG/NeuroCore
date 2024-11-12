#ifndef NLPPROCESSOR_H
#define NLPPROCESSOR_H

#include <string>
#include <vector>

class NLPProcessor {
public:
    NLPProcessor();
    std::vector<std::string> process_text(const std::string& text);
private:
    // Components like Tokenizer, TextCleaner, StopWordsRemover, Lemmatiser
};

#endif // NLPPROCESSOR_H
