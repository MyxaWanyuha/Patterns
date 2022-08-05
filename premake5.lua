workspace "Patterns"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
	}
	flags
	{
		"MultiProcessorCompile"
	}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Command"
	language "C++"
	cppdialect "C++17"
	kind "ConsoleApp"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
	}

	includedirs
	{
		"%{prj.name}"
	}

	filter "system:windows"
		systemversion "latest"

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Relase"
		runtime "Release"
		optimize "on"
		
	filter "configurations:Dist"
		runtime "Release"
		optimize "on"


project "Flyweight"
	language "C++"
	cppdialect "C++17"
	kind "ConsoleApp"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
	}

	includedirs
	{
		"%{prj.name}"
	}

	filter "system:windows"
		systemversion "latest"

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Relase"
		runtime "Release"
		optimize "on"
		
	filter "configurations:Dist"
		runtime "Release"
		optimize "on"
