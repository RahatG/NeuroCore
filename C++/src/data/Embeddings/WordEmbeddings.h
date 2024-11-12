#ifndef WORDEMBEDDINGS_H
#define WORDEMBEDDINGS_H

#include "EmbeddingLoader.h"
#include <vector>
#include <string>

class WordEmbeddings {
public:
    WordEmbeddings(const std::string& embedding_path);
    std::vector<float> get_word_embedding(const std::string& word);
private:
    EmbeddingLoader loader;
};

#endif // WORDEMBEDDINGS_H
