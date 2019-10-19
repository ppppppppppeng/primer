#ifndef Window_mgr_h
#define Window_mgr_h

#include <iostream>
#include <vector>
#include <string>

class Window_mgr
{
private:
	std::vector<string> screens{Screen(24, 80, ' ')};
};
