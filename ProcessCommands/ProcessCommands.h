#pragma once
#include <vector>
#include <string>

using namespace std;

namespace ProcessCommands {

    class Main {
        static string userCommand; // Sets the user command.
        static string action_performed; // Sets the action performed.
        static bool action_Is_Succcessful; // A boolean expression to check whether the action was successful or not.

    public:
        static int main(); // Function to run the main logic.
        static vector<string> ParseWords(const string& input); // Detect every single word and put them in a string.
        static int translateCommandstoNumber(const vector<string>& commands); // Translates commands into a number
        static bool processCommandsWithSwitch(int translatedCommand); // Determine the actions based on command and the word received. (uses Switch statements)
        static bool processCommandsWithIf(const vector<string>& commands); // Determine the actions based on command and the word received. (uses If-Else statements)
    };

}