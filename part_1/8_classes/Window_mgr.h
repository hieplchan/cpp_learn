#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>
#include "Screen.h"

class Window_mgr {
public:
    typedef std::vector<Screen>::size_type ScreenIndex;
    void clear(ScreenIndex);
    ScreenIndex addScreen(const Screen&);
private:
    // default initializer have blank Screen
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex index) {
    Screen &s = screens[index];
    // Window_mgr can access Screen private member because of "friend"
    s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
    screens.push_back(s);
    return screens.size() - 1;
}

#endif