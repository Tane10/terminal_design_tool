#include "app.h"

App::App(ToolBar tb, EventsHandler eh) : mainWin(nullptr) {
  toolbar = tb;
  eventsHandler = eh;
}

App::~App() {
  if (mainWin != nullptr) {
    delwin(mainWin);
  }
  // endwin(); // End ncurses mode
}

void App::init() {
  initscr();            // Start curses mode
  cbreak();             // Line buffering disabled
  noecho();             // Don't echo() while we do getch
  keypad(stdscr, TRUE); // Enable function keys (like arrows)

  if (maxCols == 0 && maxRows == 0) {
    getmaxyx(stdscr, maxRows, maxCols); // Get the number of rows and columns
  }

  // required
  refresh();

  mainWin = newwin(0, 0, 0, 0);
  if (mainWin == nullptr) {
    std::cerr << "ERROR creating window" << std::endl;
    exit(EXIT_FAILURE);
  }

  box(mainWin, 0, 0);
  mvwprintw(mainWin, 1, 1, "This is main window");
  wrefresh(mainWin);

  std::cout << "Screen dimensions: " << maxRows << "x" << maxCols << std::endl;
}

void App::setupScreen() { toolbar.init(); }

void App::draw() {
  int flag = 1;
  int ch = getch();

  while (flag) {

    // TODO: make quit command ctrl + c or :exit
    // ch == q
    if (ch == 113) {
      flag = 0;
    }

    eventsHandler.handleMouse();
  }

  endwin();
}