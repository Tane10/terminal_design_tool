#ifndef APP_H
#define APP_H
#include "globals.hpp"
#include "tool_bar.hpp"
#include <iostream>
#include <ncurses.h>

class App {

private:
  WINDOW *mainWin;

public:
  App();
  ~App();

  void init();
  void setupScreen();
};

#endif
