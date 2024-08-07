#include "main.h"

int main() {
  ToolBar tb;
  EventsHandler eh;

  RenderEngine renderEngine = RenderEngine::getInstance();

  State ns;
  ns.inWindow = nullptr;
  ns.event = nullptr;
  ns.option = nullptr;
  renderEngine.setEngineState(ns);

  App app(tb, eh);
  app.init();
  app.setupScreen();
  app.draw();
  return 0;
}
