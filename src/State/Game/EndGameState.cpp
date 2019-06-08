#include <State/Game/EndGameState.hpp>
#include <Graphics/GfxStream.hpp>
#include <Graphics/Attributes.hpp>
#include <State/Menu/MainMenuState.hpp>

EndGameState::EndGameState(std::shared_ptr<Game> game) : game(std::move(game)) {

}

void EndGameState::OnEntry(StateContext &stateContext) {
    timeUsed = game->GetGameTimeString();
}

void EndGameState::Update(StateContext &stateContext) {

}

void EndGameState::HandleInput(StateContext &stateContext, char input) {
    if (input == ' ') {
        stateContext.SetState(std::make_shared<MainMenuState>());
    }
}

void EndGameState::Draw(StateContext &stateContext) {
    gfx::out << gfx::clear << Attribute::STANDOUT;
    gfx::out << Position(10, 10) << "Board solved in " << timeUsed;
    gfx::out << gfx::nodecor << Position(10, 11) << "Press space to continue";
}

void EndGameState::OnExit(StateContext &stateContext) {

}
