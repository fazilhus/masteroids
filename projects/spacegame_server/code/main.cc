#include "config.h"

#include "sa_server.h"

int main(int argc, char** argv) {
	Game::SA_Server app{};
	if (app.Open()) {
		app.Run();
		app.Close();
	}
	app.Exit();
}