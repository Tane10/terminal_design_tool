#include "events_handler.h"
void EventsHandler::handleMouse(MEVENT *event, int *ch) {
  bool isInWindow = false;
  if (*ch == KEY_MOUSE) {

    if (getmouse(event) == OK) {
      int startX, startY;
      int width, height;

      getbegyx(mainWin, startY, startX);
      getmaxyx(mainWin, height, width);

      if (event->x >= startX && event->x < startX + width &&
          event->y >= startY && event->y < startY + height) {
        isInWindow = true;
      }
    }

    if (isInWindow) {
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

void EventsHandler::handleKeyEvents(ToolBar *tb, MEVENT *event, int *ch,
                                    bool *flag) {

  // TODO: FIXME: workout a way to fix the
  // if (*toolbarCh != KEY_MOUSE) {
  //   std::cout << "\n toolbarCh: " << *toolbarCh << std::endl;
  // if (*ch == 27) {
  //   *flag = false;
  // }
  // }

  // checking ascii value with character literals '1' <-> '9'
  if (*ch >= 49 && *ch <= 57) {
    tb->selectToolBarItem(*ch);
  }
}