// #include <iostream>
// #include <chrono>
// #include <random>
// #include <limits>

// void ignoreBuffer()
// {
//     if (std::cin.eof())
//     {
//         exit(0);
//     }
//     if (!std::cin)
//     {
//         std::cin.clear();
//     }

//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// }

// void showSettings(int from, int to, int attempts, std::string_view lang)
// {
//     if (lang == "ru")
//     {
//         std::cout << "Настройки игры:\n1. Диапазон загадываемых чисел: от " << from << " до " << to << ".\n2. Количество попыток: " << attempts << ".\n";
//     }
//     if (lang == "en")
//     {
//         std::cout << "Game Settings:\n1. The range of guessed numbers: from " << from << " to " << to << ".\n2. Number of attempts: " << attempts << ".\n";
//     }
// }

// int main(int argc, char const *argv[])
// {
//     if (argc < 2)
//     {
//         std::cout << "Error: Language not set.\n";
//         return 0;
//     }
//     std::string_view lang(argv[1]);
//     std::random_device rd{};
//     std::seed_seq ss{
//         rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(),
//         static_cast<std::seed_seq::result_type>(
//             std::chrono::steady_clock::now().time_since_epoch().count())};
//     std::mt19937 randomValue{ss};

//     int userNumber{};
//     int from{0};
//     int to{100};
//     int attempts{10};
//     while (true)
//     {
//     label0:
//         if (lang == "ru")
//         {
//             std::cout << "Добро пожаловать в игру Угадай число!\nСуть: угадать загаданное число (от 1 до 100) за 10 попыток.\nВы можете сами настроить параметры игры\n";
//         }
//         if (lang == "en")
//         {
//             std::cout << "Welcome to the Guess the Number game!\nThe goal: guess the number (from 1 to 100) in 10 tries.\nYou can customize the game settings yourself.\n";
//         }
//         char userAnswer{};
//         while (true)
//         {
//             if (lang == "ru")
//             {
//                 std::cout << "Настроить параметры игры (y/n)? ";
//             }
//             if (lang == "en")
//             {
//                 std::cout << "Adjust game settings (y/n)?";
//             }
//             std::cin >> userAnswer;
//             ignoreBuffer();
//             if (userAnswer == 'y')
//             {
//                 showSettings(from, to, attempts, lang);
//                 while (true)
//                 {
//                     if (lang == "ru")
//                     {
//                         std::cout << "Выберите опцию для редактирования, s для просмотра текущих настроек или q для выхода: ";
//                     }
//                     if (lang == "en")
//                     {
//                         std::cout << "Select an option to edit, s to view the current settings, or q to exit: ";
//                     }
//                     std::cin >> userAnswer;
//                     if (userAnswer == '1')
//                     {
//                         while (true)
//                         {
//                             if (lang == "ru")
//                             {
//                                 std::cout << "Выберите диапазон загадываемых значений (от - до).\nПример ввода - 0 100: ";
//                             }
//                             if (lang == "en")
//                             {
//                                 std::cout << "Select the range of values to guess (from - to).\nInput example - 0 100: ";
//                             }
//                             std::cin >> from >> to;
//                             if ((from + 2) >= to)
//                             {
//                                 if (lang == "ru")
//                                 {
//                                     std::cout << "Диапазон должен быть больше 1.\n";
//                                 }
//                                 if (lang == "en")
//                                 {
//                                     std::cout << "The range must be greater than 1.\n";
//                                 }
//                             }
//                             else
//                             {
//                                 break;
//                             }
//                             ignoreBuffer();
//                         }
//                     }
//                     else if (userAnswer == '2')
//                     {
//                         while (true)
//                         {
//                             if (lang == "ru")
//                             {
//                                 std::cout << "Выберите количество попыток: ";
//                             }
//                             if (lang == "en")
//                             {
//                                 std::cout << "Select number of attempts: ";
//                             }
//                             std::cin >> attempts;
//                             ignoreBuffer();
//                             if (attempts < 1)
//                             {
//                                 if (lang == "ru")
//                                 {
//                                     std::cout << "Попыток должно быть хотя бы 1.\n";
//                                 }
//                                 if (lang == "en")
//                                 {
//                                     std::cout << "There must be at least 1 attempt.\n";
//                                 }
//                                 continue;
//                             }
//                             break;
//                         }
//                     }
//                     else if (userAnswer == 's')
//                     {
//                         showSettings(from, to, attempts, lang);
//                     }
//                     else if (userAnswer == 'q')
//                     {
//                         break;
//                     }
//                 }

