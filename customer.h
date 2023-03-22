#include "person.h"
#pragma once
#include <iostream>
using namespace std;

class customer : public person {
private:
	string mechanicid;
	appointment cust;
public:
	customer(string name, int a, string i, string m, int h, int minutes) :person(name, a, i)
	{
		mechanicid = m;
		cust.hours = h;
		cust.mins = minutes;
	}
	customer() : person()
	{
		mechanicid = "";
		cust.hours = 0;
		cust.mins = 0;
	}
	void set_mech_id(string x)
	{
		mechanicid = x;
	}
	string get_mech_id()
	{
		return mechanicid;
	}
	void setappointment(int h, int m)              //create appointment of the customer
	{
		if (h >= 0 && h < 24 && m >= 0 && m < 60)      //validation
		{
			cust.hours = h;
			cust.mins = m;
		}
	}
	appointment getappointment()                  //return struct appointment
	{
		return cust;
	}
	void printinfo()
	{
		person::printinfo();
		cout << "assigned mechanic id : " << mechanicid << endl;
		cout << "time of appointment: " << cust.hours << ":" << cust.mins << endl;
	}


};