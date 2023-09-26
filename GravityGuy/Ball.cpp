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


Ball::Ball(Image* img, uint tipo)
{
    raio = 73.0;
    // tipo do objeto
    type = tipo;

    sprite = new Sprite(img);

    if (type == BALLGG1)
    {
        // sprite do bloco

        speed.RotateTo(45.0f);
        speed.ScaleTo(200.0f);

        // move para posição

        BBox(new Circle(img->Height() / 2.0f));

    }

    if (type == BALLGG2)
    {
        // sprite do bloco

        speed.RotateTo(135.0f);
        speed.ScaleTo(200.0f);

        // move para posição

        BBox(new Circle(img->Height() / 2.0f));

    }

    if (type == BALLG1)
    {
        // sprite do bloco

        speed.RotateTo(45.0f);
        speed.ScaleTo(200.0f);
        Scale(0.5f);

        // move para posição

        BBox(new Circle(img->Height() / 2.0f));

        raio = 36.5f;
    }

    if (type == BALLG2)
    {
        // sprite do bloco

        speed.RotateTo(135.0f);
        speed.ScaleTo(200.0f);
        Scale(0.5f);
        //this->Scale(obj->Scale() * 0.5f);

        // move para posição
        //MoveTo(obj->X(), obj->Y() - 25);

        BBox(new Circle(img->Height() / 2.0f));

        raio = 36.5f;
    }

    if (type == BALLM1)
    {
        // sprite do bloco

        speed.RotateTo(45.0f);
        speed.ScaleTo(200.0f);
        Scale(0.25f);

        // move para posição
        //MoveTo(obj->X(), obj->Y());
        //this->Scale(obj->Scale() * 0.5f);

        BBox(new Circle(img->Height() / 2.0f));

        raio = 18.25f;
    }

    if (type == BALLM2)
    {
        // sprite do bloco

        speed.RotateTo(135.0f);
        speed.ScaleTo(200.0f);
        Scale(0.25f);

        // move para posição
        //MoveTo(obj->X(), obj->Y());
       // this->Scale(obj->Scale() * 0.5f);

        BBox(new Circle(img->Height() / 2.0f));

        raio = 18.25f;

    }

    if (type == BALLP1)
    {
        // sprite do bloco
        
        speed.RotateTo(45.0f);
        speed.ScaleTo(200.0f);
        //this->Scale(obj->Scale() * 0.5f);
        Scale(0.125f);

        // move para posição
        //MoveTo(obj->X(), obj->Y());

        BBox(new Circle(img->Height() / 2.0f));

        raio = 9.125f;
    }

    if (type == BALLP2)
    {
        // sprite do bloco

        speed.RotateTo(135.0f);
        speed.ScaleTo(200.0f);
        //this->Scale(obj->Scale() * 0.5f);
        Scale(0.125f);

        // move para posição
        //MoveTo(obj->X(), obj->Y());

        BBox(new Circle(img->Height() / 2.0f));

        raio = 9.125f;
    }


}

// ---------------------------------------------------------------------------------

Ball::~Ball()
{
    delete sprite;   
}

// ---------------------------------------------------------------------------------

void Ball::Update()
{

    if (state == 1) {

        if (type == BALLGG1 || type == BALLGG2) 
        {
            Ball* ball = new Ball(Level1::redBall, BALLG1);
            ball->MoveTo(x, y - 25);
            Level1::scene->Add(ball, STATIC);
            ball = new Ball(Level1::redBall, BALLG2);
            ball->MoveTo(x, y - 25);
            Level1::scene->Add(ball, STATIC);
            Level1::scene->Delete();
        }

        if (type == BALLG1 || type == BALLG2)
        {
            Ball* ball = new Ball(Level1::redBall, BALLM1);
            ball->MoveTo(x, y - 25);
            Level1::scene->Add(ball, STATIC);
            ball = new Ball(Level1::redBall, BALLM2);
            ball->MoveTo(x, y - 25);
            Level1::scene->Add(ball, STATIC);
            Level1::scene->Delete();
        }

        if (type == BALLM1 || type == BALLM2)
        {
            Ball* ball = new Ball(Level1::redBall, BALLP1);
            ball->MoveTo(x, y - 25);
            Level1::scene->Add(ball, STATIC);
            ball = new Ball(Level1::redBall, BALLP2);
            ball->MoveTo(x, y - 25);
            Level1::scene->Add(ball, STATIC);
            Level1::scene->Delete();
        }

        if (type == BALLP1 || type == BALLP2)
        {
            Level1::scene->Delete();
        }
    }

    // Verifica em qual parede a bola bateu e trata a relação de forças
    if (X() <= raio)
    {
        // Tratamento baseado se a bola veio por cima ou por baixo na parede da esquerda
        if (speed.Angle() <= 180.0f)
        {
            MoveTo(raio, y);
            speed.RotateTo(180.0f - speed.Angle());
            Vector gravity{ 270.0f, 200.0f * gameTime };
            // adiciona gravidade ao vetor velocidade
            speed.Add(gravity);
            Translate(speed.XComponent() * gameTime, speed.YComponent() * gameTime);
        }
        else
        {
            MoveTo(raio, y);
            speed.RotateTo(540.0f - speed.Angle());
            Vector gravity{ 270.0f, 200.0f * gameTime };
            // adiciona gravidade ao vetor velocidade
            speed.Add(gravity);
            Translate(speed.XComponent() * gameTime, speed.YComponent() * gameTime);
        }
    }
    else if(X() >= window->Width() - raio)
    {
        // Tratamento baseado se a bola veio por cima ou por baixo na parede da direita
        if (speed.Angle() <= 90.0f) 
        {
            MoveTo(window->Width() - raio, y);
            speed.RotateTo(180.0f - speed.Angle());
            Vector gravity{ 270.0f, 200.0f * gameTime };
            // adiciona gravidade ao vetor velocidade
            speed.Add(gravity);
            Translate(speed.XComponent() * gameTime, speed.YComponent() * gameTime);
        }
        else 
        {
            MoveTo(window->Width() - raio, y);
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
        MoveTo(x, window->Height() - raio);
        speed.RotateTo(360.0f - speed.Angle());
        Vector gravity{ 270.0f, 200.0f * gameTime };

        // adiciona gravidade ao vetor velocidade
        speed.Add(gravity);
        Translate(speed.XComponent() * gameTime, speed.YComponent() * gameTime);
    }
    else if(Y() >= window->Height() - raio)
    {
        // Tratamento da bola batendo no chão
         MoveTo(x, window->Height() - raio - 5);
         speed.RotateTo(360.0f - speed.Angle());
         Vector gravity{ 270.0f, 200.0f * gameTime };

         // adiciona gravidade ao vetor velocidade
         speed.Add(gravity);
         Translate(speed.XComponent() * gameTime, speed.YComponent() * gameTime);

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
    if (obj->Type() == ARPAO1) {
        state = 1;
        GravityGuy::player1->disparoPlayer = false;
        GravityGuy::pontos += 250;

    }

    if (obj->Type() == ARPAO2) {
        state = 1;
        GravityGuy::player2->disparoPlayer = false;
        GravityGuy::pontos += 250;

    }

    if (obj->Type() == PLAYER)
    {
        Level1::gameover = true;
    }
}
// ---------------------------------------------------------------------------------
