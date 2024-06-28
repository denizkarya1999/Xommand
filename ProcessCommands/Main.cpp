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

// Define integer values for each state with upper case names
enum State {
    INSTALL = 1,
    UNINSTALL = 2,
    REPAIR = 3,
    DUPLICATE = 4,
    SELL = 5,
    DEVELOP = 6,
    DEBUG = 7,
    TEST = 8,
    AUTOMATE = 9,
    ANALYZE = 10,
    DOCUMENT = 11,
    INTEGRATE = 12,
    OPTIMIZE = 13,
    COMPILE = 14,
    DEPLOY = 15,
    REFACTOR = 16,
    SIMULATE = 17,
    VISUALIZE = 18,
    MAINTAIN = 19,
    BACKUP = 20
};

constexpr unsigned int Main::hash(const char* s, int off) {
    return !s[off] ? 5381 : (hash(s, off + 1) * 33) ^ s[off];
}

// Function to convert string to state integer
int Main::getState(const std::string& state) {
    switch (hash(state.c_str())) {
    case hash("install", 0): return INSTALL;
    case hash("uninstall", 0): return UNINSTALL;
    case hash("repair", 0): return REPAIR;
    case hash("duplicate", 0): return DUPLICATE;
    case hash("sell", 0): return SELL;
    case hash("develop", 0): return DEVELOP;
    case hash("debug", 0): return DEBUG;
    case hash("test", 0): return TEST;
    case hash("automate", 0): return AUTOMATE;
    case hash("analyze", 0): return ANALYZE;
    case hash("document", 0): return DOCUMENT;
    case hash("integrate", 0): return INTEGRATE;
    case hash("optimize", 0): return OPTIMIZE;
    case hash("compile", 0): return COMPILE;
    case hash("deploy", 0): return DEPLOY;
    case hash("refactor", 0): return REFACTOR;
    case hash("simulate", 0): return SIMULATE;
    case hash("visualize", 0): return VISUALIZE;
    case hash("maintain", 0): return MAINTAIN;
    case hash("backup", 0): return BACKUP;
    default: return -1;
    }
}


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

// Determine the actions based on command and the word received. (uses Switch statements) <Make a much better algorithm here >
bool Main::processCommandsWithSwitch(const vector<string>& commands) {
    // Get the first command.
    string command = commands[0];

    // Get the equivalent state from the command.
    int state = getState(command);

    switch (state) {
    case INSTALL:
        return true;
    case UNINSTALL:
        return true;
    case REPAIR:
        return true;
    case DUPLICATE:
        return true;
    case SELL:
        return true;
    case DEVELOP:
        return true;
    case DEBUG:
        return true;
    case TEST:
        return true;;
    case AUTOMATE:
        return true;
    case ANALYZE:
        return true;;
    case DOCUMENT:
        return true;;
    case INTEGRATE:
        return true;
    case OPTIMIZE:
        return true;
    case COMPILE:
        return true;
    case DEPLOY:
        return true;
    case REFACTOR:
        return true;
    case SIMULATE:
        return true;
    case VISUALIZE:
        return true;
    case MAINTAIN:
        return true;;
    case BACKUP:
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
        //const auto before1 = clock::now(); //use time_point is better?
        //action_Is_Succcessful = processCommandsWithSwitch(words);
        //const ms duration1 = clock::now() - before1;
        //std::cout << "Processing with Regular Switch statements took " << duration1.count() << " milliseconds." << std::endl;

        //Process it with a Fastest Switch statement and calculate the time.
        const auto before3 = clock::now(); //use time_point is better?
        action_Is_Succcessful = processCommandsWithSwitch(words);
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
