#include <bits/stdc++.h>
using namespace std;

struct Ship {
    int rowAttack;
    int columnAttack;
    int diagonalAttack;
};

class BattleshipPlacement {
private:
    int N, M, K;
    vector<Ship> ships;
    vector<pair<int, int>> placement;  // Stores positions of placed ships
    
    // Check if ship at (row, col) attacks position (r, c)
    bool attacks(int shipIdx, int row, int col, int r, int c) {
        Ship& ship = ships[shipIdx];
        
        // Same position
        if (row == r && col == c) return true;
        
        // Row attack
        if (row == r) {
            int dist = abs(col - c);
            if (dist <= ship.rowAttack) return true;
        }
        
        // Column attack
        if (col == c) {
            int dist = abs(row - r);
            if (dist <= ship.columnAttack) return true;
        }
        
        // Diagonal attack
        int rowDiff = abs(row - r);
        int colDiff = abs(col - c);
        if (rowDiff == colDiff && rowDiff <= ship.diagonalAttack) {
            return true;
        }
        
        return false;
    }
    
    // Check if placing ship at (row, col) is safe
    bool isSafe(int shipIdx, int row, int col) {
        // Check if current ship attacks any already placed ship
        for (int i = 0; i < placement.size(); i++) {
            int placedRow = placement[i].first;
            int placedCol = placement[i].second;
            
            // Check if current ship attacks the placed ship
            if (attacks(shipIdx, row, col, placedRow, placedCol)) {
                return false;
            }
            
            // Check if placed ship attacks current position
            if (attacks(i, placedRow, placedCol, row, col)) {
                return false;
            }
        }
        
        return true;
    }
    
    // Backtracking function
    bool solve(int shipIdx) {
        // All ships placed successfully
        if (shipIdx == K) {
            return true;
        }
        
        // Try placing current ship at each position
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) {
                if (isSafe(shipIdx, row, col)) {
                    // Place the ship
                    placement.push_back({row, col});
                    
                    // Recursively place remaining ships
                    if (solve(shipIdx + 1)) {
                        return true;
                    }
                    
                    // Backtrack
                    placement.pop_back();
                }
            }
        }
        
        return false;
    }
    
public:
    BattleshipPlacement(int n, int m, int k, vector<Ship>& s) 
        : N(n), M(m), K(k), ships(s) {}
    
    bool canPlaceShips() {
        placement.clear();
        return solve(0);
    }
    
    vector<pair<int, int>> getPlacement() {
        return placement;
    }
    
    void printPlacement() {
        if (placement.empty()) {
            cout << "No valid placement found!\n";
            return;
        }
        
        cout << "Valid placement found:\n";
        for (int i = 0; i < K; i++) {
            cout << "Ship " << i + 1 << " at position (" 
                 << placement[i].first << ", " << placement[i].second << ")\n";
        }
        
        // Visual representation
        cout << "\nBoard visualization:\n";
        vector<vector<int>> board(N, vector<int>(M, 0));
        for (int i = 0; i < K; i++) {
            board[placement[i].first][placement[i].second] = i + 1;
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 0) {
                    cout << ". ";
                } else {
                    cout << board[i][j] << " ";
                }
            }
            cout << "\n";
        }
    }
};

// Example usage and test cases
int main() {
    // Test Case 1: Simple case with 2 ships
    cout << "=== Test Case 1 ===\n";
    {
        int N = 5, M = 5, K = 2;
        vector<Ship> ships = {
            {1, 1, 1},  // Ship 1: attack range 1 in all directions
            {1, 1, 1}   // Ship 2: attack range 1 in all directions
        };
        
        BattleshipPlacement solver(N, M, K, ships);
        if (solver.canPlaceShips()) {
            solver.printPlacement();
        } else {
            cout << "Cannot place all ships!\n";
        }
    }
    
    cout << "\n=== Test Case 2 ===\n";
    {
        int N = 4, M = 4, K = 3;
        vector<Ship> ships = {
            {2, 1, 1},  // Ship 1
            {1, 2, 1},  // Ship 2
            {1, 1, 2}   // Ship 3
        };
        
        BattleshipPlacement solver(N, M, K, ships);
        if (solver.canPlaceShips()) {
            solver.printPlacement();
        } else {
            cout << "Cannot place all ships!\n";
        }
    }
    
    cout << "\n=== Test Case 3: Impossible case ===\n";
    {
        int N = 3, M = 3, K = 3;
        vector<Ship> ships = {
            {5, 5, 5},  // Very large attack range
            {5, 5, 5},
            {5, 5, 5}
        };
        
        BattleshipPlacement solver(N, M, K, ships);
        if (solver.canPlaceShips()) {
            solver.printPlacement();
        } else {
            cout << "Cannot place all ships! (Attack ranges too large)\n";
        }
    }
    
    cout << "\n=== Test Case 4: Example from problem ===\n";
    {
        int N = 10, M = 10, K = 2;
        vector<Ship> ships = {
            {3, 3, 2},  // Ship at (5,5) with column attack 3
            {2, 2, 2}
        };
        
        BattleshipPlacement solver(N, M, K, ships);
        if (solver.canPlaceShips()) {
            solver.printPlacement();
        } else {
            cout << "Cannot place all ships!\n";
        }
    }
    
    return 0;
}