//                 break;
//             }
//             else if (userAnswer == 'n')
//             {
//                 if (lang == "ru")
//                 {
//                     std::cout << "ОК. Игра запущена с стандартными настройками.\n";
//                 }
//                 if (lang == "en")
//                 {
//                     std::cout << "OK. The game is running with default settings.\n";
//                 }
//                 attempts = 10;
//                 break;
//             }
//         }

//         std::uniform_int_distribution diapason{from, to};
//         int number{diapason(randomValue)};
//         if (lang == "ru")
//         {
//             std::cout << "Игра началась!\n";
//         }
//         if (lang == "en")
//         {
//             std::cout << "The game has started!\n";
//         }
//         for (int i = attempts; i > 0; i--)
//         {
//             std::cout << ">>> ";
//             std::cin >> userNumber;

//             ignoreBuffer();
//             if (userNumber > to || userNumber < from)
//             {
//                 if (lang == "ru")
//                 {
//                     std::cout << "Число вылезает за диапазон. Попробуйте еще раз\n";
//                 }
//                 if (lang == "en")
//                 {
//                     std::cout << "The number is out of range. Please try again.\n";
//                 }
//                 i++;
//                 continue;
//             }
//             if (userNumber == number)
//             {
//                 if (lang == "ru")
//                 {
//                     std::cout << "Ты выиграл!\n\nОтладка: загаданное число = " << number << '\n';
//                 }
//                 if (lang == "en")
//                 {
//                     std::cout << "You won!\n";
//                 }
//             label:
//                 if (lang == "ru")
//                 {
//                     std::cout << "Хотите сыграть снова?(y/n) ";
//                 }
//                 if (lang == "en")
//                 {
//                     std::cout << "Want to play again?(y/n) ";
//                 }
//                 char userInput{};
//                 std::cin >> userInput;
//                 ignoreBuffer();
//                 if (userInput == 'y')
//                 {
//                     goto label0;
//                 }
//                 else if (userInput == 'n')
//                 {
//                     exit(0);
//                 }
//                 else
//                 {
//                     if (lang == "ru")
//                     {
//                         std::cout << "Попробуйте еще раз.\n";
//                     }
//                     if (lang == "en")
//                     {
//                         std::cout << "Try again.\n";
//                     }
//                     goto label;
//                 }
//             }
//             else if (number > userNumber)
//             {
//                 if (lang == "ru")
//                 {
//                     std::cout << "Неправильно! Загаданное число больше.\n";
//                 }
//                 if (lang == "en")
//                 {
//                     std::cout << "Incorrect! The number you guessed is higher.\n";
//                 }
//             }
//             else if (number < userNumber)
//             {
//                 if (lang == "ru")
//                 {
//                     std::cout << "Неправильно! Загаданное число меньше.\n";
//                 }
//                 if (lang == "en")
//                 {
//                     std::cout << "Incorrect! The number you guessed is less.\n";
//                 }
//             }
//             if (lang == "ru")
//             {
//                 std::cout << "Осталось попыток: " << i << '\n';
//             }
//             if (lang == "en")
//             {
//                 std::cout << "Attempts left: " << i << '\n';
//             }
//         }
//         if (lang == "ru")
//         {
//             std::cout << "Попытки кончились! Загаданное число было - " << number << '\n';
//         }
//         if (lang == "en")
//         {
//             std::cout << "The attempts are over! The hidden number was - " << number << '\n';
//         }
//     label2:
//         if (lang == "ru")
//         {
//             std::cout << "Хотите сыграть снова?(y/n) ";
//         }
//         if (lang == "en")
//         {
//             std::cout << "Want to play again?(y/n) ";
//         }
//         char userInput{};
//         std::cin >> userInput;
//         ignoreBuffer();
//         if (userInput == 'y')
//         {
//             goto label0;
//         }
//         else if (userInput == 'n')
//         {
//             exit(0);
//         }
//         else
//         {
//             if (lang == "ru")
//             {
//                 std::cout << "Попробуйте еще раз.\n";
//             }
//             if (lang == "en")
//             {
//                 std::cout << "Try again.\n";
//             }
//             goto label2;
//         }
//     }
//     return 0;
// }
