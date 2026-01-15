#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <fstream>
std::string_view chek(std::string_view str, std::string_view r);
std::string getLang();
bool loginManager(bool isAutorized, bool hasAccount);
std::string getUserName();
void createConfig(std::string_view str, std::string filename);
std::string langService(std::string_view r);
bool trustUsername();
#endif