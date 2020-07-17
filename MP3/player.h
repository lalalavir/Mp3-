#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>

class MP3_player
{
public:
	void run();
private:
	void MainScreen();
	void Transit();
	uint16_t choice = 0;
	uint16_t music_index = 0;
	void PlayerScreen();
	void SearchScreen();

	void LoadFolder();
	void LoadMusic(int index);

	void Continue();
	void Pause();
	
	std::wstring music_path = L"D:\\vulkan\\music\\";
	std::vector<std::wstring> music_files;
};

