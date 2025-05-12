#pragma once
//------------------------------------------------------------------------------
/**
	Space game application

	(C) 20222 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "core/app.h"
#include "core/net.h"
#include "render/window.h"

namespace Game
{
class SpaceGameApp : public Core::App
{
public:
	/// constructor
	SpaceGameApp();
	/// destructor
	~SpaceGameApp() override;

	/// open app
	bool Open() override;
	void Close() override;
	/// run app
	void Run() override;
	/// exit app
	void Exit() override;
private:

	/// show some ui things
	void RenderUI();

	Display::Window* window;

	Protocol::Client client;
	ENetAddress address;
	ENetPeer* peer;
};
} // namespace Game