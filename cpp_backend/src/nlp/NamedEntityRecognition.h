#ifndef NAMEDENTITYRECOGNITION_H
#define NAMEDENTITYRECOGNITION_H

#include <vector>
#include <string>

class NamedEntityRecognition {
public:
    NamedEntityRecognition();
    std::vector<std::pair<std::string, std::string>> recognize(const std::vector<std::string>& tokens);
};

#endif // NAMEDENTITYRECOGNITION_H
