#include <string>
#include <ctime>

#ifndef WORD_H
#define WORD_H
class Word {
public:
    Word();
    Word(std::string foreign, std::string transcription, std::string translate, time_t lastUsing, bool wasErrors);
    std::string getForeign();
    std::string getTranscription();
    std::string getTranslate();
    time_t getLastUsing();
    bool getWasErrors();
    bool isEmpty();
    std::string toString();

private:
    std::string m_foreign;
    std::string m_transcription;
    std::string m_translate;

    int id;
    time_t m_lastUsing;
    bool m_wasErrors;
};

#endif