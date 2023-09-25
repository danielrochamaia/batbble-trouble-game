/**********************************************************************************
// Home (Arquivo de Cabeçalho)
// 
// Criação:     14 Fev 2013
// Atualização: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Tela de abertura do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_HOME_H_
#define _GRAVITYGUY_HOME_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "Audio.h"
#include "Mouse.h"
#include "Item.h"
#include "Scene.h"

enum Sounds { HOME, MUSIC1, MUSIC2, GAMEOVER, TRANSITION};

enum MenuID { SINGLE, MULTI, TRACKS, LEADERBOARD, OPTIONS, EXIT };

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
    static const int MaxItens = 3;    // número de itens do menu

    Sprite    * backg = nullptr;       // pano de fundo
    TileSet   * tileset = nullptr;    // tileset da animação
    Animation * anim = nullptr;     // animação do menu
    Mouse     * mouse = nullptr;         // objeto mouse
    Item      * selected = nullptr;        // item selecionado
    Scene* scene = nullptr;

    Item* menu[MaxItens] = { 0 };    // itens do menu

    bool viewBBox = false;            // visualiza bounding box

public:
    
    static Audio* audio;
    void Init();                    // inicia nível
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza nível
};

// -----------------------------------------------------------------------------

#endif