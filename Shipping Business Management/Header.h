#pragma once
#include <iostream>
using namespace std;

class Person {
public:
    string name, surname;
    Person()
    {
        name = "name";
        surname = "surname";
    }
    Person(string a, string b)
    {
        name = a;
        surname = b;
    }
    void print()
    {
        cout << name << " " << surname << endl;
    }
};

class Courier : public Person {
public:
    string vehicle;
    int capacity;
    void print()
    {
        cout << name << " " << surname << " " << vehicle << " " << capacity << endl;
    }
    Courier()
    {
        vehicle = "vehicle";
        capacity = 0;
    }
    Courier(string nm, string snm, string vhc)
    {
        name = nm;
        surname = snm;
        vehicle = vhc;
        if (vhc == "car")
        {
            capacity = 200;
        }
        else if (vhc == "motorcycle")
        {
            capacity = 35;
        }
        else if (vhc == "bicycle")
        {
            capacity = 10;
        }
    }
    bool operator==(const Courier& x)
    {
        if (name == x.name && surname == x.surname && vehicle == x.vehicle && capacity == x.capacity) return true;
        else return false;
    }
};

class Owner : public Person {
public:
    float ownership;
    Owner() {
        ownership = 100;
    }
    Owner(string nm, string snm)
    {
        name = nm;
        surname = snm;
        ownership = 100;
    }
};

class Business {
public:
    string busname;
    string adress;
    Owner* arr;
    Courier* cl;
    int ownercount;
    int ccount, maxcr;
    Business(string nm, string adr, Owner* a, int ownerc) {
        busname = nm;
        adress = adr;
        arr = a;
        for (int i = 0; i < ownerc; i++) arr[i].ownership = 100.0 / ownerc;
        ownercount = ownerc;
        cl = new Courier[1];
        ccount = 0;
        maxcr = 1;
    }
    void hire_courier(Courier a) {
        if (ccount < maxcr)
        {
            cl[ccount] = a;
            ccount++;
        }
        else 
        {
            Courier* x = new Courier[2 * maxcr];
            for (int i = 0; i < maxcr; i++) x[i] = cl[i];
            x[ccount] = a;
            ccount++;
            delete[] cl;
            cl = x;
            maxcr = 2 * maxcr;
        }
    }
    void fire_courier(Courier x) 
    {
        for (int i = 0; i < ccount; i++) 
        {
            if (cl[i] == x) {
                for (int j = i; j < ccount-1; j++) {
                    cl[j] = cl[j + 1];
                }
                ccount -= 1;
                return;
            }
        }
        cout << "Courier does not exist." << endl;
    }
    void list_couriers()
    {
        cout << "Couriers:" << endl;
        for (int i = 0; i < ccount; i++) {
            cout << cl[i].name << " " << cl[i].surname << " with " << cl[i].vehicle << " capacity of " << cl[i].capacity << endl;

        }
    }
    void list_owners()
    {
        cout << "Owners:" << endl;
        for (int i = 0; i < ownercount; i++) {
            cout << arr[i].name << " " << arr[i].surname << " with ownership " << arr[i].ownership << "%" << endl;
        }
    }
    int calculate_shipment_capacity() 
    {
        int totalcapacity = 0;
        for (int i = 0; i < ccount; i++)
        {
            totalcapacity += cl[i].capacity;
        }
        return totalcapacity;
    }
    void operator()() 
    {
        cout << "Business name is " << busname << " and adress is  " << adress << endl;
        list_owners();
        list_couriers();
    }
    Courier operator[](const int& ind)
    {
        return cl[ind];
    }
    ~Business()
    {
        delete[] arr;
        delete[] cl;
    }
};