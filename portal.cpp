#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class login
{

    public:

        bool checklogindata(string inputusername, string inputpassword, string username, string password)
        {
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

            bool valid = 0;
            if ((inputusername == username) && (inputpassword == password))
            {
                cout << "Login successful." << endl;
                valid = 1;

            }
            
            else if ((inputusername != username) or (inputpassword != password))
            {
                cout << "Invalid username or password." << endl;
                valid = 0;

            }

            return valid;

        }    

};

class dataentry
{

    public:

        void addentry(string firstname, string middlename, string lastname, int countrycode, long long int serialno, long long int phone, string email, int dob, string mob, int yob, string gender)
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
                exit(0);
            }
            cout << "Enter first name: ";
            cin >> firstname;
            cout << "Enter middle name (Optional, Enter '-' to skip field): ";
            cin >> middlename;
            cout << "Enter last name: ";
            cin >> lastname;
            cout << "Enter phone number (without country code): ";
            cin >> phone;
            cout << "Enter country code (Eg: 1, 44, etc.): ";
            cin >> countrycode;
            cout << "Enter E-mail I.D.: ";
            cin >> email;
            cout << "Enter date of birth (Eg: 21, 15, etc.): ";
            cin >> dob;
            if ((dob < 1) or (dob > 31))
            {
                cout << "Invalid date input. Cancelling operation." << endl;
                exit(0);
            }

            cout << "Enter month of birth (Eg: January, September, etc.): ";
            cin >> mob;
            if ((mob != "January") and (mob != "February") and (mob != "March") and (mob != "April ") and (mob != "May") and (mob != "June") and (mob != "July") and (mob != "August") and (mob != "September") and (mob != "October") and (mob != "November") and (mob != "December"))
            {
                cout << "Invalid month input. Cancelling operation." << endl;
                exit(0);
            }

            cout << "Enter year of birth (Eg: 1987, 2006, etc.): ";
            cin >> yob;
            cout << "Enter gender (Eg: Male, Female, etc.): ";
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

        void showentry(long long int serialno)
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

        void updateentry(string firstname, string middlename, string lastname, int countrycode, long long int serialno, long long int phone, string email, int dob, string mob, int yob, string gender)
        {
            string line;
            vector<string> lines;
            ifstream inputfile("database.csv");
            int lineNumber = 0;

            if (inputfile.is_open())
            {
                while (getline(inputfile, line))
                {
                    lineNumber++;
                    if (lineNumber == serialno)
                    {
                        cout << "Enter first name: ";
                        cin >> firstname;
                        cout << "Enter middle name (Optional, Enter '-' to skip field): ";
                        cin >> middlename;
                        cout << "Enter last name: ";
                        cin >> lastname;
                        cout << "Enter phone number (without country code): ";
                        cin >> phone;
                        cout << "Enter country code (Eg: 1, 44, etc.): ";
                        cin >> countrycode;
                        cout << "Enter E-mail I.D.: ";
                        cin >> email;
                        cout << "Enter date of birth (Eg: 21, 15, etc.): ";
                        cin >> dob;
                        if ((dob < 1) or (dob > 31))
                        {
                            cout << "Invalid date input. Cancelling operation." << endl;
                            exit(0);
                        }

                        cout << "Enter month of birth (Eg: January, September, etc.): ";
                        cin >> mob;
                        if ((mob != "January") and (mob != "February") and (mob != "March") and (mob != "April ") and (mob != "May") and (mob != "June") and (mob != "July") and (mob != "August") and (mob != "September") and (mob != "October") and (mob != "November") and (mob != "December"))
                        {
                            cout << "Invalid month input. Cancelling operation." << endl;
                            exit(0);
                        }

                        cout << "Enter year of birth (Eg: 1987, 2006, etc.): ";
                        cin >> yob;
                        cout << "Enter gender (Eg: Male, Female, etc.): ";
                        cin >> gender;

                        line = to_string(serialno) + "," + firstname + "," + middlename + "," + lastname + "," + to_string(countrycode) + "," + to_string(phone) + "," + email + "," + to_string(dob) + "," + mob + "," + to_string(yob) + "," + gender;
                    }
                    lines.push_back(line);
                }
                inputfile.close();

                ofstream outputfile("database.csv");
                for (string l : lines)
                {
                    outputfile << l << endl;
                }
                outputfile.close();

                cout << "Record updated successfully." << endl;
            }
            else
            {
                cout << "Unable to open database." << endl;
            }
        }

        void deleteentry(long long int serialno)
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
    long long int serialnotoupdate{};
    int countrycode{};
    int dob{};
    int yob{};
    int actionchoice{};
    char choice{};
    bool valid = false;

    cout << "Welcome to UAP Datasystems. Unlock the Power of Data with Our Cutting-Edge Database Solutions." << endl;

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

    

    do
    {   actionchoice == 5;

        cout << "Please enter a number depending on the action you wish to take: " << endl;
        cout << "Enter 1 for adding an entry." << endl;
        cout << "Enter 2 for viewing entries." << endl;
        cout << "Enter 3 for updating an entry." << endl;
        cout << "Enter 4 for deleting an entry." << endl;
        cout << "Enter 5 to log out." << endl;
        cin >> actionchoice;

        if (actionchoice == 1) // add entries
        {
            
            do
            {   
                choice == 'N';
                
                entry.addentry(firstname, middlename, lastname, countrycode, serialno, phone, email, dob, mob, yob, gender);

                cout << "Entry has been added." << endl;

                cout << "Do you want to add another entry(Y/N)?: ";
                cin >> choice;
                
            } while (choice == 'Y');
        }

        if (actionchoice == 2) // view entries
        {
            

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

        if (actionchoice == 3) // update entry
        {
            cout << "Enter the serial number fo the data entry you want to update: ";
            cin >> serialnotoupdate;
            entry.updateentry(firstname, middlename, lastname, countrycode, serialnotoupdate, phone, email, dob, mob, yob, gender);

        }
        

        if (actionchoice == 4) // delete entry
        {
            cout << "Enter the serial number of the entry you want to delete: ";
            cin >> serialnotodelete;
            entry.deleteentry(serialnotodelete);

        }
         
    } while (actionchoice != 5);

    cout << "Logging out" << endl;

    return 0;
}