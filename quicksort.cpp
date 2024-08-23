#include <iostream>
using namespace std;

int hoarepartition(int A[], int l, int r) {
    int p, i, j, temp;
    p = A[l];
    i = l;
    j = r + 1;
    do {
        do {
            i = i + 1;
        } while (!(A[i] >= p || i >= r));
        do {
            j = j - 1;
        } while (!(A[j] <= p));
        if (i < j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (!(i >= j));

    temp = A[l];
    A[l] = A[j];
    A[j] = temp;

    return j;
}

void quicksort(int A[], int l, int r) {
    if (l < r) {
        int s = hoarepartition(A, l, r);
        quicksort(A, l, s - 1);
        quicksort(A, s + 1, r);
    }
}

int main() {
    int A[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(A)/sizeof(A[0]);

    quicksort(A, 0, n-1);

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
