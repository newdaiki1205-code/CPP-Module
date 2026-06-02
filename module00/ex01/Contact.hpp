#ifndef CONTACT_H
# define CONTACT_H

#include "General.hpp"

class Contact
{
    private:
       std::string FirstName;
       std::string LastName;
       std::string NickName;
       std::string PhoneNum;
       std::string DarkestSecret;

    public:
        void setFirstName(std::string fn);
        void setLastName(std::string ln);
        void setNickName(std::string nick);
        void setPhoneNum(std::string pn);
        void setDarkerSecret(std::string ds);
        std::string getFirstname();
        std::string getLastname();
        std::string getNickname();
        std::string getPhoneNum();
        std::string getDarkestSec();

        Contact(){}
        ~Contact(){}
};

#endif