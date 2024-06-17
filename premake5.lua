require('vstudio')

workspace "comp-SCI-algorithms and data structures"
  architecture "x64"
  startproject "ConsoleProject"

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

  group "Console Project"
  include "ConsoleProject"

  group "algorithm Libraries"
  include "QuickSort"
  include "StrassenMatrixMultiplication" 
  include "Prod-RecursiveIntegerMultiplication"
  include "n-Queen"
  include "BackTracking"


group "structure Libraries"

group ""