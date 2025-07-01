/*
Name: Khalid Young
Date: (06/26/2025)
Note: This is the implementation for the Battle class, with constructors completed, member functions, data members, etc. 
*/

#include "Battle.hpp"

/**
Parameterized constructor
@param: The wizard involved in the battle
@param: The tavern of creatures involved in the battle
*/
Battle::Battle(Wizard* wizard, Tavern enemies){
    this->wizard_ = wizard;
    this->enemies_ = enemies;
}

/**
@post: Simulates the entire combat between the wizard and the enemy
creatures
Steps:
Display round status
Adds creatures into your turnStack_ based on speed. The higher the speed
the earlier the creature will go (Remember how stacks work)

Executes the turn of the creature at the top of the stack. If the creature is a
wizard, you will gather user input to dictate whether the wizard will attack
or heal. If the creature is an enemy they will do their standard attack
When the wizard attacks, display all of the creatures in the tavern and gather
user input to decide who the wizard attacks
If the creature’s health falls below zero, remove them from the tavern
Check to see if the wizard is still alive or if there are still any enemies left in
the tavern. If either of the conditions is true, print an action message to
signal that the battle is over and who came out victorious. If neither of the
conditions are true, build the stack once again and continue to simulate the
battle
Hint: Keep in mind that when a creature is attacking, they need to be popped
out of the stack. Because of this reason you need to build your stack every
time a full turn occurs
*/
void Battle::simulate() {
    while(isWizardAlive() && enemiesRemain()){
        displayRoundStatus();
        buildTurnStack();

        while(!turnStack_.empty()){
            executeTurn(turnStack_.top());
            removeDefeatedEnemy();
            if(!isWizardAlive() || !enemiesRemain()){
                break;
            }
        }
    }
    if(isWizardAlive()){
        std::cout << "You have survived the endless night, and claumed your victory as the new Tavern keeper..." << "\n"
        << "You get bored pretty quick of it and blow the entire place up instead. THE END!" << "\n";
    }
    else{
        std::cout << "The enemies have taken over and chaos has taken over the world, now everyone (including your dead but immortal soul) must pay for the damages of the bar..." <<
        "\n" << "And there was a lot of damage" << "\n";
    }
}

/**
@post: Populates the turnStack_ with all current combatants (wizard and all
enemies from the tavern) sorted by ascending speed (the faster the speed the
earlier you go)
*/
void Battle::buildTurnStack() {
    std::vector<Creature*> fighters_;
    fighters_.push_back(wizard_);
    std::vector<Creature*> villains_ = enemies_.toVector();
    for(int i = 0; i < villains_.size(); i++){
        fighters_.push_back(villains_[i]);
    }
    std::sort(fighters_.begin(), fighters_.end(), compareSpeed);
    for(int i = fighters_.size() - 1; i >= 0; i--){
        turnStack_.push(fighters_[i]);
    }
}

/**
@post: Helper function to compare speeds within the array
*/
bool Battle::compareSpeed(Creature* a, Creature* b){
    return a->getSpeed() < b->getSpeed();
}

/**
@param: Pointer to the creature taking a turn
@post: Executees the turn of a given creature. If the attacker is an enemy
they will perform an attack on the Wizard. If the attacker is a wizard, the
wizard chooses and casts a spell (either offensive or defensive) on a chosen
target (indexed from your tavern)
*/
void Battle::executeTurn(Creature* attacker) {
    std::vector<Creature*> attackee = enemies_.toVector();
    if(attackee.empty()) {return;}
    if(attacker == wizard_){
        bool attack;
        int attacked;

        std::cout << "Choose a Spell: 0: Attack Spell, 1: Heal Spell" << "\n";
        std::cin >> attack;

        if(!attack){
            std::cout << "Choose an enemy (from 0 to " << attackee.size() - 1 << "): " << "\n";
            std::cin >> attacked;
            if(attacked >= 0 && attacked < attackee.size()){
                wizard_->attackSpell(attackee[attacked]);
            } else {std::cout << "Please enter a valid index" << "\n"; return;}
            turnStack_.pop();
        }

        if(attack){
            wizard_->healSpell();
            turnStack_.pop();
        }
    }

    else{
        attacker->attack(wizard_);
        turnStack_.pop();
    }
}

/**
@post: Removes any enemies whose health has dropped to 0 or below from
the tavern after turn execution
*/
void Battle::removeDefeatedEnemy(){
    std::vector<Creature*> enemy = enemies_.toVector();
    for(int i = 0; i < enemy.size(); i++){
        if(enemy[i]->getHealth() == 0){
            enemies_.exitTavern(enemy[i]);
        }
    }
}

/**
@return: true if the wizard is still alive (health > 0), false otherwise
*/
bool Battle::isWizardAlive() const{
    return wizard_->getHealth() > 0;
}

/**
@return: true if there are remaining enemies, false if all have been defeated
*/
bool Battle::enemiesRemain() const{
    return !enemies_.isEmpty();
}

/**
@post: Displays the current status of all combatants at the start of a round.
The output should include:
The Wizard’s name and current health.
A numbered list of all enemies still in the battle, showing:
- Name
- Current health
- Speed
Example output:
=== Round Status ===
Wizard: Merlin
Health: 72
Enemies:
1. Lado - Health: 25, Speed: 4
2. Meheraan - Health: 30, Speed: 3
3. Ank - Health: 18, Speed: 2
*/
void Battle::displayRoundStatus() const{
    std::vector<Creature*> post = enemies_.toVector();
    std::cout << "Wizard: " << wizard_->getName() << "\n" << "Health: " << wizard_->getHealth() << "\n" << "Speed: " << wizard_->getSpeed()
    << "\n";
    for(int i = 0; i < post.size(); i++){
        std::cout << i << "." << post[i]->getName() << " - Health: " << post[i]->getHealth() << ", Speed: " << post[i]->getSpeed() << "\n";
    }
}