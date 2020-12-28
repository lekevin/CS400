#include<bits/stdc++.h>
using namespace std;
struct n {
    int d;
    struct n* l;
    struct n* r;
    n(int d) {
        this->d = d;
        l = r = NULL;
    }
};
void inOrder(struct n* root) {
    stack<n*> s;
    n* current = root;
    while (current != NULL || s.empty() == false) {
        while (current != NULL) {
            s.push(current);
            current = current->l;
        }
        current = s.top();
        s.pop();
        cout << current->d << " ";
        current = current->r;
    }
}
int main() {
    struct n* root = new n(6);
    root->l = new n(4);
    root->r = new n(7);
    root->l->l = new n(8);
    root->l->r = new n(5);
    root->r->l = new n(9);
    root->r->r = new n(10);
    inOrder(root);
    return 0;
}