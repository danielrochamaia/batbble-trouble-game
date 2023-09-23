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
#include "Platform.h"
#include "Background.h"
#include "Ball.h"
#include "Moldura.h"

#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros estáticos da classe

Scene * Level1::scene = nullptr;

// ------------------------------------------------------------------------------

void Level1::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // pano de fundo do jogo
    backg = new Background(Color{ 1,1,1,1 }, "Resources/level1.png");
    scene->Add(backg, STATIC);

    // adiciona jogador na cena
    scene->Add(GravityGuy::player, MOVING);

    // ----------------------
    // plataformas
    // ----------------------

    Platform * plat;
    float posX, posY;
    uint  platType;
    Color white { 1,1,1,1 };
    Ball* ball;
    Moldura* moldura;

    redBall = new Image("Resources/bola-g.png");

    ball = new Ball(redBall, -200, INIMIGO);
    ball->MoveTo(window->CenterX(), window->CenterY());
    ball->BBox(new Circle(72.0f));
    scene->Add(ball, MOVING);

    moldura = new Moldura(new Image(""), 0, CIMA);
    moldura->MoveTo(5, 5, Layer::BACK);
    moldura->BBox(new Rect(-window->Width(), -16, window->Width(), 16));
    scene->Add(moldura, STATIC);

    moldura = new Moldura(new Image(""), 0, BAIXO);
    moldura->MoveTo(5, 720, Layer::BACK);
    moldura->BBox(new Rect(-window->Width(), -16, window->Width(), 16));
    scene->Add(moldura, STATIC);

    moldura = new Moldura(new Image(""), 0, ESQUERDA);
    moldura->MoveTo(5, 5, Layer::BACK);
    moldura->BBox(new Rect(-16, -window->Height(), 16, window->Height()));
    scene->Add(moldura, STATIC);

    moldura = new Moldura(new Image(""), 0, DIREITA);
    moldura->MoveTo(1080, 5, Layer::BACK);
    moldura->BBox(new Rect(-16, -window->Height(), 16, window->Height()));
    scene->Add(moldura, STATIC);

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
    GravityGuy::audio->Frequency(MUSIC, 0.94f);
    GravityGuy::audio->Frequency(TRANSITION, 1.0f);
    GravityGuy::audio->Play(MUSIC);
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    if (window->KeyPress(VK_ESCAPE))
    {
        GravityGuy::audio->Stop(MUSIC);
        GravityGuy::NextLevel<Home>();
        //GravityGuy::player->Reset();
    }
    else if (GravityGuy::player->Bottom() < 0 || GravityGuy::player->Top() > window->Height())
    {
        GravityGuy::audio->Stop(MUSIC);
        GravityGuy::NextLevel<GameOver>();
        //GravityGuy::player->Reset();
    }
    else if (GravityGuy::player->Level() == 1 || window->KeyPress('N'))
    {
        GravityGuy::NextLevel<Level2>();
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

    if (GravityGuy::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    scene->Remove(GravityGuy::player, MOVING);
    delete scene;
}

// ------------------------------------------------------------------------------
