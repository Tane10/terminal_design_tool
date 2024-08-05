#include "events_handler.h"

void EventsHandler::handleMouse(MEVENT *event) {
  // / mouse press => KEY_MOUSE => ch = 409(base_10) = 0631(base-8)
  // if (*mainWinCh == KEY_MOUSE || *toolbarCh == KEY_MOUSE) {
  //   // int mouse = getmouse(event);

  //   if (getmouse(event) == OK) {
  // Mouse events are check with Bitwise AND operation
  if (event->bstate & BUTTON1_CLICKED) {
    std::cout << "clicked the button" << std::endl;

    std::cout << "x pos: " << event->x << "y pos: " << event->y
              << "z pos: " << event->z << std::endl;
  }
  if (event->bstate & BUTTON1_PRESSED) {
    std::cout << "Pressed the button" << std::endl;
  }
  if (event->bstate & BUTTON1_RELEASED) {
    std::cout << "Relesed the button" << std::endl;
  }
}

// int EventsHandler::handleKeyEvents(MEVENT *event, int *mainWinCh, bool *flag,
//                                    int *toolbarCh) {

//   int keyInput = 0;

//   // std::cout << "mainWinCh: " << *mainWinCh << "\n toolbarCh: " <<
//   *toolbarCh
//   //           << std::endl;

//   // // exit application => ESC key
//   // if (*mainWinCh == 27 && *toolbarCh == 27) {
//   //   *flag = false;
//   // }

//   // checking ascii value with character literals '1' <-> '9'
//   if (*toolbarCh >= 49 && *toolbarCh <= 57) {
//     keyInput = *toolbarCh;
//   }

//   return keyInput;
// }