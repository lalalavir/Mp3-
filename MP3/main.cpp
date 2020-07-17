#include  "player.h"

int main()
{
	MP3_player player;
	try
	{
		player.run();
	}
	catch (std::exception& message)
	{
		std::cerr << message.what();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}