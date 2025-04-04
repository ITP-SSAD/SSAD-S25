# Week 11

## Task 1 - Facade

- **Objective:** Develop a Facade to simplify the control of various smart home devices (**lights**, **thermostat**, **security cameras**).
- **Requirements:**
  - Implement classes for different smart devices with their functionalities (**Light** with **on**() and **off**(), **Thermostat** with **setTemperature**(), **SecurityCamera** with **activate**() and **deactivate**()).
  - Design a **SmartHomeFacade** class that provides simple methods to manage scenarios like "**LeavingHome**" (turns off lights, sets thermostat to eco mode, activates security cameras) and "**ArrivingHome**" (turns on lights, sets thermostat to comfortable temperature).
  - In the main function, demonstrate using the **SmartHomeFacade** to activate different scenarios.

## Task 2 - Decorator

- **Objective:** Apply the **Decorator** pattern to create a **flexible text styling system** where styles (**bold**, **italic**, **underline**) can be dynamically added to text.
- **Requirements:**
  - Define a **Text** interface with a method **write**() that displays the text with its styles.
  - Implement a **PlainText** class that outputs the text without any styling.
  - Create a **TextDecorator** abstract class implementing **Text**, serving as the base for all text style decorators.
  - Develop decorators **Bold**, **Italic**, and **Underline** that can be used to wrap a Text object and add respective styling to it. You may use either html style wrapping or the following:
    - For Bold style - wrap your text in **"\033[1m"** and **"\033[0m"**
    - For Italic style - wrap your text in **"\033[3m"** and **"\033[0m"** 
    - For Underline style - wrap your text in **"\033[4m"** and **"\033[0m"**
  - Use these decorators in a main function to apply multiple styles to a text and display it.

## Task 3 - Proxy

- **Objective:** Implement a **Proxy** to control access to sensitive documents based on user roles.
- **Requirements:**
  - Define a **Document** interface with a method **display**().
  - Implement a **RealDocument** class that represents a sensitive document and implements the **Document** interface.
  - Create a **SecureDocumentProxy** class that also implements the **Document** interface and contains security logic to control access to a **RealDocument** based on a user's role.
  - In the main function, simulate accessing documents with different user roles, showing how the proxy grants or denies access.



