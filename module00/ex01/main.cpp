#include "General.hpp"
#include "PhoneBook.hpp"

int main()
{   
    std::string input;
    PhoneBook myPhoneBook;

    std::cout << "My Awsome Phone Book is opened!" << std::endl;

    while(1)
    {
        std::cout << "Enter Your Command(Add, Search, or Exit): ";
        std::getline(std::cin, input);
        if(!input.compare("Add"))
            myPhoneBook.add_info();
        else if (!input.compare("Search"))
            myPhoneBook.search_info();
        else if (!input.compare("Exit"))
            break;
        std::cout << std::endl;
    }

    std::cout << "My Awsome Phone Book is closed!" << std::endl;
    return 0;
}