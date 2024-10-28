void merge(int arr , int left[], leftsize , int right[] , int rsize){
    int i = 0 , j = 0 , k = 0 ;
    while(i<lsize && j<rsize){
        if(left[i]<=right[j]) arr[k++] = left[i++]; 
        else arr[k++] = rigth[j++]; 
    }
    while(i <lsize) arr[k++] = left[i++]; 
    while(j <rsize) arr[k++] = right[j++];
}
MergeSort(array , left, right):
  if(left >=right) return ; 
  mid = left + (right-left)/2; 
  mergeSort(arr,left,mid); 
  mergeSort(arr,mid+1,right); 
  form the leftarray
  form the rightarray
  merge(array,leftarray,mid -left+1 , right array , right-mid); 
