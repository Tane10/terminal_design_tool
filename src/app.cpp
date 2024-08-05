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
  // setlocale(LC_ALL, "");
  // nodelay(mainWin, TRUE); // Set the window to non-blocking mode
  halfdelay(1);

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
  // toolbar.init();
  // toolbar.drawMenu();
  refresh();
}

void App::draw() {

  wnoutrefresh(mainWin);

  // TODO: FIXME: Onclick is casing the terminal window to close and kill
  // application

  bool flag = true;

  while (flag) {
    MEVENT event;
    // int toolbarCh = wgetch(toolbar.getToolbarWin());

    // std::cout << "event-mouse: " << getmouse(&event) << std::endl;

    // WINDOW *toolbarWin = toolbar.getToolbarWin();

    int ch = wgetch(mainWin); // Wait for an input event
    // std::cout << "mouse: " << has_mouse() << std::endl;

    // if (ch == ERR) {
    //   std::cerr << "wgetch() failed with error code: " << ch << std::endl;
    //   // Handle the error or continue
    //   continue;
    // }

    if (ch == KEY_MOUSE) {

      std::cout << "CLOICKED" << std::endl;

      if (getmouse(&event) == OK) {

        std::cout << "event-mouse: " << getmouse(&event) << std::endl;

        std::cout << "HEHRHEHRHE" << std::endl;

        int startX, startY;

        getbegyx(mainWin, startY, startX);

        std::cout << "start_x: " << startX << "start_y: " << startY
                  << std::endl;
      }
    }
  }

  delwin(mainWin);
  delwin(toolbar.getToolbarWin());

  endwin();
}