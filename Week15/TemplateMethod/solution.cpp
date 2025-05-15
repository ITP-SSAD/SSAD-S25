#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract class representing the template for a recipe
class RecipeTemplate {
protected:
    vector<string> ingredients;  // List of ingredients
    
public:
    virtual void listIngredients() = 0;   // Abstract method to list ingredients
    virtual void prepareRecipe() = 0;     // Abstract method to prepare the recipe
    virtual void serve() {
        cout << "Serving the dish!" << endl;
    }

    // Final method that combines the steps
    void makeRecipe() {
        listIngredients();
        prepareRecipe();
        serve();
    }
};

// Concrete class for CakeRecipe
class CakeRecipe : public RecipeTemplate {
public:
    CakeRecipe() {
        ingredients = {"Flour", "Sugar", "Eggs", "Butter", "Baking Powder"};
    }

    void listIngredients() override {
        cout << "Ingredients for Cake: ";
        for (const auto& ingredient : ingredients) {
            cout << ingredient << " ";
        }
        cout << endl;
    }

    void prepareRecipe() override {
        cout << "1. Mix the dry ingredients." << endl;
        cout << "2. Add wet ingredients and mix." << endl;
        cout << "3. Pour into a cake pan and bake." << endl;
    }
};

// Concrete class for SaladRecipe
class SaladRecipe : public RecipeTemplate {
public:
    SaladRecipe() {
        ingredients = {"Lettuce", "Tomato", "Cucumber", "Olive Oil", "Lemon Juice"};
    }

    void listIngredients() override {
        cout << "Ingredients for Salad: ";
        for (const auto& ingredient : ingredients) {
            cout << ingredient << " ";
        }
        cout << endl;
    }

    void prepareRecipe() override {
        cout << "1. Chop the vegetables." << endl;
        cout << "2. Mix all ingredients in a bowl." << endl;
        cout << "3. Add dressing and toss." << endl;
    }
};

// Client code to demonstrate the recipe template
int main() {
    cout << "Cake Recipe:" << endl;
    CakeRecipe cake;
    cake.makeRecipe();  // Executes the recipe steps

    cout << "\nSalad Recipe:" << endl;
    SaladRecipe salad;
    salad.makeRecipe();  // Executes the recipe steps

    return 0;
}
