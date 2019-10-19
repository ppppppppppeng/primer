#include "include.h"
#include "Folder.h"
using namespace std;

Folder::Folder(Message &m)
{
	m.save(*this);
}
Folder::Folder(const Folder &f)
{
		add_to_Msg(f);
}
Folder & Folder::operator=(const Folder &f)
{
	remove_from_Msg();
	for(auto m : f.Msgs)
		m->save(*this);
	return *this;
}

void Folder::addMsg(Message *m)
{
	Msgs.insert(m);
}

void Folder::remMsg(Message *m)
{
	Msgs.erase(m);
}

void Folder::add_to_Msg(const Folder &f)
{
	for(auto m : f.Msgs)
		m->save(*this);
}

void Folder::remove_from_Msg()
{
	for(auto m : Msgs)
		m->remove(*this);
}
Folder::~Folder()
{
	for(auto m : Msgs)
		m->remove(*this);
}
void Folder::print()
{
	for(auto m : Msgs)
		cout << m->contents << " ";
}
