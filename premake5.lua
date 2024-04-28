require('vstudio')

workspace "comp-SCI-algorithms and data structures"
  architecture "x64"
  startproject "QuickSort"

    configurations
  {
  "Debug",
  "Release"
  }

  flags
	{
		"MultiProcessorCompile"
	}
  
  outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

  group "algorithms"
  include "QuickSort"
  include "StrassenMatrixMultiplication"
group ""

group "structures"

group ""