#pragma once
#include <string>

namespace fs {

namespace standard_directories {

std::string temp();
std::string user_home();
std::string working();  //!< pwd
std::string program_directory();

}  // standard_directories

}  // fs
