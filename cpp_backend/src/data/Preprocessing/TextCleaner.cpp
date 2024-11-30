#include "TextCleaner.h"
#include <algorithm>
#include <cctype>

TextCleaner::TextCleaner() {}

void TextCleaner::to_lowercase(std::string& text) {
    std::transform(text.begin(), text.end(), text.begin(),
                   [](unsigned char c){ return std::tolower(c); });
}

void TextCleaner::remove_punctuation(std::string& text) {
    text.erase(std::remove_if(text.begin(), text.end(),
        [](unsigned char c) { return std::ispunct(c); }), text.end());
}

std::string TextCleaner::clean_text(const std::string& text) {
    std::string cleaned = text;
    to_lowercase(cleaned);
    remove_punctuation(cleaned);
    return cleaned;
}
