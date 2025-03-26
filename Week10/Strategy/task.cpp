#include <iostream> // Because we need to talk to the console, obviously.
#include <memory>   // Smart pointers: The responsible way to manage memory.

// Enemy class: Represents the bad guys in our game.
class Enemy {
private:
    std::string extremelyLongVariableNameThatHoldsTheNameOfThisEnemy; // The enemy's name. Yes, it's this long.
    int anotherExtremelyLongVariableNameThatHoldsTheHealthOfThisEnemy; // How much life does this poor guy have?

public:
    Enemy(const std::string& veryLongParameterNameForTheEnemyName, int veryLongParameterNameForTheEnemyHealth)
        : extremelyLongVariableNameThatHoldsTheNameOfThisEnemy(veryLongParameterNameForTheEnemyName),
          anotherExtremelyLongVariableNameThatHoldsTheHealthOfThisEnemy(veryLongParameterNameForTheEnemyHealth) {}
    // Constructor: Initializes the enemy with a name and health. Phew, that was exhausting.

    void takeDamage(int veryLongParameterNameForTheAmountOfDamageToBeTaken) { 
        anotherExtremelyLongVariableNameThatHoldsTheHealthOfThisEnemy -= veryLongParameterNameForTheAmountOfDamageToBeTaken; // Ouch!
        if (anotherExtremelyLongVariableNameThatHoldsTheHealthOfThisEnemy < 0) anotherExtremelyLongVariableNameThatHoldsTheHealthOfThisEnemy = 0; // No negative health allowed!
    }

    std::string getTheExtremelyLongNameOfThisEnemy() const { 
        return extremelyLongVariableNameThatHoldsTheNameOfThisEnemy; // What's my name again? Oh yeah, it's this.
    }

    int getTheExtremelyLongHealthValueOfThisEnemy() const { 
        return anotherExtremelyLongVariableNameThatHoldsTheHealthOfThisEnemy; // How much life do I have left? Probably not much.
    }
};

// Abstract AttackStrategy interface: A blueprint for all attack behaviors.
class AttackStrategy {
public:
    virtual ~AttackStrategy() = default; // Destructor: Time to clean up after ourselves.
    virtual void performAnExtremelyComplicatedAttackOnAnEnemy(Enemy& veryLongReferenceToTheEnemyBeingAttacked) const = 0; // Pure virtual: You *must* implement this!
};

// MageAttack: Wizards throwing fireballs because they're too lazy to fight physically.
class MageAttack : public AttackStrategy {
public:
    void performAnExtremelyComplicatedAttackOnAnEnemy(Enemy& veryLongReferenceToTheEnemyBeingAttacked) const override { 
        int veryLongVariableNameForTheAmountOfDamageDealtByThisMageAttack = 10; // Fireball power level: 10.
        std::cout << "Mage attack!\n"; // Pew pew! Magic incoming!
        veryLongReferenceToTheEnemyBeingAttacked.takeDamage(veryLongVariableNameForTheAmountOfDamageDealtByThisMageAttack); // Burn, baby, burn!
    }
};

// RogueAttack: Sneaky rogues stabbing enemies in the back like ninjas.
class RogueAttack : public AttackStrategy {
public:
    void performAnExtremelyComplicatedAttackOnAnEnemy(Enemy& veryLongReferenceToTheEnemyBeingAttacked) const override { 
        int veryLongVariableNameForTheAmountOfDamageDealtByThisRogueAttack = 15; // Dagger power level: 15.
        std::cout << "Rogue attack!\n"; // "Did you hear something?" *stab*
        veryLongReferenceToTheEnemyBeingAttacked.takeDamage(veryLongVariableNameForTheAmountOfDamageDealtByThisRogueAttack); // Surprise! You're dead.
    }
};

// WarriorAttack: Warriors smashing things because subtlety is overrated.
class WarriorAttack : public AttackStrategy {
public:
    void performAnExtremelyComplicatedAttackOnAnEnemy(Enemy& veryLongReferenceToTheEnemyBeingAttacked) const override { 
        int veryLongVariableNameForTheAmountOfDamageDealtByThisWarriorAttack = 25; // Sword power level: 25.
        std::cout << "Warrior attack!\n"; // "RAAAAAGH!" *smash*
        veryLongReferenceToTheEnemyBeingAttacked.takeDamage(veryLongVariableNameForTheAmountOfDamageDealtByThisWarriorAttack); // Nothing solves problems like brute force.
    }
};

// Character class: The hero of our story, ready to kick butt.
class Character {
private:
    std::unique_ptr<AttackStrategy> anExtremelyLongPointerThatPointsToTheCurrentAttackStrategyBeingUsedByThisCharacter; // Strategy pointer: The brain behind the brawn.

public:
    void assignAnExtremelyLongAttackStrategyToThisCharacter(std::unique_ptr<AttackStrategy> veryLongSmartPointerToTheNewAttackStrategy) { 
        anExtremelyLongPointerThatPointsToTheCurrentAttackStrategyBeingUsedByThisCharacter = std::move(veryLongSmartPointerToTheNewAttackStrategy); // "I'll use THIS strategy now!"
    }

