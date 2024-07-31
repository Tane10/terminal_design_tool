#include "tool_bar.h"

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
  mvwprintw(toolbarWin, 1, 1, "This is toolbar window");
  wrefresh(toolbarWin);
}
