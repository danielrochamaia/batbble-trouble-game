/**********************************************************************************
// Weapon (Arquivo de Cabe�alho)
//
// Cria��o:     24 Set 2023
// Atualiza��o: 24 Set 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Define uma classe para um proj�til
//
**********************************************************************************/

#ifndef _BATBBLETROUBLE_WEAPON_H_
#define _BATBBLETROUBLE_WEAPON_H_

// --------------------------------------------------------------------------------

#include "Object.h"                             // objetos do jogo 
#include "Image.h"                              // carregamento de imagens
#include "Sprite.h"                             // desenho de sprites
#include "Vector.h"                             // representa��o de vetor
#include "Player.h"                              // objeto avi�o

// --------------------------------------------------------------------------------

class Weapon : public Object
{
public:
    Sprite* sprite;                            // sprite do m�ssil
    Vector speed;                               // velocidade do m�ssil

public:
    Weapon(Player* player, Image* img);    // construtor
    ~Weapon();                                 // destrutor
    void OnCollision(Object* obj);     // resolu��o da colis�o
    float scale;
    float dy = 0;
    float velY;                        // velocidade vertical  

    void Update();                              // atualiza��o
    void Draw();                                // desenho
};

// ------------------------------------------------------------------------------

#endif