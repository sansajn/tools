#include "standard_directories.hpp"
#include <algorithm>
#include <unistd.h>  // linux

using std::string;
using std::min;

namespace fs {

namespace standard_directories {

string temp()
{
	return "/tmp";
}

string user_home()
{
	return string{getenv("HOME")};
}

string working()
{
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	return string{cwd};
}

string program_directory()
{
	ssize_t len = 1024;
	char szTmp[32];
	char pBuf[len];
	sprintf(szTmp, "/proc/%d/exe", getpid());
	ssize_t bytes = min(readlink(szTmp, pBuf, len), len - 1);
	if(bytes >= 0)
	  pBuf[bytes] = '\0';

	string result;
	result.assign(pBuf);

	result = result.substr(0, result.find_last_of("/"));  // remove the name of the executable from the end

	return result;
}

}  // standard_Directories

}  // fs
