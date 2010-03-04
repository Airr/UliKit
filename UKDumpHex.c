//
//  UKDumpHex.c
//  VelocityLoader
//
//  Created by Uli Kusterer on 02.04.07.
//  Copyright 2007 Uli Kusterer.
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

#include "UKDumpHex.h"
#include <stdio.h>


void	UKDumpHex( const char* buf, size_t bufLen )
{
	size_t		x = 0;
	char		asciiLine[17] = { 0 };
	int			asciiLineX = 0;
	
	printf("%08u: ", 0);
	
	for( x = 0; x < bufLen; x++ )
	{
		int		n = buf[x];
		char	syms[] = { '0', '1', '2', '3',
							'4', '5','6', '7',
							'8', '9', 'A', 'B',
							'C', 'D', 'E', 'F'};
		unsigned int	n1 = (n & 0xF0) >> 4,
						n2 = n & 0x0F;
		char			c1 = syms[n1],
						c2 = syms[n2];
		printf("%c%c ", c1, c2);
		
		unsigned char		asciiCh = buf[x];
		if( asciiCh > 127 || asciiCh < ' ' )
			asciiCh = '.';
		else if( asciiCh == '\t' )
			asciiCh = ' ';
		else if( asciiCh == '\n' || asciiCh == '\r' )
			asciiCh = '.';
		asciiLine[asciiLineX++] = asciiCh;
		
		if( asciiLineX == 16 )
		{
			printf( "  %s\n", asciiLine );
			printf( "%08lu: ", x );
			asciiLineX = 0;
		}
	}
	
	// Output any partial line at end:
	if( asciiLineX < 16 )
	{
		asciiLine[asciiLineX] = 0;
		for( ; asciiLineX < 16; asciiLineX++ )
			printf("   ");
		printf("  %s\n", asciiLine);
	}
}