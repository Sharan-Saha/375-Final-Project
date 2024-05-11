#include <iostream>
using namespace std; 

struct Node
{
    int key; 
    struct Node *left, *right; 
}; 

struct Node *newNode(int item) { 
    struct Node *tempNode = new Node; 
    tempNode->key = item; 
    tempNode-> left = tempNode-> right = nullptr; 
    return tempNode; 
}

void storeSorted(Node *root, int arr[], int &i) { 
    if (root != nullptr) {
        storeSorted(root-> left, arr, i); 
        arr[i++] = root->key; 
        storeSorted(root -> right, arr, i); 
    }
}

Node* insert(Node* node, int key) {
    if (node == nullptr) { 
        return newNode(key); 
    }

    if (key < node -> key) { 
        node -> left = insert(node -> left, key); 
    }
    else if (key > node -> key) { 
        node -> right = insert(node-> right, key); 
    }

    return node; 
}

void treeSort (int arr[], int n) { 
    struct Node *root = nullptr; 

    root = insert(root, arr[0]); 
    for (int i = 1; i < n; i++) { 
        root = insert(root, arr[i]); 
    }

    int i = 0; storeSorted(root, arr, i); 
}

int main(){ 
    int arr[] = {5, 4, 7, 2, 11}; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    treeSort(arr, n); 

    //small sample treesort
    for (int i = 0; i < n; i++) { 
        cout << arr[i] << " ";
    }

    //fast example tree sort 
    int arr1[20]; 

    for (int i = 0; i < 20; i++)
    {
        arr1[i] = 20 - i;
    }

    int n1 = sizeof(arr1) / sizeof(arr[0]);

    treeSort(arr1, n1);

    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }



    return 0; 
}
