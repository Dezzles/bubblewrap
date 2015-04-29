-- Literally stolen from Psybrus (with permission)
-- http://github.com/Psybrus/psybrus

-- SDK.lua

-- Add system libraries
function PsyAddSystemLibs()
	configuration "windows-*"
		links {
			-- Windows libs.
			"user32",
			"gdi32",
			"opengl32",
			"winmm",
			"ws2_32",
			"IPHlpApi",
		}

	 configuration "linux-*"
		links {
			-- Linux libs.
			"X11",
			"GL",
			"pthread",
			"bluetooth",
			"SDL2"
		}

end
