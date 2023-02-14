//Tyler Piron - Assignment 1: Strange Calculator
//The purpose of this program is to be able to re-produce and calculate many of the functions and methods found in a common calculator. 
//The required functions include common expressions, unit-conversion, grade-calculation, and string-tokenization.


// Program1-StrangeCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//defining neccecary libraries to run this program
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//declares 6 functions below. functionSelector is designed to help select which Calculator operation to perform.
//The remaining five are the actual calcualtor functions themselves.
int functionSelector();
void mathCalculator();
void metricConversionCalculator();
void gradesCalculator();
void stringTokenizer();
void help();

//Variable holds a user input name that is used in the main class and functionSelector class. purpose is to hold users name.
std::string userName{ };

//The main class  is used to get the name of the user so it can be used in function selector.
int main()
{

    std::cout << "Please Enter Your Full Name To Begin: ";
    std::cin >> userName;
    std::cin.ignore(userName.length() + 1, '\n');
    //input that allows for a user to enter their name.
    //cin.ignore statement used so only the first name is ever printed back to user and it stops c++ from skipping the next input statement.

    functionSelector();
    //runs the function selector so the user can select a method to perform.

    return 0;
    //ends the program.

}

//function defined to select which calculator method to perform.
//All other methods contain recursive statements that come back to this method.
int functionSelector(){

    //variable that the user inputs into to select an action they want to perform.
    std::string whichProgram;

    //output statements that ask the user which methods are available and how to select them.
    //it also uses the userName variable to display the users name.
    std::cout << userName << ", Select from the following menu by typing the associated number:\n";
    std::cout << "Math Calculator (Enter 1)\n";
    std::cout << "Metric Conversion Calculator (Enter 2)\n";
    std::cout << "Grades Calculator (Enter 3)\n";
    std::cout << "String Tokenizer (Enter 4)\n";
    std::cout << "Help (Enter 5)\n";
    std::cout << "Quit (Enter 6 or type quit (any capitalization))\n\n";
    std::cout << "Enter an appropriate selection:\n";

    //Allows the user to input an action to perform.
    std::cin>>whichProgram;
    std::cout << "\n";

    //for loop that goes through entire input and makes it capital in-case the user it attempting to quit the program.
    for (int i = 0; i <= whichProgram.length(); i++) {
       whichProgram[i] = toupper(whichProgram[i]);
    }

    //The following are all if statements that use the users input to run on of the methods declared above.
    //Once the methods have been performed. They all recursivly re-start this method to allow the user to select another action.
    if (whichProgram == "1") {
        mathCalculator();
        functionSelector();
    }

    if (whichProgram == "2") {
        metricConversionCalculator();
        functionSelector();
    }

    if (whichProgram == "3") {
        gradesCalculator();
        functionSelector();
    }

    if (whichProgram == "4") {
        stringTokenizer();
        functionSelector();
    }

    if (whichProgram == "5") {
        help();
        functionSelector();
    }

    //This if statement is diffrent from the others as it ends the method and returns back to main to end the main class.
    if (whichProgram == "QUIT") {
        return 0;
    }

    //If the input didn't match anything above, it makes the user re-enter by restarting this method.
    else {
        std::cout << "Invalid input. Please select an appropriate action by entering in a valid number.\n\n";
        functionSelector();
    }
}

