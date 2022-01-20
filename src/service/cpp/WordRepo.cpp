#include "../h/WordRepo.h"
#include <fstream>
#include <ctime>

#define SEPARATOR '|'

Word readWord(std::ifstream &in) {
    std::string foreign, transcription, translate, garbage;
    time_t lastUsing;
    bool wasErrors;
    if (getline(in, foreign, SEPARATOR)
        && getline(in, transcription, SEPARATOR)
        && getline(in, translate, SEPARATOR)
        && in >> lastUsing >> wasErrors
        && getline(in, garbage)) {
        Word w(foreign, transcription, translate, lastUsing, wasErrors);
        return w;
    } else {
        Word w;
        return w;
    }
}

void writeWord(Word& word, std::ofstream &out) {
    out
        << word.getForeign() << SEPARATOR
        << word.getTranscription() << SEPARATOR
        << word.getTranslate() << SEPARATOR
        << word.getLastUsing() << ' '
        << word.getWasErrors() << '\n';
}

WordRepo::WordRepo(std::string dictionaryPath)
    : m_dictionaryPath(dictionaryPath), m_words() {
    std::ifstream in(m_dictionaryPath);
    if (in.is_open()) {
        while (true) {
            Word w = readWord(in);
            if (w.isEmpty()) {
                break;
            } else {
                m_words.push_back(w);
            }
        }
        in.close();
    } else {
        std::cerr << "Unable to open dictionary file \"" << m_dictionaryPath << "\"\n";
    }
    // for (int i = 0; i < m_words.size(); i++) {
    //     std::cout << i << ':' << m_words[i].toString() << '\n';
    // }
}

WordRepo::~WordRepo() {
    // std::string outputFileName = "~" + m_dictionaryPath;
    // std::ofstream out(outputFileName);
    // if (out.is_open()) {
    //     int size = m_words.size();
    //     for (int i = 0; i < size; i++) {
    //         writeWord(m_words[i], out);
    //     }
    //     out.close();
    //     if (rename(outputFileName.c_str(), m_dictionaryPath.c_str())) {
    //         std::cerr << "Unable to saving results of current session - unable to rename temp file \""
    //         << outputFileName << "\" to dictionary file \"" << m_dictionaryPath << "\"\n";
    //     }
    // } else {
    //     std::cerr << "Unable to saving results of current session - unable to create temp file \""
    //     << outputFileName << "\"\n";
    // }
}

int WordRepo::size() {
    return m_words.size();
}

std::string WordRepo::getForeign(int i) {
    return m_words[i].getForeign();
}

std::string WordRepo::getTranscription(int i) {
    return m_words[i].getTranscription();
}

std::string WordRepo::getTranslate(int i) {
    return m_words[i].getTranslate();
}

time_t WordRepo::getLastUsing(int i) {
    return m_words[i].getLastUsing();
}

bool WordRepo::wasErrors(int i) {
    return m_words[i].getWasErrors();
}

void WordRepo::resetWord(int i) {
    m_words[i].setWasErrors(false);
    m_words[i].setLastUsing(time(NULL));
}

void WordRepo::markError(int i) {
    m_words[i].setWasErrors(true);
}

#undef SEPARATOR