#include <Tal.h>

class SandboxApp : public Tal::Application
{
public:
	SandboxApp() 
	{
	}
	~SandboxApp() 
	{
	}
};

Tal::Application* Tal::CreateApplication() 
{
	return new SandboxApp();
}