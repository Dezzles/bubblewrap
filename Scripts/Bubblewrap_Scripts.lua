

loadLibrary = function ( lib )
	genieFile = "bubblewrap_" .. lib .. "/" .. "bubblewrap_" .. lib .. "_genie.lua"
	dofile(genieFile)
	table.insert(additionalIncludes, "../" .. "bubblewrap_" .. lib .. "/include")
	table.insert(additionalLibraries, lib )
end

