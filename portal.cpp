#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
using namespace std;

class login
{

    public:

        bool checklogindata(string inputusername, string inputpassword, string username, string password)
        {
            bool valid = 0;
            if ((inputusername == username) && (inputpassword == password))
            {
                this_thread::sleep_for(1s);
                cout << "Login successful." << endl;
                valid = 1;

            }
            
            else if ((inputusername != username) or (inputpassword != password))
            {
                this_thread::sleep_for(1s);
                cout << "Invalid username or password." << endl;
                valid = 0;

            }

            return valid;

        }    

};

class dataentry
{

    public:

        void adddata(string firstname, string middlename, string lastname, int countrycode, long long int serialno, long long int phone, string email, int dob, string mob, int yob, string gender)
        {
            string line;
            ifstream inputfile ("database.csv");
            int lineNumber = 1;

            if (inputfile.is_open()) {

                while (getline(inputfile,line)) {
                    lineNumber++;
                }

                inputfile.close();
                serialno = lineNumber;
            }
            
            else 
            {
                cout << "Unable to open database." << endl;
            }

            cout << "Enter first name: ";
            cin >> firstname;
            cout << "Enter middle name: ";
            cin >> middlename;
            cout << "Enter last name: ";
            cin >> lastname;
            cout << "Enter phone number (without country code): ";
            cin >> phone;
            cout << "Enter country code: ";
            cin >> countrycode;
            cout << "Enter E-mail I.D.: ";
            cin >> email;
            cout << "Enter day number of birth: ";
            cin >> dob;
            cout << "Enter month of birth: ";
            cin >> mob;
            cout << "Enter year of birth: ";
            cin >> yob;
            cout << "Enter gender: ";
            cin >> gender;

            ofstream outfile;
            outfile.open("database.csv", ios::app);

            outfile << serialno << "," << firstname << "," << middlename << "," << lastname << "," << countrycode << "," << phone << "," << email << "," << dob << "," << mob << "," << yob << "," << gender << endl;

            outfile.close();

        }

        void showdata()
        {
            string line;
            ifstream inFile("database.csv");
            if (inFile.is_open())
            {
                while (getline (inFile,line))
                {
                    cout << line << endl;
                }
                inFile.close();
            }

        }

        void showentry(int serialno)
        {
            string line;
            ifstream myfile ("database.csv", ios::app);
            int lineNumber = 0;

            if (myfile.is_open()) {
                while (getline(myfile,line)) {
                    lineNumber++;
                    if(lineNumber == serialno) {
                        cout << line << endl;
                    }
                }
                myfile.close();
            } 
            
            else 
            {
                cout << "Unable to open file" << endl;
            }
        }

        void deleteentry(int serialno)
        {
            string line;
            vector<string> lines;
            ifstream INFILE("database.csv");
            int lineNumber = 0;

            if (INFILE.is_open()) {
                while (getline(INFILE, line)) {
                    lineNumber++;
                    if (lineNumber != serialno) {
                        lines.push_back(line);
                    }
                }
                INFILE.close();
    
            }
            else
            {
                cout << "Unable to open file" << endl;
            }

            ofstream OUTFILE("database.csv");
            for (string l : lines)
            {
                OUTFILE << l << endl;
            }
            OUTFILE.close();
        }


        // Add more functions for updating an entry
};

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
    long long int serialno{};
    long long int serialnotofind{};
    long long int serialnotodelete{};
    int countrycode{};
    int dob{};
    int yob{};
    int actionchoice{};
    char choice{};
    bool valid = false;

    this_thread::sleep_for(1s);

    cout << "Welcome to UAP Datasystems. Unlock the Power of Data with Our Cutting-Edge Database Solutions." << endl;

    this_thread::sleep_for(1s);

    ifstream infile("username.txt");

    if (infile.is_open())
    {
        (getline(infile,username));

        infile.close();
    }

    ifstream fileinput("password.txt");

    if (fileinput.is_open())
    {
        (getline(fileinput,password));

        fileinput.close();
    }

    cout << "Please enter your username: ";
    cin >> inputusername;
    cout << "Please enter your password: ";
    cin >> inputpassword;

    valid = loginpage.checklogindata(inputusername, inputpassword, username, password);
    if (valid == 0)
    {
        cout << "Terminating program.";
        return -1;
    }

    this_thread::sleep_for(1s);

    do
    {   actionchoice == 5;

        cout << "Please enter a number depending on the action you wish to take: " << endl;

        this_thread::sleep_for(1s);

        cout << "Enter 1 for adding an entry." << endl;
        cout << "Enter 2 for viewing entries." << endl;
        cout << "Enter 3 for updating an entry." << endl; //Feature to be added
        cout << "Enter 4 for deleting an entry." << endl; //Feature to be added
        cout << "Enter 5 to log out." << endl;
        cin >> actionchoice;

        if (actionchoice == 1)
        {
            this_thread::sleep_for(1s);
            do
            {   
                choice == 'N';
                
                entry.adddata(firstname, middlename, lastname, countrycode, serialno, phone, email, dob, mob, yob, gender);
                
                cout << "Do you want to add an entry(Y/N)?: ";
                cin >> choice;
                
            } while (choice == 'Y');
        }

        if (actionchoice == 2)
        {
            this_thread::sleep_for(1s);

            cout << "Do you want to view a specific entry(Y/N)? If no, all entries will be displayed: ";
            cin >> choice;
            if (choice == 'Y')
            {
                cout << "Enter the serial number of the data entry: ";
                cin >> serialnotofind;
                entry.showentry(serialnotofind);

            }

            else
            {
                entry.showdata();
            }
                
        }

        if (actionchoice == 4)
        {
            cout << "Enter the serial number of the entry you want to delete: ";
            cin >> serialnotodelete;
            entry.deleteentry(serialnotodelete);
        }
         
    } while (actionchoice != 5);

    this_thread::sleep_for(1s);

    cout << "Logging out" << endl;

    this_thread::sleep_for(1s);

    return 0;
}
