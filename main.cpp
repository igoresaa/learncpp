#include <iostream>
#include <chrono>
#include <random>
#include <limits>

void ignoreBuffer() {
    if (std::cin.eof()) {
        exit(0);
    }
    if (!std::cin) {
        std::cin.clear();
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void showSettings(int from, int to, int attempts) {
    std::cout << "Настройки игры:\n1. Диапазон загадываемых чисел: от " << from << " до " << to << ".\n2. Количество попыток: " << attempts << ".\n";
}

int main() {
    std::random_device rd{};
    std::seed_seq ss{
        rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(),
        static_cast<std::seed_seq::result_type>(
            std::chrono::steady_clock::now().time_since_epoch().count()
        )
    };
    std::mt19937 randomValue{ss};


    int userNumber{};
    int from{0};
    int to{100};
    int attempts{10};
    while (true) {
        label0:
        std::cout << "Добро пожаловать в игру Угадай число!\nСуть: угадать загаданное число (от " << from << " до " << to << ") за " << attempts << " попыток.\nВы можете сами настроить параметры игры\n";
        char userAnswer{};
        while (true) {
            std::cout << "Настроить параметры игры (y/n)? ";
            std::cin >> userAnswer;
            ignoreBuffer();
            if (userAnswer == 'y') {
                showSettings(from, to, attempts);
                while (true) {
                    std::cout << "Выберите опцию для редактирования, s для просмотра текущих настроек или q для выхода: ";
                    std::cin >> userAnswer;
		    ignoreBuffer();
                    if (userAnswer == '1') {
                        while (true) {
                            std::cout << "Выберите диапазон загадываемых значений (от - до).\nПример ввода - 0 100: ";
                            std::cin >> from >> to;
			    ignoreBuffer();
                            if ((from + 2) >= to) {
                                std::cout << "Диапазон должен быть больше 1.\n";
                            }
                            else {
                                break;
                            }
                            ignoreBuffer();
                        }
                        

                    }
                    else if (userAnswer == '2') {
                        while (true) {
                            std::cout << "Выберите количество попыток: ";
                            std::cin >> attempts;
                            ignoreBuffer();
                            if (attempts < 1) {
                                std::cout << "Попыток должно быть хотя бы 1.\n";
                                continue;
                            }
                            break;
                        }
                        
                    }
                    else if (userAnswer == 's') {
                        showSettings(from, to, attempts);
                    }
                    else if (userAnswer == 'q') {
                        break;
                    }
                }
                
                break;
            }
            else if (userAnswer == 'n') {
                std::cout << "ОК. Игра запущена с текущими настройками.\n";
                break;
            }
        }

        std::uniform_int_distribution diapason{from, to};
        int number{diapason(randomValue)};
        std::cout << "Игра началась!\n";
        for (int i = attempts; i > 0; i--) {
            std::cout << ">>> ";
            std::cin >> userNumber;
            
            ignoreBuffer();
            if (userNumber > to || userNumber < from) {
                std::cout << "Число не в диапазоне. Попробуйте еще раз\n";
                i++;
                continue;
            }
            if (userNumber == number) {
                std::cout << "Ты выиграл!\n";
                label:
                    std::cout << "Хотите сыграть снова?(y/n) ";
                    char userInput{};
                    std::cin >> userInput;
                    ignoreBuffer();
                    if (userInput == 'y') {
                        goto label0;
                    }
                    else if (userInput == 'n') {
                        exit(0);
                    }
                    else {
                        std::cout << "Попробуйте еще раз.\n";
                        goto label;
                    }
            }
            else if (number > userNumber) {
                std::cout << "Неправильно! Загаданное число больше.\n";
            }
            else if (number < userNumber) {
                std::cout << "Неправильно! Загаданное число меньше.\n";
            }
            std::cout << "Осталось попыток: " << i - 1 << '\n';
        }
        std::cout << "Попытки кончились! Загаданное число было - " << number << '\n';
        label2:
            std::cout << "Хотите сыграть снова?(y/n) ";
            char userInput{};
            std::cin >> userInput;
            ignoreBuffer();
            if (userInput == 'y') {
                goto label0;
            }
            else if (userInput == 'n') {
                exit(0);
            }
            else {
                std::cout << "Попробуйте еще раз.\n";
                goto label2;
            }

    }
    return 0;
}
