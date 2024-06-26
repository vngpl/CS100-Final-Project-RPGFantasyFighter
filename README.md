# RPG Fantasy Fighter
Authors: [Ryan Nguyen](https://github.com/ryanxnguy), [Vansh Nagpal](https://github.com/vngpl), [Jingbo Su](https://github.com/sujingbo0217), [Nicholas Castellanos](https://github.com/Hugzaregood)

## Project Description
This project is interesting to us because it will give us a chance to be creative in developing a video game. It will also help improve our programming skills by better understanding topics such as object-oriented programming, input/output verification, and debugging/testing.

The language we plan to use for this project is C++. Some tools may include what we have learned so far such as the GNU debugger (GDB), Valgrind, VS Code for editing/developing, and Github for version control.

The input/output for the project will be the way a player interacts with their character and the world which may involve combating or communicating with other characters. For example, the user will be able to select their character class, weapons, armor, paths, and items. The output will most likely be text-based and depend on the decisions that the user makes in the game and may include things such as dialogue, combat outcomes, and other world events based on the user's decisions.

The features that the project will provide includes character customization and design through a variety of objects/items such as weapons, armor, and equipment. In addition to the customization, the user will be able to engage in dialogue and interact with other characters, make decisions, engange in combat with a chance to level up and improve their character.

## User Interface Specification

### Navigation Diagram
![Navigation Diagram](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/blob/main/NavigationDiagram.png)

Diagram illustrating how the user can navigate from one screen to another. The diagram represents the different screens the user will move between and includes confirmations, buttons, and viewing for switching to the next screen.

### Screen Layouts

![image](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/assets/127288174/a5acbbd7-70c7-4005-8ab0-592412bc8dad)

![image](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/assets/127288174/2b8f03ce-e6f2-4224-be25-76cbd9713a13)

![image](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/assets/127288174/9e58ef1c-1ebe-4e69-abf8-31752cdf8d1a)

![image](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/assets/127288174/603494f2-abcb-4b0c-9108-e518bb10da11)

![image](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/assets/127288174/85bd858c-2c0d-433c-b6d8-125a02472c6d)

![image](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/assets/127288174/bf394d5c-2ed3-4d6c-8e69-0b824df3099c)

![image](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/assets/127288174/e83672ff-d13c-44a3-8ad7-11bc4a5a38d2)

![image](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/assets/127288174/940d5e60-6c15-496c-8cf5-502d2b721fd5)

![image](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/assets/127288174/fdc3aa03-bb9c-4a16-91db-e2d8a22ed8f3)

[General Screen Layout](https://docs.google.com/presentation/d/1J9MkQOFKmCZuKEjlQRDTo65_aweelnR4qWAHOjOCGjk/edit#slide=id.p)

The general layout will consist of prompts displayed in the game window. The user will be able to act based on the options provided by each prompt. Input may mainly be in the form of clickable buttons, however, numerical and text inputs may also be used to allow for communication with/between the user and the game environment. The user will be able to provide feedback based on the options that are chosen. The layout outlines some general features of the game such as character creation/customization, the combat system, leveling system, and interactions with objects in the game.

## Class Diagram
![Class Diagram](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/blob/main/ClassDiagram.png)

Diagram illustrating main classes of project. The diagram represents the main game class and other classes and subclasses that will be used within the game. Classes include attributes and operations. 
Solid Design Principles:
1. Single Responsibility: The character class, for example, has only one responsibility. It will only have the characteristics of one of its subclasses, from warrior, wizard, or assassin.
2. Liskov Substitution: The subclasses of the item class, for example, behave similarly to their parent class. They will have the same functions as the parent class, such as getName.
3. Interface Segregation: The subclasses of the character class, for example, do not have unnecessary functions that would not fit with their respective class. Each subclass has its own attack, which will do a unique amount of damage and display its own message. 

## Screenshots
![Difficulty Select](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/blob/main/Difficulty.png)

![Character Class Select](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/blob/main/Character.png)

![Battle](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/blob/main/Battle.png)

![Battle Victory](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/blob/main/BattleVictory.png)

![LevelUp](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/blob/main/LevelUp.png)

![Shop](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/blob/main/Shop.png)

![Inventory](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/blob/main/Inventory.png)

![Run](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/blob/main/Run.png)

![EndStats](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/blob/main/EndStats.png)

## Installation/Usage
Instructions on installing and running your application: 

1. Clone this repository onto your local machine using the 'git clone' command in your terminal with the HTTPS link.
2. Use the 'cd' command in the terminal to navigate to the cloned directory on your machine.
3. Finally, type the command 'sh run.sh' into the terminal, while in the directory, to compile and run the program for you.
4. Enjoy! 

## Testing
The project was tested/validated using unit testing via the Google Test (gtest) submodule. Tests for each class were written to ensure that the methods were functioning properly for the class but also when integrating the methods into the main game. Once the tests were written, they were compiled using the CMakeLists.txt and used for debugging the code and testing the program's logic.

Additionally, the program was tested using Valgrind to detect memory leaks when allocating and deallocating memory for objects used in the game. The program was tested until it was memcheck clean:

![image](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/assets/127288174/fec6a9da-5b4e-45a3-b3ca-16cf7db5d46e)


