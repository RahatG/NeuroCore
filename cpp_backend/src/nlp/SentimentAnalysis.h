#ifndef SENTIMENTANALYSIS_H
#define SENTIMENTANALYSIS_H

#include <vector>
#include <string>

class SentimentAnalysis {
public:
    SentimentAnalysis();
    float analyze(const std::vector<std::string>& tokens);
};

#endif // SENTIMENTANALYSIS_H
