#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << "\n";
        cout << "Value: ";
        cin >> items[i].value;
        cout << "Weight: ";
        cin >> items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    cout << "\nSelected items:\n";
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            remainingCapacity -= items[i].weight;
            totalValue += items[i].value;
            cout << "Take full item " << i + 1 << " (value = " << items[i].value
                 << ", weight = " << items[i].weight << ")\n";
        } else {
            double fraction = (double)remainingCapacity / items[i].weight;
            totalValue += fraction * items[i].value;
            cout << "Take " << fraction * 100 << "% of item " << i + 1
                 << " (value = " << fraction * items[i].value << ")\n";
            break;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nMaximum profit = " << totalValue << endl;

    return 0;
}
