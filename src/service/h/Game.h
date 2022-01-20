#include "WordRoulette.h"

class Game {
public:
    Game(WordRoulette roulette, bool foreignFirst);
private:
    WordRoulette m_roulette;
    bool m_foreignFirst;
    bool pass(bool foreignFirst);
};
