#include <iostream>
#include "Wizard.hpp"
#include "Firecat.hpp"
#include "Banshee.hpp"
#include "CatThug.hpp"
#include "Tavern.hpp"
#include "Battle.hpp"

int main() {
    // Create a wizard
    Wizard* merlin = new Wizard("Merlin", HUMANOID, DEATH, 100, 1, 50, false);

    // Create enemies
    Firecat* firecat = new Firecat("Blazer", ANIMAL, STORM, 1, 30, 25, 0, Firecat::RED, 60, 1);
    Banshee* banshee = new Banshee("Wailer", UNDEAD, DEATH, 1, 40, 13, 1, Banshee::BLUE, 4, 0);
    CatThug* thug = new CatThug("Whiskers", HUMANOID, MYTH, 1, 25, 60);

    // Create tavern and add enemies
    Tavern tavern;
    tavern.enterTavern(firecat);
    tavern.enterTavern(banshee);
    tavern.enterTavern(thug);

    // Display the tavern contents before battle
    std::cout << "\n--- Initial Tavern Status ---\n";
    tavern.displayCreatures();

    // Create battle object
    Battle battle(merlin, tavern);

    // Simulate the full battle (interactive)
    std::cout << "\n--- Beginning Battle Simulation ---\n";
    battle.simulate();

    // Clean up
    delete merlin;
    delete firecat;
    delete banshee;
    delete thug;

    return 0;
}
