require "ninja"

workspace "HelloWorld"
    configurations { "Debug", "Release" }
    location "build"

project "software_3d_engine"
    kind "StaticLib"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"

    files { "src/software_3d_engine/**.hpp", "src/software_3d_engine/**.cpp" }
    includedirs { "vendor/microsoft/GSL/include" }
    buildoptions { "-std=gnu++2a" }

project "sandbox"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"

    files { "src/sandbox/**.hpp", "src/sandbox/**.cpp" }
    includedirs { "vendor/microsoft/GSL/include", "src/software_3d_engine" }
    buildoptions { "-std=gnu++2a" }
    links { "software_3d_engine", "SDL2" }
