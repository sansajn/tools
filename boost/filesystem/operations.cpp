#include "operations.hpp"

// posix
#include <sys/stat.h>

namespace boost { namespace filesystem {

bool exists(path const & p)
{
	struct stat buf;
	return stat(p.c_str(), &buf) == 0;
}

}}  // boost::filesystem
