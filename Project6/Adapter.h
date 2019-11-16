#pragma once
#include<string>
#include<iostream>

using namespace std;
class MediaPlayer
{
public:
	virtual void play(string audioType, string filename) = 0;
};
class AdvancedMediaPlayer
{
public:
	virtual void playVlc(string filename) = 0;
	virtual void playMp4(string filename) = 0;
};

class VlcPlayer :public AdvancedMediaPlayer
{

public:
	void playVlc(string filename)
	{
		cout << "playing vlc file. Name : " + filename << endl;
	}
	void playMp4(string filename)
	{
		
	}
};

class Mp4Player :public AdvancedMediaPlayer
{

public:
	virtual void playMp4(string filename)
	{
		cout << "playing mp4 file. Name : " + filename << endl;
	}

	void playVlc(string filename)
	{
	}
};

class MediaAdapter : public MediaPlayer
{
private:
	AdvancedMediaPlayer* advancedMusicPlayer;
public:
	MediaAdapter(string audioType)
	{
		if (audioType == "vlc")
		{
			advancedMusicPlayer = new VlcPlayer();
		}
		else if (audioType == "mp4")
		{
			advancedMusicPlayer = new Mp4Player();
		}
	}
	void play(string audioType, string filename)
	{
		if (audioType == "vlc")
		{
			advancedMusicPlayer->playVlc(filename);
		}
		else if (audioType == "mp4")
		{
			advancedMusicPlayer->playMp4(filename);
		}
	}
};

class AudioPlayer :public MediaPlayer
{
private:
	MediaAdapter* mediaAdapter;
public:
	void play(string audioType, string filename)
	{
		if (audioType == "mp3")
		{
			cout << "Playing mp3 file. Name: " + filename << endl;
		}
		else if (audioType == "vlc" || audioType == "mp4")
		{
			mediaAdapter = new MediaAdapter(audioType);
			mediaAdapter->play(audioType, filename);
		}
		else
		{
			cout << "Invalid media " + audioType + "format not supported" << endl;
		}
	}
};

