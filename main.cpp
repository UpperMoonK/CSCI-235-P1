#include "Creature.hpp"

int main() {
    // Test default constructor
    Creature defaultCreature;
    defaultCreature.display();
    std::cout << std::endl;

    // Test parameterized constructor with valid data
    Creature validCreature("Fire Dragon", Category::ANIMAL, School::FIRE, 150, 10, true);
    validCreature.display();
    std::cout << std::endl;
    // Test parameterized constructor with invalid health and level
    Creature invalidCreature("Lost Soul", Category::UNDEAD, School::DEATH, -50, 0, true);
    invalidCreature.display();
    std::cout << std::endl;
    //Test parameterized constructor with default values
    Creature defaultValuesCreature("Malistaire");
    defaultValuesCreature.display();
    
    // Test setName function with valid and invalid inputs
    if (validCreature.setName("Phoenix")) {
    std::cout << "Name set successfully." << std::endl;
    } else {
    std::cout << "Failed to set name." << std::endl;
    }
    validCreature.setName("123Dragon");
    if (validCreature.getName() == "Pheonix") {
    std::cout << "Correctly rejected invalid name." << std::endl;
    }
    validCreature.display();
    std::cout << std::endl;
    // Test setters with valid and invalid inputs
    if (validCreature.setHealth(200)) {
    std::cout << "Health updated successfully." << std::endl;
    } else {
    std::cout << "Failed to update health." << std::endl;
    }
    if (!validCreature.setHealth(-10)) {
        std::cout << "Correctly rejected invalid health." << std::endl;
    }
    if (validCreature.setLevel(20)) {
        std::cout << "Level updated successfully." << std::endl;
    } else {
        std::cout << "Failed to update level." << std::endl;
    
    }
    validCreature.setLevel(0);
    if (validCreature.getLevel() == 20) {
        std::cout << "Correctly rejected invalid level." << std::endl;
    }
    validCreature.setHostility(false);
    validCreature.display();
    std::cout << std::endl;
    // Test getters
    std::cout << "Name: " << validCreature.getName() << std::endl;
    std::cout << "Category: " << validCreature.getCategory() << std::endl;
    std::cout << "School: " << validCreature.getSchool() << std::endl;
    std::cout << "Health: " << validCreature.getHealth() << std::endl;
    std::cout << "Level: " << validCreature.getLevel() << std::endl;
    std::cout << "Hostile: " << (validCreature.isHostile() ? "true" : "false") << std::endl;
    return 0;
}