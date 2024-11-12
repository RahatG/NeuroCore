#include "WordEmbeddings.h"

WordEmbeddings::WordEmbeddings(const std::string& embedding_path)
    : loader(embedding_path) {}

std::vector<float> WordEmbeddings::get_word_embedding(const std::string& word) {
    return loader.get_embedding(word);
}
