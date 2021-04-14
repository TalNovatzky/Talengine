#pragma once

#ifdef TAL_PLATFORM_WINDOWS

extern Tal::Application* Tal::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Tal::CreateApplication();
	app->Run();
	delete app;
}

#endif // TAL_PLATFORM_WINDOWS

