int rotated_search(vi arr,int n,int key){
    int st = 0;
    int ed = n-1;
    while(st<=ed){
        int mid = (st+ed)/2;
        if(arr[mid]==key)return mid;
        if(arr[mid]<=arr[mid]){
            //left
            if(key>=arr[st] and key<=arr[mid]){
                ed = mid-1;
            }else{
                st = mid+1;
            }
        }else{
            //right
            if(key>=arr[mid] and key<=arr[ed]){
                st = mid+1;
            }else{
                ed = mid-1;
            }
        }
    }
    return -1;
}