if PsyProjectExternalLib( "json", "C++" ) then
	configuration "*"
		kind ( EXTERNAL_PROJECT_KIND )
		includedirs {
			"json",
		}
	files { "json/*.h", "json/*.cpp" }
end