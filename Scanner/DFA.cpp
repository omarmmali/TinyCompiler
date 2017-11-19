#include "DFA.h"

// Initialize DFA
DFA::DFA() {
    initial_state = current_state = 0;
    add_state(0, false);
    add_state(-1, false);
}

// Adds a state to the DFA's set of states, and to the set of final if is_final == 1
void DFA::add_state(int state_id, bool is_final) {
    states.insert(state_id);
    if(is_final) {
        final_states.insert(state_id);
    }
}

// Adds a transition to the DFA's set of transitions
void DFA::add_transition(int source, char edge_value, int destination) {
    std::pair<int,char> edge = std::make_pair(source, edge_value);
    transitions.insert(std::make_pair(edge, destination));
}

// Checks whether the state currently reached is an acceptable final state
bool DFA::is_accepted() {
    return final_states.count(current_state);
}

// Checks whether the state reached after taking the next transition will be accepted or not (stopping condition for Tokenizer)
bool DFA::will_accept(char next) {
    std::pair<int,char> cur_transition = std::make_pair(current_state, next);

    if(transitions.count(cur_transition)) {
        std::map<std::pair<int,char>, int>::iterator edge = transitions.find(cur_transition);
        return final_states.count(edge->second);
    }
    return false;
}

// Points back to the initial state (q0)
void DFA::reset() {
    current_state = initial_state;
}

// Inserts a character to the DFA (Moves along the edges)
int DFA::insert(char in) {
    std::pair<int, char> cur_transition = std::make_pair(current_state,in);

    if(transitions.count(cur_transition)) {
        std::map<std::pair<int,char>, int>::iterator edge = transitions.find(cur_transition);
        current_state = edge->second;
    }
    else {
        current_state = -1;
    }
    return current_state;
}


// Return the DFA's current state
int DFA::get_current_state() {
    return current_state;
}

DFA::~DFA() {}