//Method with the purpose of perorming basic mathmatical calculations on two numbers at a time.
void mathCalculator() {

    //defines 3 variables to serve as the two numbers being perfomed on and one number as the final answer.
    double input1;
    double input2;
    double answer;

    //variable to let the user pick which math operation to perform.
    int whichOperation;

    //variable used when a user is deciding to perform another operation after one has been completed.
    std::string performNewOperation{ 'y' };

    //Like functionSelector(), this outputs what operations are available for the user to perform.
    //An input is then allowed for the user to select an operation.
    std::cout << "Select from the following menu by typing the associated number:\n";
    std::cout << "Addition (Enter 1)\n";
    std::cout << "Subtraction (Enter 2)\n";
    std::cout << "Multiplication (Enter 3)\n";
    std::cout << "Division (Enter 4)\n";
    std::cout << "Power (Enter 5)\n";
    std::cout << "Log2(n) (Enter 6)\n";
    std::cout << "Modules(%) (Enter 7)\n";
    std::cout << "Return to Main Menu (Enter 8)\n\n";
    std::cout << "Enter Your Selection: \n";
    std::cin >> whichOperation;

    //This serves an an addition calculator if selected by the user.
    if (whichOperation == 1) {

        //asks for users first and second numbers and allows input.
        std::cout << "Enter the first number you want to add: \n";
        std::cin >> input1;

        //basic data type check that forces user to re-enter input to correct data type.
        //As this code stays the same, it will appear consistently but will not be re-explained.
        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> input1;
        }

        std::cout << "Enter the second number you want to add: \n";
        std::cin >> input2;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> input2;
        }

        //performs addition operation on users input numbers.
        answer = input1 + input2;

        //outputs answer to user.
        std::cout << "The sum of these two numbers is " << answer << "\n\n";
    }

    //This serves as the subtraction calculator if selected by the user.
    if (whichOperation == 2) {

        //asks for users first and second numbers and allows input.
        std::cout << "Enter the first number you want to be subtracted from: \n";
        std::cin >> input1;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> input1;
        }

        std::cout << "Enter the second number you want to subtract: \n";
        std::cin >> input2;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> input2;
        }

        //performs subtraction operation on user input numbers.
        answer = input1 - input2;

        //outputs answer to user.
        std::cout << "The subtraction of these two numbers is " << answer << "\n\n";
    }

    //This serves as a multiplication calculator if selected by user.
    if (whichOperation == 3) {

        //asks for users first and second numbers and allows input.
        std::cout << "Enter the first number you want to multiply: \n";
        std::cin >> input1;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> input1;
        }

        std::cout << "Enter the second number you want to multiply: \n";
        std::cin >> input2;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> input2;
        }

        //performs multiplication operation on user input numbers.
        answer = input1 * input2;

        //outputs answer to user.
        std::cout << "The answer of these numbers multiplied is " << answer << "\n\n";
    }

    //performs division operation if selected by user.
    if (whichOperation == 4) {

        //asks for users first and second numbers and allows input.
        std::cout << "Enter the first number you want to be divided: \n";
        std::cin >> input1;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> input1;
        }

        std::cout << "Enter the second number you want to use to divide: \n";
        std::cin >> input2;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> input2;
        }

        //since division cannot use zero, user must re-enter second input if the choose zero.
        while (input2 == 0) {
            std::cout << "Error. second number cannot be zero. Please re-enter:";
            std::cin >> input2;
        }

        //performs division operation on user input numbers.
        answer = input1/input2;

        //outputs answer to user.
        std::cout << "The division of these two numbers is " << answer << "\n\n";
    }

    //performs base and power operation if selected by user.
    if (whichOperation == 5) {

        //asks for users first and second numbers and allows input.
        std::cout << "Enter the first number you want to be the base: \n";
        std::cin >> input1;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> input1;
        }

        std::cout << "Enter the second number you want to be the power: \n";
        std::cin >> input2;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> input2;
        }

        //performs base and power operation on user input numbers.
        answer = pow(input1, input2);

        //outputs answer to user.
        std::cout << "The power operation of these two numbers is " << answer << "\n\n";
    }

    //performs modules operation if selected by user.
    if (whichOperation == 6) {

        //defines three new int type variables are modules only works with int.
        int modules1;
        int modules2;
        int modulesAnswer;

        //asks for users first and second numbers and allows input. Then defines modules with input.
        std::cout << "Enter the first number you want to perform modules on: \n";
        std::cin >> input1;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> input1;
        }
        modules1 = input1;

        std::cout << "Enter the second number you perform modules with: \n";
        std::cin >> input2;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> input2;
        }
        modules2 = input2;

        //performs modules operation on user input numbers.
        modulesAnswer = modules1%modules2;

        //outputs answer to user.
        std::cout << "The modules of these two numbers is " << modulesAnswer << "\n\n";
    }

    //performs log2(n) operation if selected by user.
    if (whichOperation == 7) {

        //allows for one input from user.
        std::cout << "Enter the number you want to perform the operation on: \n";
        std::cin >> input1;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> input1;
        }

        //performs operation on user input.
        answer = log2(input1);

        //outputs answer to user.
        std::cout << "The Log2(n) of this number is " << answer << "\n\n";
    }

        //sends user back to functionSelector() by calling it to run if selected by user.
    if (whichOperation == 8) {
        functionSelector();
    }

    //statements runs if none of the above options were selected.
    if (std::cin.fail() or whichOperation > 8 or whichOperation < 1)
    {
        //tells tells the user to enter a valid input then clears the input and allows for a new one to be entered.
        std::cout << "Invalid input. Please select an appropriate action by entering in a valid number.\n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //re-runs method to allow for new selection.
        mathCalculator();
    }

    //asks user if they want to perform another operation and allows for input.
    std::cout << "Would you like to convert again? (enter y or n):\n";
    std::cin >> performNewOperation;

    //makes user re-enter is input in incorrect.
    while (performNewOperation != "y" and performNewOperation != "n") {
        std::cout << "Invalid input. Please re-enter:\n";
        std::cin >> performNewOperation;
    }

    //if the user wants to perform another operaton, the method runs again.
    if (performNewOperation == "y") {
        mathCalculator();
    }

    //returns to function selector.

}

