#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int coins[], int length, int target) {
bool table[length + 1][target + 1];

for (int i = 0; i <= length; i++)
table[i][0] = true;

for (int j = 1; j <= target; j++)
table[0][j] = false;

for (int i = 1; i <= length; i++) {
for (int j = 1; j <= target; j++) {
if (coins[i - 1] > j) // upper value copy
table[i][j] = table[i - 1][j];
else
table[i][j] = table[i - 1][j] || table[i - 1][j - coins[i - 1]]; // include and exclude
}
}

return table[length][target];
}

int main() {
int coins[] = {2, 1, 4, 3};
int amount = 7;

int length = sizeof(coins) / sizeof(coins[0]);

if (subsetSum(coins, length, amount))
cout << "exists.";
else
cout << "not exist.";

return 0;
}
