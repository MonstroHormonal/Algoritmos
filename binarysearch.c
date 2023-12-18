int binarysearch(int A[], int l, int r, int K){

    int m;
    if(r >= l){
        m = (l + r)/2;
        if(K == A[m]) return m;
        else if(K < A[m]) return binarysearch(A, l, m - 1, K);
        else return binarysearch(A, m + 1, r, K);
    }
    else return -1;
}
