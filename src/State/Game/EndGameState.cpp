#include <State/Game/EndGameState.hpp>
#include <Graphics/GfxStream.hpp>
#include <Graphics/Attributes.hpp>
#include <State/Menu/MainMenuState.hpp>

EndGameState::EndGameState(std::shared_ptr<PlayStateModel> playStateModel) : playStateModel(std::move(playStateModel)) {

}

void EndGameState::OnEntry(Game &game) {
    timeUsed = playStateModel->GetGameTimeString();
}

void EndGameState::Update(Game &game) {

}

void EndGameState::HandleInput(Game &game, char input) {
    if (input == ' ') {
        game.SetState(std::make_shared<MainMenuState>());
    }
}

void EndGameState::Draw(Game &game) {
    gfx::out << gfx::clear << Attribute::STANDOUT;
    gfx::out << Position(10, 10) << "Board solved in " << timeUsed;
    gfx::out << gfx::nodecor << Position(10, 11) << "Press space to continue";
}

void EndGameState::OnExit(Game &game) {

}
