#include "13.4.h"

Message::Message(const Message &m) :contents(m.contents), folders(m.folders)
{
	add_Folders(*this);
}

Message & Message::operator=(const Message & m)
{
	remove_from_Folders();
	contents = m.contents;
	folders = m.folders;
	add_Folders(*this);
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder & f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder & f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_Folders(const Message &m)
{
	for (auto i : folders)
	{
		i->addMsg(this);
	}
}

void Message::remove_from_Folders()
{
	for (auto i : folders)
	{
		i->remMsg(this);
	}
}






Folder::Folder()
{
}

Folder & Folder::operator=(const Folder & m)
{
	return *this;
}

Folder::~Folder()
{
}

void Folder::addMsg(Message * m)
{
	mess.insert(m);
}

void Folder::remMsg(Message * m)
{
	mess.erase(m);
}












