#pragma once

#include "Core.h"

namespace DefaultEngine {

	class DefaultEngine_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}