#include "render_engine.h"

RenderEngine *RenderEngine::instance = nullptr;
bool RenderEngine::instanceExists = false;

RenderEngine &RenderEngine::getInstance() {
  if (!instanceExists) {
    instance = new RenderEngine();
    instanceExists = true;
  }
  return *instance;
}

RenderEngine::RenderEngine() : engineState{} {}

void RenderEngine::setEngineState(const State &newState) {

  // handling clean up exiting state
  if (engineState.event) {
    delete engineState.event;
  }
  if (engineState.inWindow) {
    delete engineState.inWindow;
  }
  if (engineState.option) {
    delete engineState.option;
  }

  // Copy new state to engineState
  engineState.event = newState.event ? new MEVENT(*newState.event) : nullptr;
  engineState.inWindow =
      newState.inWindow ? new bool(*newState.inWindow) : nullptr;
  engineState.option =
      newState.option ? new ToolBar::MenuItem(*newState.option) : nullptr;
}

State RenderEngine::getEngineState() const { return engineState; }

void RenderEngine::setInWindowState(bool *inWin) {
  if (engineState.inWindow) {
    delete engineState.inWindow;
  }

  engineState.inWindow = inWin;
};

void RenderEngine::setEventState(MEVENT *event) {
  if (engineState.event) {
    delete engineState.event;
  }

  engineState.event = event;
};

void RenderEngine::setOptionState(ToolBar::MenuItem *mItem) {
  if (engineState.option) {
    delete engineState.option;
  }

  engineState.option = mItem;
};

void RenderEngine::handler() {

};

void RenderEngine::drawRect() {};
void RenderEngine::drawCircle() {};
void RenderEngine::drawLine() {};
