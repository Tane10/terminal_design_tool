#import <Cocoa/Cocoa.h>
#include "cmd_key_listener.h"

//TODO: READ THIS AND UNDERSTAND WHAT IS HAPPENEING THEN REFACTOR

@interface  AppDelegate : NSObject <NSApplicationDelegate>
@end

@implementation AppDelegate

- (void)keyDown:(NSEvent *)event{
    NSUInteger modifierFlags = [event modifierFlags];
    if (modifierFlags & NSEventModifierFlagCommand) {
        NSLog(@"Cmd key was pressed with: %@", [event charactersIgnoringModifiers]);
        // std::cout << "Cmd key pressed with key: " << [event charactersIgnoringModifiers].UTF8String << std::endl;
        
    }
}

@end


void runCocoaEventLoop(){
    @autoreleasepool {
        NSApplication *app = [NSApplication sharedApplication];
        AppDelegate *delegate = [[AppDelegate alloc] init];
        [app setDelegate:delegate];
        [app run];
    }
}

void startListeningForCmdKeys() {
    std::thread([&]() {
        runCocoaEventLoop();
    }).detach();  // Detach the thread to run in the background
}
