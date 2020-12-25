#include "zxpch.h"

#include "LayerContainer.h"

#include "Logger.h"

namespace ZeXo
{
    LayerContainer * LayerContainer::s_LayerHandler = nullptr;

    LayerContainer::LayerContainer() : m_LayerIndex(0)
    {
        ZX_ASSERT(!s_LayerHandler, "Another layer handler exists!");
        s_LayerHandler = this;
    }

    void LayerContainer::AddLayer(Layer * layer)
    {
        m_LayerContainer.emplace(begin() + m_LayerIndex, layer);
        ++m_LayerIndex;
        layer->BeginLayer();
    }

    void LayerContainer::AddOverlay(Layer * overlay)
    {
        m_LayerContainer.emplace_back(overlay);
        overlay->BeginLayer();
    }

    void LayerContainer::RemoveLayer(Layer * layer)
    {
        std::vector<Layer*>::iterator it = std::find(begin(), begin() + m_LayerIndex, layer);
        if (it != begin() + m_LayerIndex)
        {
            (*it)->EndLayer();
            m_LayerContainer.erase(it);
            --m_LayerIndex;
        }
    }

    void LayerContainer::RemoveOverlay(Layer * overlay)
    {
        std::vector<Layer*>::iterator it = std::find(begin() + m_LayerIndex, end(), overlay);
        if (it != end())
        {
            (*it)->EndLayer();
            m_LayerContainer.erase(it);
        }
    }

    LayerContainer * LayerContainer::Get()
    {
        s_LayerHandler = new LayerContainer();
        return s_LayerHandler;
    }

}