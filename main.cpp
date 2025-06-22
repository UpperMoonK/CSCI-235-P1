#include "Tavern.hpp"
#include "Creature.hpp"
#include "CatThug.hpp"
#include "Banshee.hpp"
#include "Firecat.hpp"
#include <iostream>
#include <cassert>
#include <iomanip>


void runTavernTests() {
    Tavern tavern;
    assert(tavern.getLevelSum() == 0);
    assert(tavern.getCreatureCount() == 0);
    assert(tavern.getHostileCount() == 0);

    Creature* c1 = new Creature("Goblin", MAGICAL, FIRE, 5, 5, true);
    Creature* c2 = new Creature("Skeleton", UNDEAD, DEATH, 8, 3, true);
    Creature* c3 = new Creature("Wolf", ANIMAL, LIFE, 4, 8, false);
    Creature* c4 = new Creature("Wizard", HUMANOID, STORM, 6, 3, false);
    Creature* c5 = new Creature("Spirit", UNKNOWN, NONE, 10, 7, true);

    // Test enterTavern
    assert(tavern.enterTavern(c1) == true);
    std::cout << "Entered: " << c1->getLevel() << " -> Success: " << tavern.enterTavern(c1) << std::endl;
    assert(tavern.enterTavern(c2) == true);
    std::cout << "Entered: " << c2->getLevel() << " -> Success: " << tavern.enterTavern(c2) << std::endl;
    assert(tavern.enterTavern(c3) == true);
    std::cout << "Entered: " << c3->getLevel() << " -> Success: " << tavern.enterTavern(c3) << std::endl;
    assert(tavern.enterTavern(c4) == true);
    std::cout << "Entered: " << c4->getLevel() << " -> Success: " << tavern.enterTavern(c4) << std::endl;
    assert(tavern.enterTavern(c5) == true);
    std::cout << "Entered: " << c5->getLevel() << " -> Success: " << tavern.enterTavern(c5) << std::endl;
    assert(tavern.enterTavern(c1) == false); // duplicate

    // Test counts
    std::cout << "Level Sum: " << tavern.getLevelSum() << std::endl;
    assert(tavern.getLevelSum() == 26);
    assert(tavern.getCreatureCount() == 5);
    assert(tavern.getHostileCount() == 3);

    // Test tallyCategory
    assert(tavern.tallyCategory("MAGICAL") == 1);
    assert(tavern.tallyCategory("UNDEAD") == 1);
    assert(tavern.tallyCategory("ANIMAL") == 1);
    assert(tavern.tallyCategory("HUMANOID") == 1);
    assert(tavern.tallyCategory("UNKNOWN") == 1);
    assert(tavern.tallyCategory("INVALID") == 0);

    // Test tallySchool
    assert(tavern.tallySchool("FIRE") == 1);
    assert(tavern.tallySchool("DEATH") == 1);
    assert(tavern.tallySchool("LIFE") == 1);
    assert(tavern.tallySchool("STORM") == 1);
    assert(tavern.tallySchool("NONE") == 1);
    assert(tavern.tallySchool("MYTH") == 0);

    // Test hostile percentage
    double expected = (3.0 / 5.0) * 100.0;
    double result = tavern.calculateHostilePercentage();
    assert(std::abs(result - expected) < 0.01);

    // Test release below level
    int removed = tavern.releaseCreaturesBelowLevel(5);
    assert(removed == 2); // Skeleton(3), Wolf(4)
    assert(tavern.getCreatureCount() == 3);
    assert(tavern.getLevelSum() == 20);

    // Test release of category
    removed = tavern.releaseCreaturesOfCategory("MAGICAL");
    assert(removed == 1); // Goblin
    assert(tavern.getCreatureCount() == 2);

    // Test invalid category = remove all
    removed = tavern.releaseCreaturesOfCategory("INVALID");
    assert(removed == 2);
    assert(tavern.getCreatureCount() == 0);

    // Refill tavern for school removal test
    tavern.enterTavern(c1);
    tavern.enterTavern(c2);
    tavern.enterTavern(c3);
    tavern.enterTavern(c4);
    tavern.enterTavern(c5);

    removed = tavern.releaseCreaturesOfSchool("FIRE");
    assert(removed == 1);
    removed = tavern.releaseCreaturesOfSchool("INVALID");
    assert(removed == 4); // all remaining

    // Test exitTavern
    tavern.enterTavern(c1);
    bool exited = tavern.exitTavern(c1);
    assert(exited == true);
    exited = tavern.exitTavern(c1);
    assert(exited == false); // already gone

    // Test report and display manually
    std::cout << "\n=== Tavern Report ===\n";
    tavern.enterTavern(c1);
    tavern.enterTavern(c2);
    tavern.tavernReport();

    std::cout << "\n=== Creature Display ===\n";
    tavern.displayCreatures();

    // Clean up
    delete c1;
    delete c2;
    delete c3;
    delete c4;
    delete c5;

    std::cout << "\nAll Tavern tests passed!\n";
}

void runTavernTests2() {
    Tavern tavern;

    // Create derived creatures with explicit values
    Creature* firecat = new Firecat("Blaze", MAGICAL, FIRE, 7, 3, true, Firecat::ORANGE, 25, true);      // category, school, level, age, hostile
    Creature* thug = new CatThug("Whiskers", HUMANOID, STORM, 5, 2, false, {}, CatThug::MOB_BOSS, false);
    Creature* banshee = new Banshee("Wail", UNDEAD, DEATH, 6, 10, true, Banshee::BLUE, 10, true);

    // Add to tavern
    assert(tavern.enterTavern(firecat));
    assert(tavern.enterTavern(thug));
    assert(tavern.enterTavern(banshee));

    // Level sum
    assert(tavern.getLevelSum() == 15);

    // Creature count
    assert(tavern.getCreatureCount() == 3);

    // Hostile count
    assert(tavern.getHostileCount() == 2);  // Firecat and Banshee are hostile

    // Category tally
    assert(tavern.tallyCategory("MAGICAL") == 1);
    assert(tavern.tallyCategory("HUMANOID") == 1);
    assert(tavern.tallyCategory("UNDEAD") == 1);

    // School tally
    assert(tavern.tallySchool("FIRE") == 1);
    assert(tavern.tallySchool("STORM") == 1);
    assert(tavern.tallySchool("DEATH") == 1);

    // Hostile %
    std::cout << "Hostile %: " << tavern.calculateHostilePercentage() << std::endl;
    assert(std::abs(tavern.calculateHostilePercentage() - 66.67) < 0.01);

    // Display test
    std::cout << "\nDisplaying creatures:\n";
    tavern.displayCreatures();

    // Clean up
    delete firecat;
    delete thug;
    delete banshee;
}

int main() {
    runTavernTests2();
    return 0;
}