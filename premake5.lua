workspace "FinalExam_GP1_MI_PD_FiorentinoGabriele"
    architecture "x86_64"
    configurations {"Debug", "Release"}
    includedirs {"%{wks.location}/ThirdParty/include"}
    libdirs {"%{wks.location}/ThirdParty/libs"}
    startproject "FrameWork"

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"

    project "FrameWork"
        kind "SharedLib"
        language "C++"
        cppdialect "C++17"
        location "%{wks.location}/FrameWork"

        --includes all files in source folder
        includedirs {"%{wks.location}/FrameWork/src"}

        postbuildcommands "{COPY} %{wks.location}/ThirdParty/libs/*.dll %{wks.location}/bin/%{cfg.buildcfg}-%{cfg.architecture}"

        files {
            "%{prj.location}/src/**.h",
            "%{prj.location}/src/**.cpp"
        }

        links {
            "sfml-system.lib",
            "sfml-main.lib",
            "sfml-window.lib",
            "sfml-graphics.lib",
            "sfml-audio.lib"
        }

    postbuildcommands "{COPY} %{wks.location}/ThirdParty/libs/*.dll %{wks.location}/bin/%{cfg.buildcfg}-%{cfg.architecture}"


workspace "FinalExam_GP1_MI_PD_FiorentinoGabriele"
    architecture "x86_64"
    configurations {"Debug", "Release"}
    includedirs {"%{wks.location}/ThirdParty/include"}
    libdirs {"%{wks.location}/ThirdParty/libs"}
    startproject "Sandbox"

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"

    project "Sandbox"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"
        location "%{wks.location}/Sandbox"

        --includes all files in source folder
        includedirs {"%{wks.location}/Sandbox/src"}

        postbuildcommands "{COPY} %{wks.location}/ThirdParty/libs/*.dll %{wks.location}/bin/%{cfg.buildcfg}-%{cfg.architecture}"

        files {
            "%{prj.location}/src/**.h",
            "%{prj.location}/src/**.cpp"
        }

        links {
            "sfml-system.lib",
            "sfml-main.lib",
            "sfml-window.lib",
            "sfml-graphics.lib",
            "sfml-audio.lib"
        }

    postbuildcommands "{COPY} %{wks.location}/ThirdParty/libs/*.dll %{wks.location}/bin/%{cfg.buildcfg}-%{cfg.architecture}"