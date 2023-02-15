#ifndef _ASMD_H_
#define _ASMD_H_
#include <string>

class login
{
    public:

        bool checklogindata(std::string inputusername, std::string inputpassword, std::string username, std::string password);
};
class dataentry
{
    public:
        void addentry(std::string firstname, std::string middlename, std::string lastname, int countrycode, long long int serialno, long long int phone, std::string email, int dob, std::string mob, int yob, std::string gender);

        void showdata();

        void showentry(long long int serialno);

        void updateentry(std::string firstname, std::string middlename, std::string lastname, int countrycode, long long int serialno, long long int phone, std::string email, int dob, std::string mob, int yob, std::string gender);

        void deleteentry(long long int serialno);
};

#endif