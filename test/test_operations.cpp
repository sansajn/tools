#include <gtest/gtest.h>
#include "operations.hpp"

namespace fs = boost::filesystem;

TEST(operations_test, exists)
{
	EXPECT_TRUE(fs::exists(fs::path{"/tmp"}));
	EXPECT_FALSE(fs::exists(fs::path{"/tmp/foo/barUISBhsaB.txt"}));
	EXPECT_TRUE(fs::exists(fs::path{"operations.hpp"}));
}

int main(int argc, char * argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
