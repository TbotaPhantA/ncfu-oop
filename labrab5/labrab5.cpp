#include <iostream>
#include <fstream>
#include <string>
#include "Utils.h"
#include "UtilsTests.h"

int main() {
    runAllUnitTests();

    std::string filename;
    std::cout << "Enter the name of the file: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening file." << std::endl;
        return 1;
    }

    std::string word;
    std::cout << "Enter the word to search for: ";
    std::cin >> word;

    std::string line;
    std::string sentence;
    while (std::getline(file, line)) {
        sentence += line;

        if (isSentenceComplete(line)) {
            if (containsWord(sentence, word)) {
                std::cout << sentence << std::endl;
            }
            sentence.clear();
        }
        else {
            sentence += " ";
        }
    }

    return 0;
}