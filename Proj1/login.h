#ifndef ASF_LOGIN_H
#define ASF_LOGIN_H

#include <string>
#include <iostream>
#include <fstream>

namespace ASF
{
    class Login
    {
    public:
        // Constructors
        Login() = default;
        Login(std::string username, std::string password);
        ~Login() = default;
        Login(const Login& other) = default;

        // Operators
        Login& operator=(const Login& other) = default;
        bool operator==(const Login& other) const;
        friend std::ostream& operator<< (std::ostream& os, const Login& login);
        friend const std::istream& operator>> (const std::istream& is, const Login& login);

        // Member functions
        bool isSameUser(const Login& other) const;
        void exportLogin(const std::string filename) const;
        void exportLogin(std::ofstream file) const;

    private:
        std::string username;
        std::string password;

        class LoginException : public std::exception {};
        class FileOperationFailure : public LoginException {};
        class UserNotExist : public LoginException {};
        class PasswordTooWeak : public LoginException {};
    };

    //bool isUserInDB(const std::string username, const std::string filename);
    //bool isUserInDB(const std::string username, std::ofstream file);
}



#endif