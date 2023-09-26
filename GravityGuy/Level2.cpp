/**********************************************************************************
// Level2 (Código Fonte)
//
// Criação:     27 Set 2021
// Atualização: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Nível 2 do jogo
//
**********************************************************************************/

#include "GravityGuy.h"
#include "Home.h"
#include "Level2.h"
#include "GameOver.h"
#include "Player.h"
#include "Background.h"
#include "Transition.h"
#include "Ball.h"

#include "Enums.h"
#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros estáticos da classe

Scene* Level2::scene = nullptr;
bool Level2::gameover = false;
// ------------------------------------------------------------------------------

void Level2::Init()
{
    GravityGuy::player1->nivelAtual = 2;
    GravityGuy::player2->nivelAtual = 2;
    // cria gerenciador de cena
    scene = new Scene();
    GravityGuy::hud->ResetTime();
    // pano de fundo do jogo
    Color dark{ 0.4f, 0.4f, 0.4f, 1.0f };
    backg = new Background(dark, "Resources/level2-2.png");
    scene->Add(backg, STATIC);

    // adiciona jogador na cena
    scene->Add(GravityGuy::player1, MOVING);
    if (GravityGuy::twoPlayers) {
        GravityGuy::player2->MoveTo(GravityGuy::player1->X() + 400, GravityGuy::player1->Y());
        scene->Add(GravityGuy::player2, MOVING);
    }

    Home::audio->Play(MUSIC2);

    GravityGuy::levelResponse = false;


    if (GravityGuy::twoPlayers) {

        Ball * ball = new Ball(GravityGuy::redBall, BALLGG1);
        ball->MoveTo(450, 450);
        scene->Add(ball, STATIC);

        ball = new Ball(GravityGuy::redBall, BALLGG1);
        ball->MoveTo(300, 200);
        scene->Add(ball, STATIC);

        ball = new Ball(GravityGuy::redBall, BALLGG2);
        ball->MoveTo(window->CenterX(), window->CenterY());
        scene->Add(ball, STATIC);

        ball = new Ball(GravityGuy::redBall, BALLM1);
        ball->MoveTo(200, 350);
        scene->Add(ball, STATIC);

        ball = new Ball(GravityGuy::redBall, BALLM2);
        ball->MoveTo(300, 250);
        scene->Add(ball, STATIC);
    }
    else {

        Ball * ball = new Ball(GravityGuy::redBall, BALLGG1);
        ball->MoveTo(700, 200);
        scene->Add(ball, STATIC);

        GravityGuy::bolasEstouradas += 15;

        ball = new Ball(GravityGuy::redBall, BALLGG2);
        ball->MoveTo(window->CenterX(), window->CenterY());
        scene->Add(ball, STATIC);

        GravityGuy::bolasEstouradas += 15;

        ball = new Ball(GravityGuy::redBall, BALLM1);
        ball->MoveTo(200, 500);
        scene->Add(ball, STATIC);

        GravityGuy::bolasEstouradas += 3;

        ball = new Ball(GravityGuy::redBall, BALLM2);
        ball->MoveTo(700, 350);
        scene->Add(ball, STATIC);

        GravityGuy::bolasEstouradas += 3;
    }
    // ----------------------
    // plataformas
    // ----------------------

    //Platform* plat;
    //float posX, posY;
    //uint  platType;

    //ifstream fin;
    //fin.open("Level2.txt");

    //fin >> posX;
    //while (!fin.eof())
    //{
    //    if (fin.good())
    //    {
    //        // lê linha com informações da plataforma
    //        fin >> posY; fin >> platType;
    //        plat = new Platform(posX, posY, platType, dark);
    //        scene->Add(plat, STATIC);
    //    }
    //    else
    //    {
    //        // ignora comentários
    //        fin.clear();
    //        char temp[80];
    //        fin.getline(temp, 80);
    //    }

    //    fin >> posX;
    //}
    //fin.close();

    // ----------------------
}

// ------------------------------------------------------------------------------

void Level2::Update()
{
    if (GravityGuy::bolasEstouradas == 0 || window->KeyPress('N'))
    {
        GravityGuy::bolasEstouradas = 0;
        Home::audio->Stop(MUSIC2);
        GravityGuy::hud->Stop();
        GravityGuy::NextLevel<Transition>();
        GravityGuy::player1->disparoPlayer = false;
        if (GravityGuy::twoPlayers) {
            GravityGuy::player2->disparoPlayer = false;
        }
        GravityGuy::player1->Reset();
    }
    else if (window->KeyPress(VK_ESCAPE)) {
        Home::audio->Stop(MUSIC2);
        GravityGuy::hud->Stop();
        GravityGuy::NextLevel<Home>();
        GravityGuy::player1->disparoPlayer = false;
        if (GravityGuy::twoPlayers) {
            GravityGuy::player2->disparoPlayer = false;
        }
        GravityGuy::player1->Reset();
        GravityGuy::pontos = 0;
    }
    else
    {
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Level2::Draw()
{
    backg->Draw();
    scene->Draw();
    GravityGuy::hud->Draw();

    if (GravityGuy::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level2::Finalize()
{
    scene->Remove(GravityGuy::player1, MOVING);
    if (GravityGuy::twoPlayers) {
        scene->Remove(GravityGuy::player2, MOVING);
    }
    delete scene;
}

// ------------------------------------------------------------------------------
