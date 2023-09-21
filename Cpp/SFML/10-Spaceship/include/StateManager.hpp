#pragma once

namespace space
{

class State;

class StateManager
{
    public:
        StateManager();
        void loadNextState();
        void setNextState(State* nextState, bool resetState);
        State* getCurrentState();

    private:
        State* mCurrentState;
        State* mNextState;
};

}
