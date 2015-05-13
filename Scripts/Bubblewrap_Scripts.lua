

loadLibrary = function ( lib )
	genieFile = "bubblewrap_" .. lib .. "/" .. "bubblewrap_" .. lib .. "_genie.lua"
	dofile(genieFile)
	table.insert(additionalIncludes, "../" .. "bubblewrap_" .. lib .. "/include")
	table.insert(additionalLibraries, lib )
end

loadLibraries = function ( _libraries )
	for i, name in ipairs( _libraries ) do
		table.insert( additionalDefines, string.upper("bubblewrap_" .. name ) )
		links { "External_" .. name }
	end
	for i, name in ipairs( _libraries ) do
		loadLibrary( name )
	end
end