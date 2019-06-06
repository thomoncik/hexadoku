#include <State/BoardCreatorState.hpp>
#include <State/Menu/MainMenuState.hpp>

BoardCreatorState::BoardCreatorState(int size)  : size(size) {

}

void BoardCreatorState::OnEntry(Game &game) {

}

void BoardCreatorState::Update(Game &game) {

}

void BoardCreatorState::HandleInput(Game &game, char input) {
    if (input == 'q') {
        game.SetState(std::make_shared<MainMenuState>());
    }
}

void BoardCreatorState::Draw(Game &game) {

}

void BoardCreatorState::OnExit(Game &game) {

}
