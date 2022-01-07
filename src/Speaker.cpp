#include "Speaker.h"
#include <iostream>
#include <string>

void Speaker::speak() {
    std::cout << "I speak\n";
    std::string s = "And i to";
    std::cout << s << "\n";
}

Speaker::Speaker() {
    std::cout << "Create new Speaker\n";
}

Speaker::~Speaker() {
        std::cout << "Delete Speaker\n";
}