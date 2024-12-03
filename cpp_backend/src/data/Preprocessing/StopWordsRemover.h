#ifndef STOPWORDSREMOVER_H
#define STOPWORDSREMOVER_H

#include <string>
#include <vector>
#include <unordered_set>

class StopWordsRemover {
public:
    StopWordsRemover();
    std::vector<std::string> remove_stopwords(const std::vector<std::string>& words);
private:
    std::unordered_set<std::string> stopwords;
    void load_stopwords();
};

#endif // STOPWORDSREMOVER_H
