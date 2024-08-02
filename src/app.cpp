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
  std::array<int, 3> mousePos = {0, 0, 0};

  while (flag) {
    MEVENT event;
    int ch = getch();

    // 27 (base10) -> ESC key
    if (ch == 27) {
      flag = false;
    }

    // mouse press => KEY_MOUSE => ch = 409(base_10) = 0631(base-8)
    if (ch == KEY_MOUSE) {
      int mouse = getmouse(&event);

      if (mouse == OK) {
        // Mouse events are check with Bitwise AND operation
        if (event.bstate & BUTTON1_CLICKED) {
          std::cout << "clicked the button" << std::endl;

          std::cout << "x pos: " << event.x << "y pos: " << event.y
                    << "z pos: " << event.z << std::endl;
        }
        if (event.bstate & BUTTON1_PRESSED) {
          std::cout << "Pressed the button" << std::endl;
        }
        if (event.bstate & BUTTON1_RELEASED) {
          std::cout << "Relesed the button" << std::endl;
        }
      }
    }

    // eventsHandler.handleMouse();
  }

  endwin();
}