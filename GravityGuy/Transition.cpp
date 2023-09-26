/**********************************************************************************
// GameOver (Arquivo de Cabeçalho)
//
// Criação:     14 Fev 2013
// Atualização: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Fim do jogo
//
**********************************************************************************/

#include "Engine.h"
#include "Transition.h"
#include "GravityGuy.h"
#include "Home.h"
#include "Level2.h"
#include "Level1.h"
#include "PLayer.h"

// ----------------------------------------------------------------------

void Transition::Init()
{
    title = new Sprite("Resources/OIG.png");
    Home::audio->Play(TELAPONTO);
}

// ----------------------------------------------------------------------

void Transition::Update()
{
    if (window->KeyPress(VK_RETURN) || window->KeyPress('N')) {
        if (GravityGuy::player1->nivelAtual == 1) {
            Home::audio->Stop(TELAPONTO);
            GravityGuy::NextLevel<Level2>();
            GravityGuy::pontos = 0;
        }
        else {
            Home::audio->Stop(TELAPONTO);
            GravityGuy::NextLevel<Home>();
            GravityGuy::pontos = 0;
        }
    }
}

// ----------------------------------------------------------------------

void Transition::Draw()
{
    title->Draw(window->CenterX()+50, window->CenterY(), Layer::BACK, 1.2);
    float posicoesTxt[8] = { window->CenterX() + 100 ,window->CenterY() + 20 ,window->CenterX() + 115 ,window->CenterY() + 60, window->CenterX() - 100 ,window->CenterY() + 20 ,window->CenterX() - 85 ,window->CenterY() + 60 };
    GravityGuy::hud->Draw(posicoesTxt);
}

// ----------------------------------------------------------------------

void Transition::Finalize()
{
    delete title;
}

// ----------------------------------------------------------------------