//method to perform metric conversions.
void metricConversionCalculator(){
    
    //varibales declared to hold the number a user wants to convert and the number after is has been converted.
    double numberToConvert;
    double numberConverted;

    //variable designed to help select which conversion to perform.
    int whichConversion;

    //variable used when a user decides whether or not to make another conversion.
    std::string makeAnotherConversion{"y"};

    //this variables are used in the conversion process.
    //conversion numbers taken from online.
    double OneKphToMph{0.621};
    double OneMphToKph{1.61};
    double OneMeterToFoot{3.28};
    double OneFootToMeter{0.305};

    //tells the user what conversions can be performed and allows for user input.
    std::cout << "Select from the following menu by typing the associated number:\n";
    std::cout << "Miles Per Hour to Kilometers Per Hour (Enter 1)\n";
    std::cout << "Kilometers Per Hour to Miles Per Hour (Enter 2)\n";
    std::cout << "Celcius to Fahrenheit (Enter 3)\n";
    std::cout << "Fahrenheit to Celcius (Enter 4)\n";
    std::cout << "Meters to Feet (Enter 5)\n";
    std::cout << "Feet to Meters (Enter 6)\n";
    std::cout << "Return to Main Menu (Enter 7)\n\n";
    std::cout << "Enter Your Selection: \n";
    std::cin >> whichConversion;
    std::cout << "\n";

    //converts miles per hour to kilometers per hour if selected.
    if (whichConversion == 1) {

        //allows user to enter input in miles per hour.
        std::cout << "Enter your number in MPH to see it in KPH: \n";
        std::cin >> numberToConvert;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> numberToConvert;
        }

        //performs conversion to kilometers per hour.
        numberConverted = numberToConvert* OneMphToKph;

        //outputs conversion
        std::cout << numberToConvert << " MPH is equal to " << numberConverted << " KPH\n\n";
    }

    //converts kilometers per hour to miles per hour if selected.
    if (whichConversion == 2) {

        //allows user to enter input in kilometers per hour.
        std::cout << "Enter your number in KPH to see it in MPH: \n";
        std::cin >> numberToConvert;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> numberToConvert;
        }

        //performs converion
        numberConverted = numberToConvert*OneKphToMph;

        //outputs conversion
        std::cout << numberToConvert << " KPH is equal to " << numberConverted << " MPH\n\n";
    }

    //converts celcius to fahrenheit if selected.
    if (whichConversion == 3) {

        //allows user to enter input in celcius
        std::cout << "Enter your number in Celcius to see it in Fahrenheit: \n";
        std::cin >> numberToConvert;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> numberToConvert;
        }

        //performs conversion based on online formula.
        numberConverted = ((numberToConvert * 1.8) + 32);

        //outputs conversion
        std::cout << numberToConvert << " degrees Celcius is equal to " << numberConverted << " degrees Fahrenheit\n\n";
    }

    //converts fahrenheit to celcius if selected.
    if (whichConversion == 4) {

        //allows user to enter input in fahrenheit
        std::cout << "Enter your number in Fahrenheit to see it in Celcius: \n";
        std::cin >> numberToConvert;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> numberToConvert;
        }

        //performs conversion based on online formula.
        numberConverted = ((numberToConvert -32) * 1.8);

        //outputs conversion.
        std::cout << numberToConvert << " degrees Fahrenheit is equal to " << numberConverted << " degrees Celcius\n\n";
    }

    //converts meters to feet if selected.
    if (whichConversion == 5) {

        //allows user to enter input in meters.
        std::cout << "Enter your number in Meters to see it in Feet: \n";
        std::cin >> numberToConvert;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> numberToConvert;
        }

        //performs conversion
        numberConverted = numberToConvert * OneMeterToFoot;

        //outputs conversion
        std::cout << numberToConvert << " Meters is equal to " << numberConverted << " Feet\n\n";
    }

    //converts feet to meters is selected.
    if (whichConversion == 6) {

        //allows user to enter input in feet
        std::cout << "Enter your number in Feet to see it in Meters: \n";
        std::cin >> numberToConvert;

        while (std::cin.fail()) {
            std::cout << "incorrect input. Must be a number. Re-enter: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> numberToConvert;
        }

        //performs conversion
        numberConverted = numberToConvert * OneFootToMeter;

        //outputs conversion
        std::cout << numberToConvert << " Feet is equal to " << numberConverted << " Meters\n\n";
    }

    //returns user to functionSelector() is selected by user.
    if (whichConversion == 7) {
        functionSelector();
    }

    //runs if user did not input one of the options listed above.
    if (std::cin.fail() or whichConversion > 7 or whichConversion < 1)
    {
        //tells the user their input was not correct.
        //clears the inpu variable so it can be re-entered into.
        std::cout << "Invalid input. Please select an appropriate action by entering in a valid number.\n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //re-starts method to allow for new input.
        metricConversionCalculator();
    }

    //asls user if they want to perform another conversion and allows for input.
    std::cout << "Would you like to convert again? (enter y or n):\n";
    std::cin >> makeAnotherConversion;

    //forces user to re-enter until input for above is correct.
    while (makeAnotherConversion != "y" and makeAnotherConversion != "n") {
        std::cout << "Invalid input. Please re-enter:\n";
        std::cin >> makeAnotherConversion;
    }

    std::cout << "\n";

    //if the user chooses to convert again, the method re-runs.
    if (makeAnotherConversion == "y") {
        metricConversionCalculator();
    }

    //returns to functionSelector();
}

