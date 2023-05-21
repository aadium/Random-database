#include <iostream>
#include <string>
#include "portal.h"
using namespace std;

int main(int argc, char const *argv[])
{
    login loginpage;
    dataentry entry;
    string username{};
    string password{};
    string inputusername{};
    string inputpassword{};
    string firstname{};
    string middlename{};
    string lastname{};
    string email{};
    string mob{};
    string gender{};
    string accounttype{};
    long long int phone{};
    long long int personid{};
    long long int personidtofind{};
    long long int personidtodelete{};
    long long int personidtoupdate{};
    int countrycode{};
    int dob{};
    int yob{};
    int actionchoice{};
    char choice{};
    bool valid = false;

    cout << "Welcome to UAP Datasystems. Unlock the Power of Data with Our Cutting-Edge Database Solutions." << endl;

    valid = loginpage.checklogindata(inputusername, inputpassword, username, password);
    if (valid == 0)
    {
        cout << "Terminating program.";
        return -1;
    }

    do
    {
        actionchoice == 5;

        cout << "Please enter a number depending on the action you wish to take: " << endl;
        cout << "Enter 1 for adding an entry." << endl;
        cout << "Enter 2 for viewing entries." << endl;
        cout << "Enter 3 for updating an entry." << endl;
        cout << "Enter 4 for deleting an entry." << endl;
        cout << "Enter 5 to log out." << endl;
        cin >> actionchoice;
        while (cin.fail())
        {
            cout << "Enter a number from 1 to 5: ";
            cin >> actionchoice;
        }

        if (actionchoice == 1) // add entries
        {
            do
            {
                choice == 'N';

                entry.addentry(firstname, middlename, lastname, countrycode, personid, phone, email, dob, mob, yob, gender);

                cout << "Entry has been added." << endl;

                cout << "Do you want to add another entry(Y/N)?: ";
                cin >> choice;

            } while (choice == 'Y');
        }

        if (actionchoice == 2) // view entries
        {

            cout << "Do you want to view a specific entry(Y/N)? If no, all entries will be displayed: ";
            cin >> choice;
            if ((choice == 'Y') || (choice == 'y'))
            {
                cout << "Enter the person I.D.: ";
                cin >> personidtofind;
                entry.showentry(personidtofind);
            }

            else if ((choice == 'N') || (choice == 'n'))
            {
                entry.showdata();
            }

            else
            {
                cout << "Invalid input" << endl;
            }
        }

        if (actionchoice == 3) // update entry
        {
            cout << "Enter the person I.D.: ";
            cin >> personidtoupdate;
            while (cin.fail())
            {
                cout << "Enter a valid person I.D.: ";
                cin >> personidtoupdate;
            }

            entry.updateentry(firstname, middlename, lastname, countrycode, personidtoupdate, phone, email, dob, mob, yob, gender);
        }

        if (actionchoice == 4) // delete entry
        {
            cout << "Enter the person I.D.: ";
            cin >> personidtodelete;
            while (cin.fail())
            {
                cout << "Enter a valid person I.D.: ";
                cin >> personidtodelete;
            }
            entry.deleteentry(personidtodelete);
        }

    } while (actionchoice != 5);

    cout << "Logging out" << endl;

    return 0;
}