/**********************************************************************************
// Weapon (Arquivo de Cabeçalho)
//
// Criação:     24 Set 2023
// Atualização: 24 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Define uma classe para um projétil
//
**********************************************************************************/

#ifndef _BATBBLETROUBLE_WEAPON_H_
#define _BATBBLETROUBLE_WEAPON_H_

// --------------------------------------------------------------------------------

#include "Object.h"                             // objetos do jogo 
#include "Image.h"                              // carregamento de imagens
#include "Sprite.h"                             // desenho de sprites
#include "Vector.h"                             // representação de vetor
#include "Player.h"                              // objeto avião

// --------------------------------------------------------------------------------

class Weapon : public Object
{
public:
    Sprite* sprite;                            // sprite do míssil
    Vector speed;                               // velocidade do míssil

public:
    Weapon(Player* player, Image* img);    // construtor
    ~Weapon();                                 // destrutor
    void OnCollision(Object* obj);     // resolução da colisão
    float scale;
    float dy = 0;
    float velY;                        // velocidade vertical  

    void Update();                              // atualização
    void Draw();                                // desenho
};

// ------------------------------------------------------------------------------

#endif