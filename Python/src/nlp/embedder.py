import torch
from torch import nn
from ..config.settings import settings

class Embedder:
    def __init__(self, embedding_path):
        self.embedding = nn.EmbeddingBag.from_pretrained(torch.load(embedding_path), freeze=False)

    def get_embeddings(self, tokens):
        indices = [self.vocab[token] for token in tokens if token in self.vocab]
        tensor = torch.tensor(indices, dtype=torch.long)
        return self.embedding(tensor).detach().numpy()
