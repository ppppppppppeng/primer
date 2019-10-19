#include <iostream>
#include <string>
#include "Screen.h"

Screen &Screen::move(pos r, pos c)
{
	if(r > height || c > width)
		return *this;
	cursor = r * width + c;
	return *this;
}

inline char Screen::get(pos r, pos c) const
{
	return contents[r * width + c];
}
Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch;
	return *this;
}

void Screen::some_member() const
{
	++access_ctr;
}
