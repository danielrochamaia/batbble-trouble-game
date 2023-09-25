/**********************************************************************************
// Block (Arquivo de Cabeçalho)
//
// Criação:     22 Dez 2012
// Atualização: 01 Dez 2022
// Compilador:  Visual C++ 2022
//
// Descrição:   Bloco do jogo Breakout
//
**********************************************************************************/

#ifndef _BREAKOUT_BLOCK_H_
#define _BREAKOUT_BLOCK_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"              // tipos específicos da engine
#include "Object.h"             // interface de Object
#include "Sprite.h"             // interface de Sprites
#include "Vector.h"

// ---------------------------------------------------------------------------------

class Ball : public Object
{
private:
    Sprite* sprite;            // sprite do bloco
    Vector speed;

public:

    static Image* image;


    Ball(Image* img, uint tipo);         // construtor
    Ball(Image* img, Object* obj, uint tipo); // construtor para outra bolas
    ~Ball();                   // destrutor


    void OnCollision(Object* obj);     // resolução da colisão
    void Update();              // atualização do objeto
    void Draw();                // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Ball::Draw()
{
    sprite->Draw(x, y, z , scale);
}

// ---------------------------------------------------------------------------------

#endif