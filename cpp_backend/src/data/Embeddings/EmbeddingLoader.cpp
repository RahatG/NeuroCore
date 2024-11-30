#include "EmbeddingLoader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

EmbeddingLoader::EmbeddingLoader(const std::string& embedding_path) {
    load_embeddings(embedding_path);
}

void EmbeddingLoader::load_embeddings(const std::string& path) {
    std::ifstream infile(path);
    if (!infile.is_open()) {
        throw std::runtime_error("Failed to open embedding file.");
    }
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string word;
        iss >> word;
        std::vector<float> vec;
        float val;
        while (iss >> val) {
            vec.push_back(val);
        }
        embeddings[word] = vec;
    }
    infile.close();
}

std::vector<float> EmbeddingLoader::get_embedding(const std::string& word) {
    if (embeddings.find(word) != embeddings.end()) {
        return embeddings[word];
    }
    return std::vector<float>();
}
