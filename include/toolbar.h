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

  using MenuItem = struct {
    int key;
    std::string name;
    bool active;
  };

  std::array<MenuItem, 13> menu;

public:
  WINDOW *getToolbarWin();

  ToolBar(/* args */);
  ~ToolBar();

  void init();
  void drawMenu();
  void selectToolBarItem(int key);
};

#endif