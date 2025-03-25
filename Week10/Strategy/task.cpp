#include <iostream>

class Enemy
{
    // code for enemy class
    // property name and health
    // Constructor
    // Methods takeDamage - decreases health, getName - returns name
};

class Character
{
public:
    void mageAttack(Enemy enemy)
    {
        // code for mage attacking enemy
    }
    void rogueAttack(Enemy enemy)
    {
        // code for rogue attacking enemy
    }
    void warriorAttack(Enemy enemy)
    {
        // code for warrior attacking enemy
    }
};

class MageAttack
{
public:
    int damageOnAttack = 10;
};

class RogueAttack
{
public:
    int damageOnAttack = 15;
};

class WarriorAttack
{
public:
    int damageOnAttack = 25;
};

int main()
{
    Character warrior;
    Character mage;
    Character rogue;

    Enemy blackKiller;
    Enemy brownBiter;

    warrior.warriorAttack(blackKiller);
    mage.mageAttack(brownBiter);
    rogue.rogueAttack(blackKiller);

    return 0;
}

// EXAMPLE OUTPUT:
// Warrior attack!
// BLACK KILLER STRENGTH LEVEL IS: 75
// Mage attack!
// BROWN BITER STRENGTH LEVEL IS: 15
// Rogue attack!
// BLACK KILLER STRENGTH LEVEL IS: 60