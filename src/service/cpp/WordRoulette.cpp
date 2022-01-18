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

void shuffle(std::vector<int> &set) {
    size_t size = set.size();
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int tmp = set[i];
        set[i] = set[j];
        set[j] = tmp;
    }
}

WordRoulette::WordRoulette(WordRepo repo, int wordCount)
: m_repo(repo), m_wordCount(wordCount) {
    time_t startTime = time(NULL);
    m_currentWordIndex = 0;
    m_readyWordsAddIndex = 0;
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

    for (int i = 0; i < m_wordCount; i++) {
        m_readyWords.push_back(m_words[i]);
    }
    shuffle(m_readyWords);

    std::cout << '{';
    for (int i = 0; i < m_wordCount; i++) {
        std::cout << m_readyWords[i] << '-';
    }
    std::cout << '}' << '\n';
    std::cout << "m_wordIndexes size = " << m_words.size() << '\n';
    std::cout << "m_currentWord = " << m_readyWords[m_currentWordIndex] << '\n';
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
    bool result = true;
    if (!successful) {
        m_readyWords[m_readyWordsAddIndex] = m_readyWords[m_currentWordIndex];
        m_repo.markError(m_readyWords[m_currentWordIndex]);
        m_readyWordsAddIndex++;
    }
    m_currentWordIndex++;
    if (m_currentWordIndex == m_readyWords.size()) {
        m_currentWordIndex = 0;
        if (m_readyWordsAddIndex == 0) {
            result = false;
            for (int i = 0; i < m_wordCount; i++) {
                m_readyWords.push_back(m_words[i]);
            }
        } else {
            m_readyWords.resize(m_readyWordsAddIndex);
        }
        shuffle(m_readyWords);
        m_readyWordsAddIndex = 0;

        std::cout << '\n' << '{';
        for (int i = 0; i < m_readyWords.size(); i++) {
            std::cout << m_readyWords[i] << '-';
        }
        std::cout << '}' << '\n' << '\n';

    }
    return result;
}