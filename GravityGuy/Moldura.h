/**********************************************************************************
// Block (Arquivo de Cabe�alho)
//
// Cria��o:     22 Dez 2012
// Atualiza��o: 01 Dez 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Bloco do jogo Breakout
//
**********************************************************************************/

#ifndef _MOLDURA_H_
#define _MOLDURA_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"              // tipos espec�ficos da engine
#include "Object.h"             // interface de Object
#include "Sprite.h"             // interface de Sprites

// ---------------------------------------------------------------------------------

class Moldura : public Object
{
private:
    //Sprite* sprite;            // sprite do bloco

public:

    Moldura(uint tipo);         // construtor
    ~Moldura();                   // destrutor


    void OnCollision(Object* obj);     // resolu��o da colis�o
    void Draw();
    void Update();              // atualiza��o do objeto
};

// ---------------------------------------------------------------------------------

inline void Moldura::Draw()
{
    /*sprite->Draw(x, y, z);*/
}

// ---------------------------------------------------------------------------------

#endif