#include "base.h"

void createConfig(std::string_view str, std::string filename)
{
    std::ofstream file(filename);
    if (!file)
    {
        // std::cout << "cannot open file :^(" << '\n';
        return;
    }
    file << str;
}