#include "app.h"
#include "tool_bar.h"

class App {
public:
  int row, col;
  void init(void) {
    initscr();            // Start curses mode
    cbreak();             // Line buffering disabled
    noecho();             // Don't echo() while we do getch
    keypad(stdscr, TRUE); // Enable function keys (like arrows)
    raw();

    getmaxyx(stdscr, row, col); // Get the number of rows and columns
  }

  void setupScreen(void) { ToolBar toolBar; }
};