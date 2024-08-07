#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H
#include "globals.h"
#include "toolbar.h"
#include <ncurses.h>

// Singleton setup to handel the renderEngine
/**
 * TODO:
 * - how do we handle lots of shapes ion the window?
 * - how can we trace all of this?
 */

struct State {
  MEVENT *event;
  bool *inWindow;
  ToolBar::MenuItem *option;

  State() : event(nullptr), inWindow(nullptr), option(nullptr) {}
};

class RenderEngine {
private:
  /* data */

  RenderEngine();
  State engineState; // private var to handle state

  static RenderEngine *instance; // singleton instance pointer
  static bool instanceExists;    // manage current state

public:
  static RenderEngine &getInstance();

  // passing a const value so we
  // don't modify the need state
  void setEngineState(const State &newState);
  State getEngineState() const;

  void setInWindowState(bool *inWin);
  void setEventState(MEVENT *event);
  void setOptionState(ToolBar::MenuItem *mItem);

  void drawRect();
  void drawLine();
  void drawCircle();
  void handler();
};

#endif
