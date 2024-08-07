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
  struct MenuItem {
    int key;
    std::string name;
    bool active;
  };

  std::array<MenuItem, 13> menu;

  WINDOW *getToolbarWin();

  std::array<MenuItem, 13> *getMenu();

  ToolBar(/* args */);
  ~ToolBar();

  void init();
  void drawMenu();
  void selectToolBarItem(int key);
};

#endif