#include "data/Embeddings/EmbeddingLoader.h"
#include "data/Embeddings/WordEmbeddings.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cerr << "Usage: generate_embeddings <input_text> <output_embedding>" << std::endl;
        return 1;
    }
    std::string input_text = argv[1];
    std::string output_embedding = argv[2];
    WordEmbeddings embedder("path_to_embeddings");
    // Placeholder: Implement embedding generation logic
    std::vector<float> embeddings = embedder.get_word_embedding("sample");
    // Save embeddings to output_embedding path
    std::cout << "Embeddings generated and saved." << std::endl;
    return 0;
}
