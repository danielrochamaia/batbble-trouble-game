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

#include "Ball.h"
#include "Level1.h"
#include "GravityGuy.h"

// ---------------------------------------------------------------------------------
double posBX = 0;
double posBY = 0;

int speedX = 20;
int speedY = 20;

Ball::Ball(Image* img, float velocidade, uint tipo)
{
    // tamanho do bloco � 60x24
    /*BBox(new Rect(-30, -12, 29, 11));*/

    // sprite do bloco
    sprite = new Sprite(img);

    speed.Rotate(45.0);
    speed.Scale(400.0);

    // move para posi��o
    MoveTo(window->CenterX(), window->CenterY());

    // velocidades iniciais
    vel = velocidade;
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
    //Translate(velX * gameTime, velY * gameTime);

    Vector gravity{ 270.0f, 200.0f * gameTime };

    // adiciona gravidade ao vetor velocidade
    speed.Add(gravity);

    Translate(speed.XComponent() * gameTime, -speed.YComponent() * gameTime);

    // Faz a bola quicar
    if (X() < 0 || X() > window->Width() || Y() < 0 || Y() > window->Height() - 73)
    {
            MoveTo(x, window->Height() - 73);
            speed.Rotate(90.0);
            Translate(speed.XComponent() * gameTime, speed.YComponent() * gameTime);
    }
}

void Ball::OnCollision(Object* obj)
{
    //if (obj - Type() == Weapon) {

   // }

    // bola colidiu com o player
    if (obj->Type() == CIMA)
    {
        MoveTo(x, y+1);
        velY = -velY;

    }
    // bola colidiu com o player
    if (obj->Type() == BAIXO)
    {
        MoveTo(x, y - 1);
        velY = -velY;

    }
    // bola colidiu com o player
    if (obj->Type() == ESQUERDA)
    {
        MoveTo(x+1, y);
        velX = -velX;
    }
    // bola colidiu com o player
    if (obj->Type() == DIREITA)
    {
        MoveTo(x-1, y);
        velX = -velX;
    }

}
// ---------------------------------------------------------------------------------
