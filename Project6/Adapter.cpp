#include "Adapter.h"

#include <iostream>
using namespace std;

int Adaptermain()
{
	AudioPlayer* audioPlayer = new AudioPlayer();

	audioPlayer->play("mp3", "LongTimeago.mp3");
	audioPlayer->play("vlc", "Beyond.vlc");
	audioPlayer->play("mp4", "Tigger.mp4");
	audioPlayer->play("avi", "Keep me to your heart.avi");
	return 0;
}
