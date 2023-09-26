/**********************************************************************************
// GravityGuy (Arquivo de Cabe�alho)
// 
// Cria��o:     05 Out 2011
// Atualiza��o: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

#ifndef _GRAVITYGUY_H_
#define _GRAVITYGUY_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Player.h"
#include "Resources.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

enum TypeObjects
{
    PLAYER,
    ARPAO,
    AMIGAVEL,
    INIMIGO,
    BOLA,
    CIMA,
    BAIXO,
    ESQUERDA,
    DIREITA
};

// ------------------------------------------------------------------------------

class GravityGuy : public Game
{
private:
    static Game * level;            // n�vel atual do jogo

public:
    static Player * player1;         // jogador 1
    static Player * player2;         // jogador 2
    static bool viewBBox;           // estado da bounding box
    static bool twoPlayers;
    static float pontos;
    static Hud* hud;

    void Init();                    // inicializa jogo
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo

    template<class T>
    static void NextLevel()         // muda para pr�ximo n�vel do jogo
    {
        if (level)
        {
            level->Finalize();
            delete level;
            level = new T();
            level->Init();
        }
    };
};

// ---------------------------------------------------------------------------------

#endif