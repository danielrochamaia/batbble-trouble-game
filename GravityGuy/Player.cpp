/**********************************************************************************
// Player (Código Fonte)
// 
// Criação:     20 Abr 2012
// Atualização: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Define uma classe para o jogador 
//
**********************************************************************************/

#include "Player.h"
#include "GravityGuy.h"
#include "Weapon.h"
#include "Level1.h"

// ---------------------------------------------------------------------------------
const double Player::PIXEL_PER_METER = 50;
Player::Player()
{
    tileset = new TileSet("Resources/bat-flow-2.png", 50, 101, 3, 12);
    anim = new Animation(tileset, 0.120f, true);
    velx = 6;
    // sequências de animação do player

    uint seqIdle[1] = { 4 };
    uint seqIdleLeft[1] = { 4 };
    uint seqRun[3] = { 6,7,8 };
    uint seqRunLeft[3] = { 9,10,11 };

    anim->Add(IDLE, seqIdle, 1);
    anim->Add(IDLELEFT, seqIdleLeft, 1);
    anim->Add(RUN, seqRun, 3);
    anim->Add(RUNLEFT, seqRunLeft, 3);

    state = IDLE;
    weapon = new Image("Resources/hook-weapon.png");
    // cria bounding box
    BBox(new Rect(
        -1.0f * tileset->TileWidth() / 2.0f,
        -1.0f * tileset->TileHeight() / 2.0f,
        tileset->TileWidth() / 2.0f,
        tileset->TileHeight() / 2.0f));
    
    // inicializa estado do player
    gravity = RUN;  
    level = 0;

    // posição inicial
    MoveTo(window->CenterX(), 670, Layer::FRONT);
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete anim;
    delete tileset;
    delete weapon;
}

// ---------------------------------------------------------------------------------


// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    //if (obj->Type() == FINISH)
    //{
    //    // chegou ao final do nível
    //    level++;
    //}
    //else
    //{
    //    // mantém personagem em cima da plataforma
    //    if (gravity == FRENTE)
    //        MoveTo(window->CenterX(), obj->Y() - 32);
    //    else
    //        MoveTo(window->CenterX(), obj->Y() + 32);
    //}

    // ----------------------------------------------------------
    // Processa teclas pressionadas
    // ----------------------------------------------------------
    // jogador só pode alterar a gravidade enquanto estiver
    // em cima de uma plataforma, não é possível a mudança no ar
    // ----------------------------------------------------------

    //if (window->KeyPress(VK_SPACE))
    //{
    //    gravity = !gravity;

    //    // toca efeito sonoro
    //    GravityGuy::audio->Play(TRANSITION);

    //    // tira player da plataforma para evitar 
    //    // detecção de colisão no quadro seguinte
    //    if (gravity == FRENTE)
    //        Translate(0, 12);
    //    else
    //        Translate(0 , -12);
    //}
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    hasZeroGravity = false;

    if (window->KeyPress(VK_SPACE)) {
        Level1::scene->Add(new Weapon(this, weapon), STATIC);
    }

    if (window->KeyDown('A') || window->KeyDown(VK_LEFT)) {
        state = RUN;
        isMovingLeft = true;
        Translate(-velx * PIXEL_PER_METER * gameTime, 0);
    }
    if (window->KeyDown('D') || window->KeyDown(VK_RIGHT)) {
        state = RUN;
        isMovingLeft = false;
        Translate(velx * PIXEL_PER_METER * gameTime, 0);
    }

    if (state % 2 == 0) {
        if (isMovingLeft)
            ++state;
    }
    else if (!isMovingLeft) {
        --state;
    }

    anim->Select(state);

    if (!isClimbing) {
        if (isMovingLeft)
            state = IDLELEFT;
        else
            state = IDLE;
        anim->NextFrame();
    }
}

void Player::Draw()
{
    anim->Draw(x, y, Layer::MIDDLE, scale, rotation);
}
// ---------------------------------------------------------------------------------