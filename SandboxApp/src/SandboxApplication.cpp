#include <ZeXo.h>

class SandboxApplication : public ZeXo::Application
{
public:
	 SandboxApplication() {}
	~SandboxApplication() {}

};

ZeXo::Application * CreateZeXoApplication()
{	
	return new SandboxApplication();
}