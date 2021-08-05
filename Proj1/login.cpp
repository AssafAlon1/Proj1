#include "login.h"
#include "auxiliaries.h"

using std::endl;

namespace ASF
{


    Login::Login(std::string username, std::string password) : username(username), password(password) {}

    bool Login::isSameUser(const Login& other) const
    {
        return username == other.username;
    }


    bool Login::operator==(const Login& other) const
    {
        if (!this->isSameUser(other))
        {
            return false;
        }

        //TODO: SECURE IT UP
        return password == other.password;
    }

    std::ostream& operator<< (std::ostream& os, const Login& login)
    {
        os << "Username: " << login.username << endl;

        //TODO: SECURE IT UP
        os << "Password: " << login.password << endl;
        return os;
    }

    const std::istream& operator>> (const std::istream& is, const Login& login)
    {
        is >> login.username >> login.password;
        return is;
    }


    void Login::exportLogin(const std::string filename) const
    {
        if(!isFileExist(filename))
        {
            throw FileOperationFailure();
        }
        
        std::ofstream write_file(filename);
        write_file << "User:" << username << endl;

        //TODO: SECURE IT UP
        write_file << "Pass:" << password << endl;

        write_file.close();
    }
    
    void Login::exportLogin(std::ofstream file) const
    {
        file << "User:" << username << endl;

        //TODO: SECURE IT UP
        file << "Pass:" << password << endl;
    }

}

