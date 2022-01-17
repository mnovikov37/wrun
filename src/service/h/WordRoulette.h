#include "WordRepo.h"
#include <vector>

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
    bool m_foreignFirst;
    int m_currentWordIndex;
    void grabWord(int i);
    void markError(int i);
};
