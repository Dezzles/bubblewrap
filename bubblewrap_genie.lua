PsyProjectEngineLib( "base" )
	files 
	{ 
		"include/**.h", 
		"include/**.hpp", 
		"src/**.cpp" 
	}
	includedirs { 
		"./include",
		"./External",
		}
   PsyAddExternalLinks {
      "physfs",
      "json",
   }
