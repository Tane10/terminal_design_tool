#ifndef TOOL_BAR_H
#define TOOL_BAR_H
#include "globals.h"
#include <iostream>
#include <ncurses.h>

class ToolBar {
private:
  WINDOW *toolbarWin;

public:
  ToolBar(/* args */);
  ~ToolBar();

  void init();
};

#endif