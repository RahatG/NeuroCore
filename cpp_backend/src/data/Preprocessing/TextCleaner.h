#ifndef TEXTCLEANER_H
#define TEXTCLEANER_H

#include <string>

class TextCleaner {
public:
    TextCleaner();
    std::string clean_text(const std::string& text);
private:
    void to_lowercase(std::string& text);
    void remove_punctuation(std::string& text);
};

#endif // TEXTCLEANER_H
