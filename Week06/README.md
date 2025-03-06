# Week 6

## Task 1: Wrapper

Create a class template `Wrapper` that wraps a single value of any type. Implement a member function called `getValue()` that returns the wrapped value.

- Explicitly specialize this template for the `char*` type and provide a custom implementation for the `getValue()` function that returns the length of the string instead.

## Task 2: Dictionary

a) Implement a class template `Dictionary` that stores pairs of keys and values that can be of different types. It should have the following member functions:

- `get(K key)` returns the value for the given key
- `put(K key, V value)` inserts the pair (key, value) to the dictionary
- `remove(K key)` removes the pair with the given key
- `size()` returns the number of elements in the dictionary

Finally, write a main function that demonstrates how your solution works.

b) Write partial specialization for the previous class template (`Dictionary`) that will be used only when the value type is `int` (i.e. `<K, int>`)

- In case of this specialization, member function `get(K key)` should return the **absolute value** of the value with the given key instead of value itself.

- Moreover, member function `size()` should not return the number of elements in the dictionary but the **sum** of all values in the dictionary.

## Task 3: Custom Map and Filter

1. **Implement a map Function**

   - The **map** function takes a vector and a callback function as its parameters.

   - The callback function performs an operation on each element of the vector

   - It returns a new vector containing the results of applying the callback function to each element in the original vector.

   ```c++
   vector<int> customMap(const vector<int> &vec, int (*func)(int)) {
       vector<int> result;
       ...
       return result;
   }
   ```

1. **Implement a filter Function**

   - The **filter** function takes a vector and a callback function as its parameters.
   - The callback function for **filter** should be a predicate (returning a boolean value) that decides whether an element in the vector should be included in the result.
   - The **filter** function should return a new vector containing only those elements of the original vector for which the callback function returns **true**.

1. Test Your Functions

   - Demonstrate the use of your **map** and **filter** functions with at least two different lambda expressions for each function.
   - For **map**, you might use a lambda that squares each number.
   - For **filter**, you could use a lambda that filters out even numbers.

   ```c++
   vector<int> nums = {1, 2, 3, 4, 5};
   
   // Usage for map: Squaring each element
   auto squared = customMap(nums, /* write your lambda here */);
   
   // Usage for filter: Retaining odd numbers
   auto odds = customFilter(nums, /* write your lambda here */);
   ```
