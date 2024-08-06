#include "app.h"

App::App(ToolBar tb, EventsHandler eh) : mainWin(nullptr) {
  toolbar = tb;
  eventsHandler = eh;
}

App::~App() {
  if (mainWin != nullptr) {
    delwin(mainWin);
  }
}

void App::init() {
  initscr(); // Start curses mode
  clear();
  cbreak();             // Line buffering disabled
  noecho();             // Don't echo() while we do getch
  keypad(stdscr, TRUE); // Enable function keys (like arrows)
  mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION,
            NULL); // Enable mouse mask
  curs_set(0);
  nodelay(mainWin, TRUE); // Set the window to non-blocking mode

  if (maxY == 0 && maxX == 0) {
    getmaxyx(stdscr, maxY, maxX); // Get the number of rows and columns
  }

  // required
  refresh();

  // *newwin(int nlines (Y), int ncols (X), int begin_y, int begin_x);
  mainWin = newwin(maxY - 5, maxX, 0, 0);
  if (mainWin == nullptr) {
    std::cerr << "ERROR creating window" << std::endl;
    exit(EXIT_FAILURE);
  }

  box(mainWin, 0, 0);
  mvwprintw(mainWin, 0, 1, "Canvas");
  wrefresh(mainWin);
}

void App::setupScreen() {
  toolbar.init();
  toolbar.drawMenu();
  refresh();
}

void App::draw() {

  bool flag = true;
  WINDOW *toolbarWin = toolbar.getToolbarWin();

  while (flag) {
    MEVENT event;
    int ch = getch(); // Wait for an input event

    if (ch == ERR) {
      std::cerr << "wgetch() failed with error code: " << ch << std::endl;
      continue;
    }

    eventsHandler.handleMouse(&event, &ch, mainWin);
    eventsHandler.handleKeyEvents(&toolbar, &event, &ch, &flag);
  }

  delwin(mainWin);
  delwin(toolbarWin);
  endwin();
}