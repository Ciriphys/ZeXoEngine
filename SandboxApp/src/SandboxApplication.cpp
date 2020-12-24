#include <ZeXo.h>

class SandboxApplication : public ZeXo::Application
{
public:
	 SandboxApplication(const char * appName = "ZeXo Client") : ZeXo::Application(appName) {}
	~SandboxApplication() {}

};

ZeXo::Application * CreateZeXoApplication()
{	
	return new SandboxApplication();
}