#ifndef APP_H
#define APP_H
#include <iostream>
#include <ncurses.h>

class App {
private:
  /* data */
public:
  App(/* args */);
  ~App();
  void init();

  void setupScreen(void);
};

#endif