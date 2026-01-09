#include "header.h"
#include <cstdlib>

void setupPokemon(Pokemon& p, string name, int hp) {
    p.name = name;
    p.hp = hp;
    p.maxHp = hp;
    p.movesHead = nullptr;
}

void addMove(Pokemon& p, string name, int min, int max, float critM) {
    MoveNode* newNode = new MoveNode;
    newNode->name = name;
    newNode->minDmg = min;
    newNode->maxDmg = max;
    newNode->critMult = critM;
    newNode->next = nullptr;

    if (p.movesHead == nullptr) {
        p.movesHead = newNode;
    } else {
        MoveNode* temp = p.movesHead;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

MoveNode* getMove(Pokemon& p, int index) {
    MoveNode* temp = p.movesHead;
    int counter = 1;
    while (temp != nullptr) {
        if (counter == index) return temp;
        temp = temp->next;
        counter++;
    }
    return nullptr;
}

int calculateDamage(MoveNode* move) {
    int dmg = rand() % (move->maxDmg - move->minDmg + 1) + move->minDmg;
    if ((rand() % 16) == 0) {
        dmg = static_cast<int>(dmg * move->critMult);
        cout << ">>> CRITICAL HIT! <<<" << endl;
    }
    return dmg;
}

void printBattleStatus(Pokemon& p1, Pokemon& p2) {
    int p1_display_hp = p1.hp;
    int p2_display_hp = p2.hp;

    if (p1_display_hp < 0) p1_display_hp = 0;
    if (p2_display_hp < 0) p2_display_hp = 0;

    cout << "\n----------------------------------------" << endl;
    cout << "CHAMPION CYNTHIA: " << p2.name << " [" << p2_display_hp << "/" << p2.maxHp << "]" << endl;
    cout << "PLAYER: " << p1.name << " [" << p1_display_hp << "/" << p1.maxHp << "]" << endl;
    cout << "----------------------------------------" << endl;
}

void cleanUpMemory(Pokemon& p) {
    MoveNode* current = p.movesHead;
    while (current != nullptr) {
        MoveNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    p.movesHead = nullptr;
}

