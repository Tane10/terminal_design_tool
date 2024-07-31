#ifndef APP_H
#define APP_H
#include "events_handler.h"
#include "globals.h"
#include "toolbar.h"
#include <iostream>
#include <ncurses.h>

class App {

private:
  WINDOW *mainWin;

public:
  ToolBar toolbar;
  EventsHandler eventsHandler;

  App(ToolBar tb, EventsHandler eh);
  ~App();

  void init();
  void setupScreen();

  void draw();
};

#endif
