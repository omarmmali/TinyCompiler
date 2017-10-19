#include "utilities.h"

class DFA {
private:
    int initial_state; // DFA's root node (q0)
    int current_state; // The current state the input has reached 
    set <int> states; // The set of all states
    set <int> final_states; // The set of all final states (To improve Complexity)
    map <pair<int,char>, int> transitions; // The set of all transitions (Edges), which is a tuple of (source, edge value, destination) 
public:
    DFA();
    void add_state(int, bool);
    void add_transition(int, char, int);
    bool is_accepted();
    bool will_accept(char);
    void reset();
    int insert(char);
    int get_current_state();
    ~DFA();
};