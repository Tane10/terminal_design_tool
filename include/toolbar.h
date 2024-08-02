#ifndef TOOL_BAR_H
#define TOOL_BAR_H
#include "globals.h"
#include <array>
#include <iostream>
#include <ncurses.h>
#include <string>

class ToolBar {
private:
  WINDOW *toolbarWin;

public:
  ToolBar(/* args */);
  ~ToolBar();

  void init();
  void drawMenu();
  WINDOW *getToolbarWin();
};

#endif