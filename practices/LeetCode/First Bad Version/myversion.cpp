// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int front = 1;
    int rear = n;
    
    while(true){
        if(!isBadVersion(rear-1) && isBadVersion(rear)) return rear;
        int mid = front + (rear - front)/2;
        if(isBadVersion(mid)) rear = mid;
        else front = mid;
    }
    return 0;
}