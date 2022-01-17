#include <cstdlib>
#include "../h/WordRoulette.h"

void WordRoulette::grabWord(int i) {
    m_words.push_back(i);
    std::cout << i << ':' << m_repo.wasErrors(i) << '-' << m_repo.getLastUsing(i) << '\n';
    m_repo.resetWord(i);
}

void WordRoulette::markError(int i) {
    m_repo.markError(i);
}

void deleteElement(std::vector<int> &set, int index) {
    size_t newSize = set.size() -1;
    for (int i = index; i < newSize; i++) {
        // std::cout << set[i] << " <- " << set[i+1] << '\n';
        set[i] = set[i + 1];
    }
    set.pop_back();
}

WordRoulette::WordRoulette(WordRepo repo, int wordCount)
: m_repo(repo), m_wordCount(wordCount) {
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

    for (int i = 0; i < m_wordCount; i++) {
        m_readyWords.push_back(m_words[i]);
    }
    
    std::cout << "m_wordIndexes size = " << m_words.size() << '\n';
    std::cout << "m_currentWordIndex = " << m_currentWordIndex << '\n';
}

std::string WordRoulette::getForeign() {
    return m_repo.getForeign(m_readyWords[m_currentWordIndex]);
}

std::string WordRoulette::getTranscription() {
    return m_repo.getTranscription(m_readyWords[m_currentWordIndex]);
}

std::string WordRoulette::getTranslate() {
    return m_repo.getTranslate(m_readyWords[m_currentWordIndex]);
}

bool WordRoulette::pass(bool successful) {
    bool result;
    if (successful) {
        m_passedWords.push_back(m_readyWords[m_currentWordIndex]);
    } else {
        m_notPassedWords.push_back(m_readyWords[m_currentWordIndex]);
        m_repo.markError(m_readyWords[m_currentWordIndex]);
    }
    deleteElement(m_readyWords, m_currentWordIndex);
    size_t readyWordsCount = m_readyWords.size();
    // std::cout << "m_readyWords,size() = " << readyWordsCount << '\n';

    if (readyWordsCount) {
        m_currentWordIndex = rand() % readyWordsCount;
        // std::cout << "m_currentWordIndex = " << m_currentWordIndex << '\n';
        result = true;
    } else {
        result = false;
    }

    return result;
}