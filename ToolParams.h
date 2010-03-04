//
//	ToolParams.h
//	ToolParams
//
//	Created by Uli Kusterer on Wed Sep 05 2001.
//	Copyright 2001 Uli Kusterer.
//	
//	This software is provided 'as-is', without any express or implied
//	warranty. In no event will the authors be held liable for any damages
//	arising from the use of this software.
//
//	Permission is granted to anyone to use this software for any purpose,
//	including commercial applications, and to alter it and redistribute it
//	freely, subject to the following restrictions:
//
//	   1. The origin of this software must not be misrepresented; you must not
//	   claim that you wrote the original software. If you use this software
//	   in a product, an acknowledgment in the product documentation would be
//	   appreciated but is not required.
//
//	   2. Altered source versions must be plainly marked as such, and must not be
//	   misrepresented as being the original software.
//
//	   3. This notice may not be removed or altered from any source
//	   distribution.
//
    
/*
        This simplifies parsing of parameters passed to a command line tool
        somewhat. This understands two parameters: Those preceded by a switch,
        which starts with a minus sign and continues with only one more
        character (i.e. -f, or -i), and those that do not have a switch,
        and are thus "unlabeled".
        
        Unlabeled parameters are processed in the order they appear in the
        parameter mapping table (see below), while switched parameters are
        looked up by name, case-sensitively.
        
        To have ToolParams automatically store your parameters in the proper
        variables for you, simply create an array of ToolParamEntry structures,
        one per parameter, and pass that and the argc and argv parameters
        passed to your main() function to the ParseParamArray() function.
        Unlabeled parameters must have mSwitch set to an empty string,
        while labeled parameters must contain the entire label (i.e. "-i"
        or "-F" or whatever).
        
        Put a pointer to the variable that is to contain the char* from the
        parameter array into mDest. The variable pointed to by this will be
        set to NULL if the parameter was not found, or otherwise will point
        to the string.
        
        If a label is immediately followed by a second label, or if a label
        is the last entry in the parameter list, its string is set to an empty
        string.
        
    EXAMPLE:
        int main( int argc, const char* argv )
        {
            char*		vFilename, *vOverwrite;
            ToolParamEntry	mEntries[3] = { { "", &vFilename },
                                            { "-o", &vOverwrite },
                                            { "", NULL } };
            ParseParamArray(argc, argv, mEntries );
            if( vOverwrite != NULL )	; // overwite.
            if( vFilename == NULL )		return EXIT_FAIL;
            fopen( vFilename );
        }
*/

#ifdef __cplusplus
extern "C" {
#endif

/* -----------------------------------------------------------------------------
    Data Structures:
   -------------------------------------------------------------------------- */

typedef struct ToolParamEntry
{
    const char*			mSwitch;	// Enter indicator, like "-i" here. Use empty string for unlabeled param.
    const char** const  mDest;		// Pointer to variable to hold param, if found. Otherwise var pointed to by this is set to NULL.
} ToolParamEntry;


/* -----------------------------------------------------------------------------
    Prototypes:
   -------------------------------------------------------------------------- */

void	ParseParamArray( int argc, const char* argv[], ToolParamEntry* pMap );

#ifdef __cplusplus
}
#endif