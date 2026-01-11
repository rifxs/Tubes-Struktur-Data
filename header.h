#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>

using namespace std;

struct MoveNode {
    string name;
    int minDmg;
    int maxDmg;
    float critMult;
    MoveNode* next;
};

struct Pokemon {
    string name;
    int hp;
    int maxHp;
    MoveNode* movesHead;
};

void setupPokemon(Pokemon& p, string name, int hp);
void addMove(Pokemon& p, string name, int min, int max, float critM);
MoveNode* getMove(Pokemon& p, int index);
int calculateDamage(MoveNode* move);
void printBattleStatus(Pokemon& p1, Pokemon& p2);

#endif


