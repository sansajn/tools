#include <gtest/gtest.h>
#include "path.hpp"

using std::string;

using namespace boost::filesystem;

TEST(path_test, creation)
{
	path p{"/tmp/foo.txt"};
	path r;
	string pathname = "/tmp/foo.txt";
	path s{pathname};
	path t{pathname.begin(), pathname.end()};
	path u{p};
	path v{path{"foo.txt"}};
}

TEST(path_test, clear)
{
	path p{"/tmp"};
	EXPECT_FALSE(p.empty());
	p.clear();
	EXPECT_TRUE(p.empty());
}

TEST(path_test, native)
{
	path p{"/tmp/"};
	EXPECT_EQ(p.native(), "/tmp/");
}

TEST(path_test, compare)
{
	path p{"/tmp/"};
	path r{"/tmp/"};
	EXPECT_TRUE(p == r);
	path s{"/tmp"};
	EXPECT_FALSE(p == s);
}

TEST(path_test, remove_filename)
{
	path p{"/tmp/store/foo.txt"};
	EXPECT_EQ(path{"/tmp/store"}, p.remove_filename());
	EXPECT_EQ(path{"/tmp"}, p.remove_filename());
	EXPECT_EQ(path{}, p.remove_filename());

	path r{".."};
	EXPECT_EQ(path{}, r.remove_filename());
}

TEST(path_test, replace_extension)
{
	path p{"/tmp/teresa.jpg"};
	p.replace_extension(path{"tiff"});
	EXPECT_EQ(p, path{"/tmp/teresa.tiff"});

	path r{"/tmp/teresa"};
	r.replace_extension(path{"png"});
	EXPECT_EQ(r, path{"/tmp/teresa.png"});
}

TEST(path_test, parent_path)
{
	EXPECT_EQ(path{"/foo"}, path{"/foo/bar.txt"}.parent_path());
	EXPECT_EQ(path{"/foo"}, path{"/foo/bar"}.parent_path());
	EXPECT_EQ(path{"/foo/bar"}, path{"/foo/bar/"}.parent_path());
	EXPECT_EQ(path{}, path{"/"}.parent_path());
	EXPECT_EQ(path{}, path{"."}.parent_path());
	EXPECT_EQ(path{}, path{".."}.parent_path());
	EXPECT_EQ(path{}, path{"foo.txt"}.parent_path());  //! TODO: tento pripad nieje v dokumentacii
}

TEST(path_test, root_directory)
{
	EXPECT_EQ(path{"/"}, path{"/foo/bar"}.root_directory());
	EXPECT_EQ(path{}, path{"foo/bar"}.root_directory());
	EXPECT_EQ(path{"/"}, path{"/"}.root_directory());
	EXPECT_EQ(path{}, path{"."}.root_directory());
	EXPECT_EQ(path{}, path{".."}.root_directory());
}

TEST(path_test, filename)
{
	EXPECT_EQ(path{"bar.txt"}, path{"/foo/bar.txt"}.filename());
	EXPECT_EQ(path{"bar"}, path{"/foo/bar"}.filename());
	EXPECT_EQ(path{"."}, path{"/foo/bar/"}.filename());
	EXPECT_EQ(path{"/"}, path{"/"}.filename());
	EXPECT_EQ(path{"."}, path{"."}.filename());
	EXPECT_EQ(path{".."}, path{".."}.filename());
}

TEST(path_test, extension)
{
	EXPECT_EQ(path{".jpg"}, path{"/tmp/teresa.jpg"}.extension());
	EXPECT_EQ(path{}, path{"/tmp/teresa"}.extension());
}

TEST(path_test, has_root_directory)
{
	EXPECT_TRUE(path{"/home/"}.has_root_directory());
	EXPECT_FALSE(path{"bar.txt"}.has_root_directory());
	EXPECT_TRUE(path{"/"}.has_root_directory());
	EXPECT_FALSE(path{"."}.has_root_directory());
	EXPECT_FALSE(path{".."}.has_root_directory());
}

TEST(path_test, append_operator)
{
	EXPECT_EQ(path{"/foo/bar.txt"}, path{"/foo"} / path{"bar.txt"});
}


int main(int argc, char * argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
