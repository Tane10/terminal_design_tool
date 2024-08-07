#include "toolbar.h"

ToolBar::ToolBar() : toolbarWin(nullptr) {
  menu = {{{49, "Line (1)", false},
           {50, "Rectangle (2)", false},
           {51, "Arrow (3)", false},
           {52, "Select (4)", false},
           {53, "Text (5)", false},
           {54, "Circle (6)", false},
           {55, "Diamond (7)", false},
           {56, "Pencil (8)", false},
           {57, "Erase (9)", false},
           {111, "Undo (cmd + z)", false},
           {222, "Redo (shift + cmd + z)", false},
           {333, "Save (cmd + s)", false},
           {444, "New (cmd + n)", false}}};
}
ToolBar::~ToolBar() {
  if (toolbarWin != nullptr) {
    delwin(toolbarWin);
  }
}

void ToolBar::init() {
  // *newwin(int nlines (Y), int ncols (X), int begin_y, int begin_x);
  toolbarWin = newwin(5, maxX, maxY - 5, 0);
  if (toolbarWin == nullptr) {
    std::cerr << "ERROR creating window" << std::endl;
    exit(EXIT_FAILURE);
  }
  // nodelay(toolbarWin, TRUE); // Set the window to non-blocking mode

  refresh();

  box(toolbarWin, 0, 0);
  mvwprintw(toolbarWin, 0, 1, "Toolbar");
  wrefresh(toolbarWin);
}

WINDOW *ToolBar::getToolbarWin() { return toolbarWin; }

std::array<ToolBar::MenuItem, 13> *ToolBar::getMenu() { return &menu; }

void ToolBar::drawMenu() {
  int x, y;
  x = 2;
  y = 3;
  for (auto &item : menu) {
    if (item.active) {
      wattron(toolbarWin, A_STANDOUT);
    }

    mvwprintw(toolbarWin, y, x, "%s", item.name.c_str());
    if (item.active) {
      wattroff(toolbarWin, A_STANDOUT);
    }

    x += item.name.length() + 2;
  }

  wrefresh(toolbarWin);
}

void ToolBar::selectToolBarItem(int key) {
  for (auto &menuItem : menu) {
    if (menuItem.key == key) {
      menuItem.active = true;
    } else {
      if (menuItem.active) {
        menuItem.active = false;
      }
    }
  }
  drawMenu();
}