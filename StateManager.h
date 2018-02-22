#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class StateManager{
    private:
        enum State{
            Playing = 1,
            Victory = 2,
            Defeat = 3
        };

        State state;
    public:
        StateManager();
        setState(int i);
};
