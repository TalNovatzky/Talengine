#pragma once

#ifdef TAL_PLATFORM_WINDOWS

extern Tal::Application* Tal::CreateApplication();

int main(int argc, char** argv)
{
	Tal::Log::Init();
	TAL_CORE_INFO("Core log initialized");
	TAL_CLIENT_INFO("Client log initialized");

	auto app = Tal::CreateApplication();
	app->Run();
	delete app;
}

#endif // TAL_PLATFORM_WINDOWS

