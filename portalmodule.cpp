#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex> // required for generating custom patterns for string validation
#include "portal.h"
using namespace std;

// function manages the login process
bool login::checklogindata(string inputusername, string inputpassword, string username, string password)
{
    // stores the data taken from username.txt and password.txt in username and password string
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

    // initializes the value of valid to 0 or false
    bool valid = 0;
    
    cout << "Please enter your username: ";
    cin >> inputusername;
    cout << "Please enter your password: ";
    cin >> inputpassword;

    // valid is set to 1 or true if the input username and password match the values in the username and password string
    if ((inputusername == username) && (inputpassword == password))
    {
        cout << "Login successful." << endl;
        valid = 1;

    }
    // valid remains at 0 or false if the input username and password do not match the values in the username and password string
    else if ((inputusername != username) or (inputpassword != password))
    {
        cout << "Invalid username or password." << endl;
        valid = 0;

    }

    //value of valid is returned
    return valid;

}    

//function adds an entry into the csv file
void dataentry::addentry(string firstname, string middlename, string lastname, int countrycode, long long int personid, long long int phone, string email, int dob, string mob, int yob, string gender)
{
    // user I.D. is automatically generated
    string line;
    ifstream inputfile ("database.csv");
    int lineNumber = 1;

    if (inputfile.is_open()) {
        // lineNumber is incremented as long as data is stored in 'line'
        while (getline(inputfile,line)) {
            lineNumber++;
        }
        inputfile.close();
        // the value of lineNumber is stored in personid
        personid = lineNumber;
        // Ensure that the user I.D. is always one greater than the previous user I.D.
        personid++;
    }

    else 
    {
        cout << "Unable to open database." << endl;
        exit(0);
    }

        cout << "Enter first name: ";
        cin >> firstname;
        regex firstName("[A-Za-z]+");
        while (!regex_match(firstname, firstName)) 
        {
            cin.clear(); // clear error flags
            cin.ignore(100, '\n'); // ignore remaining characters in buffer
            cout << "Invalid first name input. Please enter a valid first name: ";
            cin >> firstname;
        }
        
        cout << "Enter middle name: ";
        cin >> middlename;
        regex middleName("[A-Za-z]+");
        while (!regex_match(middlename, middleName) && (middlename != "-"))
        {
            cin.clear(); // clear error flags
            cin.ignore(100, '\n'); // ignore remaining characters in buffer
            cout << "Invalid middle name input. Please enter a valid middle name: ";
            cin >> middlename;
        }

        cout << "Enter last name: ";
        cin >> lastname;
        regex lastName("[A-Za-z]+");
        while (!regex_match(lastname, lastName)) {
            cin.clear(); // clear error flags
            cin.ignore(100, '\n'); // ignore remaining characters in buffer
            cout << "Invalid last name input. Please enter a valid last name: ";
            cin >> lastname;
        }

        cout << "Enter phone number (without country code): ";
        cin >> phone;
        while ((phone <= 0) || cin.fail())
        {
            cin.clear(); // clear error flags
            cin.ignore(100, '\n'); // ignore remaining characters in buffer
            cout << "Please enter a valid phone number: ";
            cin >> phone;
        }
        
        cout << "Enter country code (Eg: 1, 44, etc.): ";
        cin >> countrycode;
        while ((countrycode <= 0) || cin.fail())
        {
            cin.clear(); // clear error flags
            cin.ignore(100, '\n'); // ignore remaining characters in buffer
            cout << "Please enter a valid country code (omit the '+' sign): ";
            cin >> countrycode;
        }

        cout << "Enter E-mail I.D.: ";
        cin >> email;
        // check if input format is valid
        regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
        while (!regex_match(email, pattern)) {
            cin.clear(); // clear error flags
            cin.ignore(100, '\n'); // ignore remaining characters in buffer
            cout << "Invalid email input. Please enter a valid email address: ";
            cin >> email;
        }

        cout << "Enter date of birth (Eg: 21, 15, etc.): ";
        cin >> dob;
        // check if input is valid
        while (cin.fail() || dob < 1 || dob > 31) {
            cin.clear(); // clear error flags
            cin.ignore(100, '\n'); // ignore remaining characters in buffer
            cout << "Invalid date input. Please enter a value between 1 and 31: ";
            cin >> dob;

        }

        cout << "Enter month of birth (Eg: January, September, etc.): ";
        cin >> mob;
        while ((mob != "January") and (mob != "February") and (mob != "March") and (mob != "April") and (mob != "May") and (mob != "June") and (mob != "July") and (mob != "August") and (mob != "September") and (mob != "October") and (mob != "November") and (mob != "December") or cin.fail())
        {
            cin.clear(); // clear error flags
            cin.ignore(100, '\n'); // ignore remaining characters in buffer
            cout << "Invalid month input. Please enter a valid month: ";
            cin >> mob;
        }
        while ((dob > 30) and ((mob == "April") or (mob == "June") or (mob == "September") or (mob == "November")))
        {
            cout << "The month of " << mob << " has only 30 days. Please enter the correct date: ";
            cin >> dob;
        }
        while ((dob > 31) and ((mob == "January") or (mob == "March") or (mob == "May") or (mob == "July") or (mob == "August") or (mob == "October") or (mob == "December")))
        {
            cout << "The month of " << mob << " has only 31 days. Please enter the correct date: ";
            cin >> dob;
        }
        
        cout << "Enter year of birth (Eg: 1987, 2006, etc.): ";
        cin >> yob;
        while ((yob < 1850) or (yob > 2023))
        {
            cin.clear(); // clear error flags
            cin.ignore(100, '\n'); // ignore remaining characters in buffer
            cout << "Invalid year input. Please enter a value between 1850 and 2023: ";
            cin >> yob;
        }
        while ((dob > 28) and (mob == "February") and (yob % 4 != 0))
        {
            cout << "February " << yob << " has only 28 days. Please enter a valid date: ";
            cin >> dob;
        }
        while ((dob > 29) and (mob == "February") and (yob % 4 == 0))
        {
            cout << "February " << yob << " has only 29 days. Please enter a valid date: ";
            cin >> dob;
        }

        cout << "Enter gender (Eg: Male, Female, etc.): ";
        cin >> gender;
        regex Gender("[A-Za-z]+");
        while (!regex_match(firstname, Gender)) {
            cin.clear(); // clear error flags
            cin.ignore(100, '\n'); // ignore remaining characters in buffer
            cout << "Please enter a valid gender: ";
            cin >> gender;
        }

        ofstream outfile;
        outfile.open("database.csv", ios::app);

        //the values stored in the variables are entered in the csv file.
        outfile << personid << "," << firstname << "," << middlename << "," << lastname << "," << countrycode << "," << phone << "," << email << "," << dob << "," << mob << "," << yob << "," << gender << endl;

        outfile.close();

}

