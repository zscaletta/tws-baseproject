workspace "DefaultEngine"
	architecture "x64"
	

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"



project "DefaultEngine"

	location "DefaultEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DE_PLATFORM_WINDOWS",
			"DE_BUILD_DLL"
		}


		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DE_DIST"
		optimize "On"

		
project "Sandbox"

	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"DefaultEngine/vendor/spdlog/include",
		"DefaultEngine/src"
	}

	links
	{
		"DefaultEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DE_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "DE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DE_DIST"
		optimize "On"

