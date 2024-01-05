#include <iostream>
#include <cassert>
#include "Utils.h"
#include "UtilsTests.h"

void testContainsWord_Present() {
  std::string sentence = "Hello, world fish";
  std::string word = "world";
  assert(containsWord(sentence, word) == true);
}

void testContainsWord_NotPresent() {
	std::string sentence = "Hello, world!";
	std::string word = "foo";
	assert(containsWord(sentence, word) == false);
}

void testContainsWord_AtStart() {
	std::string sentence = "Hello, world fish";
	std::string word = "Hello";
	assert(containsWord(sentence, word) == true);
}

void testContainsWord_AtEnd() {
	std::string sentence = "Hello, world!";
	std::string word = "world!";
	assert(containsWord(sentence, word) == true);
}

void testIsSentenceComplete() {
    assert(isSentenceComplete("") == true);

    assert(isSentenceComplete("Hello, how are you today?") == true);

    assert(isSentenceComplete("What is your name?") == true);

    assert(isSentenceComplete("I can't believe it!") == true);
}

int runAllUnitTests() {
	testContainsWord_Present();
	testContainsWord_NotPresent();
	testContainsWord_AtStart();
	testContainsWord_AtEnd();
	testIsSentenceComplete();

	std::cout << "All tests passed!" << std::endl;

	return 0;
}