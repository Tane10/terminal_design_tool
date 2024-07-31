#include "tool_bar.hpp"

ToolBar::ToolBar() : toolbarWin(nullptr) {}

ToolBar::~ToolBar() {
  if (toolbarWin != nullptr) {
    delwin(toolbarWin);
  }
}

// void ToolBar::init() {
//   toolbarWin = newwin(maxRows, maxCols, 1, 1);
//   if (toolbarWin == nullptr) {
//     std::cerr << "ERROR creating window" << std::endl;
//     exit(EXIT_FAILURE);
//   }

//   box(toolbarWin, 0, 0);
//   wrefresh(toolbarWin);
// }
