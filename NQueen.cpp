#include <iostream>

class NQueensSolver {
private:
    int x[20];
    int count;

    int place(int k) {
        for (int i = 1; i <= k - 1; i++) {
            if (i + x[i] == k + x[k] || i - x[i] == k - x[k] || x[i] == x[k]) {
                return 0;
            }
        }
        return 1;
    }

public:
    NQueensSolver() {
        count = 0;
        for (int i = 0; i < 20; i++) {
            x[i] = 0;
        }
    }

    void solve(int n) {
        int k = 1;
        x[k] = 0;

        while (k != 0) {
            x[k]++;
            while (place(k) != 1 && x[k] <= n) {
                x[k]++;
            }

            if (x[k] <= n) {
                if (k == n) {
                    std::cout << "\nSolution is " << ++count << "\n";
                    std::cout << "Queen\t\tPosition\n";
                    for (k = 1; k <= n; k++) {
                        std::cout << k << "\t\t" << x[k] << "\n";
                    }
                } else {
                    k++;
                    x[k] = 0;
                }
            } else {
                k--;
            }
        }
    }
};

int main() {
    NQueensSolver solver;
    int n;

    std::cout << "Enter the number of Queens\n";
    std::cin >> n;

    solver.solve(n);

    return 0;
}
