//
//  UKXMLToDictionary.h
//  MobileMoose
//
//  Created by Uli Kusterer on 13.07.08.
//  Copyright 2008 Uli Kusterer. All rights reserved.
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
	Handy utility functions for turning XML into a dictionary that is a bit
	easier to work with. As an example:
	
	<foo>
		<bar>
			Welcome to Abu Dhabi
			<snort>50</snort>
		</bar>
		<bazzes>
			<baz>one</baz>
			<baz>two</baz>
			<baz>three</baz>
		</bazzes>
	</foo>
	
	will be turned into:
	
	{
		UKNameOfXMLTagKey = "foo"
		bar =
		{
			UKNameOfXMLTagKey = "bar"
			UKTextOfXMLTagKey = "Welcome to Abu Dhabi"
			snort = "50"
		}
		bazzes =
		{
			baz =
			(
				"one",
				"two",
				"three"
			)
		}
	}
	
	(where curly brackets indicate dictionaries, regular brackets indicate arrays)
*/

#import <Foundation/Foundation.h>


// The following keys share a namespace with the actual tag names, so should
//	be invalid XML tag names to avoid collisions:

#define UKNameOfXMLTagKey			@"  NAME"
#define UKTextOfXMLTagKey			@"  TEXT"


NSDictionary*	UKXMLDataToDictionary( NSData* inXMLData );
NSDictionary*	UKXMLStringToDictionary( NSString* inXMLString );
