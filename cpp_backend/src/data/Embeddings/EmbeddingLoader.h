#ifndef EMBEDDINGLOADER_H
#define EMBEDDINGLOADER_H

#include <string>
#include <unordered_map>
#include <vector>

class EmbeddingLoader {
public:
    EmbeddingLoader(const std::string& embedding_path);
    std::vector<float> get_embedding(const std::string& word);
private:
    std::unordered_map<std::string, std::vector<float>> embeddings;
    void load_embeddings(const std::string& path);
};

#endif // EMBEDDINGLOADER_H
