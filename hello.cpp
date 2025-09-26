#include<iostream>
using namespace std;

int n;
int a[100000 + 1], tree[400000 + 1];
int setup (int l, int r, int idx){
    int mid = (l + r) / 2;
    if (l == r){
        tree[idx] = a[l];
    }else{
        tree[idx] = setup(l, mid, idx * 2) + setup(mid + 1, r, idx * 2 + 1);
    }
    return tree[idx];
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    setup(1, n, 1);
    for (int i = 1; i <= 4 * n; i++)
        cout << tree[i] << ' ';
}
