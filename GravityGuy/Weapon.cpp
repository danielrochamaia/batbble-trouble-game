#include "Weapon.h"
#include "Level1.h"
#include "Level2.h"
#include "GravityGuy.h"
#include "Ball.h"

Weapon::Weapon(Player* player, Image* img, uint tipo)
{
    // inicializa sprite
    sprite = new Sprite(img);
    velY = -800;
    scale = 1;

    jogador = player;
    // inicializa vetor velocidade
    //speed.Rotate(90);
    //speed.Scale(500);

    // usa mesma rota��o do avi�o
    //RotateTo(player->Rotation());

    MoveTo(player->X(), 800.00);

    BBox(new Rect(-10,-400 , 10, 400));

    type = tipo;
}

Weapon::~Weapon()
{
	delete sprite;
}

void Weapon::OnCollision(Object* obj)
{
    //if (obj - Type() == Weapon) {

   // }

}

void Weapon::Update()
{
    if (jogador->disparoPlayer == false) {
        Level1::scene->Delete();
    }

    // --- aumente a escala de acordo com a dist�ncia percorrida ---
    //if (y > 400) {
    //    Translate(0, velY * gameTime);
    //}
    Translate(0, velY * gameTime);

    //// destr�i ao sair da janela
    if (y < 0) {
        jogador->disparoPlayer = false;
    }
}

void Weapon::Draw()
{
	sprite->Draw(x, y, 0, scale, 0);	
}
