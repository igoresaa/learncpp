#include <iostream>
#include "base.h"

std::string_view lang{};

std::string_view getLang()
{
    return lang;
}

int main()
{
    std::cout << "Welcome to smile OS 1.0!\nEnter a launguage:\n"
              << "1). English\n"
              << "2). Русский (Russian)\n";
    std::string inp{};
    while (true)
    {
        std::cout << "> ";
        std::cin >> inp;
        lang = chek(inp, "lang");
        if (lang == "en")
        {
            std::cout << "English\n";
            break;
        }
        else if (lang == "ru")
        {
            std::cout << "Выбран русский язык\n";
            break;
        }
    }
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
        std::cerr << "user::" << getUserName() << "\n> ";
        std::cin >> inp;
        chek(inp, "command");
    }
}
