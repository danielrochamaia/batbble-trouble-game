/**********************************************************************************
// Painel (Arquivo de Cabeçalho)
//
// Criação:     20 Ago 2023
// Atualização: 20 Ago 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Painel de pontos do jogo Pokemon Run
//
**********************************************************************************/

#ifndef _PAINEL_H_
#define _PAINEL_H_

#include "Animation.h"
#include "Object.h"
#include <iomanip>
#include <sstream>
#include <string>
using std::setfill;
using std::setw;
using std::string;
using std::stringstream;
using std::to_string;

class Painel : public Object
{
private:

    TileSet* numbers = nullptr;
    Animation* anim = nullptr;
    float time = 0.0f;
    uint score = 50;
    string scoreTxt = "50";

public:
    Painel();
    ~Painel();

    void SubScore(uint s);
    uint Score();

    void Update();
    void Draw();
};

#endif