#ifndef PARTOFSPEECHTAGGER_H
#define PARTOFSPEECHTAGGER_H

#include <vector>
#include <string>

class PartOfSpeechTagger {
public:
    PartOfSpeechTagger();
    std::vector<std::pair<std::string, std::string>> tag(const std::vector<std::string>& tokens);
};

#endif // PARTOFSPEECHTAGGER_H
