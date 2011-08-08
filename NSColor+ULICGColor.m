//
//  NSColor+ULICGColor.m
//  Stacksmith
//
//  Created by Uli Kusterer on 27.10.09.
//  Copyright 2009 Uli Kusterer.
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

#import "NSColor+ULICGColor.h"


@implementation NSColor (ULICGColor)

-(CGColorRef)	CGColor
{
    CGColorSpaceRef 	colorSpace = [[self colorSpace] CGColorSpace];
    NSInteger			componentCount = [self numberOfComponents];
    CGFloat				*components = (CGFloat *)calloc( componentCount, sizeof(CGFloat) );
    [self getComponents: components];
    CGColorRef			color = CGColorCreate( colorSpace, components );
    free( components );
	
	[(id)color autorelease];
	
    return color;
}

@end