// function displays all the data in the csv file
void dataentry::showdata()
{
    string line;
    ifstream inFile("database.csv");
    cout << endl;
    cout << "Output displayed in the order: user I.D., First Name, Middle Name, Last Name, Country Code, Phone Number, Email, Date of Birth, Month of Birth, Year of Birth, Gender" << endl;
    cout << endl;
    if (inFile.is_open())
    {
        // every line from the csv file is stored in the 'line' string, which is then displayed
        while (getline (inFile,line))
        {
            cout << line << endl;
        }
        inFile.close();
    }
    cout << endl;

}

// function displays a single data entry based on the person I.D.
void dataentry::showentry(long long int personid)
{
    string line;
    vector<string> lines;
    ifstream INFile("database.csv");
    int lineNumber = 0;

    if (INFile.is_open()) {
        while (getline(INFile, line)) {
            lineNumber++;
            stringstream ss(line);
            string field;
            getline(ss, field, ',');
            if (stoll(field) == personid) {
                cout << endl;
                cout << line << endl;
                cout << endl;
            }
        }
        INFile.close();

    }
    else 
    {
        cout << "Unable to open file" << endl;
    }
}

// function updates a data entry based on the person I.D.
void dataentry::updateentry(string firstname, string middlename, string lastname, int countrycode, long long int personid, long long int phone, string email, int dob, string mob, int yob, string gender)
{
    string line;
    vector<string> lines;
    ifstream INFILE("database.csv");
    int lineNumber = 0;
    bool personFound = false;

    if (INFILE.is_open()) {
        while (getline(INFILE, line)) {
            lineNumber++;
            stringstream ss(line);
            string field;
            getline(ss, field, ',');
            if (stoll(field) == personid)
            {
                personFound = true;
                // formats the updated data and adds it to a vector of strings called lines
                stringstream updatedData;

                // user enters new data. the same logic as addentry() is followed
                cout << "Enter first name: ";
                cin >> firstname;
                regex firstName("[A-Za-z]+");
                while (!regex_match(firstname, firstName)) 
                {
                    cin.clear(); // clear error flags
                    cin.ignore(100, '\n'); // ignore remaining characters in buffer
                    cout << "Invalid first name input. Please enter a valid first name: ";
                    cin >> firstname;
                }
                
                cout << "Enter middle name: ";
                cin >> middlename;
                regex middleName("[A-Za-z]+");
                while (!regex_match(middlename, middleName) && (middlename != "-"))
                {
                    cin.clear(); // clear error flags
                    cin.ignore(100, '\n'); // ignore remaining characters in buffer
                    cout << "Invalid middle name input. Please enter a valid middle name: ";
                    cin >> middlename;
                }

                cout << "Enter last name: ";
                cin >> lastname;
                regex lastName("[A-Za-z]+");
                while (!regex_match(lastname, lastName)) {
                    cin.clear(); // clear error flags
                    cin.ignore(100, '\n'); // ignore remaining characters in buffer
                    cout << "Invalid last name input. Please enter a valid last name: ";
                    cin >> lastname;
                }

                cout << "Enter phone number (without country code): ";
                cin >> phone;
                while ((phone <= 0) || cin.fail())
                {
                    cin.clear(); // clear error flags
                    cin.ignore(100, '\n'); // ignore remaining characters in buffer
                    cout << "Please enter a valid phone number: ";
                    cin >> phone;
                }
                
                cout << "Enter country code (Eg: 1, 44, etc.): ";
                cin >> countrycode;
                while ((countrycode <= 0) || cin.fail())
                {
                    cin.clear(); // clear error flags
                    cin.ignore(100, '\n'); // ignore remaining characters in buffer
                    cout << "Please enter a valid country code (omit the '+' sign): ";
                    cin >> countrycode;
                }

                cout << "Enter E-mail I.D.: ";
                cin >> email;
                // check if input format is valid
                regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
                while (!regex_match(email, pattern)) {
                    cin.clear(); // clear error flags
                    cin.ignore(100, '\n'); // ignore remaining characters in buffer
                    cout << "Invalid email input. Please enter a valid email address: ";
                    cin >> email;
                }

                cout << "Enter date of birth (Eg: 21, 15, etc.): ";
                cin >> dob;
                // check if input is valid
                while (cin.fail() || dob < 1 || dob > 31) {
                    cin.clear(); // clear error flags
                    cin.ignore(100, '\n'); // ignore remaining characters in buffer
                    cout << "Invalid date input. Please enter a value between 1 and 31: ";
                    cin >> dob;

                }

                cout << "Enter month of birth (Eg: January, September, etc.): ";
                cin >> mob;
                while ((mob != "January") and (mob != "February") and (mob != "March") and (mob != "April") and (mob != "May") and (mob != "June") and (mob != "July") and (mob != "August") and (mob != "September") and (mob != "October") and (mob != "November") and (mob != "December") or cin.fail())
                {
                    cin.clear(); // clear error flags
                    cin.ignore(100, '\n'); // ignore remaining characters in buffer
                    cout << "Invalid month input. Please enter a valid month: ";
                    cin >> mob;
                }
                while ((dob > 30) and ((mob == "April") or (mob == "June") or (mob == "September") or (mob == "November")))
                {
                    cout << "The month of " << mob << " has only 30 days. Please enter the correct date: ";
                    cin >> dob;
                }
                while ((dob > 31) and ((mob == "January") or (mob == "March") or (mob == "May") or (mob == "July") or (mob == "August") or (mob == "October") or (mob == "December")))
                {
                    cout << "The month of " << mob << " has only 31 days. Please enter the correct date: ";
                    cin >> dob;
                }
                
                cout << "Enter year of birth (Eg: 1987, 2006, etc.): ";
                cin >> yob;
                while ((yob < 1850) or (yob > 2023))
                {
                    cin.clear(); // clear error flags
                    cin.ignore(100, '\n'); // ignore remaining characters in buffer
                    cout << "Invalid year input. Please enter a value between 1850 and 2023: ";
                    cin >> yob;
                }
                while ((dob > 28) and (mob == "February") and (yob % 4 != 0))
                {
                    cout << "February " << yob << " has only 28 days. Please enter a valid date: ";
                    cin >> dob;
                }
                while ((dob > 29) and (mob == "February") and (yob % 4 == 0))
                {
                    cout << "February " << yob << " has only 29 days. Please enter a valid date: ";
                    cin >> dob;
                }

                cout << "Enter gender (Eg: Male, Female, etc.): ";
                cin >> gender;
                regex Gender("[A-Za-z]+");
                while (!regex_match(firstname, Gender)) {
                    cin.clear(); // clear error flags
                    cin.ignore(100, '\n'); // ignore remaining characters in buffer
                    cout << "Please enter a valid gender: ";
                    cin >> gender;
                }

                updatedData << personid << "," << firstname << "," << middlename << "," << lastname << "," << countrycode << "," << phone << "," << email << "," << dob << "," << mob << "," << yob << "," << gender << "\n";
                lines.push_back(updatedData.str());
            }
            else
            {
                // If the record is not found, the original line from the file is added to the lines vector.
                lines.push_back(line + "\n");
            }
        }
        INFILE.close();

        if (!personFound)
        {
            cout << "Person with ID " << personid << " not found." << endl;
            return;
        }

        ofstream OUTFILE("database.csv");
        for (int i = 0; i < lines.size(); i++)
        {
            OUTFILE << lines[i];
        }
        OUTFILE.close();

        cout << "Entry updated successfully." << endl;
    }
    else 
    {
        cout << "Unable to open file." << endl;
    }
}

// function deletes an entry based on the person I.D.
void dataentry::deleteentry(long long int personid)
{
    string line;
    vector<string> lines;
    ifstream InFILE("database.csv");
    int lineNumber = 0;

    if (InFILE.is_open()) {
        while (getline(InFILE, line)) {
            lineNumber++; // increments lineNumber in every iteration
            stringstream ss(line); // separates each field by a comma
            string field;
            getline(ss, field, ',');
            if (stoll(field) != personid) {
                lines.push_back(line); // the data in 'line' is added to 'lines' if the personid and stoll(field) are not equal
            }
        }
        InFILE.close();

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