//method to take an external file and perform operations on it to find a final grade based on a students scores.
void gradesCalculator() {

    //string defined to store a line from a file.
    std::string lineInFile;

    //used for loops. this variable is equal to the amount of items on each line. This number is known.
    int numberOfLineItems{ 6 };

    //used to hold the final grade of a student.
    int studentGrade{ 0 };

    //defines an array to hold all of the student scores.
    int grades[5];

    //informs user of the file being read from and makes an variable to hold the file being specified.
    std::cout << "Welcome to Grade Calculator. The following scores come from the file named Program1-Data.txt.\n\n";
    std::ifstream fileToRead("Program1-Data.txt");

    //As long as a line exists to read, the following lines perform.
    while (getline(fileToRead, lineInFile)) {

        //defines a new string array to hold items in file/
        std::string gradeOfStudent[6];

        //defines a stringstream using the line currently being read from the file.
        std::stringstream stringStream(lineInFile);

        //defines an i variable to be used in multiple loops/statements below.
        int i{ 0 };

        //while there are still items in the line this loop continues.
        while (stringStream.good()) {

            //defines a variable testGrade to hold an item from the file.
            std::string testGrade;

            //items in the line being read are seperated by comma and placed into the gradeOfStudent string array to be held for later.
            std::getline(stringStream, testGrade, ',');
            gradeOfStudent[i] = testGrade;
            i++;
        }
        //there are now six items in the gradeOfStudent arrray. one name and six grades.

        //for loop that runs through each item now in gradeOfStudent array.
        for (i = 0; i < numberOfLineItems; i++) {

            //checks which item it is looking at based on location in array.
            //item from array is then output with appropriate nececary information about what the item represents.
            if (i == 0){
                std::cout << gradeOfStudent[i] << "\n";
            }
            if (i == 1) {
                std::cout << gradeOfStudent[i] << "% on Labs.\n";
            }
            if (i == 2) {
                std::cout << gradeOfStudent[i] << "% on Quizzes.\n";
            }
            if (i == 3) {
                std::cout << gradeOfStudent[i] << "% on projects.\n";
            }
            if (i == 4) {
                std::cout << gradeOfStudent[i] << "% on Midterm. \n";
            }
            if (i == 5) {
                std::cout << gradeOfStudent[i] << "% on Final.\n";
            }
        }

        //for loop designed to turn numbers in gradeOfStudent into int data type and put them in seperate array.
        //array starts at one a the first item in gradeOfStudent is a name, not a number, and should not be added to grades array.
        for (i = 1; i < numberOfLineItems; i++) {
            //as grades starts at zero and gradeOfStudent needs to start at one, appropriate math is performed on i.
            //all numbers in gradeOfStudent are turned into int by stoi command and put into grades array.
            grades[i - 1] = stoi(gradeOfStudent[i]);
        }

        //for loop that runs through grades array and adds them all to the student grade variable as a sum.
        for (i = 0; i < 5; i++) {
            studentGrade = studentGrade + grades[i];
        }

        //divides the studentGrade variable by 5 to find the average.
        //five is used as there are five test scores being added to studentGrade.
        studentGrade = studentGrade / 5;

        //Outputs the final studentGrade as a percentage.
        std::cout << "With all Grades weight equally at 20%, Students final grade percentage was " << studentGrade << "%.\n";


        //If ststements run that check the users grade and assign it the proper grade based on normal grading systems.
        //final grade is output to the user.
         if (studentGrade >= 90) {
           std::cout << gradeOfStudent[0] << "'s Final Grade is A.";
         }
         if (studentGrade >= 80 and studentGrade <= 89) {
             std::cout << gradeOfStudent[0] << "'s Final Grade is B.";
         }
         if (studentGrade >= 70 and studentGrade <= 79) {
             std::cout << gradeOfStudent[0] << "'s Final Grade is C.";
         }
         if (studentGrade >= 60 and studentGrade <= 69) {
             std::cout << gradeOfStudent[0] << "'s Final Grade is D.";
         }
         if (studentGrade <= 59) {
             std::cout << gradeOfStudent[0] << "'s Final Grade is F.";
         }
        

        //sets studentGrade to 0 again so it can be used again for a new student.
        studentGrade = 0;
        std::cout << "\n\n";

        //line printed for formatting purposes.
        std::cout << "--------" << "\n";

    }

}

