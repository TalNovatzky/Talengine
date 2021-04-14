#pragma once
#include "Core.h"

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


