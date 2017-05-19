#include <stdio.h>
int c,m,t=0;

void peak1 (int arr[], int low, int high)
    {
        if (high - low < 2)
            return;
        int mid = (low + high) / 2;     /*This finds the mid value of an array*/
       /* O(logn) algorithm for finding the peak or valley*/
        if (((arr[mid] > (arr[mid - 1])) && (arr[mid] > (arr[mid + 1])))){ 
            printf("\npeak :%d\n",arr[mid]);
            c++; //counter for peaks
        }
        else if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1]){    /*Here, valley can be found*/
            printf("\nValley %d\n",arr[mid]);
            
             m++; /* counter for valleys*/
        }
       /*look for other peaks or valleys if present */
        peak1 (arr, low, mid);
        peak1 (arr, mid, high);
         
        t = c+m;                                                     /*Total castles that can be built*/
    } 

int main() {  
    int new_size,size;
    int i,j,k;
    int arr[7] = {2,3,4,4,2,7,1}; /*Enter values here for the array and change size of array as well*/
    size = sizeof(arr) / sizeof(arr[0]);
    int new_arr[size] ; //new array if there are consecutive duplicates in given array
    
    /*The logic below will get rid of consecutive duplicates if present in an array*/
    for(i=0; i<size;i++)
    {
      
        for(j =i+1;j<size;){
           
            if(arr[i+1]==arr[i]){
                for(k=j;k<size;k++){
               
                    arr[k] = arr[k + 1];   
                }
                size--;
            }
            else j++;
        }
        new_size = size;
       // printf("Size is %d\n",new_size);
        new_arr[i] = arr[i];
    }
    
   peak1(new_arr,0,new_size);

   printf("\nTotal castles AEQ can build : %d\n", t);
   
   return 0;
}

