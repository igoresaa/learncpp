#ifndef BASE_H
#define BASE_H
#include <iostream>
std::string_view chek(std::string_view str, std::string_view r);
std::string_view getLang();
bool loginManager(bool isAutorized, bool hasAccount);
std::string getUserName();
#endif