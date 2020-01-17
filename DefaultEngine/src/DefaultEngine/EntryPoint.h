#pragma once


#ifdef DE_PLATFORM_WINDOWS

extern DefaultEngine::Application* DefaultEngine::CreateApplication();

int main(int argc, char** argv)
{
	DefaultEngine::Log::Init();
	DE_CORE_WARN("Initialized Log!");
	int a = 5;
	DE_INFO("Hello! Var={0}", a);

	auto app = DefaultEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif