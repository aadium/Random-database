#ifndef _PORTAL_H_
#define _PORTAL_H_
#include <string>

class login
{
    public:
        bool checklogindata(std::string inputusername, std::string inputpassword, std::string username, std::string password);
};
class dataentry
{
    public:
        void addentry(std::string firstname, std::string middlename, std::string lastname, int countrycode, long long int personid, long long int phone, std::string email, int dob, std::string mob, int yob, std::string gender);

        void showdata();

        void showentry(long long int personid);

        void updateentry(std::string firstname, std::string middlename, std::string lastname, int countrycode, long long int personid, long long int phone, std::string email, int dob, std::string mob, int yob, std::string gender);

        void deleteentry(long long int personid);
};

#endif