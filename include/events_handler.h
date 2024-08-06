#ifndef EVENTS_HANDLER_H
#define EVENTS_HANDLER_H
#include "toolbar.h"
#include <iostream>
#include <ncurses.h>

class EventsHandler {
private:
  /* data */
public:
  //   events_handler(/* args */);
  //   ~events_handler();
  void handleMouse(MEVENT *event, int *ch, WINDOW *win);

  void handleKeyEvents(ToolBar *tb, MEVENT *event, int *ch, bool *flag);
};

#endif
