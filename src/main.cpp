#include "main.h"

int main() {
  ToolBar toolBar;
  EventsHandler eventsHandler;

  App app(toolBar, eventsHandler);
  app.init();
  app.setupScreen();
  app.draw();
  return 0;
}