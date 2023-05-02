/*
Manually trace the given code segment for the following array assuming size=5.
Array =  10 20 10 10 100
 Show the changes of all the variables in each step.
 for(i=0; i<size; i++){
 for(j=i+1; j<size; j++){
 if(arr[i] == arr[j]){
 for(k=j; k<size-1; ++k){
 arr[k] = arr[k+1];
 }
 size--;
 j--;
 }
 }
 }
*/

#include <stdio.h>
int main() {
  int size;
  scanf("%d", &size);
  int arr[size];
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i] == arr[j]) {
        for (int k = j; k < size - 1; ++k) {
          arr[k] = arr[k + 1];
        }
        size--;
        j--;
      }
    }
  }
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
