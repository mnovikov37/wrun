#include <iostream>
#include <vector>
#include "../../domain/h/Word.h"

class WordRepo {
public:
    WordRepo(std::string dictionaryPath);
    ~WordRepo();
    int size();
    std::string getForeign(int i);
    std::string getTranscription(int i);
    std::string getTranslate(int i);
    time_t getLastUsing(int i);
    bool getWasErrors(int i);

private:
    std::string m_dictionaryPath;
    std::vector<Word> m_words;
};