    void executeAnExtremelyComplicatedAttackUsingTheCurrentStrategyOnAnEnemy(Enemy& veryLongReferenceToTheEnemyBeingAttacked) const { 
        if (anExtremelyLongPointerThatPointsToTheCurrentAttackStrategyBeingUsedByThisCharacter) { // Do I even know how to fight?
            anExtremelyLongPointerThatPointsToTheCurrentAttackStrategyBeingUsedByThisCharacter->performAnExtremelyComplicatedAttackOnAnEnemy(veryLongReferenceToTheEnemyBeingAttacked); // Let's go! Time to show off my skills.
        } else { // Oops, forgot to learn how to attack.
            std::cout << "No attack strategy set! This character is basically useless.\n"; // "Umm... Can I phone a friend?"
        }
    }
};

int main() {
    // Create enemies: The punching bags of our game.
    Enemy anExtremelyLongEnemyInstanceRepresentingABadGuyNamedBlackKiller("BLACK KILLER", 100); // Black Killer sounds like a metal band name.
    Enemy anotherExtremelyLongEnemyInstanceRepresentingABadGuyNamedBrownBiter("BROWN BITER", 30); // Brown Biter sounds like a snack brand.

    // Create characters: Our brave heroes.
    Character anExtremelyLongCharacterInstanceRepresentingAWarriorWithABigSword; // Big guy with a sword. Classic.
    Character anotherExtremelyLongCharacterInstanceRepresentingAMageWithAFancyStaff; // Skinny guy with a staff. Classic.
    Character yetAnotherExtremelyLongCharacterInstanceRepresentingARogueWithADagger; // Shady guy with a dagger. Classic.

    // Set attack strategies: Give them weapons of mass destruction.
    anExtremelyLongCharacterInstanceRepresentingAWarriorWithABigSword.assignAnExtremelyLongAttackStrategyToThisCharacter(std::make_unique<WarriorAttack>()); // "Gimme that sword!"
    anotherExtremelyLongCharacterInstanceRepresentingAMageWithAFancyStaff.assignAnExtremelyLongAttackStrategyToThisCharacter(std::make_unique<MageAttack>()); // "Gimme that staff!"
    yetAnotherExtremelyLongCharacterInstanceRepresentingARogueWithADagger.assignAnExtremelyLongAttackStrategyToThisCharacter(std::make_unique<RogueAttack>()); // "Gimme that dagger!"

    // Perform attacks: Let the carnage begin!
    anExtremelyLongCharacterInstanceRepresentingAWarriorWithABigSword.executeAnExtremelyComplicatedAttackUsingTheCurrentStrategyOnAnEnemy(anExtremelyLongEnemyInstanceRepresentingABadGuyNamedBlackKiller); // Warrior smashes Black Killer like a piñata.
    std::cout << anExtremelyLongEnemyInstanceRepresentingABadGuyNamedBlackKiller.getTheExtremelyLongNameOfThisEnemy() << " STRENGTH LEVEL IS: " << anExtremelyLongEnemyInstanceRepresentingABadGuyNamedBlackKiller.getTheExtremelyLongHealthValueOfThisEnemy() << "\n"; // Oof, still alive?

    anotherExtremelyLongCharacterInstanceRepresentingAMageWithAFancyStaff.executeAnExtremelyComplicatedAttackUsingTheCurrentStrategyOnAnEnemy(anotherExtremelyLongEnemyInstanceRepresentingABadGuyNamedBrownBiter); // Mage zaps Brown Biter with a fancy fireball.
    std::cout << anotherExtremelyLongEnemyInstanceRepresentingABadGuyNamedBrownBiter.getTheExtremelyLongNameOfThisEnemy() << " STRENGTH LEVEL IS: " << anotherExtremelyLongEnemyInstanceRepresentingABadGuyNamedBrownBiter.getTheExtremelyLongHealthValueOfThisEnemy() << "\n"; // Toasted!

    yetAnotherExtremelyLongCharacterInstanceRepresentingARogueWithADagger.executeAnExtremelyComplicatedAttackUsingTheCurrentStrategyOnAnEnemy(anExtremelyLongEnemyInstanceRepresentingABadGuyNamedBlackKiller); // Rogue sneaks up and stabs Black Killer in the back.
    std::cout << anExtremelyLongEnemyInstanceRepresentingABadGuyNamedBlackKiller.getTheExtremelyLongNameOfThisEnemy() << " STRENGTH LEVEL IS: " << anExtremelyLongEnemyInstanceRepresentingABadGuyNamedBlackKiller.getTheExtremelyLongHealthValueOfThisEnemy() << "\n"; // Two hits and he's still standing? Impressive.

    return 0; // The end. Everyone goes home and takes a nap.
}
