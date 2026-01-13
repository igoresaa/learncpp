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

    if (!std::filesystem::exists(filename)) {
        if (argc >= 3) {
            std::string_view expectedCreate{argv[2]};
            if (expectedCreate == "-create") {
                std::ofstream file(filename);
                if (file) {
                    std::cout << "Файл успешно записан.\n";
                }
                if (!(argc >= 4)) {
		    file.close();
                    return 0;
                }
                std::cout << "Ожидаем еше один параметр.\n";
            }
            else {
                std::cout << "Странный параметр. Если хотите создать файл, используйте -create.\n";
                return 0;
            }

        }
        else {
            std::cout << "Подобного файла не существует.\n";
            return 1;
        }
        std::cout << "Ожидаем еше один параметр.\n";
    }

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
                std::string line{};
                std::ifstream file{filename};
                if (std::getline(file, line)) {
                    writeFile << '\n';
                }
                writeFile << userLine;
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
