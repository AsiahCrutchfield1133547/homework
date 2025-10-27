#include <iostream>
#include <vector>
using namespace std;

void robotTurns(int turns) {
    int left = -1;
    int right = 1;
    int instructions;
    int position = 0;
    vector<int> cases;
    vector<int> actions;
    int randTurn;

    cout << "The number cases in this run is [" << turns << "].\n";
    cout << "----\n";

    for (int i = 0; i < turns; i++) {
        int turnNum = i+1;
        instructions = (rand() % 10) + 3; // range: 1–10

        actions.clear();
        position = 0; 

        cout << "Case #" << turnNum << " has " << instructions << " instructions.\n";
        for (int j = 0; j < instructions; j++) {
            int choice = rand() % 3; // 0 = LEFT, 1 = RIGHT, 2 = SAME AS i
            
            cout << j+1 << ") ";
            if (choice == 0) {
                actions.push_back(-1);
                position -= 1;
                cout << "LEFT\n";
            } else if (choice == 1) {
                actions.push_back(1);
                position += 1;
                cout << "RIGHT\n";
            } else {
                if (actions.empty()) {
                    // Fallback to LEFT or RIGHT if no previous instruction exists yet
                    int fallback = rand() % 2;
                    if (fallback == 0) {
                        actions.push_back(-1);
                        position -= 1;
                        cout << "LEFT\n";
                    } else {
                        actions.push_back(1);
                        position += 1;
                        cout << "RIGHT\n";
                    }
                } else {
                    int ref = rand() % actions.size(); // random earlier instruction
                    actions.push_back(actions[ref]);
                    position += actions[ref];
                    cout << "SAME AS " << (ref + 1) << "\n";
                }
            }
        }
        cases.push_back(position);
        cout << endl;
    }
    cout << "----\n";
    for (int i = 0; i < cases.size(); i++) {
        cout << "Case " << i+1 << "'s final position: " << cases[i] << "\n";
    }
}

int main() {
    srand(time(0));

    int turns = (rand() % 10) + 1;

    robotTurns(turns);
}