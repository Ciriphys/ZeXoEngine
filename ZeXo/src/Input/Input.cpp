#include "zxpch.h"

#include "Input.h"

#include "Core/Macro.h"
#include "Core/Logger.h"
#include "Core/Application.h"

#include <GLFW/glfw3.h>

namespace ZeXo
{
    Input * Input::s_InputHandler = nullptr;

    Input::Input() 
    {
        ZX_ASSERT(!s_InputHandler, "Another input handler exists!");
        s_InputHandler = this;
    }

    bool Input::GetKey(int key)
    {
        GLFWwindow * nativeWindow = reinterpret_cast<Window*>(Application::Get()->GetWindowRaw())->glfwGetWindow();
        int keyState = glfwGetKey(nativeWindow, key);
        return keyState == GLFW_PRESS || keyState == GLFW_REPEAT;
    }

    bool Input::GetKeyPress(int key)
    {
        GLFWwindow* nativeWindow = reinterpret_cast<Window*>(Application::Get()->GetWindowRaw())->glfwGetWindow();
        int keyState = glfwGetKey(nativeWindow, key);
        return keyState == GLFW_PRESS;
    }

    bool Input::GetKeyRelease(int key)
    {
        GLFWwindow* nativeWindow = reinterpret_cast<Window*>(Application::Get()->GetWindowRaw())->glfwGetWindow();
        int keyState = glfwGetKey(nativeWindow, key);
        return keyState == GLFW_RELEASE;
    }

    Input * Input::Get()
    {
        s_InputHandler = new Input();
        return s_InputHandler;
    }

    bool Input::GetMouseButtonPress(int button)
    {
        GLFWwindow* nativeWindow = reinterpret_cast<Window*>(Application::Get()->GetWindowRaw())->glfwGetWindow();
        int btnState = glfwGetMouseButton(nativeWindow, button);
        return btnState == GLFW_PRESS;
    }

    bool Input::GetMouseButtonRelease(int button)
    {
        GLFWwindow* nativeWindow = reinterpret_cast<Window*>(Application::Get()->GetWindowRaw())->glfwGetWindow();
        int btnState = glfwGetMouseButton(nativeWindow, button);
        return btnState == GLFW_RELEASE;
    }

    int Input::GetKeyScancode(int key) const
    {
       return glfwGetKeyScancode(key);
    }

    const char* Input::GetKeyName(int key)
    {
        const char * keyName = glfwGetKeyName(key, GetKeyScancode(key));
        return keyName ? keyName : "Unknown";
    }
}