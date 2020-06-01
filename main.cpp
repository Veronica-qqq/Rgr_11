#include <iostream>
#include "Phone.h"

using namespace std;

void menu(){
    cout << "\nMENU:\n\n";
    cout << "1) View the entire contact list\n";
    cout << "2) Add contact\n";
    cout << "3) Edit contact\n";
    cout << "4) Delete contact\n";
    cout << "5) Clear the entire contact list\n";
    cout << "6) Search for contacts by characteristics\n";
    cout << "7) Save the phone book to a file\n\n";
    cout << "0) Exit the program\n\n";
}

int main()
{
    PhoneBook e(9);
    e.readfile();

    int var;
    bool run = true;
    while (run) {
    menu();
    cout << "\nEnter the option number\n";
    cin >> var;

    if (var!=0)
    {
    switch (var)
    {
    case 1:
        e.viewlist();
        break;
    case 2:
        e.addcontact();
        e.viewlist();
        break;
    case 3:
        e.viewlist();
        e.editcontact();
        e.viewlist();
        break;
    case 4:
        e.viewlist();
        e.deletecontact();
        e.viewlist();
        break;
    case 5:
        e.deletelist();
        e.viewlist();
        break;
    case 6:
        int v;
        cout << "\nSelect which characteristic you want to search for a contact:\n";
        cout << "1 - Number\n2 - Name\n3 - Address\n\n";
        cin >> v;

        if (v == 1)
        {
            e.search_number();
        }

        if (v == 2)
        {
            e.search_name();
        }

        if (v == 3)
        {
            e.search_address();
        }

        break;
    case 7:
        e.loadfile();
        break;
    }

    cout << "\nDo you want to continue working with the phone book?\n";
    cout << "1 - yes\n0 - no\n";
    int ch;
    cin >> ch;

    if (ch == 0)
    {
        run = false;
    }

    if (ch == 1)
    {
        run = true;
    }

    }

    if (var == 0)
    {
        int a;
        cout << "\nDo you want to exit the program?\n";
        cout << "1 - Yes\n0 - No\n";
        cin >> a;

        if (a == 1)
        {
            run = false;
        }

        if (a == 0)
        {
            run = true;
        }
    }

    }

    return 0;
}
