#include <thread>
#include <string>
#include <cassert>
#include <vlc/vlc.h>

char const * default_media_path = "test.mp4";

using std::string;

int main(int argc, char * argv[])
{
	string media_path = (argc > 1 ? argv[1] : default_media_path);

	libvlc_instance_t * vlc = libvlc_new(0, nullptr);
	assert(vlc);
	
	// create a new item
	libvlc_media_t * media = libvlc_media_new_path(vlc, media_path.c_str());
	assert(media);
	
	// create a media player environment
	libvlc_media_player_t * player = libvlc_media_player_new_from_media(media);
	assert(player);
	
	libvlc_media_release(media);  // release media (not needed anymore)
	
	libvlc_media_player_play(player);  // start playing
	
	std::this_thread::sleep_for(std::chrono::seconds{10});
	
	libvlc_media_player_stop(player);  // stop playing
	
	libvlc_media_player_release(player);
	libvlc_release(vlc);

	return 0;
}
