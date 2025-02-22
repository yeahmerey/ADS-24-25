 #include<bits/stdc++.h>
using namespace std;
 
void merge(vector<int> & array, int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne
        = 0, 
        indexOfSubArrayTwo
        = 0; 
    int indexOfMergedArray
        = left;
 
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
void mergeSort(vector <int> &array, int const begin, int const end)
{
    if (begin >= end)
        return; 
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main(){
   int n;
   int s;
   vector<int> arr;
   vector<int> v;
   cin >> n;
   cin >> s;
   for (int i = 0; i < n; i++){
        int b;
        cin >> b;
        arr.push_back(b);
   }

   for (int i = 0; i < s; i++){
        int b;
        cin >> b;
        v.push_back(b);
   }
   
   mergeSort(arr, 0, arr.size() - 1);
   mergeSort(v, 0, v.size() - 1);


   vector<int> mat(n + s);
   vector<int>::iterator it;

   it = set_intersection(arr.begin(), arr.end(), v.begin(), v.end(), mat.begin());
    
   for (int i = 0; i < mat.size(); i++){
        if(mat[i] != 0){
            cout << mat[i] << " ";  
        }
        else{
            break;
        }
   }
   
}