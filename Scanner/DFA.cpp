// #include "DFA.h"

// // Initialize DFA
// template<typename T>
// DFA<T>::DFA() {
//     initial_state = current_state = 0;
//     add_state(0, false);
//     add_state(-1, false);
// }

// // Adds a state to the DFA's set of states, and to the set of final if is_final == 1
// template<typename T>
// void DFA<T>::add_state(int state_id, bool is_final) {
//     states.insert(state_id);
//     if(is_final) {
//         final_states.insert(state_id);
//     }
// }

// // Adds a transition to the DFA's set of transitions
// template<typename T>
// void DFA<T>::add_transition(int source, T edge_value, int destination) {
//     std::pair<int,char> edge = std::make_pair(source, edge_value);
//     transitions.insert(std::make_pair(edge, destination));
// }

// // Checks whether the state currently reached is an acceptable final state
// template<typename T>
// bool DFA<T>::is_accepted() {
//     return final_states.count(current_state);
// }

// // Checks whether the state reached after taking the next transition will be accepted or not (stopping condition for Tokenizer)
// template<typename T>
// bool DFA<T>::will_accept(T next) {
//     std::pair<int, T> cur_transition = std::make_pair(current_state, next);

//     if(transitions.count(cur_transition)) {
//         auto edge = transitions.find(cur_transition);
//         return final_states.count(edge->second);
//     }
//     return false;
// }

// // Points back to the initial state (q0)
// template<typename T>
// void DFA<T>::reset() {
//     current_state = initial_state;
// }

// // Inserts a character to the DFA (Moves along the edges)
// template<typename T>
// int DFA<T>::insert(T in) {
//     std::pair<int, T> cur_transition = std::make_pair(current_state,in);

//     if(transitions.count(cur_transition)) {
//         auto edge = transitions.find(cur_transition);
//         current_state = edge->second;
//     }
//     else {
//         current_state = -1;
//     }
//     return current_state;
// }


// // Return the DFA's current state
// template<typename T>
// int DFA<T>::get_current_state() {
//     return current_state;
// }

// template<typename T>
// DFA<T>::~DFA() {}