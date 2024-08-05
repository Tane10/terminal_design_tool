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
  // for (int i = 0; i < menu.size(); i++) {
  //   if (key == menu[i].key) {
  //     menu[i].active = true;
  //   } else {
  //     if (menu[i].active) {
  //       menu[i].active = false;
  //     }
  //   }
  // }
  // drawMenu();

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