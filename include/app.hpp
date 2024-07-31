#ifndef APP_H
#define APP_H
#include "globals.hpp"
#include "tool_bar.hpp"
#include <iostream>
#include <ncurses.h>

class App {
public:
  // App(/* args */);
  // ~App();

  void init();
  void setupScreen();
};

#endif
