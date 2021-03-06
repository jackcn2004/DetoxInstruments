//
//  DTXPlotHostConstructor.m
//  DetoxInstruments
//
//  Created by Leo Natan (Wix) on 4/26/18.
//  Copyright © 2018 Wix. All rights reserved.
//

#import "DTXPlotHostConstructor.h"

@implementation DTXPlotHostConstructor

- (void)setUpWithView:(NSView *)view
{
	[self setUpWithView:view insets:NSEdgeInsetsMake(0, 0, 0, 0) isForTouchBar:NO];
}

- (void)setUpWithView:(NSView *)view insets:(NSEdgeInsets)insets isForTouchBar:(BOOL)isForTouchBar
{
	_isForTouchBar = isForTouchBar;
	
	if(_wrapperView)
	{
		[_wrapperView removeFromSuperview];
		_wrapperView.frame = view.bounds;
	}
	else
	{
		_wrapperView = [DTXLayerView new];
		_wrapperView.translatesAutoresizingMaskIntoConstraints = NO;
		
		_hostingView = [[isForTouchBar ? DTXTouchBarGraphHostingView.class : DTXGraphHostingView.class alloc] initWithFrame:view.bounds];
		_hostingView.translatesAutoresizingMaskIntoConstraints = NO;
		
		_graph = [[CPTXYGraph alloc] initWithFrame:_hostingView.bounds];
		
		_graph.paddingLeft = 0;
		_graph.paddingTop = 0;
		_graph.paddingRight = 0;
		_graph.paddingBottom = 0;
		_graph.masksToBorder  = NO;
		_graph.backgroundColor = _isForTouchBar ? NSColor.gridColor.CGColor : NSColor.clearColor.CGColor;
		
		[self setupPlotsForGraph];
		
		[self.graph.allPlots enumerateObjectsUsingBlock:^(__kindof CPTPlot * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
			obj.backgroundColor = _isForTouchBar ? NSColor.blackColor.CGColor : NSColor.clearColor.CGColor;
		}];
		
		_hostingView.hostedGraph = _graph;
		
		[_wrapperView addSubview:_hostingView];
	}
	
	[view addSubview:_wrapperView];
	
	[NSLayoutConstraint activateConstraints:@[
											  [_wrapperView.topAnchor constraintEqualToAnchor:_hostingView.topAnchor],
											  [_wrapperView.leadingAnchor constraintEqualToAnchor:_hostingView.leadingAnchor],
											  [_wrapperView.trailingAnchor constraintEqualToAnchor:_hostingView.trailingAnchor],
											  [_wrapperView.bottomAnchor constraintEqualToAnchor:_hostingView.bottomAnchor],
											  
											  [view.topAnchor constraintEqualToAnchor:_wrapperView.topAnchor constant:-insets.top],
											  [view.leadingAnchor constraintEqualToAnchor:_wrapperView.leadingAnchor constant:-insets.left],
											  [view.trailingAnchor constraintEqualToAnchor:_wrapperView.trailingAnchor constant:-insets.right],
											  [view.bottomAnchor constraintEqualToAnchor:_wrapperView.bottomAnchor constant:-insets.bottom]
											  ]];
	
	[self didFinishViewSetup];
}

- (void)setupPlotsForGraph
{
	
}

- (void)dealloc
{
	[_hostingView removeFromSuperview];
	[_wrapperView removeFromSuperview];
}

- (void)didFinishViewSetup
{
	
}

@end
