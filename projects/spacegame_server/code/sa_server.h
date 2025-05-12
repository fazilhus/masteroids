#pragma once

#include "core/app.h"
#include "core/net.h"

namespace Game {

	class SA_Server : public Core::App {
	public:
		/// constructor
		SA_Server();
		/// destructor
		~SA_Server() override;

		/// open app
		bool Open() override;
		/// close app
		void Close() override;
		/// run app
		void Run() override;
		/// exit app
		void Exit() override;

	private:
		Protocol::Host host;
	};

} // namespace Game