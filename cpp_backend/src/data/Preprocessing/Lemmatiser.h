// Lemmatiser.h
#ifndef LEMMATISER_H
#define LEMMATISER_H

#include <string>
#include <unordered_map>

class Lemmatiser {
public:
    Lemmatiser();
    std::string lemmatize(const std::string& word) const;
    void addLemma(const std::string& word, const std::string& lemma);

private:
    std::unordered_map<std::string, std::string> lemma_dict;
};

#endif // LEMMATISER_H