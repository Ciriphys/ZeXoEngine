#include <ZeXo.h>

class SandboxLayer : public ZeXo::Layer
{
public:
	SandboxLayer(const char* layerName) : ZeXo::Layer(layerName) {}

	virtual void Event(ZeXo::Event& e) override {
		ZeXo::EventDispatcher dispatcher(e);

		dispatcher.Emit<ZeXo::KeyPressed>(ZX_BIND_FUNCTION(&SandboxLayer::OnKeyPress, this));
		dispatcher.Emit<ZeXo::KeyReleased>(ZX_BIND_FUNCTION(&SandboxLayer::OnKeyRelease, this));
	}
	virtual void BeginLayer() override {}
	virtual void EndLayer() override {}
	virtual void Tick(double deltaTime) override {
		ZX_CLIENT_LOGGER_TRACE("{0} layer deltaTime: {1}", GetLayerName(), deltaTime);
	}


private:
	bool OnKeyPress(ZeXo::KeyPressed& e) {
		ZX_CLIENT_LOGGER_INFO("{0} layer handles the Key Pressed Event", GetLayerName());
		return true;
	}

	bool OnKeyRelease(ZeXo::KeyReleased& e) {
		ZX_CLIENT_LOGGER_INFO("{0} layer handles the Key Released Event", GetLayerName());
		return true;
	}
};

class Overlay : public ZeXo::Layer
{
public:
	Overlay(const char* layerName) : ZeXo::Layer(layerName) {}

	virtual void Event(ZeXo::Event& e) override {
		ZeXo::EventDispatcher dispatcher(e);

		dispatcher.Emit<ZeXo::KeyPressed>(ZX_BIND_FUNCTION(&Overlay::OnKeyPress, this));
	}
	virtual void BeginLayer() override {}
	virtual void EndLayer() override {}
	virtual void Tick(double deltaTime) override {
		ZX_CLIENT_LOGGER_TRACE("{0} layer deltaTime: {1}", GetLayerName(), deltaTime);
	}

private:
	bool OnKeyPress(ZeXo::KeyPressed& e) {
		ZX_CLIENT_LOGGER_INFO("{0} layer handles the Key Pressed Event", GetLayerName());
		return true;
	}
};

class SandboxApplication : public ZeXo::Application
{
public:
	 SandboxApplication(const char * appName = "ZeXo Client") : ZeXo::Application(appName)
	 {
		AddLayer(new SandboxLayer("Sandbox"));
		AddOverlay(new Overlay("Overlay"));
	 }
	~SandboxApplication() {}

};

ZeXo::Application * CreateZeXoApplication()
{	
	return new SandboxApplication();
}