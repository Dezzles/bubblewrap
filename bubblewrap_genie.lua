project "Bubblewrap"
	kind "staticlib"
	language "C++"
	files { "include/**.h", "include/**.hpp", "src/**.cpp" }
	location "../build/bubblewrap/"
	includedirs { 
		"./include", 
		"./External",
		PHYSFSDIR
		}
	links { 
		"External_Json"
	}
	configuration "CrashNBurn"
		targetdir ( "../build/lib/crashnburn" )
		defines { "DEBUG", "CRASHNBURN" }
		flags { "Symbols" }

	configuration "Debug"
		targetdir ( "../build/lib/debug" )
		defines { "DEBUG" }
		flags { "Symbols" }

	configuration "Release"
		targetdir ( "../build/lib/release" )
		defines { "NDEBUG" }
		flags { "Optimize" }