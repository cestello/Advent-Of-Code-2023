//
// DrCesty's template <<<
//
//
//#pragma optimization_level 3
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <algorithm>
#include <string>
#include <fstream>

#define ll long long
#define ull unsigned long long
#define pi pair<int, int>

constexpr ll INF = 10e8 + 42;
constexpr ll mINF = -10e8 - 42;
constexpr ll MOD  = 1000000007;

using namespace std;

int main() {
    string linea, tmp;
    fstream file;

    vector<string> controlli = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine"};

    file.open("input.txt", ios::in); //file input
    int ans = 0, first, last;
    while (file.peek() != EOF) { //legge fino a EOF
        int tmp;
        getline(file, linea);
        int primo_digit_idx = INF, secondo_digit_idx = -1;
        string primo_digit, secondo_digit;
        for(int i = 0; i < controlli.size(); ++i) {
            int y = linea.find(controlli[i]); //prende la prima apparizione della sottostringa
            int y0 = linea.rfind(controlli[i]); //prende l'ultima apparizione della sottostringa
            if(y < primo_digit_idx && y != -1) {
                primo_digit_idx = y; //prendo la prima
                primo_digit = controlli[i];
            }
            if(secondo_digit_idx < y0 && y0 != -1) {
                secondo_digit_idx = y0; //prendo la seconda
                secondo_digit = controlli[i];
            }
        }

        int prima_cifra, seconda_cifra;
        for(int i = 0; i < controlli.size(); ++i) { //trasformo da stringa a int
            if(!primo_digit.compare(controlli[i])) {  //la prima
                prima_cifra = (i % 9) + 1;
            }
            if(!secondo_digit.compare(controlli[i])) { //la seconda
                seconda_cifra = (i % 9) + 1;
            }
        }

        prima_cifra*=10; // per 10 cosi' si sposta di uno a sinitra
        ans += prima_cifra + seconda_cifra;
    }

    file.close();

    cout << ans << '\n';
    return 0;
}