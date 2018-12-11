#include "GameClearState.h"
#include "Game.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "AnimatedGraphic.h"
#include "PlayState.h"

const std::string GameClearState::s_gameClearID = "GAMECEALR";


void GameClearState::s_gameClearToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(
		new MenuState());
}

bool GameClearState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/MENU.png",
		"mainbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/ClearBG.png",
		"ClearBG", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* gameClear = new AnimatedGraphic(
		new  LoaderParams(0, 0, 640, 520, "ClearBG"), 2);

	GameObject* button1 = new MenuButton(
		new LoaderParams(240, 320, 145, 50, "mainbutton"),
		s_gameClearToMain);

	m_gameObjects.push_back(gameClear);
	m_gameObjects.push_back(button1);
	std::cout << "entering PauseState\n";
	return true;
}

void GameClearState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void GameClearState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool GameClearState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()
		->clearFromTextureMap("gameovertext");
	TheTextureManager::Instance()
		->clearFromTextureMap("mainbutton");
	std::cout << "exiting GameOverState\n";
	return true;
}