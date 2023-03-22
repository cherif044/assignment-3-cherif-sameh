#include <iostream>
using namespace std;
#include "person.h"
#include "customer.h"
#include "mechanic.h"

int main()
{
    string tempid, tempname, temp;
    bool check = false;
    int cust_count = 0, tempage, temphour, tempmin;



    cout << "how many customers are there ?" << endl;
    cin >> cust_count;
    customer* CUSTOMERS;
    CUSTOMERS = new customer[cust_count];                          //collecting information about the system, and creating dynamic arrays
    int mechanic_count = 0;
    cout << "how many mechanics are there ?" << endl;
    cin >> mechanic_count;
    mechanic* MECHANICS;

    MECHANICS = new mechanic[mechanic_count];

    for (int i = 0; i < mechanic_count; i++)
    {
        cout << "mechanic: " << i + 1 << endl;
        cout << "enter name: ";
        cin >> temp;
        cout << endl;
        // collecting mechanics data
        MECHANICS[i].setname(temp);
        cout << "enter id: ";
        cin >> temp;
        MECHANICS[i].setid(temp);
        cout << endl;
        cout << "enter age: ";
        cin >> tempage;
        MECHANICS[i].setage(tempage);
        MECHANICS[i].setarraysize(cust_count);
    }

    cout << endl;


    for (int i = 0; i < cust_count; i++)
    {
        cout << "customer: " << i + 1 << endl;
        cout << "enter name: " << endl;
        cin >> tempname;
        CUSTOMERS[i].setname(tempname);
        cout << "enter age: " << endl;
        cin >> tempage;
        CUSTOMERS[i].setage(tempage);
        cout << "enter id: " << endl;
        cin >> tempid;                                                        //collecting customers data
        CUSTOMERS[i].setid(tempid);
        cout << "what hour you would like to register? " << endl;
        cin >> temphour;
        cout << "what minutes you would like to register? " << endl;
        cin >> tempmin;

        CUSTOMERS[i].setappointment(temphour, tempmin);                         // registering the timing of the desired time of appointment

        bool check = false;
        int j = i % mechanic_count;                                            // i used i% mechanic_count in order to loop in a sequential way on customers so if there are 5 mechanics than it will be 0-4 and then start again the same loop
        do
        {

            if (MECHANICS[j].isavailable(CUSTOMERS[i].getappointment()))
            {
                CUSTOMERS[i].set_mech_id(MECHANICS[j].getid());                 // setting the registered mechanic id to the customer
                check = true;
                MECHANICS[j].add_app(CUSTOMERS[i].getappointment());            //pushing the appointment in the array
                MECHANICS[j].incr_counter();                                   //incrementing counter to move to the next index in the next loop

            }
            j++;
        } while (check == false && j < mechanic_count);



        int h = 0;
        if (check == false)
        {
            do
            {
                if (MECHANICS[h].isavailable(CUSTOMERS[i].getappointment()))
                {
                    CUSTOMERS[i].set_mech_id(MECHANICS[h].getid());
                    check = true;
                    //looping from 0 t j in case j was 2 for example, to check on all mechanics
                    MECHANICS[h].add_app(CUSTOMERS[i].getappointment());
                    MECHANICS[h].incr_counter();

                }
                h++;
            } while (check == false && h < j);
        }

        if (check == false)
            cout << "cancelled, no slots available" << endl;

    }

    cout << endl << endl << endl;

    for (int i = 0; i < cust_count; i++)
    {
        bool m = false;
        for (int j = 0; j < mechanic_count; j++)
        {

            if (CUSTOMERS[i].get_mech_id() == MECHANICS[j].getid())
            {
                cout << CUSTOMERS[i].getname() << " is assigned with: " << MECHANICS[j].getname() << " at: " << CUSTOMERS[i].getappointment().hours << ":" << CUSTOMERS[i].getappointment().mins << endl;
                m = true;
            }


        }
        if (m == false)
            cout << "sorry " << CUSTOMERS[i].getname() << ", but your registration was cancelled because we couldn't find an empty slot" << endl;
    }

    queue <customer>x(cust_count);
    customer tempCUST;
    for (int i = 0; i < cust_count; i++)
    {
        for (int j = i + 1; j < cust_count; j++)
        {
            if (CUSTOMERS[i].getappointment() > CUSTOMERS[j].getappointment())
            {

                tempCUST = CUSTOMERS[i];
                CUSTOMERS[i] = CUSTOMERS[j];
                CUSTOMERS[j] = tempCUST;
            }
        }

    }



    cout << endl << endl << endl;
    for (int i = 0; i < cust_count; i++)
    {
        x.push(CUSTOMERS[i]);
    }
    cout << endl;
    cout << "sorted queue: " << endl << endl << endl;

    for (int i = 0; i < cust_count; i++)
    {
        bool status = false;

        for (int j = 0; j < mechanic_count; j++)
        {
            if (x.getfront().get_mech_id() == MECHANICS[j].getid())
            {
                cout << x.getfront().getname() << " is assigned with: " << MECHANICS[j].getname() << " at: " << CUSTOMERS[i].getappointment().hours << ":" << CUSTOMERS[i].getappointment().mins << endl;
                status = true;
            }


        }
        if (status == false)
        {
            cout << x.getfront().getname() << "'s appointment got cancelled" << endl;
        }
        x.pop();
    }
    return 0;

}