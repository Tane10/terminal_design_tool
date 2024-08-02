#include "events_handler.h"

void EventsHandler::handleMouse() {}

// / mouse press => KEY_MOUSE => ch = 409(base_10) = 0631(base-8)
//     if (ch == KEY_MOUSE) {
//       int mouse = getmouse(&event);

//       if (mouse == OK) {
//         // Mouse events are check with Bitwise AND operation
//         if (event.bstate & BUTTON1_CLICKED) {
//           std::cout << "clicked the button" << std::endl;

//           std::cout << "x pos: " << event.x << "y pos: " << event.y
//                     << "z pos: " << event.z << std::endl;
//         }
//         if (event.bstate & BUTTON1_PRESSED) {
//           std::cout << "Pressed the button" << std::endl;
//         }
//         if (event.bstate & BUTTON1_RELEASED) {
//           std::cout << "Relesed the button" << std::endl;
//         }
//       }
//     }

//     // eventsHandler.handleMouse();