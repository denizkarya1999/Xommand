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
string Main::translateCommandstoNumber(const vector<string>& commands) {
    string generatedResult = numberGenerator(commands); //Initiliaze the generatedResult with numberGenerator method.
    return generatedResult; //Return the result
}

string Main::numberGenerator(const vector<string>& commands) {
    // Alphabet and their corresponding indexes
    std::unordered_map<char, int> alphabetIndex = {
        {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}, {'h', 8},
        {'i', 9}, {'j', 10}, {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'o', 15}, {'p', 16},
        {'q', 17}, {'r', 18}, {'s', 19}, {'t', 20}, {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24},
        {'y', 25}, {'z', 26}
    };
    
    std::string indexNumbers;
    
    string firstCommand = commands[0]; //Store the first command

    // Loop through each character in the input string
    for (char ch : firstCommand) {
        auto it = alphabetIndex.find(ch);
        if (it != alphabetIndex.end()) {
            indexNumbers += std::to_string(it->second);
        }
    }

    return indexNumbers;
}

// Determine the actions based on command and the word received. (uses Switch statements) <Make a much better algorithm here >
bool Main::processCommandsWithSwitch(const std::string& translatedCommand) {
    try {
        long long commandNumber = std::stoll(translatedCommand);

        switch (commandNumber) {
        case 914192011212: // "install"
            return true;
        case 2114914192011212: // "uninstall"
            return true;
        case 185161918: // "repair"
            return true;
        case 431621218194: // "duplicate"
            return true;
        case 1951212: // "sell"
            return true;
        case 45225121516: // "develop"
            return true;
        case 452217: // "debug"
            return true;
        case 2051920: // "test"
            return true;
        case 1212015131205: // "automate"
            return true;
        case 11411225265: // "analyze"
            return true;
        case 4153211351420: // "document"
            return true;
        case 9142057181205: // "integrate"
            return true;
        case 1516209139265: // "optimize"
            return true;
        case 31513169125: // "compile"
            return true;
        case 4516121525: // "deploy"
            return true;
        case 185613201518: // "refactor"
            return true;
        case 1991321121205: // "simulate"
            return true;
        case 22919211129265: // "visualize"
            return true;
        case 131914201914: // "maintain"
            return true;
        case 213112116: // "backup"
            return true;
        default:
            return false;
        }
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        return false;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
        return false;
    }
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
        string translatedCommand = translateCommandstoNumber(words);
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
