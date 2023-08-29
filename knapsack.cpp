#include <iostream>
using namespace std;

class KnapsackSolver {
private:
    int n, m;
    int *p;
    int *w;
    int **v;

public:
    KnapsackSolver(int numItems, int capacity) {
        n = numItems;
        m = capacity;

        p = new int[n + 1];
        w = new int[n + 1];
        v = new int *[n + 1];
        for (int i = 0; i <= n; i++) {
            v[i] = new int[m + 1];
        }
    }

    ~KnapsackSolver() {
        delete[] p;
        delete[] w;
        for (int i = 0; i <= n; i++) {
            delete[] v[i];
        }
        delete[] v;
    }

    void inputItems() {
        cout << "Enter the weight and profit of each item:\n";
        for (int i = 1; i <= n; i++) {
            cin >> w[i] >> p[i];
        }
    }

    void solveKnapsack() {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    v[i][j] = 0;
                } else if (j - w[i] < 0) {
                    v[i][j] = v[i - 1][j];
                } else {
                    v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
                }
            }
        }
    }

    void displayResults() {
        cout << "\nThe output is:\n";
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                cout << v[i][j] << "\t";
            }
            cout << "\n\n";
        }

        cout << "\nThe optimal solution is " << v[n][m] << endl;

        cout << "The solution vector is:\n";
        int x[n + 1];
        for (int i = n; i >= 1; i--) {
            if (v[i][m] != v[i - 1][m]) {
                x[i] = 1;
                m = m - w[i];
            } else {
                x[i] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << x[i] << "\t";
        }
    }
};

int main() {
    int numItems, capacity;
    cout << "Enter the no. of items:\t";
    cin >> numItems;

    cout << "Enter the knapsack's capacity:\t";
    cin >> capacity;

    KnapsackSolver solver(numItems, capacity);
    solver.inputItems();
    solver.solveKnapsack();
    solver.displayResults();

    return 0;
}
