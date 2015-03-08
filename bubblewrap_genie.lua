project "Bubblewrap"
	kind "staticlib"
	language "C++"
	files { "include/**.h", "include/**.hpp", "src/**.cpp" }
	location "../../build/bubblewrap/"
	includedirs { 
		"./include", 
		"./External",
		SFML2DIR .. "/include/"
		}
	links { 
		"External_Json"
	}
	configuration "Debug"
		defines { "DEBUG" }
		flags { "Symbols" }

	configuration "Release"
		defines { "NDEBUG" }
		flags { "Optimize" }