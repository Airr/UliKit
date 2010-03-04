//
//  UKColumnRowFilledBgView.h
//  ValueConverter
//
//  Created by Uli Kusterer on 26.04.08.
//  Copyright 2008 Uli Kusterer.
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

// -----------------------------------------------------------------------------
//	Headers:
// -----------------------------------------------------------------------------

#import <Cocoa/Cocoa.h>


// -----------------------------------------------------------------------------
//	Constants:
// -----------------------------------------------------------------------------

#define COL_ROW_COUNT		16


// -----------------------------------------------------------------------------
//	UKColumnRowFilledBgView:
// -----------------------------------------------------------------------------

@interface UKColumnRowFilledBgView : NSView
{
	float		colWidths[COL_ROW_COUNT];
	float		rowHeights[COL_ROW_COUNT];
}

-(void)	setColumnWidth: (float)w atIndex: (int)n;
-(void)	setRowHeight: (float)h atIndex: (int)n;

@end
