#include "StateManager.hpp"
#include "State.hpp"

#include <stdexcept>

namespace space
{

StateManager::StateManager()
{
    mCurrentState = nullptr;
    mNextState = nullptr;
}

void StateManager::loadNextState()
{
    if(mNextState != nullptr)
    {
        mCurrentState = mNextState;
        mNextState = nullptr;
    }
}

void StateManager::setNextState(State* nextState, bool resetState)
{
    mNextState = nextState;
    if(resetState)
    {
        mNextState->reset();
    }
}

State* StateManager::getCurrentState()
{
    if(mCurrentState == nullptr)
    {
        throw std::runtime_error("No state loaded");
    }
    return mCurrentState;
}

}
