env = Environment(
	#CXX='clang++', 
	CPPFLAGS=['-std=c++11'], 
	CCFLAGS=['-g', '-O0', '-Wall'],
	LIBS=['gtest', 'pthread'])

lib_objs = env.Object([
	'directory_iterator.cpp',
	'path.cpp',
	'operations.cpp'])

env.Program(['test_directory_iter.cpp', lib_objs])
env.Program(['test_path.cpp', lib_objs])
env.Program(['test_operations.cpp', lib_objs])
