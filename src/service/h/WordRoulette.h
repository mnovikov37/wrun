#include "WordRepo.h"
#include <vector>

#ifndef CLASS_WORD_ROULETTE
#define CLASS_WORD_ROULETTE

class WordRoulette {
public:
    WordRoulette(WordRepo repo, int wordCount);
    std::string getForeign();
    std::string getTranscription();
    std::string getTranslate();
    bool pass(bool successful);
private:
    WordRepo m_repo;
    std::vector<int> m_words;
    std::vector<int> m_readyWords;
    std::vector<int> m_passedWords;
    std::vector<int> m_notPassedWords;
    int m_wordCount;
    int m_currentWordIndex;
    int m_readyWordsAddIndex;
    void grabWord(int i);
    void markError(int i);
};

#endif  // CLASS_WORD_ROULETTE
