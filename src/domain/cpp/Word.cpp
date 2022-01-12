#include <vector>
#include "../h/Word.h"

#define EMPTY_FOREIGN "[foreign]"
#define EMPTY_TRANSCRIPTION "[transcription]"
#define EMPTY_TRANSLATE "[translate]"
#define EMPTY_LAST_USING 0
#define EMPTY_WAS_ERRORS false

Word::Word()
    : m_foreign(EMPTY_FOREIGN), m_transcription(EMPTY_TRANSCRIPTION), m_translate(EMPTY_TRANSLATE)
    , m_lastUsing(EMPTY_LAST_USING), m_wasErrors(EMPTY_WAS_ERRORS) {}

Word::Word(std::string foreign
    , std::string transcription
    , std::string translate
    , time_t lastUsing
    , bool wasErrors)
    : m_foreign(foreign), m_transcription(transcription), m_translate(translate)
    , m_lastUsing(lastUsing), m_wasErrors(wasErrors) {}

std::string Word::getForeign() {
    return m_foreign;
}

std::string Word::getTranscription() {
    return m_transcription;
}

std::string Word::getTranslate() {
    return m_translate;
}

time_t Word::getLastUsing() {
    return m_lastUsing;
}

bool Word::getWasErrors() {
    return m_wasErrors;
}

bool Word::isEmpty() {
    return m_lastUsing == EMPTY_LAST_USING;
}

void Word::setLastUsing(time_t lastUsing) {
    m_lastUsing = lastUsing;
}

void Word::setWasErrors(bool wasErrors) {
    m_wasErrors = wasErrors;
}

std::string Word::toString() {
    std::string result;
    result += "Word={";
    result += ("m_foreign=\"" + m_foreign + "\"");
    result += (", m_transcription=\"" + m_transcription + "\"");
    result += (", m_translate=\"" + m_translate + "\"");
    result += (", m_lastUsing=" + std::to_string(m_lastUsing));
    result += (", m_wasErrors=" + std::to_string(m_wasErrors));
    result += ("}");
    return result;
}