#include <cstdlib>
#include "../h/Game.h"

void Game::grabWord(int i) {
    m_wordIndexes.push_back(i);
    std::cout << i << ':' << m_repo.wasErrors(i) << '-' << m_repo.getLastUsing(i) << '\n';
    m_repo.resetWord(i);
}

void Game::markError(int i) {
    m_repo.markError(i);
}

Game::Game(WordRepo repo, int wordCount, bool foreignFirst)
: m_repo(repo), m_wordCount(wordCount), m_foreignFirst(foreignFirst){
    time_t startTime = time(NULL);
    srand(startTime);
    std::cout << "startTime = " << startTime << '\n';
    int repoSize = m_repo.size();
    int j = 0;
    if (m_wordCount > repoSize) {
        m_wordCount = repoSize;
    }
    for (int i = 0; i < repoSize && j < wordCount; i++) {
        if (m_repo.wasErrors(i)) {
            grabWord(i);
            j++;
        }
    }
    for (; j < m_wordCount; j++) {
        time_t minTime = startTime;
        int index = -1;
        for (int i = 0; i < repoSize; i++) {
            if (m_repo.getLastUsing(i) < minTime) {
                index = i;
                minTime = m_repo.getLastUsing(i);
            }
        }
        grabWord(index);
    }
    m_currentWordIndex = rand() % m_wordCount;
    std::cout << "m_wordIndexes size = " << m_wordIndexes.size() << '\n';
    std::cout << "m_currentWordIndex = " << m_currentWordIndex << '\n';
}