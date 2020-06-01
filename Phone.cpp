#include "Phone.h"

PhoneBook::PhoneBook()
{
    n = 0;
    p = NULL;
}

PhoneBook::PhoneBook(int t_n)
{
    n = t_n;
    p = new Contact[t_n];
    for (int i = 0; i < t_n; i++)
    {
        p[i].number  = 0;
        p[i].name = "none";
        p[i].address = "none";
    }
}

PhoneBook::PhoneBook(const PhoneBook &b)
{
    n = b.n;
    p = new Contact[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = b.p[i];
    }
}

PhoneBook:: ~PhoneBook()
{
    delete [] p;
}

PhoneBook& PhoneBook::operator=(const PhoneBook &a)
{
    delete [] p;
    n = a.n;
    p = new Contact[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = a.p[i];
    }
    return *this;
}

void PhoneBook::viewlist() const
{
    cout << "\nEntire contact list:\n\n";
    for (int i = 0; i < n; i++)
    {
        cout  << p[i].number << "\t";
        cout << p[i].name <<"\t\t";
        cout  << p[i].address << "\t" << endl;
    }
}

void PhoneBook::addcontact()
{
    int new_n = n + 1;
    Contact *new_p = new Contact[new_n];
    for (int i = 0; i < n; i++)
    {
        new_p[i] = p[i];
    }
    delete [] p;
    p = new_p;
    cout << "\nEnter data for new contact:\n";
    cin >> p[n].number >> p[n].name >> p[n].address;
    n++;
}

 void PhoneBook::deletelist()
 {
    delete [] p;
    p = NULL;
    n = 0;
    cout << "\nThe list is deleted" <<endl;
 }

void PhoneBook::editcontact()
{
    int i;
    cout << "\nSelect which contact you want to edit:\n";
    cin >> i;
    cout << "\nEnter new data for edit:\n";
    cin >> p[i-1].number >> p[i-1].name >> p[i-1].address;
}

void PhoneBook::deletecontact()
{
    int s;
    cout << "\nSelect which contact you want to delete:\n";
    cin >> s;
    for (int i = s - 1; i < n - 1; i++)
    {
        p[i] = p[i + 1];
    }
    n--;
}

void PhoneBook::search_number()
{
    int number1;
    int h = 0;
    cout << "\nEnter the contact number you want to find: ";
    cin >> number1;
    for (int i = 0; i < n; i++)
    {
        if (p[i].number == number1)
        {
            cout << "\n" << p[i].number << " " << p[i].name << " " << p[i].address << "\n";
            h++;
        }
    }
    if (h == 0)
    {
        cout << "\nThis contact is not listed in the phone book" << endl;
    }
}

void PhoneBook::search_name()
{
    string name1;
    int h = 0;
    cout << "\nEnter the name of the contact you want to find: ";
    cin >> name1;
    for (int i = 0; i < n; i++)
    {
        if (p[i].name == name1)
        {
            cout << "\n" << p[i].number << " " << p[i].name << " " << p[i].address << "\n";
            h++;
        }
    }
    if (h == 0)
    {
        cout << "\nThis contact is not listed in the phone book" << endl;
    }
}

void PhoneBook::search_address()
{
    string address1;
    int h = 0;
    cout << "\nEnter the address of the contact you want to find: ";
    cin >> address1;
    for (int i = 0; i < n; i++)
    {
        if (p[i].address == address1)
        {
            cout << "\n" << p[i].number << " " << p[i].name << " " << p[i].address << "\n";
            h++;
        }
    }
    if (h == 0)
    {
        cout << "\nThis contact is not listed in the phone book" << endl;
    }
}

void PhoneBook::readfile()
{
    ifstream in;
    in.open("input.txt");
    if (!in.is_open())
    {
        cout << "\nFile is not found\n";
    }
    if (in.is_open())
    {
    for (int i = 0; i < n; i++)
    {
        in >> p[i].number;
        in >> p[i].name;
        in >> p[i].address;
    }
    }

    in. close();
}

void PhoneBook::loadfile()
{
    ofstream out;
    out.open("output.txt");
    if (!out.is_open())
    {
        cout << "\nFile cannot be opened or created\n";
    }
    if (out.is_open())
    {
    for (int i = 0; i < n; i++)
    {
        out << p[i].number << " ";
        out << p[i].name << " ";
        out << p[i].address << "\n";
    }
        cout << "\nFile is loaded\n";
    }

    out.close();
}
