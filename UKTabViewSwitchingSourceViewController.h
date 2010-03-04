//
//  UKTabViewSwitchingSourceViewController.h
//  TalkingMoose
//
//  Created by Uli Kusterer on 22.01.10.
//  Copyright 2010 Uli Kusterer
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


@interface UKTabViewSwitchingSourceViewController : NSObject
{
	IBOutlet NSTableView		*sourceView;	// List view to show the tab names in. This object should be its data source and delegate.
	IBOutlet NSTabView			*tabSwitcher;	// Tab view to switch according to list view selection.
}

@end
