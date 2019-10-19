#ifndef FOLDER_H
#define FOLDER_H

#include "include.h"
#include "Message.h"

class Folder
{
public:
	Folder(Message &m);
	Folder(const Folder&);
	Folder & operator=(const Folder &);
	~Folder();

	void addMsg(Message *);
	void remMsg(Message *);
	void print();
private:
	std::set<Message *> Msgs;
	void add_to_Msg(const Folder &);
	void remove_from_Msg();
};


#endif
