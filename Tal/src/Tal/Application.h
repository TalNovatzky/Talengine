#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Tal 
{
	class TAL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//TO BE defined in client
	Application* CreateApplication();

}


