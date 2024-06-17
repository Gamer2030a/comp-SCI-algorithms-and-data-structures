project "BackTracking"
kind "staticLib"
language "C++"
cppdialect "C++20"
staticruntime "off"

targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

   files 
{
  "Include/**.h",
  "Include/**.hpp",
	"Include/**.cpp",
}

includedirs
{
  "%{prj.name}/",
}

defines
{
  "_CRT_SECURE_NO_WARNINGS"
}

  flags { "NoPCH" }  

  filter "system:windows"
  systemversion "latest"

  filter "configurations:Debug"
  defines "_DEBUG"
  runtime "Debug"
  symbols "on"

filter "configurations:Release"
  defines "_RELEASE"
  runtime "Release"
  optimize "on"