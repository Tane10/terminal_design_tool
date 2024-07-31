#include "app.hpp"

int main() {
  App app;

  app.init();
  app.setupScreen();

  // // mvprintw(row / 2, (col - strlen("Hello, ncurses!")) / 2, "Hello,
  // ncurses!");

  // WINDOW *win = newwin(15, 17, 2, 10);
  // refresh();

  // box(win, 0, 0);

  // mvwprintw(win, 0, 1, "top");
  // mvwprintw(win, 1, 1, "inner");

  // this is a ascii number that matches a key
  // int ch = getch();

  // if (ch) {
  //   printw("The button pressed is: %c", ch);
  // }

  // wrefresh(win);

  getch();
  endwin();
  return 0;
}