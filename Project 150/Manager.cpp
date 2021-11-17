#include "Manager.h"

#include "Application.h"
#include "Observer.h"
#include "BrushObserver.h"

using namespace olc;

Manager::Manager()
{
    m_Application = Application::get();
    m_BrushObserver = new BrushObserver();
}

void Manager::attach(Observer* observer)
{
    m_ActiveObserver = observer;
}

void Manager::detach()
{
    m_ActiveObserver = nullptr;
}

void Manager::update()
{
    if (m_Application->GetKey(olc::B).bPressed)
    {
        m_ActiveObserver = m_BrushObserver;
    }
    else if (m_Application->GetKey(olc::Z).bPressed)
    {

    }
    else if (m_Application->GetKey(olc::S).bPressed)
    {

    }
    else if (m_Application->GetKey(olc::E).bPressed)
    {

    }
    else if (m_Application->GetKey(olc::P).bPressed)
    {
        scenePlay = !scenePlay;
    }
    else
    {

    }
}

void Manager::notify()
{
    if (m_ActiveObserver != nullptr)
        m_ActiveObserver->update();
    if (scenePlay)
        TileMap::play();
    else TileMap::pause();
}
