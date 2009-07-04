//
//  UKColumnRowFilledBgView.h
//  ValueConverter
//
//  Created by Uli Kusterer on 26.04.08.
//  Copyright 2008 The Void Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>


#define COL_ROW_COUNT		16


@interface UKColumnRowFilledBgView : NSView
{
	float		colWidths[COL_ROW_COUNT];
	float		rowHeights[COL_ROW_COUNT];
}

-(void)	setColumnWidth: (float)w atIndex: (int)n;
-(void)	setRowHeight: (float)h atIndex: (int)n;

@end
