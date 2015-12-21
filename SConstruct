env = Environment(CXX='clang++', CPPFLAGS=['-std=c++11'], CCFLAGS=['-g', '-Wall'])
lib_objs = env.Object(['directory_iterator.cpp'])
env.Program(['test_directory_iter.cpp',lib_objs])
