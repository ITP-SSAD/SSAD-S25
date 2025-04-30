# Week 15

## Task 1 - Template Method

Design a simple cooking recipe application. While each type of recipe has unique ingredients and preparation steps, the overall structure of presenting the recipe follows a standard format: list ingredients, prepare the recipe, and serve the dish.

- Implement the abstract and concrete classes as shown

  ![img](https://i.imgur.com/pqUN8P1.png)

- Create objects for **CakeRecipe** and **SaladRecipe** and call **makeRecipe()** on these objects to ensure that they output the steps correctly.

- Demonstrate the use of the Template Method pattern with your classes.

## Task 2 - Mediator

The starter code represents a smart house system, which has several devices such as door locks, motion sensors, lights, etc, that communicate with each other.

Complete this code using the **Mediator** design pattern.

## Task 3 - Memento

A text editor application is to be built. It should allow users to **undo/redo** changes to the text they have entered. Use the **Memento** pattern to store the state of the editor at various points in time, so that the user can **undo/redo** changes as needed.

- What will be the Originator and Caretaker classes in our text editor application
- Implement all the empty functions present in the TextEditor and the UndoRedoManager.

## Task 4 - Abstract Factory

Implement the UML class diagram representing the Abstract Factory Design Pattern. 

- Implement the classes as shown

  ![img](https://i.imgur.com/xAjUUp3.png))

- Demonstrate your solution by instantiating a factory for a specific operating system and creating widgets(buttons/checkboxes) using that factory
