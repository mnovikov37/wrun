#include "../h/Frame.h"

#define LEFT_UP "┌"
#define RIGHT_UP "┐"
#define LEFT_DOWN "└"
#define RIGHT_DOWN "┘"
#define HORISONTAL "─"
#define VERTICAL "│"
#define SPACE " "

void Frame::show() {
    int width = m_width - 2;
    int height = m_height - 2;
    
    std::cout << LEFT_UP;
    for (int i = 0; i < width; i++) {
        std::cout << HORISONTAL;
    }
    std::cout << RIGHT_UP << '\n';

    for (int i = 0; i < height; i++) {
        std::cout << VERTICAL;
        for (int j = 0; j < width; j++) {
            std::cout << SPACE;
        }
        std::cout << VERTICAL << '\n';
    }

    std::cout << LEFT_DOWN;
    for (int i = 0; i < width; i++) {
        std::cout << HORISONTAL;
    }
    std::cout << RIGHT_DOWN << '\n';
}

Frame::Frame(int x, int y, int width, int height)
: m_x(x), m_y(y), m_width(width), m_height(height) {
    show();
}