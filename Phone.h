#ifndef PHONE_H_INCLUDED
#define PHONE_H_INCLUDED
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Contact {
public:
    int number;
    string name;
    string address;
};

class PhoneBook {
private:
    int n;
    Contact *p;
public:
    PhoneBook();
    PhoneBook(int t_n);
    PhoneBook(const PhoneBook &b);
    ~PhoneBook();
    PhoneBook& operator=(const PhoneBook &a);
    void viewlist() const;
    void addcontact();
    void editcontact();
    void deletecontact();
    void deletelist();
    void search_number();
    void search_name();
    void search_address();
    void readfile();
    void loadfile();

};

#endif // PHONE_H_INCLUDED
