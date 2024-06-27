#include "ProcessCommands.h"
#include "String.h"
#include <iostream>
#include <regex>
#include <chrono>
#include <unordered_map>

using namespace std;
using namespace ProcessCommands;

string Main::userCommand; // Sets the user command.
string Main::action_performed; // Sets the action performed.
bool Main::action_Is_Succcessful; // A boolean expression to check whether the action was successful or not.

// Detect every single word and put them in a string.
vector<string> Main::ParseWords(const string& input) {
    // Use a regular expression to find words.
    regex wordRegex(R"(\b\w+\b)");
    sregex_iterator wordsBegin = sregex_iterator(input.begin(), input.end(), wordRegex);
    sregex_iterator wordsEnd = sregex_iterator();

    // A variable to store the words.
    vector<string> words;

    // In each Regex match, add the value to the list.
    for (sregex_iterator i = wordsBegin; i != wordsEnd; ++i) {
        smatch match = *i;
        words.push_back(match.str());
    }

    // Return the vector.
    return words;
}

// Translates commands into a number <Make a much better algorithm here>
int Main::translateCommandstoNumber(const vector<string>& commands) {
    int asciiResult = 0; // Store the ASCII value
    string firstCommand = commands[0]; //Store the first command

    // Make the raw command processible
    string lowercaseCommand = firstCommand;
    transform(lowercaseCommand.begin(), lowercaseCommand.end(), lowercaseCommand.begin(), ::tolower);

    // Add ASCII characters based on the string
    for (int i = 0; i < lowercaseCommand.size(); i++) {
        asciiResult += int(lowercaseCommand[i]);
    }

    return asciiResult;
}

