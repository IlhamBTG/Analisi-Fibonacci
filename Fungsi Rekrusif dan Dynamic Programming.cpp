#include <iostream>
#include <unordered_map>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

unordered_map<int, long long> memo;

long long fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

long long fibonacci_dynamic(int n) {
    if (memo.find(n) != memo.end())
        return memo[n];
    if (n <= 1)
        return n;
    else {
        memo[n] = fibonacci_dynamic(n-1) + fibonacci_dynamic(n-2);
        return memo[n];
    }
}

void measure_execution_time(long long (*func)(int), int n) {
    auto start = high_resolution_clock::now();
    long long result = func(n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << setw(5) << n << " | " << setw(20) << result << " | " << setw(15) << duration.count() << " mikrodetik" << endl;
}

int main() {
    int values_of_n[] = {10, 25, 30, 40, 50};
    
    cout << "-------------------------------------------------------------" << endl;
    cout << "  n  |   Fibonacci(n)   |   Waktu Eksekusi (mikrodetik)" << endl;
    cout << "-------------------------------------------------------------" << endl;

    cout << "Pendekatan Rekursif:" << endl;
    for (int n : values_of_n) {
        cout << "-------------------------------------------------------------" << endl;
        measure_execution_time(fibonacci_recursive, n);
    }

    cout << "-------------------------------------------------------------" << endl;
    cout << "\nPendekatan Dynamic Programming:" << endl;
    for (int n : values_of_n) {
        memo.clear(); 
        cout << "-------------------------------------------------------------" << endl;
        measure_execution_time(fibonacci_dynamic, n);
    }

    cout << "-------------------------------------------------------------" << endl;

    return 0;
}
