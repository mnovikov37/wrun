#include "../h/Game.h"

bool Game::pass(bool foreignFirst) {
    char answer = 0;
    bool result = false;
    std::string letters[3];
    if (foreignFirst) {
        letters[0] = m_roulette.getForeign();
        // std::cout << m_roulette.getForeign() << '\n';
        letters[2] = m_roulette.getTranslate();
    } else {
        letters[0] = m_roulette.getTranslate();
        letters[2] = m_roulette.getForeign();
    }
    letters[1] = m_roulette.getTranscription();
    for (int i = 0; i < 3; i++) {
        std::cout << letters[i];
        answer = std::getchar();
    }
    std::cout << "------------------------\n";
    if (answer == ' ') { result = true; }
    return result;
}

Game::Game(WordRoulette roulette, bool foreignFirst)
:m_roulette(roulette), m_foreignFirst(foreignFirst) {
    while (m_roulette.pass(pass(m_foreignFirst)));
    while (m_roulette.pass(pass(!m_foreignFirst)));
}