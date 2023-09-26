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
#include "Level2.h"
#include "Home.h"
#include "Engine.h"
#include "Enums.h"

// ---------------------------------------------------------------------------------
const double Player::PIXEL_PER_METER = 50;

Player::Player(string src)
{
    tileset = new TileSet(src, 50, 101, 3, 12);
    anim = new Animation(tileset, 0.120f, true);
    velx = 6;
    type = PLAYER;
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
    MoveTo(300, 670, Layer::FRONT);
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

    #pragma region DisparoArma
    if (window->KeyPress(VK_SPACE)) {
        
        Weapon* disparo = new Weapon(GravityGuy::player1, weapon, ARPAO1);

        if (nivelAtual == 1 && GravityGuy::player1->disparoPlayer == false) {
            
            Level1::scene->Add(disparo, MOVING);
            GravityGuy::player1->disparoPlayer = true;
        }

        if (nivelAtual == 2 && disparoPlayer == false) {
           
            Level2::scene->Add(disparo, MOVING);
            GravityGuy::player1->disparoPlayer = true;
        }
    }

    if (window->KeyPress('Q')) {

        Weapon* disparo = new Weapon(GravityGuy::player2, weapon, ARPAO2);

        if (nivelAtual == 1 && GravityGuy::player2->disparoPlayer == false) {

            Level1::scene->Add(disparo, MOVING);
            GravityGuy::player2->disparoPlayer = true;
        }

        if (nivelAtual == 2 && GravityGuy::player2->disparoPlayer == false) {

            Level2::scene->Add(disparo, MOVING);
            GravityGuy::player2->disparoPlayer = true;
        }
    }
    #pragma endregion


    #pragma region Movimentação Player 1
    if (window->KeyDown(VK_LEFT)) {
        GravityGuy::player1->state = RUN;
        GravityGuy::player1->isMovingLeft = true;
        GravityGuy::player1->Translate(-velx * PIXEL_PER_METER * gameTime, 0);
    }
    if (window->KeyDown(VK_RIGHT)) {
        GravityGuy::player1->state = RUN;
        GravityGuy::player1->isMovingLeft = false;
        GravityGuy::player1->Translate(velx * PIXEL_PER_METER * gameTime, 0);
    }

    if (GravityGuy::player1->state % 2 == 0) {
        if (GravityGuy::player1->isMovingLeft)
            GravityGuy::player1->state += 1;
    }
    else if (!GravityGuy::player1->isMovingLeft) {
        GravityGuy::player1->state -= 1;
    }

    GravityGuy::player1->anim->Select(GravityGuy::player1->state);

    if (!GravityGuy::player1->isClimbing) {
        if (GravityGuy::player1->isMovingLeft)
            GravityGuy::player1->state = IDLELEFT;
        else
            GravityGuy::player1->state = IDLE;
        GravityGuy::player1->anim->NextFrame();
    }
    #pragma endregion

    #pragma region Movimentação Player 2
    if (GravityGuy::twoPlayers) {
        if (window->KeyDown('A')) {
            GravityGuy::player2->state = RUN;
            GravityGuy::player2->isMovingLeft = true;
            GravityGuy::player2->Translate(-velx * PIXEL_PER_METER * gameTime, 0);
        }
        if (window->KeyDown('D')) {
            GravityGuy::player2->state = RUN;
            GravityGuy::player2->isMovingLeft = false;
            GravityGuy::player2->Translate(velx * PIXEL_PER_METER * gameTime, 0);
        }

        if (GravityGuy::player2->state % 2 == 0) {
            if (GravityGuy::player2->isMovingLeft)
                GravityGuy::player2->state += 1;
        }
        else if (!GravityGuy::player2->isMovingLeft) {
            GravityGuy::player2->state -= 1;
        }

        GravityGuy::player2->anim->Select(GravityGuy::player2->state);

        if (!GravityGuy::player2->isClimbing) {
            if (GravityGuy::player2->isMovingLeft)
                GravityGuy::player2->state = IDLELEFT;
            else
                GravityGuy::player2->state = IDLE;
            GravityGuy::player2->anim->NextFrame();
        }
    }
    #pragma endregion

}

void Player::Reset()
{
    // volta ao estado inicial
    GravityGuy::player1->MoveTo(300, 670, Layer::FRONT);
    if (GravityGuy::twoPlayers) {
        GravityGuy::player2->MoveTo(GravityGuy::player1->X() + 400, GravityGuy::player1->Y());
    }
}

void Player::Draw()
{
    anim->Draw(x, y, Layer::MIDDLE, scale, rotation);
}
// ---------------------------------------------------------------------------------