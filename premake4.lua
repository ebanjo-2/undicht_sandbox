solution "undicht_sandbox"

    language "C++"
    buildoptions "-std=c++11"
    configurations { "debug - windows","debug - linux", "release - windows", "release - linux" }


    dofile "undicht_0.37_engine/premake4_include_engine.lua"


    project "sandbox"

        kind "ConsoleApp"
        files { "src/**.*" }
		includedirs { "src", "../undicht/core/include","../undicht/engine/src", "../undicht/vendor", "../undicht/vendor/glm" }
		links { "core", "engine" }
		
		configuration "debug - linux"
			links { "dl" }
			
		configuration "release - linux"
			links { "dl" }

    

			

        
