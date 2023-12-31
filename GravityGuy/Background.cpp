/**********************************************************************************
// Background (C�digo Fonte)
// 
// Cria��o:     21 Abr 2012
// Atualiza��o: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Plano de fundo do jogo
//
**********************************************************************************/

#include "Background.h"

// ---------------------------------------------------------------------------------

Background::Background(Color tint, string source) : color(tint)
{
    MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);
    xF = xB = x;

    // carrega imagens
    imgB = new Image(source);
    backgB1 = new Sprite(imgB);
    // cria sprites do plano de fundo
    //sky     = new Sprite("Resources/Sky.png");    
    //backgF1 = new Sprite(imgF);
    //backgF2 = new Sprite(imgF);
    //backgB1 = new Sprite(imgB);
    //backgB2 = new Sprite(imgB);
}

// ---------------------------------------------------------------------------------

Background::~Background()
{
    //delete imgF;
    delete imgB;    
    //delete backgF1;
    //delete backgF2;
    //delete backgB1;
    //delete backgB2;
    //delete sky;
}

// -------------------------------------------------------------------------------

void Background::Update()
{
    // move sprites com velocidades diferentes
}

// -------------------------------------------------------------------------------

void Background::Draw()
{
    //// desenha pano de fundo
    //sky->Draw(window->CenterX(), window->CenterY(), Layer::BACK, 1.0f, 0.0f, color);

    //// desenha pr�dios mais distantes
    //backgB1->Draw(xB, y, Layer::LOWER, 1.0f, 0.0f, color);
    //backgB2->Draw(xB + imgB->Width(), y, Layer::LOWER, 1.0f, 0.0f, color);
    //
    //// traz pano de fundo de volta para dentro da tela
    //if (xB + imgB->Width()/2.0f < 0)
    //    xB += imgB->Width();

    //// desenha pr�dios mais pr�ximos
    //backgF1->Draw(xF, y, Layer::MIDDLE, 1.0f, 0.0f, color);
    //backgF2->Draw(xF + imgF->Width(), window->Height()/2.0f, Layer::MIDDLE, 1.0f, 0.0f, color);

    //// traz pano de fundo de volta para dentro da tela
    //if (xF + imgF->Width()/2.0f < 0)
    //    xF += imgF->Width();
    backgB1->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// -------------------------------------------------------------------------------
