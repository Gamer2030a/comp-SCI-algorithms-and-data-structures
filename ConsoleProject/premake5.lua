project "ConsoleProject"
kind "ConsoleApp"
language "C++"
cppdialect "C++20"
staticruntime "off"

targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

files 
{
    "**.h",
    "**.hpp",
    "**.cpp",


    "QuickSort/**.h",
    "QuickSort/**.cpp",
    "StrassenMatrixMultiplication/**.h",
    "StrassenMatrixMultiplication/**.cpp",
    "Prod-RecursiveIntegerMultiplication/**.h",
    "Prod-RecursiveIntegerMultiplication/**.cpp",
    "n-Queen/**.h",
    "n-Queen/**.cpp",
}

includedirs
{
    "%{prj.name}/",

    "QuickSort/",
    "StrassenMatrixMultiplication/",
    "Prod-RecursiveIntegerMultiplication/",
    "n-Queen/",
}

defines
{
    "_CRT_SECURE_NO_WARNINGS"
}

flags { "NoPCH" }

libdirs
{
    "QuickSort",
    "StrassenMatrixMultiplication",
    "Prod-RecursiveIntegerMultiplication",
    "n-Queen",
}

links
{
    "QuickSort",
    "StrassenMatrixMultiplication",
    "Prod-RecursiveIntegerMultiplication",
    "n-Queen",
}

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