//method to take a user input string and perfrom various actions on it.
void stringTokenizer() {

    //defines the line the user is going to input.
    std::string inputLine{};

    //user inputs into this variable to search for a word in the input line.
    std::string wordToSearch;

    //used to run the method again after completed if desired by user
    std::string makeAnotherLine;

    //Hold the length of the input line and the length of the word being searched for.
    int inputLineLength;
    int wordToSearchLength;

    //defines variables that hold the amount of letters, uppercase words, and words from input line.
    int amountOfLetters{ 0 };
    int amountOfUpperCaseWords{ 0 };
    int amountOfWords{ 0 };

    //tells user to input line.
    std::cout << "Enter a line of text with proper grammar to see various stats and information about it (Full details in help)\n";
    std::cout << ("Enter Line: ");
    //used so user input does not get skipped over.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //allows for user input of line to examine.
    getline(std::cin, inputLine);
    std::cout << "\n";

    //holds character length of input line to use for later.
    inputLineLength = inputLine.size();

    //for loop that goes through each character in the line.
    //if the character is an uppercase (isupper function) or lowercase (islower function) it adds one to amountOfLetters variable.
    for (int i = 0; i <= inputLineLength; i++) {
        if (isupper(inputLine[i]) or islower(inputLine[i])) {
            amountOfLetters += 1;
        }
    }
    //outputs the total amount of letters in line after loop has figured out amount.
    std::cout << "Number of letters in line is " << amountOfLetters << ". \n";

    //for loop to find amount of words by running through every character in line.
    for (int i = 0; i <= inputLineLength; i++) {

        //if there is a space, that means a new word exists after that space and one is added to the total amountOfWords.
        if (isspace(inputLine[i])) {
            amountOfWords += 1;
        }
    }

    //an additional one is added to account for the first word in the line as there is not a space before that word.
    amountOfWords += 1;

    //outputs the total number of words.
    std::cout << "Number of words in line is " << amountOfWords << ". \n";

    //loops that finds the amountOfuppercase words in the line by running through each charater.
    for (int i = 0; i <= inputLineLength; i++) {
        if (isspace(inputLine[i]) and (isupper(inputLine[i + 1]) or isupper(inputLine[i + 2]))) {
            //as an uppercase word can only follow a space or a space and a punctuation (" " or ". "), those spaces can be used to determined amount of uppercase words.
            //also uses the fact that an uppercase letter is being used.
            amountOfUpperCaseWords += 1;
        }
    }

    //checks if the first word is also uppercase as the previous loop does not account for it.
    if (isupper(inputLine[0])) {
        amountOfUpperCaseWords += 1;
    }

    //outputs total number of uppercase words.
    std::cout << "Number of Upper Case Words in line is " << amountOfUpperCaseWords << ". \n";

    //desgiedn to output the line backwards.
    std::cout << "Entered line backwards: ";

    //for loop that runs through each character and outputs the opposite-placed character in the line.
    //result is the line appearing backwards.
    for (int i = 0; i <= inputLineLength; i++) {
        std::cout << inputLine[inputLineLength - i];
    }
    std::cout << "\n\n";

    //allows the user to enter a line to search for in the line then allows for input.
    //variable then stores the word size.
    std::cout << "Enter a word you would like to search for in the line: ";
    std::cin >> wordToSearch;
    wordToSearchLength = wordToSearch.size();

    //uses the find function to search for the word and uses npos to avoid going outside of line length.
    //if-else statements thn display whether or not the word was found.
    if (inputLine.find(wordToSearch) != std::string::npos) {
        std::cout << "Word was Found\n";
    }
    else {
        std::cout << "Word was not Found\n";
    }

    //asks the user whether or not thy want to perform these actions for another line and allows for input.
    std::cout << "Would you like to perform these action on another line? (enter y or n):\n";
    std::cin >> makeAnotherLine;

    //if input is not desired, forces user to re-enter until desired input aquired.
    while (makeAnotherLine != "y" and makeAnotherLine != "n") {
        std::cout << "Invalid input. Please re-enter:\n";
        std::cin >> makeAnotherLine;
    }

    std::cout << "\n";

    //if the user wants to enter another line the method is called recursivly.
    if (makeAnotherLine == "y") {
        stringTokenizer();
    }

    //returns to functionSelector();
}

//method that displays help and info about the methods that can be performed.
void help() {
    //statements are output that explain what each method does.
    std::cout << "Welcome to the help menu. This menu contains detailed descriptions on each program.\n\n";
    std::cout << "Math Calculator: Perform basic mathmatical functions on 2 numbers of the users choice. Addition, Subtraction, Multiplication, Division, Power, Log2(n), and Modules are all possible.\n\n";
    std::cout << "Metric Conversion Calculator: Allows you to convert Mph to Kph, Fahrenheit to Celcius, and Meters to Feet. Vice-Versa also applies respectivly.\n\n";
    std::cout << "Grades Calculator: Takes a pre-given file containing grades of students and assigns them letter grades based on their class scores.\n\n";
    std::cout << "String Tokenizer: Takes a full line of text and returns the total number of letters words, pritns the line backwards, returns all words that start with a capital letter, and allows a user to check if a word is in the line.\n\n";
    std::cout << "Returning to main selection screen. \n\n";

    //once messages are displayed, the user returns to functionSelector()
}

//end of methods/program.


