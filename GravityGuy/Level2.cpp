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
    // cria gerenciador de cena
    scene = new Scene();

    // pano de fundo do jogo
    Color dark{ 0.4f, 0.4f, 0.4f, 1.0f };
    backg = new Background(dark, "Resources/level2.png");
    scene->Add(backg, STATIC);

    // adiciona jogador na cena
    scene->Add(GravityGuy::player1, MOVING);
    if (GravityGuy::twoPlayers) {
        scene->Add(GravityGuy::player2, MOVING);
    }

    Home::audio->Play(MUSIC2);
    Home::audio->Volume(MUSIC2, 0.05f);

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
    if (gameover)
    {
        Home::audio->Stop(MUSIC2);
        GravityGuy::NextLevel<GameOver>();
        GravityGuy::player1->disparoPlayer = false;
        if (GravityGuy::twoPlayers) {
            GravityGuy::player2->disparoPlayer = false;
        }
        GravityGuy::player1->Reset();
        gameover = false;
    }
    if (window->KeyPress(VK_ESCAPE) || GravityGuy::player1->Level() == 2 || window->KeyPress('N'))
    {
        Home::audio->Stop(MUSIC2);
        GravityGuy::NextLevel<Home>();
        GravityGuy::player1->disparoPlayer = false;
        if (GravityGuy::twoPlayers) {
            GravityGuy::player2->disparoPlayer = false;
        }
        GravityGuy::player1->Reset();
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
