#include "toolbar.h"

ToolBar::ToolBar() : toolbarWin(nullptr) {}

ToolBar::~ToolBar() {
  if (toolbarWin != nullptr) {
    delwin(toolbarWin);
  }
}

void ToolBar::init() {
  toolbarWin = newwin(5, maxCols, maxRows - 5, 0);
  if (toolbarWin == nullptr) {
    std::cerr << "ERROR creating window" << std::endl;
    exit(EXIT_FAILURE);
  }

  refresh();

  box(toolbarWin, 0, 0);
  mvwprintw(toolbarWin, 0, 1, "Toolbar");
  wrefresh(toolbarWin);

  // nodelay(toolbarWin, TRUE); // Set the window to non-blocking mode
}

WINDOW *ToolBar::getToolbarWin() { return toolbarWin; }

void ToolBar::drawMenu() {
  int x, y;
  x = 2;
  y = 3;

  const char *menuItems[13] = {"Line (1)",
                               "Rectangle (2)",
                               "Arrow (3)",
                               "Select (4)",
                               "Text (5)",
                               "Circle (6)",
                               "Diamond (7)",
                               "Pencil (8)",
                               "Erase (9)",
                               "Undo (cmd + z)",
                               "Redo (shift + cmd + z)",
                               "Save (cmd + s)",
                               "New (cmd + n)"};

  for (int i = 0; i < 13; i++) {
    mvwprintw(toolbarWin, y, x, "%s", menuItems[i]);
    x += strlen(menuItems[i]) + 2;
  }
  wrefresh(toolbarWin);
}
