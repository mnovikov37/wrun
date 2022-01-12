#include <iostream>
#include <vector>
#include "../../domain/h/Word.h"

#ifndef CLASS_WORD_REPO
#define CLASS_WORD_REPO

class WordRepo {
public:
    WordRepo(std::string dictionaryPath);
    ~WordRepo();
    int size();
    std::string getForeign(int i);
    std::string getTranscription(int i);
    std::string getTranslate(int i);
    time_t getLastUsing(int i);
    bool wasErrors(int i);
    void resetWord(int i);
    void markError(int i);

private:
    std::string m_dictionaryPath;
    std::vector<Word> m_words;
};

#endif //  CLASS_WORD_REPO