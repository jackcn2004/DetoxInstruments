//
//  DTXGraphHostingView.m
//  DetoxInstruments
//
//  Created by Leo Natan (Wix) on 09/06/2017.
//  Copyright © 2017 Wix. All rights reserved.
//

#import "DTXGraphHostingView.h"

@implementation DTXGraphHostingView

@synthesize flipped=_flipped;

- (instancetype)initWithFrame:(NSRect)frameRect
{
	self = [super initWithFrame:frameRect];
	if(self)
	{
		self.wantsLayer = YES;
		self.layerContentsRedrawPolicy = NSViewLayerContentsRedrawNever;
		self.openHandCursor = [NSCursor arrowCursor];
//		self.closedHandCursor = [NSCursor arrowCursor];
	}
	return self;
}

-(void)scrollWheel:(nonnull NSEvent *)theEvent
{
	if(fabs(theEvent.scrollingDeltaY) > fabs(theEvent.scrollingDeltaX))
	{
		[self.nextResponder scrollWheel:theEvent];
		return;
	}
	
	[super scrollWheel:theEvent];
}

@end
