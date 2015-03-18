additionalIncludes = ""
additionalLibraries = ""


loadLibrary = function ( lib )
	genieFile = lib .. "/" .. lib .. "_genie.lua"
	dofile(genieFile)
	additionalIncludes = additionalIncludes .. ", " .. lib .. "/include"
	additionalLibraries = additionalLibraries .. ", " .. lib
end

