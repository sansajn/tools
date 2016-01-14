env = Environment(
	#CXX='clang++',
	CPPFLAGS=['-std=c++11'], 
	CCFLAGS=['-g', '-O0', '-Wall'],
	LIBS=['gtest', 'pthread'],
	CPPPATH=['boost/filesystem'])

fs_objs = env.Object([
	Glob('boost/filesystem/*.cpp')])

lib_objs = []

env.Program(['test/test_directory_iter.cpp', fs_objs])
env.Program(['test/test_path.cpp', fs_objs])
env.Program(['test/test_operations.cpp', fs_objs])
