#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class City
{
private:
	char * name;
	int id;
public:
	City();
	City(char * cname, int cid);
	char * getName();
	int getId();
	friend ostream& operator<<(ostream& out, const City& s)
	{
		out << "(" << s.name << "," << s.id << ")\t";
		return out;
	}
	~City();
};

