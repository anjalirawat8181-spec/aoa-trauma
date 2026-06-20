#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

bool compare(Item a, Item b) {
    return (double)a.value/a.weight >
           (double)b.value/b.weight;
}

int main() {
    Item items[] = {{60,10},{100,20},{120,30}};
    int W = 50;
    int n = 3;

    sort(items, items+n, compare);

    double profit = 0;

    for(int i=0;i<n;i++) {
        if(W >= items[i].weight) {
            profit += items[i].value;
            W -= items[i].weight;
        }
        else {
            profit += ((double)items[i].value/items[i].weight)*W;
            break;
        }
    }

    cout<<"Maximum Profit = "<<profit;
}