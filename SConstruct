common_env = Environment(
	CXXFLAGS=['-std=c++14', '-O0', '-g', '-Wall'],
	CPPPATH=['.']
)

# filesystem
fs_env = Environment(
	#CXX='clang++',
	CXXFLAGS=['-std=c++11'],
	CCFLAGS=['-g', '-O0', '-Wall'],
	LIBS=['gtest', 'pthread'],
	CPPPATH=['.', 'boost/filesystem'])

fs_objs = fs_env.Object([
	Glob('boost/filesystem/*.cpp')])

lib_objs = []

#fs_env.Program(['test/test_directory_iter.cpp', fs_objs])
#fs_env.Program(['test/test_path.cpp', fs_objs])
#fs_env.Program(['test/test_operations.cpp', fs_objs])


# config
conf_env = common_env.Clone()

# keyval config
conf_env.Program(['config/test/keyval_app_config.cpp', 'config/keyval_config.cpp'])

# json config
json_conf_env = conf_env.Clone()
json_conf_env.Append(
	LIBS=['boost_system', 'boost_thread'],
	CPPDEFINES=['BOOST_SPIRIT_THREADSAFE']  # for thread safe property_tree
)

json_conf_env.Program([
	'config/test/json_app_config.cpp',
	'config/json_config.cpp',
	'config/string_algo.cpp'
])

# lua config
lua_conf_env = conf_env.Clone()
lua_conf_env.ParseConfig('pkg-config --cflags --libs lua52')

lua_conf_env.Program([
	'config/test/lua_app_config.cpp',
	'config/lua_config.cpp',
	'config/script_engine.cpp',
	'config/error_output.cpp'
])
