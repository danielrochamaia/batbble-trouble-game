/**********************************************************************************
// GravityGuy (Arquivo de Cabeçalho)
// 
// Criação:     05 Out 2011
// Atualização: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Jogo estilo plataforma usando a engine do curso
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
    static Game * level;            // nível atual do jogo

public:
    static Player * player1;         // jogador 1
    static Player * player2;         // jogador 2
    static bool viewBBox;           // estado da bounding box
    static bool twoPlayers;
    static float pontos;
    static Hud* hud;

    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo

    template<class T>
    static void NextLevel()         // muda para próximo nível do jogo
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