/**********************************************************************************
// GravityGuy (Código Fonte)
// 
// Criação:     05 Out 2011
// Atualização: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

#include "Engine.h"
#include "GravityGuy.h"
#include "Home.h"
#include "GameOver.h"
#include "Hud.h"
#include "Player.h"


// ------------------------------------------------------------------------------

// inicializa membros estáticos da classe
Game*   GravityGuy::level = nullptr;
Player* GravityGuy::player1 = nullptr;
Player* GravityGuy::player2 = nullptr;
bool    GravityGuy::viewBBox = false;
Hud * GravityGuy::hud = nullptr;
float   GravityGuy::pontos = 0.0f;
bool    GravityGuy::twoPlayers = false;
bool GravityGuy::gameover = false;

// ------------------------------------------------------------------------------

void GravityGuy::Init() 
{
    

    // bounding box não visível
    viewBBox = false;

    // cria jogador
    twoPlayers = false;
    player1 = new Player("Resources/bat-flow-2.png");
    player2 = new Player("Resources/robin-flow-2.png");
    hud = new Hud();
    // inicializa nível de abertura do jogo
    level = new Home();
    level->Init();
}

// ------------------------------------------------------------------------------

void GravityGuy::Update()
{
    if (gameover)
    {
        NextLevel<GameOver>();
        gameover = false;
        Home::audio->Stop(MUSIC1);
        Home::audio->Stop(MUSIC2);
    }

    if (hud->Time() == 0) {
        gameover = true;
    }

    // habilita/desabilita visualização da bounding box
    if (window->KeyPress('B'))
        viewBBox = !viewBBox;    

    // atualiza nível
    level->Update();
    hud->Update();
} 

// ------------------------------------------------------------------------------

void GravityGuy::Draw()
{
    // desenha nível
    level->Draw();
} 

// ------------------------------------------------------------------------------

void GravityGuy::Finalize()
{
    level->Finalize();

    delete player1;
    if (twoPlayers) {
        delete player2;
    }
    delete level;
    delete Home::audio;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura o motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(1080, 720);
    engine->window->Color(0, 0, 0);
    engine->window->Title("Gravity Guy");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new GravityGuy());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

