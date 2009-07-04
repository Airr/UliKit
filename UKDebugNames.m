//
//  UKDebugNames.m
//  filebrowser
//
//  Created by Uli Kusterer on 01.05.05.
//  Copyright 2005 M. Uli Kusterer. All rights reserved.
//

#import "UKDebugNames.h"


NSMutableDictionary*    gUKDebugNamesObjectToNameMap = nil;     // Object pointer -> human-readable name map. Keys are hex strings ("0x00123456").
NSArray*                gUKDebugNamesArray = nil;               // Array of human-readable names we pick object names from.
int                     gUKDebugNamesNextNameIndex = 0;         // Counter of next name from debug names array we'll use. May be out of range, in which case we wrap it before look-up.
int                     gUKDebugNamesReuseNumber = 0;           // Counter to allow reusing names when we have used up all names in the debug names array.



NSString*   UKDebugNameFor( id obj )
{
    if( obj == nil )
        return @"(null)";
    
    // Lazily instantiate our mapping table and our list of human-readable names to choose from:
    if( !gUKDebugNamesObjectToNameMap )
        gUKDebugNamesObjectToNameMap = [[NSMutableDictionary alloc] init];
    if( !gUKDebugNamesArray )
        gUKDebugNamesArray = [[NSArray alloc] initWithContentsOfFile: [[NSBundle mainBundle] pathForResource: @"UKDebugNames" ofType: @"plist"]];
    
    // Generate a key and try to look up an existing mapping table entry:
    NSString*       key = [NSString stringWithFormat: @"%lx", obj];
    NSString*       value = [gUKDebugNamesObjectToNameMap objectForKey: key];
    
    if( !value )    // No entry yet?
    {
        // Verify the "next name" index is still in range:
        if( gUKDebugNamesNextNameIndex >= [gUKDebugNamesArray count] )
        {
            gUKDebugNamesReuseNumber++;     // If not, increase the number appended to each name by one...
            gUKDebugNamesNextNameIndex = 0; // ... and wrap back to the start of the name list.
        }
        
        // Get the next name and increment our "next name" counter:
        value = [gUKDebugNamesArray objectAtIndex: gUKDebugNamesNextNameIndex++];
        if( !value )
            return @"(null-name)";
        
        // If we're out of fresh names (reuse > 0), append the number to the name:
        if( gUKDebugNamesReuseNumber > 0 )
            value = [value stringByAppendingFormat: @" %d", gUKDebugNamesReuseNumber +1];
        if( !value )
            return @"(null-name2)";
            
        // Add name to our mapping table so next time we can return the same name for this object:
        [gUKDebugNamesObjectToNameMap setObject: value forKey: key];
    }
    
    return value;   // Let the caller have the name.
}
