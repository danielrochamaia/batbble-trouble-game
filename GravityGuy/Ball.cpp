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
#include "GravityGuy.h"
#include "Enums.h"

// ---------------------------------------------------------------------------------

Image* Ball::image = nullptr;


Ball::Ball(Image* img, uint tipo)
{
    // sprite do bloco
    sprite = new Sprite(img);

    // imagem guardada

    image = img;

    speed.RotateTo(45.0);
    speed.ScaleTo(200.0f);

    // move para posição
    MoveTo(window->CenterX(), window->CenterY());

    BBox(new Circle(img->Height() / 2.0f));

    // tipo do objeto
    type = BOLA;
}

// ---------------------------------------------------------------------------------

Ball::Ball(Image* img, Object* obj , uint tipo)
{

    // tipo do objeto
    type = tipo;

    sprite = new Sprite(img);

    image = img;


    if (obj->Type() == BALLGG1)
    {
        // sprite do bloco

        speed.RotateTo(45.0f);
        speed.ScaleTo(200.0f);

        // move para posição
        MoveTo(obj->X(), obj->Y());

        BBox(new Circle(img->Height() / 2.0f));
    }

    if (obj->Type() == BALLGG2)
    {
        // sprite do bloco

        speed.RotateTo(135.0f);
        speed.ScaleTo(200.0f);

        // move para posição
        MoveTo(obj->X(), obj->Y());
        BBox(new Circle(72.0f));
    }

    if (obj->Type() == BALLG1)
    {
        // sprite do bloco

        speed.RotateTo(45.0f);
        speed.ScaleTo(200.0f);
        this->Scale(obj->Scale() * 0.5f);

        // move para posição
        MoveTo(obj->X(), obj->Y());

        BBox(new Circle(img->Height() / 4.0f));
    }

    if (obj->Type() == BALLG2)
    {
        // sprite do bloco

        speed.RotateTo(135.0f);
        speed.ScaleTo(200.0f);
        this->Scale(obj->Scale() * 0.5f);

        // move para posição
        MoveTo(obj->X(), obj->Y());

        BBox(new Circle(img->Height() / 4.0f));
    }

    if (obj->Type() == BALLM1)
    {
        // sprite do bloco

        speed.RotateTo(45.0f);
        speed.ScaleTo(200.0f);

        // move para posição
        MoveTo(obj->X(), obj->Y());
        this->Scale(obj->Scale() * 0.5f);

        BBox(new Circle(72.0f));
    }

    if (obj->Type() == BALLM2)
    {
        // sprite do bloco

        speed.RotateTo(135.0f);
        speed.ScaleTo(200.0f);

        // move para posição
        MoveTo(obj->X(), obj->Y());
        this->Scale(obj->Scale() * 0.5f);

        BBox(new Circle(72.0f));
    }

    if (obj->Type() == BALLP1)
    {
        // sprite do bloco
        
        speed.RotateTo(45.0f);
        speed.ScaleTo(200.0f);
        this->Scale(obj->Scale() * 0.5f);

        // move para posição
        MoveTo(obj->X(), obj->Y());

        BBox(new Circle(72.0f));
    }

    if (obj->Type() == BALLP2)
    {
        // sprite do bloco

        speed.RotateTo(135.0f);
        speed.ScaleTo(200.0f);
        this->Scale(obj->Scale() * 0.5f);

        // move para posição
        MoveTo(obj->X(), obj->Y());

        BBox(new Circle(72.0f));
    }



}

// ---------------------------------------------------------------------------------

Ball::~Ball()
{
    delete sprite;
    delete image;   
}

// ---------------------------------------------------------------------------------

void Ball::Update()
{

    // Verifica em qual parede a bola bateu e trata a relação de forças
    if (X() < 74.0f)
    {
        // Tratamento baseado se a bola veio por cima ou por baixo na parede da esquerda
        if (speed.Angle() <= 180.0f)
        {
            MoveTo(74.0f, y);
            speed.RotateTo(180.0f - speed.Angle());
            Vector gravity{ 270.0f, 200.0f * gameTime };
            // adiciona gravidade ao vetor velocidade
            speed.Add(gravity);
            Translate(speed.XComponent() * gameTime, speed.YComponent() * gameTime);
        }
        else
        {
            MoveTo(74.0f, y);
            speed.RotateTo(540.0f - speed.Angle());
            Vector gravity{ 270.0f, 200.0f * gameTime };
            // adiciona gravidade ao vetor velocidade
            speed.Add(gravity);
            Translate(speed.XComponent() * gameTime, speed.YComponent() * gameTime);
        }
    }
    else if(X() > window->Width() - 74.0f)
    {
        // Tratamento baseado se a bola veio por cima ou por baixo na parede da direita
        if (speed.Angle() <= 90.0f) 
        {
            MoveTo(window->Width() - 74.0f, y);
            speed.RotateTo(180.0f - speed.Angle());
            Vector gravity{ 270.0f, 200.0f * gameTime };
            // adiciona gravidade ao vetor velocidade
            speed.Add(gravity);
            Translate(speed.XComponent() * gameTime, speed.YComponent() * gameTime);
        }
        else 
        {
            MoveTo(window->Width() - 74.0f, y);
            speed.RotateTo(540.0f - speed.Angle());
            Vector gravity{ 270.0f, 200.0f * gameTime };
            // adiciona gravidade ao vetor velocidade
            speed.Add(gravity);
            Translate(speed.XComponent() * gameTime, speed.YComponent() * gameTime);
        }
    }
    else if(Y() < 0)
    {
        // SEM USO ATÉ O MOMENTO!
        MoveTo(x, window->Height() - 74.0f);
        speed.RotateTo(360.0f - speed.Angle());
        Vector gravity{ 270.0f, 200.0f * gameTime };

        // adiciona gravidade ao vetor velocidade
        speed.Add(gravity);
        Translate(speed.XComponent() * gameTime, speed.YComponent() * gameTime);
    }
    else if(Y() > window->Height() - 74.0f)
    {
        // Tratamento da bola batendo no chão
         MoveTo(x, window->Height() - 80.0f);
         speed.RotateTo(360.0f - speed.Angle());
         Vector gravity{ 270.0f, 200.0f * gameTime };

         // adiciona gravidade ao vetor velocidade
         speed.Add(gravity);
         Translate(speed.XComponent() * gameTime, speed.YComponent() * gameTime);

              Ball* ball = new Ball(image, this, BALLG1);
              Level1::scene->Add(ball, MOVING);
              ball = new Ball(image, this, BALLG2);
              Level1::scene->Add(ball, MOVING);
              Level1::scene->Delete();
    }
    else
    {
        Translate(speed.XComponent() * gameTime, -speed.YComponent() * gameTime);
        Vector gravity{ 270.0f, 200.0f * gameTime };

        // adiciona gravidade ao vetor velocidade
        speed.Add(gravity);
    }
}

void Ball::OnCollision(Object* obj)
{
    if (obj->Type() == PLAYER) {
       Ball* ball = new Ball(image, this, BALLG1);
       Level1::scene->Add(ball, MOVING);
       ball = new Ball(image, this, BALLG2);
       Level1::scene->Add(ball, MOVING);
       Level1::scene->Delete();
    }

    if (obj->Type() == PLAYER)
    {
        Level1::gameover = true;
    }

}
// ---------------------------------------------------------------------------------
