# Week 5

## Task 1: Generic Stack

Implement a generic stack in C++ that can store elements of any data type. Use templates to achieve generality and constructors for initialization. Extend the functionality through inheritance to customize the stack for specific data types.

- Implement a class template named `GenericStack` that supports basic stack operations: `push()`, `pop()`, and `peek()`.
- The `push()` method should insert an element at the top of the stack.
- The `pop()` method should remove and return the element at the top of the stack. If the stack is empty, it should throw an exception or return a default value.
- The `peek()` method should return the element at the top of the stack without removing it. If the stack is empty, it should throw an exception or return a default value.
- Include a constructor that initializes the stack's capacity. The stack should dynamically adjust its size as elements are added.
- Ensure proper memory management to avoid leaks.

- Create a subclass of `GenericStack` named `StringStack` that is specifically designed for handling strings.
- Override the `push()` method in `StringStack` to include a check that rejects empty strings (i.e., the method should not allow pushing empty strings onto the stack).
- Add a new method `concatTopTwo()` in `StringStack` that pops the top two strings, concatenates them, and then pushes the result back onto the stack. If there are not enough elements in the stack, throw an exception.

### Instructions

- Start by planning your implementation and sketching out the class structure.
- Implement the `GenericStack` class template, focusing on correctly handling generic data types with templates.
- After testing your `GenericStack`, proceed to implement the `StringStack` class, paying attention to how inheritance can be used to extend and customize behavior.
- Include error handling for edge cases, such as popping from an empty stack or pushing invalid elements.
- Write a simple main function to demonstrate the functionality of your stack implementation, particularly showcasing the features of the `StringStack`.

## Task 2: Smart Pointers

Understand and apply smart pointers in C++ (`unique_ptr`, `shared_ptr`, `weak_ptr`) to manage resources automatically and solve common memory management problems.

1. **Create class Box**

   - The class should have integer value with a constructor and a destrutor

1. **Understanding `unique_ptr`**
   - Implement a function `create_unique()` that dynamically allocates an `Box` with a given value and returns `int` which is the value inside Box.
   - Demonstrate transferring ownership of the `unique_ptr` to another `unique_ptr` and the automatic deallocation of resources.

1. **Exploring `shared_ptr`**
   - Implement a function `create_shared_boxes()` that creates two `shared_ptr<Box>` pointing to different `Box` instances and demonstrates shared ownership.
   - Show how the reference count changes when new `shared_ptr` instances are created or destroyed.

1. **Working with `weak_ptr`**
   - Extend the `Box` class usage by introducing a `weak_ptr<Box>`. Demonstrate how to check if a `weak_ptr` points to an object (i.e., if the object is still alive) and how to convert a `weak_ptr` to a `shared_ptr` to access the object.
   - Explain the use case of `weak_ptr` to solve the problem of circular references.

### Instructions

- Implement each part of the task sequentially, testing your understanding of how each smart pointer type works and their respective use cases.
- Pay attention to the mechanics of ownership transfer, especially how `unique_ptr` cannot be copied but can be moved.
- For `shared_ptr`, observe how the reference count mechanism prevents premature deallocation and how it automatically cleans up when no more `shared_ptr` instances point to the object.
- Use `weak_ptr` to access resources without taking ownership and demonstrate how it helps in managing circular references by breaking dependency cycles.
