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
  bool flag = true;
  while (flag) {
    MEVENT event;
    int ch = getch();

    // TODO: make quit command ctrl + c or :exit
    // ch == q
    if (ch == 113) {
      flag = false;
    }

    // mouse press => ch = 409 => KEY_MOUSE => 0631(octal base-8) = 409(base_10)
    if (ch == KEY_MOUSE) {
      if (getmouse(&event) == OK) {
        std::cout << "We pushed the button" << std::endl;
      }
    }

    //   if (getmouse(&event) == OK) {
    //     if (event.bstate & BUTTON1_PRESSED) {
    //       mvprintw(1, 0, "Mouse button pressed");
    //       std::cout << "We pushed the button" << std::endl;
    //     }
    //   }
    // }

    eventsHandler.handleMouse();
  }

  endwin();
}