# Week 10

## Task 1 - Strategy 

Imagine a game where the player controls a **team of characters**, each with their own unique set of abilities and **attack styles**. The player may want to switch between characters during battle, and each **character** may have a **name** and a different **attack strategy** that is more effective against certain **enemies**. The **enemy** class should have a name field and contain a method to display **current strength** of the enemy and a method to decrease **strength level** on attack.

Task:

- Implement this scenario using the Strategy design pattern.
- Create characters with various attack strategies, enemies with varying levels of strength and weakness, and observe the game.
- Show a UML class diagram representing your solution.

## Task 2 - Adapter

We are to build a **payment gateway system** that can handle payments from multiple international payment providers, such as **PayPal** and **Stripe**. Each payment provider has its own interface and payment processing system, making it challenging to integrate them all into a single system.

Task:

1. Create a **uniform interface** for all payment providers. (hints: The common interface should include methods for processing payments, handling refunds, and verifying payment information)
1. Create an **adapter class** for each payment provider that can **translate** its interface into a common interface that each payment gateway system can **understand**.
1. Create a payment gateway **class** that **accepts** payment requests and **delegates** them to the **appropriate adapter class** based on the payment provider selected by the user
1. Show a UML class diagram representing your solution

## Task 3 - Composite

You are to design a **file system** program that handles **files** and **directories**. A directory can contain files or **subdirectories**, which can in turn contain more files or subdirectories.

The goal is to create a **class hierarchy** that represents files and directories as **components** of a larger system and also creates a **common interface** for accessing and manipulating files and directories.

The directory class should have a **list of components** that can be files or subdirectories and allow for adding and removing components from this list.

Task:

- Using the composite design pattern, you need to print to the console the name of **every directory** and **file** present in the file system, starting from the root. 
- Show a UML class diagram representing your solution.
