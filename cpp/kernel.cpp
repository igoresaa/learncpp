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
        std::cout << "Smile OS 1.0 🙂. Корпорация Евка.\n";
    }
    if (lang == "en")
    {
        std::cout << "Smile OS 1.0 🙂. Ewka Corporation.\n";
    }
    trustUsername();
    // bool isAutorized{false}, hasAccount(false);
    // loginManager(isAutorized, hasAccount);
    // isAutorized = true, hasAccount = true;
    while (true) // обработчик
    {
    lang = langService("check");
        std::cerr << "\nuser::" << getUserName() << "\n> ";
        std::cin >> inp;
        chek(inp, "command");
    }
}
