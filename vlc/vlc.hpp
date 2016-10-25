#pragma once
#include <string>
#include <cassert>
#include <vlc/vlc.h>

namespace vlc {

class media
{
public:
	media() : _media{nullptr} {}
	media(libvlc_media_t * ptr) : _media{ptr} {assert(ptr);}
	~media() {libvlc_media_release(_media);}

	void from_new_path(libvlc_instance_t * vlc, std::string const & path)
	{
		_media = libvlc_media_new_path(vlc, path.c_str());
		assert(_media);
	}

	libvlc_media_t * native() const {return _media;}

	media(media const &) = delete;
	media & operator=(media const &) = delete;

private:
	libvlc_media_t * _media;
};

};
