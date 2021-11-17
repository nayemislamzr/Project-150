#include "Observer.h"

#include "Application.h"

Observer::Observer()
{
	m_Application = Application::get();
}
