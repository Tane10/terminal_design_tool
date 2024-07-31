#include "app.hpp"

// Undefined symbols for architecture arm64:
//   "_maxCols", referenced from:
//       App::init() in app-d23f1a.o
//   "_maxRows", referenced from:
//       App::init() in app-d23f1a.o
// ld: symbol(s) not found for architecture arm64
// clang: error: linker command failed with exit code 1 (use -v to see
// invocation) make: *** [build] Error 1

void App::init() {
  initscr();                          // Start curses mode
  cbreak();                           // Line buffering disabled
  noecho();                           // Don't echo() while we do getch
  keypad(stdscr, TRUE);               // Enable function keys (like arrows)
  getmaxyx(stdscr, maxRows, maxCols); // Get the number of rows and columns
}

void App::setupScreen() {
  ToolBar toolBar;
  // if (!maxRows || !maxCols) {
  // toolBar.init();
  // }
}
