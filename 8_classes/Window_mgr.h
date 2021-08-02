#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>
#include "Screen.h"

class Window_mgr {
public:
    typedef std::vector<Screen>::size_type ScreenIndex;
    void clear(ScreenIndex);
private:
    // default initializer have blank Screen
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex index) {
    Screen &s = screens[index];
    // Window_mgr can access Screen private member because of "friend"
    s.contents = std::string(s.height * s.width, ' ');
}

#endif