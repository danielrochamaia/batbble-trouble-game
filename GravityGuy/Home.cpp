/**********************************************************************************
// Home (Código Fonte) 
// 
// Criação:     14 Fev 2013
// Atualização: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Tela de abertura do jogo
//
**********************************************************************************/

#include "Engine.h"
#include "GravityGuy.h"
#include "Home.h"
#include "Level1.h"
#include "Audio.h"
#include <iostream>
#include <random>
using namespace std;

// ------------------------------------------------------------------------------

Audio* Home::audio = nullptr;

// ------------------------------------------------------------------------------

void Home::Init()
{
    //delete audio;
    //audio = nullptr;
    //random_device rd;
    //mt19937 mt(rd());
    //uniform_int_distribution<int> dist(0, 7);
    string musicas[8];
    musicas[0] = "Megaman";
    musicas[1] = "Joker";
    musicas[2] = "Heathens";
    musicas[3] = "Gravity Falls";
    musicas[4] = "Clint Eastwood";
    musicas[5] = "Another Brick In The Wall";
    musicas[6] = "Sunflower";
    musicas[7] = "In The End";

    //int a = dist(mt);
    //int b = dist(mt);
    //if (a == b) {
    //    b == 5;
    //    if (a == b) {
    //        b = 5 - 2;
    //    }
    //}

    //string musica1 = musicas[a];
    //string musica2 = musicas[b];

    // cria sistema de áudio
    audio = new Audio();
    audio->Add(HOME, "Resources/sons/Menu.wav");
    audio->Add(MUSIC1, "Resources/sons/" + musicas[0] + ".wav");
    audio->Add(MUSIC2, "Resources/sons/" + musicas[7] + ".wav");
    audio->Add(TRANSITION, "Resources/Transition.wav");

    scene = new Scene();

    backg = new Sprite("Resources/menu-background.jpg");
    //backg = new Sprite("Resources/menu.png");
    tileset = new TileSet("Resources/PressEnter.png", 72, 48, 1, 5);
    anim = new Animation(tileset, 0.180f, true);
    audio->Play(HOME, true);
    audio->Volume(HOME, 0.05f);

    mouse = new Mouse();
    scene->Add(mouse, MOVING);

    // cria itens de menu
    menu[0] = new Item(900, 250, SINGLE, "Resources/SinglePlayer.png");
    menu[1] = new Item(900, 305, MULTI, "Resources/MultiPlayer.png");
    menu[2] = new Item(900, 360, EXIT, "Resources/ExitGame.png");

    // adiciona itens na cena
    for (int i = 0; i < MaxItens; ++i)
        scene->Add(menu[i], STATIC);

}

// ------------------------------------------------------------------------------

void Home::Update()
{

    // fecha a janela ao pressionar ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza objeto mouse
    mouse->Update();

    // destaca item selecionado
    for (int i = 0; i < MaxItens; ++i)
    {
        if (scene->Collision(mouse, menu[i]))
        {
            menu[i]->Select();
            selected = menu[i];

                if (mouse->Clicked())
                {
                    switch (menu[i]->Type())
                    {
                    case SINGLE:
                    case MULTI:
                        audio->Stop(HOME);
                        GravityGuy::NextLevel<Level1>();
                    break;
                    case EXIT: window->Close(); break;
                    }
                    break;
                }
        }
        else
        {
            menu[i]->UnSelect();
        }

            menu[i]->Update();
    }

    // habilita/desabilita bounding box
    if (window->KeyPress('B')) {
        viewBBox = !viewBBox;
    }

}

// ------------------------------------------------------------------------------

void Home::Draw()
{
    backg->Draw(window->CenterX() + 220, window->CenterY(), Layer::BACK);
    anim->Draw(545, 275);

    // desenha itens do menu
    scene->Draw();

    // desenha bounding box dos menus
    if (viewBBox)
        scene->DrawBBox();

}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete anim;
    delete tileset;
    delete backg;
    delete scene;
}

// ------------------------------------------------------------------------------