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

#include "Ball.h"
#include "Level1.h"
#include "Player.h"
#include "GravityGuy.h"

// ---------------------------------------------------------------------------------
double posBX = 0;
double posBY = 0;

int speedX = 20;
int speedY = 20;

Ball::Ball(Image* img, float speed, uint tipo)
{
    // tamanho do bloco é 60x24
    /*BBox(new Rect(-30, -12, 29, 11));*/

    // sprite do bloco
    sprite = new Sprite(img);

    // velocidades iniciais
    vel = speed;
    velX = 300;
    velY = -300;

    // tipo do objeto
    type = tipo;
}

// ---------------------------------------------------------------------------------

Ball::~Ball()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Ball::Update()
{
    // objeto caminha no eixo x
    Translate(velX * gameTime, velY * gameTime);

}

void Ball::OnCollision(Object* obj)
{

    // bola colidiu com o player
    if (obj->Type() == CIMA)
    {
        velY = -velY;

    }
    // bola colidiu com o player
    if (obj->Type() == BAIXO)
    {
        velY = -velY;

    }
    // bola colidiu com o player
    if (obj->Type() == ESQUERDA)
    {
        velX = -velX;
    }
    // bola colidiu com o player
    if (obj->Type() == DIREITA)
    {
        velX = -velX;
    }

}
// ---------------------------------------------------------------------------------
