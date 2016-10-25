// vlc player with playlist use sample
#include <string>
#include <vector>
#include <thread>
#include <iostream>
#include <cassert>
#include <vlc/vlc.h>

using std::string;
using std::vector;
using std::cout;

int main(int argc, char * argv[])
{
	
	libvlc_instance_t * vlc = libvlc_new(0, nullptr);
	assert(vlc);

	libvlc_media_list_player_t * player = libvlc_media_list_player_new(vlc);
	assert(player);

	// create playlist
	// vector<string> files{"img1.jpg", "img2.jpg", "img3.jpg"};
	vector<string> files{"img1.jpg", "a10.mp4", "a12.mp4", "a18.mp4"};

	libvlc_media_list_t * playlist = libvlc_media_list_new(vlc);
	for (string const & file: files)
	{
		libvlc_media_t * media = libvlc_media_new_path(vlc, file.c_str());
		assert(media && "unable to create a media");
		libvlc_media_list_add_media(playlist, media);
		libvlc_media_release(media);
	}

	libvlc_media_list_player_set_media_list(player, playlist);

	// list playlist files
	int playlist_count = libvlc_media_list_count(playlist);
	for (int i = 0; i < playlist_count; ++i)
	{
		libvlc_media_t * media = libvlc_media_list_item_at_index(playlist, i);

		if (!libvlc_media_is_parsed(media))
			libvlc_media_parse(media);  // parse media

		string title = libvlc_media_get_meta(media, libvlc_meta_Title);
		cout << "#" << i << ". " << title << "\n";
	}

	libvlc_media_list_player_play(player);  // start playing

	std::this_thread::sleep_for(std::chrono::seconds{45});

	// cleanup
	libvlc_media_list_release(playlist);
	libvlc_media_list_player_release(player);
	libvlc_release(vlc);

	return 0;
}

 
