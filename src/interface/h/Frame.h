#ifndef MNOVIKOV37_INTERFACE_FRAME
#define MNOVIKOV37_INTERFACE_FRAME

#include <iostream>

class Frame {
public:
    Frame(int x, int y, int width, int height);
private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    std::string m_text;
    void show();
};

#endif  // MNOVIKOV37_INTERFACE_FRAME