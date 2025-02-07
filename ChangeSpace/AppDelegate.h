//
//  AppDelegate.h
//  ChangeSpace
//
//  Created by Stephen Sykes on 20/10/11.
//  Copyright (c) 2011 Switchstep. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Sparkle/Sparkle.h>
#import <ScriptingBridge/ScriptingBridge.h>
#import "SRRecorderControl.h"
#import "SpacesCBridge.h"
#import "DDHotKeyCenter.h"
#import "StatusItemView.h"
#import "TransparentWindow.h"

#define MAX_DESKTOPS 16

typedef enum {
  CSLeft,
  CSRight,
  CSUp,
  CSDown,
  CSUpLeft,
  CSUpRight,
  CSDownLeft,
  CSDownRight
} CSDirection;

#define kVK_LeftArrow 0x7B
#define kVK_RightArrow 0x7C
#define kVK_DownArrow 0x7D
#define kVK_UpArrow 0x7E

#define POLLING_INTERVAL 1.0
// how long we must wait before asking the current space when moving
#define DESKTOP_MOVE_DELAY 0.4f

@interface AppDelegate : NSObject <NSApplicationDelegate, NSWindowDelegate>
{
  IBOutlet NSWindow *window;
  IBOutlet NSPanel *preferences;
  IBOutlet SUUpdater *suupdater;
  IBOutlet NSPopUpButton *gridColumns;
  IBOutlet NSPopUpButton *gridRows;
  IBOutlet NSTextField *desktopCount;
  IBOutlet NSButton *circulateVertical;
  IBOutlet SRRecorderControl *leftKeys;
  IBOutlet SRRecorderControl *rightKeys;
  IBOutlet SRRecorderControl *upKeys;
  IBOutlet SRRecorderControl *downKeys;
  IBOutlet NSTextField *versionString;
  
  SpacesCBridge *c_bridge;
  
  NSUInteger width, height, totalSpaces, savedTotalSpaces;
  
  StatusItemView *statusItemView;
  
  NSImage *blank_image;
  NSMutableArray *menu_images;
  
  BOOL observing, remapNeeded;
  
  DDHotKeyCenter *ddh;
  
  TransparentWindow *transWindow;
}

@property (assign) IBOutlet NSWindow *window;
@property (nonatomic, retain) SpacesCBridge *c_bridge;  
@property (nonatomic, retain) StatusItemView *statusItemView;
@property (nonatomic, retain) NSImage *blank_image;
@property (nonatomic, retain) NSMutableArray *menu_images;
@property (nonatomic, retain) NSTimer *pollingTimer;
@property (nonatomic, retain) DDHotKeyCenter *ddh;
@property (nonatomic, retain) TransparentWindow *transWindow;

- (IBAction) updateGrid:(id) sender;

@end
