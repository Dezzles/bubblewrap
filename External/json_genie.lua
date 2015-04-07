project "External_Json"
	kind "staticlib"
	language "C++"
	files { "json/*.h", "json/*.cpp" }
	location "../../build/external"

	configuration "Debug"
		defines { "DEBUG" }
		flags { "Symbols" }

	configuration "CrashNBurn"
		defines { "DEBUG" }
		flags { "Symbols" }

	configuration "Release"
		defines { "NDEBUG" }
		flags { "Optimize" }