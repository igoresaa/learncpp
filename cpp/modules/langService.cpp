#include <base.h>
std::string langService(std::string_view r)
{
    std::ifstream file("LangConfig.conf");
    if (r == "check")
    {
        std::ifstream file("LangConfig.conf");
        std::string line{};
        if (std::getline(file, line))
        {
            return line;
        }

        std::cout << "Welcome to smile OS 1.0!\nEnter a launguage:\n"
                  << "1). English\n"
                  << "2). Русский (Russian)\n";
        std::string inp{};
        std::string lang{};
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

        createConfig(lang, "LangConfig.conf");
        return lang;
    }
    else if (r == "change")
    {
        std::cout << "Enter a language:\n"
                  << "1). English\n"
                  << "2). Русский\n";
        std::string inp{};
        std::string newLang{};
        while (true)
        {
            std::cout << "> ";
            std::cin >> inp;
            newLang = chek(inp, "lang");
            if (newLang == "en")
            {
                std::cout << "English\n";
                break;
            }
            else if (newLang == "ru")
            {
                std::cout << "Выбран русский язык\n";
                break;
            }
        }
        createConfig(newLang, "LangConfig.conf");
        return newLang;
    }
}