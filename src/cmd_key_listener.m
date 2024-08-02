// #import <Cocoa/Cocoa.h>
// #include "cmd_key_listener.h"

// //TODO: READ THIS AND UNDERSTAND WHAT IS HAPPENEING THEN REFACTOR
/// NOTE: DEEP RABBIT HOLD

// @interface  AppDelegate : NSObject <NSApplicationDelegate>
// @end

// @implementation AppDelegate

// - (void)keyDown:(NSEvent *)event{
//     NSUInteger modifierFlags = [event modifierFlags];
//     if (modifierFlags & NSEventModifierFlagCommand) {
//         NSLog(@"Cmd key was pressed with: %@", [event charactersIgnoringModifiers]);
//         pr
//         std::cout << "Cmd key pressed with key: " << [event charactersIgnoringModifiers].UTF8String << std::endl;
        
//     }
// }

// @end


// void runCocoaEventLoop(){
//     @autoreleasepool {
//         NSApplication *app = [NSApplication sharedApplication];
//         AppDelegate *delegate = [[AppDelegate alloc] init];
//         [app setDelegate:delegate];
//         [app run];
//     }
// }

// void startListeningForCmdKeys() {
//     std::thread([&]() {
//         runCocoaEventLoop();
//     }).detach();  // Detach the thread to run in the background
// }

#import <Cocoa/Cocoa.h>

// Define the AppDelegate interface
@interface AppDelegate : NSObject <NSApplicationDelegate>
@end

@implementation AppDelegate

// Method to handle key presses
- (void)keyDown:(NSEvent *)event {
    NSUInteger modifierFlags = [event modifierFlags];
    if (modifierFlags & NSEventModifierFlagCommand) {
        // Print to standard output using printf
        printf("Cmd key was pressed with: %s\n", [[event charactersIgnoringModifiers] UTF8String]);
    }
}

@end

// Main function to run the Cocoa event loop
void runCocoaEventLoop(int argc, const char * argv[]) {
    @autoreleasepool {
        NSApplication *app = [NSApplication sharedApplication];
        AppDelegate *delegate = [[AppDelegate alloc] init];
        [app setDelegate:delegate];
        [app run];
    }}
