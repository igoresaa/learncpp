// #include "base.h"

// // bool trustUsername()
// // {
// //     std::ifstream usernameCache("username.login");
// //     std::string username{};
// //     if (!usernameCache)
// //     {
// //         return loginManager(false, false);
// //     }
// //     std::getline(usernameCache, username);
// //     usernameCache.close();
// //     std::ifstream passCache("password.login");
// //     std::string pass{};
// //     if (!passCache)
// //     {
// //         return loginManager(false, false);
// //     }
// //     std::getline(passCache, pass);
// //     return loginManager(true, false);
// // }