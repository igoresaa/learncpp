#include <iostream>
#include "base.h"

std::string lang{};

std::string getLang()
{
    return lang;
}

int main()
{
    lang = langService("check");
    std::string inp{};
    if (lang == "ru")
    {
        std::cout << "Для получения справки введите help.\n";
    }
    if (lang == "en")
    {
        std::cout << "For help, enter help.\n";
    }
    bool isAutorized{false}, hasAccount(false);
    loginManager(isAutorized, hasAccount);
    isAutorized = true, hasAccount = true;
    while (true) // обработчик
    {
    lang = langService("check");
        std::cerr << "user::" << getUserName() << "\n> ";
        std::cin >> inp;
        chek(inp, "command");
    }
}
