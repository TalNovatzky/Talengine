workspace "Tal"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Tal"
	location "Tal"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" ..outputdir .. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir .. "/%{prj.name}")

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
			"TAL_PLATFORM_WINDOWS",
			"TAL_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}


	filter "configurations:Debug"
		defines "TAL_DEBUG"
		symbols "On"


	filter "configurations:Release"
		defines "TAL_RELEASE"
		optimize "On"


	filter "configurations:Dist"
		defines "TAL_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" ..outputdir .. "/%{prj.name}")	
	objdir ("bin-int/" ..outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}	

	includedirs
	{
		"Tal/vendor/spdlog/include",
		"Tal/src"
	}

	links
	{
		"Tal"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TAL_PLATFORM_WINDOWS",
		}


	filter "configurations:Debug"
		defines "TAL_DEBUG"
		symbols "On"


	filter "configurations:Release"
		defines "TAL_RELEASE"
		optimize "On"


	filter "configurations:Dist"
		defines "TAL_DIST"
		optimize "On"