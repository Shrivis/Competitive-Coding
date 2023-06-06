solve(vector<int> arr) {
    int res=0;
    if (arr.size() == 0) return 0;
    for (int i=0; i<N-1; ++i) {
        int temp = arr[i], count=1;
        for (int j=i+1; j<N; ++j) {
            if (arr[j] == temp or arr[j] == temp+1) count++;
            else break;