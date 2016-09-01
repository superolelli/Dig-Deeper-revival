#pragma once


#include "../Framework/Gamestate.hpp"
#include "../Framework/Graphics/Sprite.hpp"
#include "../Framework/Gui/Button.hpp"
#include "../Framework/Gui/Beam.hpp"



class CGame : public CGameState
{

public:

	void Init(CGameEngine *_engine) override;
	void Cleanup() override;

	void Pause() override;
	void Resume() override;

	void HandleEvents() override;
	void Update() override;
	void Render(double _normalizedTimestep) override;


private:
	int m_value;
	int m_maxValue;

	sf::Texture m_ButtonTexture;
	sf::Texture m_BeamFrameTexture;
	sf::Texture m_BeamTexture;

	CButton m_button;
	CBeam m_beam;

};