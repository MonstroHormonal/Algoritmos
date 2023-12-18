int hoarepartition(int A[], int l, int r){
    int p, i, j, temp;
    p = A[l];
    i = l;
    j = r + 1;
    do{
        do{
            i = i + 1;
        }while(!(A[i] >= p || i >= r));
        do{
            j = j - 1;
        }while(!(A[j] <= p));
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }while(!(i >= j));

    temp = A[i];
    A[i] = A[j];
    A[j] = temp;

    temp = A[l];
    A[l] = A[j];
    A[j] = temp;
    return j;
}

void quicksort(int A[], int l, int r){
    int s;
    if(l < r){
        s = hoarepartition(A, l, r);
        quicksort(A, l, s - 1);
        quicksort(A, s + 1, r);

    }
}