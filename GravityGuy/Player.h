/**********************************************************************************
// Player (Arquivo de Cabeçalho)
// 
// Criação:     20 Abr 2012
// Atualização: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Define uma classe para o jogador 
//
**********************************************************************************/

#ifndef _GRAVITYGUY_PLAYER_H_
#define _GRAVITYGUY_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites

// ------------------------------------------------------------------------------

enum PlayerAnim {
    IDLE, IDLELEFT,
    WALK, WALKLEFT,
    JUMP, JUMPLEFT,
    HIT, HITLEFT,
    SLASH, SLASHLEFT,
    PUNCH, PUNCHLEFT,
    RUN, RUNLEFT,
    CLIMB, CLIMBLEFT,
    ANDANO_DIR1, ANDANO_ESQ1
};

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet   * tileset;                // folha de sprites do personagem
    //TileSet   * player1TileSet;                // folha de sprites do personagem
    Animation * anim;                   // animação do personagem
    Image* weapon;
    uint        gravity;                // gravidade atuando sobre o jogador
    int         level;                  // nível finalizado
    static const double PIXEL_PER_METER;

    bool isClimbing;
    bool hasZeroGravity;
    bool isMovingLeft;
    uint state;

    float velx;
    float mass;
    float inverseMass;
    
public:
    Player(string src);                           // construtor
    ~Player();                          // destrutor

    uint nivelAtual;
    bool disparoPlayer;

    void Reset();                       // volta ao estado inicial
    int Level();                        // último nível finalizado
    float Bottom();                     // coordenadas da base
    float Top();                        // coordenadas do topo

    void OnCollision(Object * obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline int Player::Level()
{ return level; }

inline float Player::Bottom()
{ return y + tileset->Height()/2; }

inline float Player::Top()
{ return y - tileset->Height()/2; }

// ---------------------------------------------------------------------------------

#endif