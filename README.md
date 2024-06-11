# RPG Fantasy Fighter

 > Authors: [Ryan Nguyen](https://github.com/ryanxnguy), [Vansh Nagpal](https://github.com/vngpl), [Jingbo Su](https://github.com/sujingbo0217), [Nicholas Castellanos](https://github.com/Hugzaregood)

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
[General Screen Layout](https://docs.google.com/presentation/d/1J9MkQOFKmCZuKEjlQRDTo65_aweelnR4qWAHOjOCGjk/edit#slide=id.p)

The general layout will consist of prompts displayed in the game window. The user will be able to act based on the options provided by each prompt. Input may mainly be in the form of clickable buttons, however, numerical and text inputs may also be used to allow for communication with/between the user and the game environment. The user will be able to provide feedback based on the options that are chosen. The layout outlines some general features of the game such as character creation/customization, the combat system, leveling system, and interactions with objects in the game.

## Class Diagram
![Class Diagram](https://github.com/cs100/final-project-ryan-nicholas-jingbo-vansh/blob/main/ClassDiagram.png)

Diagram illustrating main classes of project. The diagram represents the main game class and other classes and subclasses that will be used within the game. Classes include attributes and operations. 
Solid Design Principles:
1. Single Responsibility: The character class, for example, has only one responsibility. It will only have the characteristics of one of its subclasses, from warrior, wizard, or assassin.
2. Liskov Substitution: The subclasses of the item class, for example, behave similarly to their parent class. They will have the same functions as the parent class, such as getName.
3. Interface Segregation: The subclasses of the character class, for example, do not have unnecessary functions that would not fit with their respective class. Each subclass has its own attack, which will do a unique amount of damage and display its own message. 


 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members.
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.

 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 The project was tested/validated using unit testing via the Google Test (gtest) submodule. Tests for each class were written to ensure that the methods were functioning properly for the class but also when integrating the methods into the main game. Once the tests were written, they were compiled using the CMakeLists.txt and used for debugging the code and testing the program's logic.

