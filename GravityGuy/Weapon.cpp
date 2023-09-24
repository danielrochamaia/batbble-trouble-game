#include "Weapon.h"
#include "Level1.h"
#include "Level2.h"
#include "GravityGuy.h"

Weapon::Weapon(Player* player, Image* img)
{
    // inicializa sprite
    sprite = new Sprite(img);
    velY = -300;
    scale = 1;


    // inicializa vetor velocidade
    //speed.Rotate(90);
    //speed.Scale(500);

    // usa mesma rotação do avião
    //RotateTo(player->Rotation());

    MoveTo(player->X(), 800.00);

    BBox(new Rect(-25.0,-400 , 25.0, 400));
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
    // --- aumente a escala de acordo com a distância percorrida ---
    if (y > 400) {
        Translate(0, velY * gameTime);
    }
}

void Weapon::Draw()
{
	sprite->Draw(x, y, 0, scale, 0);	
}
