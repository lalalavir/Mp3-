#include "player.h"

void MP3_player::run()
{
	LoadFolder();
	MainScreen();
	Transit();
}

void MP3_player::MainScreen()
{
	choice = 0;
	system("cls");
	std::wcout << "MP3播放器" << std::endl;
	std::wcout << "1 播放" << std::endl;
	std::wcout << "2 搜索" << std::endl;
	std::wcout << "3 退出" << std::endl;
	std::cin >> choice;
}

void MP3_player::Transit()
{
	if (choice == 1)
		PlayerScreen();
	else if (choice == 2)
		SearchScreen();
	else if (choice == 3)
		return;
	else
	{
		std::cout << "选项错误" << std::endl;
		run();
	}
}

void MP3_player::PlayerScreen()
{
	system("cls");
	for (size_t i = 0; i < music_files.size(); i++)
	{
		std::wcout << i + 1<<" "<<
			music_files[i].c_str() << std::endl; //一定要wcout，要不乱码
	}
	std::cout << "\n请输入歌曲序号" << std::endl;

	std::cin >> music_index;
	LoadMusic(music_index);
	system("cls");
	std::cout << "1 暂停" << std::endl;
	std::cout << "2 下一首" << std::endl;
	std::cout << "3 返回主菜单" << std::endl;

	std::cin >> choice;
	switch (choice)
	{
	case  1:
		Pause();
		break;
	case  2:
		if ((music_index + 1) == music_files.size())
		{
			music_index = 0;
			LoadMusic(music_index);
		}
		else
		{
			music_index++;
			LoadMusic(music_index);
		}
		break;
	case 3:
		run();
		break;
	default:
		std::cout << "输入错误" << std::endl;
		PlayerScreen();
		break;
	}

	
}

void MP3_player::SearchScreen()
{
	system("cls");
	std::cout << "请输入你想要查找的歌曲" << std::endl;
	std::string name;
	std::cin >> name;
	for (size_t i=0;i<music_files.size();i++)
	{
	
	}
}

void MP3_player::LoadFolder()
{
	HANDLE h_find;
	WIN32_FIND_DATA data;
	music_files.clear();
	std::wstring post_fix = L"*.txt";

	std::wstring search_name = music_path + post_fix;

	h_find = FindFirstFile(search_name.c_str(), &data);
	if(h_find!=INVALID_HANDLE_VALUE)
	{
		do
		{
			music_files.emplace_back(data.cFileName);
		}
		while (FindNextFile(h_find,&data));
	}
}

void MP3_player::LoadMusic(int index)
{
	
}

void MP3_player::Continue()
{
	
}

void MP3_player::Pause()
{
}
