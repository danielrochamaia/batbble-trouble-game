#include "Hud.h"
#include "GravityGuy.h"

Hud::Hud()
{
	fonte = new Font("Resources/Agency30.png");
	fonte->Spacing("Resources/Agency30.dat");

	time = 100;

	timer.Start();
	float delta = 24.0f;
	float init = -24.0f;
}

Hud::~Hud()
{
	delete fonte;
}

void Hud::Update()
{
	if (!stopped && timer.Elapsed() > 1.0f) {
		time--;
		timer.Reset();

		if (time < 0)
			time = 0;
	}

}

void Hud::Draw() {

	text.str("");
	text << "Tempo";
	fonte->Draw(window->Width() - 48.0f, 30.0f, text.str());

	text.str("");
	text.width(3);
	text.fill('0');
	text << time;
	fonte->Draw(window->Width() - 35.0f, 60.0f, text.str());

	text.str("");
	text << "Pontua��o";
	fonte->Draw(40.0f, 30.0f, text.str());

	text.str("");
	text.width(4);
	text.fill('0');
	text << GravityGuy::pontos;
	fonte->Draw(60.0f, 60.0f, text.str());
}

void Hud::Draw(float posicoesTxt[]) {
	text.str("");
	text << "Tempo";
	fonte->Draw(posicoesTxt[0], posicoesTxt[1], text.str());

	text.str("");
	text.width(3);
	text.fill('0');
	text << time;
	fonte->Draw(posicoesTxt[2], posicoesTxt[3], text.str());

	text.str("");
	text << "Pontua��o";
	fonte->Draw(posicoesTxt[4], posicoesTxt[5], text.str());

	text.str("");
	text.width(4);
	text.fill('0');
	text << GravityGuy::pontos;
	fonte->Draw(posicoesTxt[6], posicoesTxt[7], text.str());
}

void Hud::ResetTime()
{
	stopped = false;
	timer.Start();
	time = 100;
}

uint Hud::Time() {
	return time;
}