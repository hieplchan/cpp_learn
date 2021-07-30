#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen {
public:
    typedef std::string::size_type pos; // types member - hide what type is used - user only know "pos" - not "size_type"
    Screen() = default;
    Screen(pos ht, pos wd, char c):
        height(ht), width(wd), contents(ht * wd, c) { }
    
    inline char get(pos r, pos c) const; // explicitly inline
    char get() const { return contents[cursor]; } // implicitly inline
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &move(pos r, pos c); // inline outside - make easier to read
    void some_member() const;
    size_t access_ctr_count() const {
        return access_ctr;
    }

private:
    pos cursor = 0;
    pos width = 0, height = 0;
    std::string contents;
    mutable size_t access_ctr; // mutable object is never const - even if object is const
};

inline Screen &Screen::move(pos r, pos c) { // explicitly inline outside of Class
    pos row = r * width;
    cursor = row + c;
    return *this;
}
char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}
inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this; // return this object as an lvalue
}
inline Screen &Screen::set(pos r, pos col, char c) {
    contents[r*width + col] = c;
    return *this;
}
void Screen::some_member() const {
    ++ access_ctr;
}
#endif