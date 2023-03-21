





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
template<class t>
class queue {
public:
	int front, rear, size;
	t* storage;

	queue(int s)
	{
		size = s;
		front = -1;
		rear = -1;
		storage = new t[size];
		
	}
	bool isfull()
	{
		if ((front == 0 && rear == size - 1) || (front == rear + 1))
			return true;
		else
			return false;
	}
	bool isempty()
	{
		if (front == -1 && rear == -1)
			return true;
		else
			return false;
	}
	void push(t x)
	{
		if (isfull())
			cout << "full" << endl;
		if (isempty())
		{
			front++, ++rear;
			storage[rear] = x;
		}
		else if (rear == size - 1)
		{
			rear = 0;
			storage[rear] = x;
		}
		else
		{
			rear = rear + 1;
			storage[rear] = x;
		}
	}
	void pop()
	{
		if (isempty())
			cout << "empty" << endl;
		else if (rear == front)
		{
			front = rear = -1;
		}
		else if (front == size - 1)
		{
			front = 0;

		}
		else
			front++;

	}
	t getfront()
	{
		
			return storage[front];                                             //circular queue implementation
	}
	void display()
	{
		if (isempty())
			cout << "empty" << endl;
		else if (front <= rear)
		{
			cout << "front: " << endl;
			for (int i = front; i <= rear; i++)
			{
				cout << storage[i] << endl;
			}
			cout << "rear" << endl;
		}
		else
		{
			cout << "front: ";
			for (int i = front; i < size; i++)
			{
				cout << storage[i] << endl;
			}

			for (int i = 0; i <= rear; i++)
			{
				cout << storage[i] << endl;
			}
			cout << "rear" << endl;
		}

	}
};


