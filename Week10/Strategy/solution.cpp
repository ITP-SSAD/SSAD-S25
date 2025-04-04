
#include <iostream>
#include <string>

class Enemy {
private:
    std::string name;
    int health;

public:
    Enemy(const std::string& enemyName, int enemyHealth) : name(enemyName), health(enemyHealth) {}

    void takeDamage(int damage) {
        health -= damage;
        std::cout << name << " STRENGTH LEVEL IS: " << health << std::endl;
        if (health <= 0) {
            std::cout << name << " IS DEAD" << std::endl;
        }
    }

    std::string getName() {
            return name;
    }
};

class AttackStrategy {
public:
    virtual void attack(Enemy &enemy) = 0;
};

class WarriorAttack : public AttackStrategy {
private:
    int damageOnAttack = 25;
public:
    void attack(Enemy &enemy) override {
        std::cout << "Warrior attack!" << std::endl;
        enemy.takeDamage(damageOnAttack);
    }
};

class MageAttack : public AttackStrategy {
private:
    int damageOnAttack = 10;
public:
    void attack(Enemy &enemy) override {
        std::cout << "Mage attack!" << std::endl;
        enemy.takeDamage(damageOnAttack);
    }
};

class RogueAttack : public AttackStrategy {
private:
    int damageOnAttack = 15;
public:
    void attack(Enemy &enemy) override {
        std::cout << "Rogue attack!" << std::endl;
        enemy.takeDamage(damageOnAttack);
    }
};

class Character {
private:
    AttackStrategy* attackStrategy;

public:
    Character(AttackStrategy* strategy) : attackStrategy(strategy) {}

    void attack(Enemy &enemy) {
        attackStrategy->attack(enemy);
    }
};


int main() {

    // Create characters with different attack strategies
    Character warrior(new WarriorAttack());
    Character mage(new MageAttack());
    Character rogue(new RogueAttack());

    // Create enemies
    Enemy enemy1("BLACK KILLER", 100);
    Enemy enemy2("BROWN BITER", 25);

    // Attack enemies with different characters
    warrior.attack(enemy1);
    mage.attack(enemy2);
    rogue.attack(enemy1);

    return 0;
}
