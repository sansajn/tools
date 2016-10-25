// vlc player with playlist use sample
#include <string>
#include <vector>
#include <thread>
#include <cassert>
#include <vlc/vlc.h>
#include "vlc.hpp"

using std::string;
using std::vector;

int main(int argc, char * argv[])
{
	libvlc_instance_t * vlc = libvlc_new(0, nullptr);
	assert(vlc);

	libvlc_media_list_player_t * player = libvlc_media_list_player_new(vlc);
	assert(player);

	// create playlist
	vector<string> files{"a10.mp4", "a12.mp4", "a18.mp4"};

	libvlc_media_list_t * playlist = libvlc_media_list_new(vlc);
	for (string const & file: files)
	{
		vlc::media item{libvlc_media_new_path(vlc, file.c_str())};
		libvlc_media_list_add_media(playlist, item.native());
	}

	libvlc_media_list_player_set_media_list(player, playlist);

	libvlc_media_list_player_play(player);  // start playing

	std::this_thread::sleep_for(std::chrono::seconds{45});

	// cleanup
	libvlc_media_list_release(playlist);
	libvlc_media_list_player_release(player);
	libvlc_release(vlc);

	return 0;
}

