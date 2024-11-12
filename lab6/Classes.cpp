#include <iostream>
#include <vector>

class Graph {
public:

    Graph(int n) : n(n) {
        degrees.resize(n, 0); 
    }

    bool check_graph() {
        int total_degrees = 0;

        total_degrees += 9 * 3;  
        total_degrees += 11 * 4; 
        total_degrees += 10 * 5; 
        

        if (total_degrees % 2 == 0) {
            return true;
        } else {
            return false;
        }
    }

private:
    int n; 
    std::vector<int> degrees;  
};

int main() {
    Graph g(30);  

    if (g.check_graph()) {
        std::cout << "Possibaliti to create." << std::endl;
    } else {
        std::cout << "Possibaliti not to create." << std::endl;
    }

    return 0;
}
