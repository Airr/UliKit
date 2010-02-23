//
//  NSSet+DeepCopy.h
//  UKSyntaxColoredDocument
//
//  Created by Uli Kusterer on Tue May 18 2004.
//  Copyright (c) 2004 M. Uli Kusterer. All rights reserved.
//

/*
	This category adds a method to NSSet that performs a deep copy of all
	instead of the usual shallow copy. For any objects inside it, it calls deepCopy
	again, unless they don't implement that selector, then a regular copy will
	be done.
*/

// -----------------------------------------------------------------------------
//	Headers:
// -----------------------------------------------------------------------------

#import <Foundation/Foundation.h>


// -----------------------------------------------------------------------------
//	Interface:
// -----------------------------------------------------------------------------

@interface NSSet (UKDeepCopy)

-(NSSet*)  deepCopy;							// Call deepCopy on anything that understands it, copy on anything else.

-(NSMutableSet*)  deepMutableContainerCopy;	// Call deepMutableContainerCopy on anyone that understands it, copy on anything else.
-(NSMutableSet*)  deepMutableCopy;			// Call deepMutableCopy on anyone that understands it, mutableCopy on anything else.

@end
