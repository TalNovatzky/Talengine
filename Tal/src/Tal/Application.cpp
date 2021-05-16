#include "talpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Tal/Log.h"

namespace Tal 
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}
	void Application::Run()
	{
		//test of events
		WindowResizeEvent e(1280, 720);
		TAL_CLIENT_TRACE(e);

		while (true);
	}
}

