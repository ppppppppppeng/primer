# ifndef SCREEN_H
# define SCREEN_H

#include <iostream>
#include <string>

class Screen
{
public: 
	
	typedef std::string::size_type pos;

	Screen(pos ht = 0, pos wd = 1, char c = '\0'):
		height(ht), width(wd), contents(ht * wd, c){}
	
	char get() const { 
		return contents[cursor];
	}
	char get(pos r, pos c) const;
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &move(pos r, pos c);

	Screen &display(std::ostream &os){
	       	do_display(os); 
		return *this;
	}
	const Screen &display(std::ostream &os) const {
		do_display(os);
		return *this;
	}

	void some_member() const;
private:
	void do_display(std::ostream &os) const
	{
		for(int i = 0; i <= height; i++)
		{
			for(int j = i * width; j <= (width * (i + 1)) - 1; j++)
				os << contents[j];
			os << std::endl;
		}

	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

	mutable size_t access_ctr;


};
#endif
