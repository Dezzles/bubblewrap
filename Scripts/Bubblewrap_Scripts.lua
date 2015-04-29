

loadLibrary = function ( lib )
	genieFile = lib .. "/" .. lib .. "_genie.lua"
	dofile(genieFile)
	table.insert(additionalIncludes, "../" .. lib .. "/include")
end

