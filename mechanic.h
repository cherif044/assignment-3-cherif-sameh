#include "person.h"
#pragma once
#include <iostream>
using namespace std;
class mechanic : public person

{
private:
	int counter;
	appointment* array;
public:
	mechanic() :person()              //initializing variables
	{
		counter = 0;
		array = NULL;
	}

	mechanic(string nam, int a, string i, int c, appointment x[]) :person(nam, a, i)
	{
		counter = c;
		array = new appointment[c];
		for (int i = 0; i < c; i++)
		{
			array[i] = x[i];
		}
	}
	void setarraysize(int s)               //setting the size of array
	{
		array = new appointment[s];
	}
	void setcounter(int x)                // set the number of assigned customers
	{
		counter = x;
	}
	int getcounter()
	{
		return counter;
	}
	void incr_counter()                  // incrementing the counter, i will be using this way to include appointments, by ++counter
	{
		counter++;
	}
	void add_app(appointment x)         // it's like pushing appointments into the array which is a better way for me, the counter is incremented manually by me so the counter here will be the empty index
	{
		array[counter] = x;
	}
	void set_App(appointment x[], int size)   // in case i wanted to add a whole array to the mechanic
	{
		array = new appointment[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = x[i];
		}
	}
	appointment get_app(int i)             // in case i wanted to get a specific app
	{
		return array[i];
	}
	bool isavailable(appointment x)             //checking availability
	{
		int check = 0;
		for (int i = 0; i < counter; i++)
		{
			if (array[i].hours == x.hours && array[i].mins == x.mins)
				check++;
		}
		if (check == 0)
			return true;
		else
			return false;
	}
	void printnfo()
	{
		person::printinfo();
		cout << "this mechanic has " << counter << "appointments" << endl;

	}
};