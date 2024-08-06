#ifndef EVENTS_HANDLER_H
#define EVENTS_HANDLER_H
#include "globals.h"
#include "toolbar.h"
#include <iostream>
#include <ncurses.h>

class EventsHandler {
private:
  /* data */
public:
  //   events_handler(/* args */);
  //   ~events_handler();
  void handleMouse(MEVENT *event, int *ch);

  void handleKeyEvents(ToolBar *tb, MEVENT *event, int *ch, bool *flag);
};

#endif
