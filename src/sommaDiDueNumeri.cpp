// Dato un vettore di numeri interi NUMS
// Dato un intero TARGET
// Determinare se esistono almeno due elementi di NUMS la cui somma sia uguale a TARGET e ritornare gli indici di tali elementi
// gli elementi di NUMS ed il TARGET sono compresi tra -10^9 e 10^9
// il numero di elementi di NUMS e' compreso tra 1 e 10^5 

// nums = [2, 7, 11, 15], target = 9  =>  {0, 1}
// nums = [3, 2, 4], target = 6  =>  {1, 2}
// nums = [1, 2, 3], target = 12  =>  { }

#include <fstream>
#include <unordered_map>

using namespace std;

// complessita' quasi sempre lineare
pair<int, int> sum(int *nums, int n, int target) {
    unordered_map<int, int> visited;

    for (int = 0; i < n; i++) { 
        if (visited.find(target - nums[i]) != visited.end())
            return {i, visited[target - nums[i]]};
        
        visited.emplace(nums[i], i);
    }

    return {-1, -1};
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 1; task <= 3; task++) {

        int n;
        in >> n;

        int *nums = new int[n+1];
        for (int i = 0; i < n; i++)
            in >> nums[i];

        int target;
        in >> target;

        auto res = sum(nums, n, target);
        out << res[0] << ' ' << res[0] << endl;

    }

    return 0;
}
