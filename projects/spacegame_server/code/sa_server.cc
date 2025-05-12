#include "config.h"

#include "sa_server.h"

#include <cstdio>

#include <enet/enet.h>

namespace Game {

	SA_Server::SA_Server() {
		host.addr.host = 0;
		host.addr.port = 0;
	}

	SA_Server::~SA_Server() {
	}

	bool SA_Server::Open() {
		if (enet_initialize() != 0) {
			fprintf_s(stderr, "[ERROR] Could not init ENet\n");
			return false;
		}

		printf_s("Hello, ENet\n");

		host.addr.host = ENET_HOST_ANY;
		host.addr.port = 6969;

		host.server = enet_host_create(&host.addr, 32, 2, 0, 0);
		if (host.server == nullptr) {
			fprintf_s(stderr, "[ERROR] ENet could not create host\n");
			return false;
		}

		printf_s("Created host on port %u\n", host.addr.port);

		return true;
	}

	void SA_Server::Close() {
	}

	void SA_Server::Run() {
		ENetEvent e;
		for (int i = 0; i < 1000; ++i) {
			while (enet_host_service(host.server, &e, 16) > 0) {
				switch (e.type) {
				case ENET_EVENT_TYPE_CONNECT:
					printf_s("New connection from %x:%u\n", e.peer->address.host, e.peer->address.port);
					break;
				case ENET_EVENT_TYPE_DISCONNECT:
					printf_s("Disconnected\n");
					break;
				case ENET_EVENT_TYPE_RECEIVE:
					enet_packet_destroy(e.packet);
					break;
				}
			}
		}
	}

	void SA_Server::Exit() {
		if (host.server != nullptr) {
			enet_host_destroy(host.server);
		}
		enet_deinitialize();
	}

} // namespace Game