int numberGenerator(const std::string& target) {
    // Alphabet and their corresponding indexes
    std::unordered_map<char, int> alphabetIndex = {
        {'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7},
        {'I', 8}, {'J', 9}, {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14}, {'P', 15},
        {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19}, {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23},
        {'Y', 24}, {'Z', 25}
    };
    
    std::string indexNumbers;
    
    // Loop through each character in the input string
    for (char ch : target) {
        indexNumbers += std::to_string(alphabetIndex[ch]);
    }
    
    // Convert the concatenated string of numbers to an integer
    int generatedNumber = std::stoi(indexNumbers);
    
    return generatedNumber;
}

// Determine the actions based on command and the word received. (uses Switch statements) <Make a much better algorithm here >
bool Main::processCommandsWithSwitch(int translatedCommand) {
    switch (translatedCommand) {
    case 759: //"install" is recieved
        //action_performed = "Installation";
        return true;
    case 986: //"uninstall" is recieved
        //action_performed = "Uninstallation";
        return true;
    case 643: //"repair" is recieved
        //action_performed = "Repair";
        return true;
    case 955: //"duplicate" is recieved
        //action_performed = "Duplicate";
        return true; 
    case 432: //"sell" is recieved
        //action_performed = "Sell";
        return true;
    case 751: //"develop" is recieved.
        return true;
    case 519: //"debug" is recieved.
        return true;
    case 448: //"test" is recieved.
        return true;
    case 864: //"automate" is recieved.
        return true;
    case 756: //"analyze" is recieved.
        return true;
    case 863: //"document" is recieved.
        return true;
    case 963: //"integrate" is recieved.
        return true;
    case 881: //"optimize" is recieved.
        return true;
    case 745: //"compile" is recieved.
        return true;
    case 653: //"deploy" is recieved.
        return true;
    case 854: //"refactor" is recieved.
        return true;
    case 868: //"simulate" is recieved.
        return true;
    case 988: //"visualize" is recieved.
        return true;
    case 849: //"maintain" is recieved.
        return true;
    case 630: //"backup" is recieved.
        return true;
    }
    return false;
}

// Determine the actions based on command and the word received. (uses If-Else statements)
bool Main::processCommandsWithIf(const vector<string>& commands) {
    for (const auto& command : commands) {
        // Make the raw command processible
        string lowercaseCommand = command;
        transform(lowercaseCommand.begin(), lowercaseCommand.end(), lowercaseCommand.begin(), ::tolower);

        //Make a variable to store the processed command.
        char processedCommand[100];
        copy(lowercaseCommand.begin(), lowercaseCommand.end(), processedCommand);

        // Make decision based on the string.
        if (_strnicmp(processedCommand, "install", 7)) {
            //action_performed = "Installation";
            return true;
        }
        else if (_strnicmp(processedCommand, "uninstall", 9)) {
            //action_performed = "Uninstallation";
            return true;
        }
        else if (_strnicmp(processedCommand, "repair", 6)) {
            //action_performed = "Repair";
            return true;
        }
        else if (_strnicmp(processedCommand, "duplicate", 9)) {
            //action_performed = "Duplicate";
            return true;
        }
        else if (_strnicmp(processedCommand, "sell", 4)) {
            //action_performed = "Sell";
            return true;
        }
        else if (_strnicmp(processedCommand, "develop", 7)) {
            // action_performed = "Develop";
            return true;
        }
        else if (_strnicmp(processedCommand, "debug", 5)) {
            // action_performed = "Debug";
            return true;
        }
        else if (_strnicmp(processedCommand, "test", 4)) {
            // action_performed = "Test";
            return true;
        }
        else if (_strnicmp(processedCommand, "automate", 8)) {
            // action_performed = "Automate";
            return true;
        }
        else if (_strnicmp(processedCommand, "analyze", 7)) {
            // action_performed = "Analyze";
            return true;
        }
        else if (_strnicmp(processedCommand, "document", 8)) {
            // action_performed = "Document";
            return true;
        }
        else if (_strnicmp(processedCommand, "integrate", 9)) {
            // action_performed = "Integrate";
            return true;
        }
        else if (_strnicmp(processedCommand, "optimize", 8)) {
            // action_performed = "Optimize";
            return true;
        }
        else if (_strnicmp(processedCommand, "compile", 7)) {
            // action_performed = "Compile";
            return true;
        }
        else if (_strnicmp(processedCommand, "deploy", 6)) {
            // action_performed = "Deploy";
            return true;
        }
        else if (_strnicmp(processedCommand, "refactor", 8)) {
            // action_performed = "Refactor";
            return true;
        }
        else if (_strnicmp(processedCommand, "simulate", 8)) {
            // action_performed = "Simulate";
            return true;
        }
        else if (_strnicmp(processedCommand, "visualize", 9)) {
            // action_performed = "Visualize";
            return true;
        }
        else if (_strnicmp(processedCommand, "maintain", 8)) {
            // action_performed = "Maintain";
            return true;
        }
        else if (_strnicmp(processedCommand, "backup", 6)) {
            // action_performed = "Backup";
            return true;
        }
        else {
            return 0;
        }
    }
    return false;
}

// Function to run the main logic.
int Main::main() {
    // Test the 
    const string commands[] = {
    "install software",
    "uninstall application",
    "repair database",
    "duplicate file",
    "sell product",
    "develop module",
    "debug code",
    "test functionality",
    "automate process",
    "analyze data",
    "document procedures",
    "integrate system",
    "optimize performance",
    "compile project",
    "deploy application",
    "refactor code",
    "simulate environment",
    "visualize results",
    "maintain server",
    "backup data"
    };

    for (string userCommand : commands) {
        // Input commands from the user.
        //cout << "Please enter a command: " << endl;
        //getline(cin, userCommand);

        //Blank space
        std::cout << "" << endl;

        //Show the name of the command
        std::cout << userCommand << endl;

       // Trim the string into words.
        vector<string> words = ParseWords(userCommand);

        // Setup timing variables.
        using clock = std::chrono::system_clock;
        using ms = std::chrono::duration<double, std::milli>;

        //Process it with an if-else statement and calculate the time.
        const auto before2 = clock::now(); //use time_point is better?
        action_Is_Succcessful = processCommandsWithIf(words);
        const ms duration2 = clock::now() - before2;
        std::cout << "Processing with If-Else statement took " << duration2.count() << " milliseconds." << std::endl;

        //Process it with a Regular Switch statement and calculate the time.
        const auto before1 = clock::now(); //use time_point is better?
        int translatedCommand = translateCommandstoNumber(words);
        action_Is_Succcessful = processCommandsWithSwitch(translatedCommand);
        const ms duration1 = clock::now() - before1;
        std::cout << "Processing with Regular Switch statements took " << duration1.count() << " milliseconds." << std::endl;

        //Process it with a Fastest Switch statement and calculate the time.
        const auto before3 = clock::now(); //use time_point is better?
        action_Is_Succcessful = processCommandsWithSwitch(translatedCommand);
        const ms duration3 = clock::now() - before3;
        std::cout << "Processing with Fastest Switch statements as possible took " << duration3.count() << " milliseconds." << std::endl;

        //std::cout << "" << endl;

        if (action_Is_Succcessful) {
            //cout << "Detected action: " << action_performed << endl;
        }
        else
        {
            cout << "An error occured identifying the command. - E001" << endl;
        }
    }
   
    return 0;
}

int main() {
    return Main::main();
}
