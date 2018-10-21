//#include "stdafx.h"
#include "City.h"


City::City()
{

}

City::City(char * cname, int cid)
{
	this->name = new char[sizeof(cname)+1];
	strcpy(this->name,cname);
	this->id = cid;
}


char * City::getName()
{
	return this->name;
}

int City::getId()
{
	return this->id;
}


City::~City()
{

}
