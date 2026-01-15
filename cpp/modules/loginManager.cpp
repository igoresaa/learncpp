#include <iostream>
#include "base.h"
std::string userName{};
std::string password{};
std::string getUserName()
{
    return userName;
}

bool trustUsername()
{
    std::ifstream usernameCache("username.login");
    if (!usernameCache)
    {
        return loginManager(false, false);
    }
    std::getline(usernameCache, userName);
    usernameCache.close();
    std::ifstream passCache("password.login");
    if (!passCache)
    {
        return loginManager(false, false);
    }
    std::getline(passCache, password);
    return loginManager(false, true);
}

bool loginManager(bool isAutorized, bool hasAccount)
{
    if (isAutorized)
    {
        return true;
    }
    if (!isAutorized)
    {
        if (hasAccount)
        {
            std::cout << "Хотите [В]ойти или [З]арегистрироваться? ";
            std::string inp{};
            std::cin >> inp;
            std::string_view ans = chek(inp, "ask-login_1");
            if (ans == "registr")
            {
                std::cout << "Введите логин: ";
                std::cin >> inp;
                userName = inp;
                std::cout << "Введите пароль: ";
                std::cin >> inp;
                password = inp;
                return true;
            }
            if (ans == "login")
            {
                while (true)
                {
                    std::cout << "Введите логин: ";
                    std::cin >> inp;
                    std::cout << "Введите пароль: ";
                    std::string inp2{};
                    std::cin >> inp2;
                    if (userName == inp && password == inp2)
                    {
                        return true;
                    }
                    std::cout << "Неверный логин или пароль. Попробуйте еще раз.\n";
                }
            }
        }
        if (!hasAccount)
        {
            std::string userInput{};
            std::cout << "Введите логин: ";
            std::cin >> userInput;
            userName = userInput;
            std::ofstream createUserCache("username.login");
            createUserCache << userName;
            createUserCache.close();
            std::cout << "Введите пароль: ";
            std::string userInput2{};
            std::cin >> userInput2;
            password = userInput2;
            std::ofstream createPassCache("password.login");
            createPassCache << password;
            createPassCache.close();
            return true;
        }
    }
}