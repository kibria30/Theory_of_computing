#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Transition {
    std::string nextState;
    char symbol;
};

typedef std::map<std::string, std::vector<Transition>> DFATable;

// Function to compute regular expressions
std::string computeRegularExpression(const DFATable& dfa, const std::string& startState, const std::string& endState, int steps) {
    if (steps == 0) {
        if (startState == endState) {
            return "ε";
        } else {
            return "";
        }
    }

    std::string result;

    for (const Transition& transition : dfa.at(startState)) {
        std::string transitionExpr = transition.symbol + computeRegularExpression(dfa, transition.nextState, endState, steps - 1);
        if (!result.empty()) {
            result += "+";
        }
        result += transitionExpr;
    }

    return result;
}

int main() {
    // Define the DFA table
    DFATable dfa = {
        {"q1", {{"q2", '0'}, {"q1", '1'}}},
        {"q2", {{"q3", '0'}, {"q1", '1'}}},
        {"q3", {{"q3", '0'}, {"q2", '1'}}}
    };

    std::string startState = "q1";
    std::string endState = "q3";
    int intermediateSteps = 2;

    std::string regex = computeRegularExpression(dfa, startState, endState, intermediateSteps);

    if (!regex.empty()) {
        std::cout << "Regular expression from state " << startState << " to state " << endState << " with " << intermediateSteps << " intermediate steps: " << regex << std::endl;
    } else {
        std::cout << "No regular expression found for the given parameters." << std::endl;
    }

    return 0;
}
