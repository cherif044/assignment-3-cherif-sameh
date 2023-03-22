#pragma once
#include <iostream>
using namespace std;
class person
{
private:
	string Name, id;
	int age;
public:
	person() //default constructor
	{
		Name = "", id = "", age = 0;
	}
	person(string name, int a, string i)   //constructor
	{
		Name = name;
		age = a;
		id = i;

	}
	void setname(string n)
	{
		Name = n;
	}
	string getname()
	{
		return Name;
	}
	void setid(string i)
	{
		id = i;
	}
	string getid()
	{
		return id;
	}
	void setage(int a)
	{
		age = a;
	}
	int getage()
	{
		return age;
	}
	void printinfo()
	{
		cout << "name: " << Name << endl;
		cout << "id: " << id << endl;
		cout << "age: " << age << endl;
	}
	struct appointment {
		int hours, mins;
		appointment()
		{
			hours = 0, mins = 0;
		}
		bool operator <(appointment x)     //overloading operators
		{
			if (this->hours < x.hours)

				return true;

			else if (this->hours > x.hours)
				return false;
			else if (this->hours == x.hours)
			{
				if (this->mins > x.mins)
					return false;
				else if (this->mins < x.mins)
					return true;
				else
					return false;
			}
		}
		bool operator >(appointment x)
		{
			if (this->hours < x.hours)

				return false;

			else if (this->hours > x.hours)
				return true;
			else if (this->hours == x.hours)
			{
				if (this->mins > x.mins)
					return true;
				else if (this->mins < x.mins)
					return false;
				else
					return false;
			}
		}
		bool operator ==(appointment x)
		{
			if (this->hours == x.hours && this->mins == x.mins)
				return true;
			else
				return false;
		}
	};




};