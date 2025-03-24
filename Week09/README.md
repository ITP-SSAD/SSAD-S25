# Week 9

## Task: Smart Document Editor

Practice design patterns: Singleton, State, and Prototype with the following task.

### Part 1: Singleton - Logging Mechanism

Implement a Logger Class:

- Design a `Logger` class that follows the `Singleton` pattern to ensure only one instance exists throughout the application.
- Include a method `log(const std::string& message)` for logging messages to the console or a file.

### Part 2: State - Document State Management

Abstract `DocumentState` Class:

- Create an abstract class `DocumentState` with a virtual method `handleInput(const std::string& input)` to represent how a document behaves when receiving input in different states.

Concrete State Classes:

- Implement derived classes for specific states (`DraftState`, `ReviewState`, `FinalState`) that override `handleInput`.

State Transition in Document:

- In the Document class, manage the current state using a `DocumentState*` and implement a method `changeState(DocumentState* newState)` for state transitions

### Part 3: Prototype - Document Creation

Abstract `DocumentPrototype` Class:

- Design an abstract `DocumentPrototype` class with a `clone()` method for cloning document prototypes.

Concrete Document Classes:

- Implement concrete classes (`ReportType`, `InvoiceType`) that inherit from `DocumentPrototype` and override the `clone()` method, incorporating default settings.

Prototype Usage:

- Demonstrate the cloning of document prototypes to create new documents, incorporating the Singleton Logger to log cloning actions.

### Main function

- Write a main function to showcase the entire system's functionality. Demonstrate the creation of document prototypes, cloning of these prototypes to produce new documents, and the transition of documents through different states.
- Use the Singleton Logger to log significant events, such as document state changes and cloning operations.
