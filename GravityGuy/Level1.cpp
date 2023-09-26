/**********************************************************************************
// Level1 (Código Fonte) 
// 
// Criação:     14 Fev 2013
// Atualização: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Nível 1 do jogo
//
**********************************************************************************/

#include "GravityGuy.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "GameOver.h"
#include "Player.h"
#include "Background.h"
#include "Ball.h"
#include "Transition.h"

#include <string>
#include <fstream>
#include "Enums.h"
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros estáticos da classe

Scene * Level1::scene = nullptr;
// ------------------------------------------------------------------------------

void Level1::Init()
{
    GravityGuy::player1->nivelAtual = 1;
    GravityGuy::player2->nivelAtual = 1;
    // cria gerenciador de cena
    scene = new Scene();
    GravityGuy::hud->ResetTime();

    // pano de fundo do jogo
    backg = new Background(Color{ 1,1,1,1 }, "Resources/level1-2.png");
    scene->Add(backg, STATIC);

    // adiciona jogador na cena
    scene->Add(GravityGuy::player1, MOVING);
    if (GravityGuy::twoPlayers) {
        scene->Add(GravityGuy::player2, MOVING);
        GravityGuy::player2->MoveTo(GravityGuy::player1->X() + 400, GravityGuy::player1->Y());

    }


    GravityGuy::levelResponse = true;
    // ----------------------
    // plataformas
    // ----------------------

    //Platform * plat;
    //float posX, posY;
    //uint  platType;
    //Color white { 1,1,1,1 };
    //Ball* ball;
    //Moldura* moldura;
    
    //ball = new Ball(redBall, -200, INIMIGO);
    //Ball * ball = new Ball(redBall, -200, INIMIGO);
    //ball->MoveTo(window->CenterX(), window->CenterY());
    //ball->BBox(new Circle(72.0f));
    Ball* ball;



    if (GravityGuy::twoPlayers) {
        ball = new Ball(GravityGuy::redBall, BALLGG1);
        ball->MoveTo(700, 200);
        scene->Add(ball, STATIC);

        ball = new Ball(GravityGuy::redBall, BALLGG2);
        ball->MoveTo(window->CenterX(), window->CenterY());
        scene->Add(ball, STATIC);

        GravityGuy::bolasEstouradas = 30;
    }
    else {
        ball = new Ball(GravityGuy::redBall, BALLGG1);
        ball->MoveTo(350, 350);
        scene->Add(ball, STATIC);

        GravityGuy::bolasEstouradas = 15;
    }

    
    //moldura = new Moldura(new Image(""), 0, CIMA);
    //moldura->MoveTo(5, 5, Layer::BACK);
    //moldura->BBox(new Rect(-window->Width(), -16, window->Width(), 16));
    //scene->Add(moldura, STATIC);

    //moldura = new Moldura(new Image(""), 0, BAIXO);
    //moldura->MoveTo(5, 720, Layer::BACK);
    //moldura->BBox(new Rect(-window->Width(), -16, window->Width(), 16));
    //scene->Add(moldura, STATIC);

    //moldura = new Moldura(new Image(""), 0, ESQUERDA);
    //moldura->MoveTo(5, 5, Layer::BACK);
    //moldura->BBox(new Rect(-16, -window->Height(), 16, window->Height()));
    //scene->Add(moldura, STATIC);

    //moldura = new Moldura(new Image(""), 0, DIREITA);
    //moldura->MoveTo(1080, 5, Layer::BACK);
    //moldura->BBox(new Rect(-16, -window->Height(), 16, window->Height()));
    //scene->Add(moldura, STATIC);
    //ifstream fin;
    //fin.open("Level1.txt");

    //fin >> posX;
    //while (!fin.eof())
    //{
    //    if (fin.good())
    //    {
    //        // lê linha com informações da plataforma
    //        fin >> posY; fin >> platType;
    //        plat = new Platform(posX, posY, platType, white);
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
        // inicia com música
    Home::audio->Play(MUSIC1, true);
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    if (window->KeyPress(VK_ESCAPE))
    {
        Home::audio->Stop(MUSIC1);
        GravityGuy::NextLevel<Home>();
        GravityGuy::player1->disparoPlayer = false;
        if (GravityGuy::twoPlayers) {
            GravityGuy::player2->disparoPlayer = false;
        }
        GravityGuy::player1->Reset();
        GravityGuy::pontos = 0;
    }
    else if (GravityGuy::bolasEstouradas == 0 || window->KeyPress('N'))
    {
        GravityGuy::bolasEstouradas = 0;
        Home::audio->Stop(MUSIC1);
        GravityGuy::hud->Stop();
        GravityGuy::NextLevel<Transition>();
        GravityGuy::player1->disparoPlayer = false;
        GravityGuy::player2->disparoPlayer = false;
    }
    else
    {
        scene->Update();
        scene->CollisionDetection();
    }    
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
    backg->Draw();
    scene->Draw();
    GravityGuy::hud->Draw();

    if (GravityGuy::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    scene->Remove(GravityGuy::player1, MOVING);
    if (GravityGuy::twoPlayers) {
        scene->Remove(GravityGuy::player2, MOVING);
    }
    delete scene;
}

// ------------------------------------------------------------------------------
