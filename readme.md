**OBSAH**

[TOC]


# rozsahy (range/)

základna podpora pre rozsahy, knižnica obsahuje nasledujúce moduly

**filter** : implementuje podporu pre filtrovanie rozsahou (jednotlivé položky rozsahu nie je možné meniť)

```c++
vector<int> data = vector<int>{{1, 2, 3, 4, 5, 6}};
auto only_even = filtered(data, [](int n){return (n%2) == 0;});
```

**printer** : podpora pre vyzualizáciu rozsahou

```c++
vector<int> data = vector<int>{{1, 2, 3, 4, 5, 6}};
auto only_even = filtered(data, [](int n){return (n%2) == 0;});
cout << "only_even=" << printable(only_even) << "\n";
```

---

# konfigurácia (config/)

podpora pre čítanie konfigurákou, modul obsahuje podporu pre konfiguračné
súbory v JSON formáte a lua skripte.

Napr. prečítať konfiguračný súbor v jazyku lua môžme takto:

```c++
#include "config/lua_config.hpp"

struct app_conf
{
	string python_home;
	string format;
	string bitrate;
	int freq;
	bool verbose;

	void read(string const & fname) 
	{
		lua_config conf{fname};
		python_home = conf.get("python_home");
		format = conf.get("format");
		bitrate = conf.get("bitrate");
		freq = conf.get<int>("freq");
		verbose = conf.get<bool>("verbose");
	}
};

int main(int argc, char * argv[]) 
{
	app_conf conf;
	conf.read("config.lua");
	cout << "bitrate=" << conf.bitrate << "\n";
}
```

konfiguračný súbor `config.lua`

```lua
python_home='python27'
ffmpeg_home='ffmpeg'  -- ffmpeg player binary
format='mp3'
bitrate='192k'
freq=48000
verbose=true
```

---

# signáli (event/)

podpora pre asynchrónne udalosti (signal/slot system)

```c++
void foo()
{
	cout << "foo()" << std::endl;
}

void test_event()
{
	event_handler<> h{foo};
	event<> e;
	e.add(h);
	e.call();
	e.remove(h);
}
```

---

# sqlite3 (sql3/)

modul uľahčujúci prácu s sqlite3 databázou

```c++
#include "sql3/session.hpp"

void test_sql()
{
	dbw::session sql("test.db");

	std::vector<int> one;
	std::vector<double> two;
	std::string tree;

	sql << "select one, two, tree from test where one=" << 1, one, two, tree;
}
```

---

# súborový sytém (fs/)

v podstate boost::filesystem ako fs menný priestor

```c++
#include "fs.hpp"

void test_fs()
{
	cout 
		<< "temp: " << fs::standard_directories::temp() << "\n"
		<< "user home: " << fs::standard_directories::user_home() << "\n"
		<< "current working: " << fs::standard_directories::working() << "\n"
		<< "program directory: " << fs::standard_directories::program_directory() << "\n";
}
```

---

# fake_boost (fake_boost/)

**directory_iterator** : Umožnuje iterovať obsah adresára v posix kompatibilnom
systéme. Iterácia pomocou štandardneho for cykla 

```c++
directory_iterator it{path_to_list}, end_it;
for (; it != end_it; ++it)
	cout << (*it)->d_name << "\n";
```

, alebo pomocou for-loop s c++11

```c++
for (auto entry : directory_iterator{path_to_list})
	cout << entry->d_name << "\n";
```


**boost::filesystem::path** : Implementuje cestu súboru/adresára v súborovom
systéme.

```c++
path p{"/foo/bar.txt"};
// ...
```

, pozri `test_path.cpp` pre ďalšie ukážky použitia.


**boost.filesystem.operations** : Implementované funkcie s modulu operations

```c++
exists()
file_size()
```

Ukážka:

```c++
path p{"foo/bar.txt"};
if (exists(p))
	// do something ...
```

, pozri 'test_operations.cpp' pre ďalšie ukážky použitia.


Author: Adam Hlavatovič, adam.hlavatovic@protonmail.ch
