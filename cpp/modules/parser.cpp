#include <iostream>
#include <cstdlib>
#include "base.h"
std::string_view chek(std::string_view str, std::string_view r) // r - режим парсера. От режима парсера, задаваемого при вызове функции, зависит, как парсер
                                                                // обработает запрос
{
    std::string lang{getLang()};
    if (r == "command")
    {
        if (str == "help")
        {
            std::string cmd{"./bin/help " + lang};
            std::system(cmd.c_str());
        }
        else if (str == "myLang")
        {
            std::cout << lang << '\n';
        }
        else if (str == "guesTheNumber")
        {
            std::string cmd{"./bin/games/guesTheNumber " + lang};
            std::system(cmd.c_str());
        }
        else if (str == "whoami")
        {
            std::cout << getUserName() << '\n';
        }
        else if (str == "changeLang")
        {
            langService("change");
        }
        else
        {
            if (lang == "en")
            {
                std::cout << "Command not found!\n";
            }
            if (lang == "ru")
            {
                std::cout << '\n' << "Команда не найдена!\n";
            }
        }
    }
    else if (r == "lang")
    {
        if (str == "1")
        {
            return "en";
        }
        else if (str == "2")
        {
            return "ru";
        }
        else
        {
            std::cout << "Try again\n";
        }
    }
    else if (r == "ask-login_1")
    {
        if (str == "В")
        {
            return "login";
        }
        if (str == "З")
        {
            return "registr";
        }
    }
    return "invalid r";
}