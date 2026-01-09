#include <iostream>
#include <ctime>
#include <cstdlib>
#include "header.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // 1. SETUP
    Pokemon player;
    setupPokemon(player, "GENGAR", 1000);
    addMove(player, "Shadow Ball", 68, 80, 2.0f);
    addMove(player, "Sludge Bomb", 77, 90, 2.0f);
    addMove(player, "Dark Pulse", 68, 80, 2.0f);
    addMove(player, "Psychic", 77, 80, 2.0f);

    Pokemon enemy;
    setupPokemon(enemy, "GARCHOMP", 1100);
    addMove(enemy, "Dragon Rush", 85, 100, 2.0f);
    addMove(enemy, "Earthquake", 85, 100, 2.0f);
    addMove(enemy, "Brick Break", 64, 75, 2.0f);
    addMove(enemy, "Poison Jab", 68, 80, 2.0f);

    cout << "You are challenged by Champion Cynthia!" << endl;
    cout << "Champion Cynthia sent out " << enemy.name << "!" << endl;
    cout << "Go! " << player.name << "!" << endl;

    // 2. BATTLE LOOP
    while (player.hp > 0 && enemy.hp > 0) {
        printBattleStatus(player, enemy);

        // --- PLAYER TURN ---
        cout << "\nSelect a Move:" << endl;
        MoveNode* temp = player.movesHead;
        for (int i = 1; temp != nullptr; i++) {
            cout << i << ". " << temp->name << endl;
            temp = temp->next;
        }

        int choice;
        cout << "> ";
        cin >> choice;

        MoveNode* selectedMove = getMove(player, choice);
        if (selectedMove != nullptr) {
            cout << "\n" << player.name << " used " << selectedMove->name << "!" << endl;
            int dmg = calculateDamage(selectedMove);
            enemy.hp -= dmg;
            cout << "Dealt " << dmg << " damage!" << endl;
        }

        // Check if Enemy fainted
        if (enemy.hp <= 0) {
            cout << "The foe's " << enemy.name << " fainted!" << endl;
            break;
        }

        // --- ENEMY TURN ---
        int aiChoice = (rand() % 4) + 1;
        MoveNode* aiMove = getMove(enemy, aiChoice);
        if (aiMove != nullptr) {
            cout << "\n" << enemy.name << " used " << aiMove->name << "!" << endl;
            int aiDmg = calculateDamage(aiMove);
            player.hp -= aiDmg;
            cout << player.name << " took " << aiDmg << " damage!" << endl;
        }

        // Check if Player fainted
        if (player.hp <= 0) {
            cout << player.name << " fainted!" << endl;
        }
    }

    // 3. RESULTS
    if (player.hp > 0) {
        cout << "\nChampion Cynthia: 'You have a truly wonderful battle style.'" << endl;
        cout << "VICTORY!" << endl;
    } else {
        cout << "\nDEFEAT... You scurried back to a Pokemon Center." << endl;
    }

    cleanUpMemory(player);
    cleanUpMemory(enemy);
    return 0;
}
