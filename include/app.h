#ifndef APP_H
#define APP_H
#include "globals.h"
#include "tool_bar.h"
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
