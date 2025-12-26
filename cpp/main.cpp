#include <iostream>
#include <fstream>
#include <limits>
#include <filesystem>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Использование: " << argv[0] << " <имя файла> <параметр> <строка>\n";
        return 0;
    }

    std::string filename{argv[1]};
    if (argc >= 3) {
        std::string parametr{argv[2]}; 
        if (parametr == "-reset") {
            std::ofstream offile(filename);
            std::cout << "Файл перезаписан.\n";
            offile.close();
            return 0;
        }

        if (parametr == "-write") {
            if (argc >= 4) {
                std::string userLine{argv[3]};
                std::ofstream writeFile{filename, std::ios::app};
                writeFile << '\n' << userLine;
                std::cout << "Строка { " << userLine << " } записана.\n";
                writeFile.close();
                return 0;
            }
            else {
                std::cout << "Не указана строка для записи!\n";
                return 1;
            }

        }
    }


    if (!std::filesystem::exists(filename)) {
        std::cout << "Подобного файла не существует.\n";
        return 1;
    }


    std::ifstream file(filename);
    if (!file) {
        std::cout << "Не удалось прочитать!\n";
        return 1;
    }
    std::string line{};
    while (std::getline(file, line)) {
        std::cout << line << '\n';
    }
    file.close();
    return 0;
}