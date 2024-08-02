#include "events_handler.h"

void EventsHandler::handleMouse(MEVENT *event, int *mainWinCh) {
  // / mouse press => KEY_MOUSE => ch = 409(base_10) = 0631(base-8)
  if (*mainWinCh == KEY_MOUSE) {
    int mouse = getmouse(event);

    if (mouse == OK) {
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
  }
}

void EventsHandler::handleKeyEvents(MEVENT *event, int *mainWinCh, bool *flag,
                                    int *toolbarCh) {
  // exit application => ESC key
  if (*mainWinCh == 27 || *toolbarCh == 27) {
    *flag = false;
  }

  if (*toolbarCh <= 49 && *toolbarCh >= 57) {
  }

  // handle menu items selection
  switch (*toolbarCh) {

  // num key 1
  case 49:
    /* code */
    break;

  // num key 2
  case 50:
    /* code */
    break;

  // num key 3
  case 51:
    /* code */
    break;

  // num key 4
  case 52:
    /* code */
    break;

  // num key 5
  case 53:
    /* code */
    break;

  // num key 6
  case 54:
    /* code */
    break;

  // num key 7
  case 55:
    /* code */
    break;

  // num key 6
  case 56:
    /* code */
    break;

  // num key 7
  case 57:
    /* code */
    break;

  default:
    break;
  }

  // std::cout << "toolbar ch: " << wgetstr << std::endl;
}