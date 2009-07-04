//
//  UKCarbonEventHandler.h
//  TalkingMoose (XC2)
//
//  Created by Uli Kusterer on 26.03.06.
//  Copyright 2006 Uli Kusterer. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#ifndef __CARBON__
// Avoid pulling in all of Carbon.h into files that use an object of this kind (you'll still need it for creating one, though):
typedef void*	EventHandlerRef;
typedef void*	EventHandlerCallRef;
typedef void*	EventRef;
#endif

extern NSString*	UKCarbonEventHandlerEventReceived;

@interface UKCarbonEventHandler : NSObject
{
	EventHandlerRef		evtHandler;		// Reference to our event handler to pass to Carbon.
	EventHandlerCallRef	currCall;		// Allows us to forward the event. Only valid while we're handling an event.
	EventRef			currEvent;		// The event we're currently handling.
}

-(id)	initWithEventClass: (UInt32)eclass kind: (UInt32)ekind;

-(BOOL)	performEventActionAndPassOn;	// Override this to perform your action. By default sends a UKCarbonEventHandlerEventReceived notification with this object as the notification object.
-(BOOL)	callNextHandler;				// Returns YES when the other handler handled the event, NO on error or eventNotHandledErr.

// For you Carbon afficionados:
-(EventHandlerCallRef)	currentCallRef;
-(EventRef)				currentEventRef;

// Private:
-(OSStatus)	handleEvent: (EventRef)inEvent call: (EventHandlerCallRef)inHandlerCallRef;

@end
