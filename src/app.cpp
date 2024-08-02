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
  mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION,
            NULL); // Enable mouse mask
  curs_set(0);

  // startListeningForCmdKeys();

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
  nodelay(mainWin, TRUE); // Set the window to non-blocking mode

  std::cout << "Screen dimensions: " << maxRows << "x" << maxCols << std::endl;
}

void App::setupScreen() {
  toolbar.init();
  toolbar.drawMenu();
  refresh();
}

void App::draw() {
  bool flag = true;
  // std::array<int, 3> mousePos = {0, 0, 0};

  while (flag) {
    MEVENT event;
    int mainWinCh = wgetch(mainWin);

    int toolbarCh = wgetch(toolbar.getToolbarWin());

    // TODO: implement mouse event handler
    eventsHandler.handleMouse(&event, &mainWinCh);

    eventsHandler.handleKeyEvents(&event, &mainWinCh, &flag, &toolbarCh);
  }

  endwin();
}