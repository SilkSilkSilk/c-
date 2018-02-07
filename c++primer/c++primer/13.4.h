#ifndef _13CHAPTER4_H__
#define _13CHAPTER4_H__

#include <iostream>
#include <vector>
#include <cstring>
#include "string"
#include <memory>
#include <set>


using namespace std;

class Folder;
class Message
{
	friend class Folder;
public:
	Message(const string &str = ""):contents(str){}
	Message(const Message&);
	Message& operator=(const Message& m);
	~Message();

	void save(Folder &f);
	void remove(Folder &f);
private:
	string contents;
	set<Folder*> folders;
	void add_Folders(const Message&);
	void remove_from_Folders();
};

class Folder
{
public:
	Folder();
	Folder(const Folder& f);
	Folder& operator=(const Folder& m);
	~Folder();

	void addMsg(Message *m);
	void remMsg(Message *m);

private:
	set<Message*> mess;
};



#endif