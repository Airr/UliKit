//
//  NSBezierPathRoundRects.h
//  UKDockableWindow
//
//  Created by Uli Kusterer on Wed Feb 04 2004.
//  Based on code by John C. Randolph.
//  Copyright (c) 2004 M. Uli Kusterer.
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

#import <Cocoa/Cocoa.h>


@interface NSBezierPath (RoundRects)

+(void)				fillRoundRectInRect:(NSRect)rect radius:(float) radius;
+(void)				strokeRoundRectInRect:(NSRect)rect radius:(float) radius;

+(NSBezierPath*)	bezierPathWithRoundRectInRect:(NSRect)rect radius:(float) radius;

@end

// Some nifty utility functions this uses:
NSPoint  UKCenterOfRect( NSRect rect );
NSPoint  UKTopCenterOfRect( NSRect rect );
NSPoint  UKTopLeftOfRect( NSRect rect );
NSPoint  UKTopRightOfRect( NSRect rect );
NSPoint  UKLeftCenterOfRect( NSRect rect );
NSPoint  UKBottomCenterOfRect( NSRect rect );
NSPoint  UKBottomLeftOfRect( NSRect rect );
NSPoint  UKBottomRightOfRect( NSRect rect );
NSPoint  UKRightCenterOfRect( NSRect rect );