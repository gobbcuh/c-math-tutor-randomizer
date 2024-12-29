# Jasmin's Math Randomizer Tutor  

Welcome to **Jasmin's Math Randomizer Tutor**, an interactive and fun educational game designed to help learners practice basic arithmetic operations like addition, subtraction, multiplication, and division. The program generates random math questions and keeps track of your score, making learning math an engaging and rewarding experience!  

## Features  
- **Math Operations**: Practice addition, subtraction, multiplication, and division.  
- **Customizable Questions**: Choose the number of questions and the maximum number value.  
- **Randomized Problems**: Questions are randomly generated for a dynamic learning experience.  
- **Score Tracking**: Keeps track of your score and total questions answered.  
- **User-Friendly Interface**: Intuitive prompts and easy-to-use input system.  
- **Loading Animations**: Engaging loading screens for a polished user experience.  

## Installation  

### Option 1: Using GCC in the Terminal  
1. Clone this repository to your local machine:  
   ```bash
   git clone https://github.com/your-username/math-randomizer-tutor.git
   ```  
2. Compile the code using a C compiler, such as GCC:  
   ```bash
   gcc -o math_tutor math_tutor.c
   ```  
3. Run the compiled program:  
   ```bash
   ./math_tutor
   ```  
### Option 2: Running in Visual Studio Code  
1. Open the `.c` file in Visual Studio Code.  
2. Install the **Code Runner** extension or ensure you have **g++** installed on your system.  
3. Open the integrated terminal in VS Code and navigate to the file's directory.  
4. Compile the program using the following command:  
   ```bash
   g++ file_name.c
   ```  
5. Run the compiled program:  
   ```bash
   ./a.exe
   ```
   
## Usage
- Run the program and follow the on-screen instructions.  
- Use the menu to select a math operation:
  - Addition
  - Subtraction
  - Multiplication
  - Division
- Enter your choices for the number of questions and the maximum value of numbers.  
- Answer the questions as they appear.  
- Check your performance and replay if desired!  

## Code Overview
The program is divided into several functions for modularity and readability:

- **Math Operations**: Functions like `addNum`, `subtractNum`, `multiplyNum`, and `divideNum` handle the arithmetic operations.  
- **User Input**: Functions like `maxQuestions` and `maxValue` let the user specify preferences.  
- **Randomization**: The randomizing function generates random numbers within a specified range.  
- **Loading Animations**: `intro_loading` and `exit_loading` add a visual appeal.  
- **Scoring System**: Tracks and displays scores across multiple sessions.  

## Sample Output  

![View Video Demo](https://github.com/user-attachments/assets/acd6b455-daf4-44d9-b1e7-4278d27aacd6)

## Future Enhancements  
- Add support for advanced operations like exponentiation and square roots.  
- Implement a leaderboard for competitive scoring.  
- Make the program platform-independent by replacing `windows.h` with standard C functions.  

## Acknowledgments  
Thanks for trying out Jasmin's Math Randomizer Tutor! Contributions are always welcome. Feel free to submit a pull request or open an issue for suggestions. 
