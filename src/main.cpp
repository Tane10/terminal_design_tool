#include "main.hpp"

int main() {
  App app;
  app.init();
  app.setupScreen();

  getch();
  endwin();
  return 0;
}