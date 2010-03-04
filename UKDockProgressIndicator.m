//
//  UKDockProgressIndicator.m
//  Doublette
//
//  Created by Uli Kusterer on 30.04.05.
//  Copyright 2005 Uli Kusterer.
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

#import "UKDockProgressIndicator.h"


@implementation UKDockProgressIndicator

-(void)     setMinValue: (double)mn
{
    min = mn;
    [progress setMinValue: mn];

    [self updateDockTile];
}

-(double)   minValue
{
    return min;
}


-(void)     setMaxValue: (double)mn
{
    max = mn;
    [progress setMaxValue: mn];

    [self updateDockTile];
}

-(double)   maxValue
{
    return max;
}


-(void)     setDoubleValue: (double)mn
{
    current = mn;
    [progress setDoubleValue: mn];
    [self updateDockTile];
}

-(double)   doubleValue
{
    return current;
}


-(void)     setNeedsDisplay: (BOOL)mn
{
    [progress setNeedsDisplay: mn];
}


-(void)     display
{
    [progress display];
}


-(void)     setHidden: (BOOL)flag
{
    [progress setHidden: flag];
    if( flag ) // Progress indicator is being hidden? Reset dock tile to regular icon again:
        [NSApp setApplicationIconImage: [NSImage imageNamed: @"NSApplicationIcon"]];
}

-(BOOL)     isHidden
{
    return [progress isHidden];
}


-(void) updateDockTile
{
    NSImage*    dockIcon = [[[NSImage alloc] initWithSize: NSMakeSize(128,128)] autorelease];
    
    
    [dockIcon lockFocus];
        NSRect      box = { {4, 4}, {120, 16} };
        
        // App icon:
        [[NSImage imageNamed: @"NSApplicationIcon"] dissolveToPoint: NSZeroPoint fraction: 1.0];
        
        // Track & Outline:
        [[NSColor whiteColor] set];
        [NSBezierPath fillRect: box];
        
        [[NSColor blackColor] set];
        [NSBezierPath strokeRect: box];
        
        // State fill:
        box = NSInsetRect( box, 1, 1 );
        [[NSColor knobColor] set];
        
        box.size.width = (box.size.width / (max -min)) * (current -min);
        
        NSImage*    prImg = [NSImage imageNamed: @"MiniProgressGradient"];
        NSRect      picBox = { { 0,0 }, { 0,0 } };
		if( prImg )
		{
			picBox.size = [prImg size];
			[prImg drawInRect: box fromRect: picBox operation: NSCompositeCopy fraction: 1.0];
		}
		else
			NSRectFill( box );
    [dockIcon unlockFocus];
    
    [NSApp setApplicationIconImage: dockIcon];
}

@end
