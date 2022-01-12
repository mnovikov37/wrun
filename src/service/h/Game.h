#include "WordRepo.h"
#include <vector>

class Game {
public:
    Game(WordRepo repo, int wordCount, bool foreignFirst);
private:
    WordRepo m_repo;
    std::vector<int> m_wordIndexes;
    int m_wordCount;
    bool m_foreignFirst;
    int m_currentWordIndex;
    void grabWord(int i);
    void markError(int i);
};
