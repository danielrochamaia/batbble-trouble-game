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

#ifndef _MOLDURA_H_
#define _MOLDURA_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"              // tipos específicos da engine
#include "Object.h"             // interface de Object
#include "Sprite.h"             // interface de Sprites

// ---------------------------------------------------------------------------------

class Moldura : public Object
{
private:


public:

    Moldura(uint tipo);         // construtor
    ~Moldura();                   // destrutor


    //void OnCollision(Object* obj);     // resolução da colisão
    void Draw();
    void Update();              // atualização do objeto
};

// ---------------------------------------------------------------------------------


// ---------------------------------------------------------------------------------

#endif