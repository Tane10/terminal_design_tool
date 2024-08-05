#ifndef EVENTS_HANDLER_H
#define EVENTS_HANDLER_H
#include <iostream>
#include <ncurses.h>

class EventsHandler {
private:
  /* data */
public:
  //   events_handler(/* args */);
  //   ~events_handler();
  void handleMouse(MEVENT *event);

  // int handleKeyEvents(MEVENT *event, int *mainWinCh, bool *flag,
  //                     int *toolbarCh);
};

#endif
