#ifndef APP_H
#define APP_H
#include "events_handler.h"
#include "globals.h"
#include "render_engine.h"
#include "toolbar.h"
#include <array>
#include <iostream>
#include <ncurses.h>

class App {

private:
  // WINDOW *mainWin;

public:
  ToolBar toolbar;
  EventsHandler eventsHandler;
  RenderEngine *renderEngine;

  App(ToolBar tb, EventsHandler eh);
  ~App();

  void init();
  void setupScreen();

  void draw();
};

#endif
