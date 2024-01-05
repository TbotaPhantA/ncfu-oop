#include <iostream>
#include <fstream>
#include <string>

bool containsWord(const std::string& sentence, const std::string& word) {
    size_t pos = sentence.find(word);

    if (pos != std::string::npos && (pos == 0 || !isalnum(sentence[pos - 1])) && (pos + word.length() == sentence.length() || !isalnum(sentence[pos + word.length()]))) {
        return true;
    }

    return false;
}

bool isSentenceComplete(std::string line) {
    return line.empty() || line[line.length() - 1] == '.' || line[line.length() - 1] == '?' || line[line.length() - 1] == '!';
}
