#ifndef HEXADOKU_ABSTRACTSTATE_HPP
#define HEXADOKU_ABSTRACTSTATE_HPP

class AbstractState {
public:
    virtual void Update() = 0;

    virtual void HandleInput(char input) = 0;

    virtual void Draw() = 0;
};

#endif //HEXADOKU_ABSTRACTSTATE_HPP
