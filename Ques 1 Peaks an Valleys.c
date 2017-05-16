#include <stdio.h>

int c,m,t=0;

void peak1 (int arr[], int low, int high)
    {
     
    int N = sizeof(arr);
        if (high - low < 2)
            return;
        int mid = (low + high) / 2;     //This finds the mid value of an array

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){            //O(logn) algorithm for finding the peak or valley
            printf("peak :%d\n ",arr[mid]);
            c++;
             
        }
    
    
        if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1]){    //Here, valley can be found
            printf("Valley %d\n",arr[mid]);
            
             m++;
        }
    
        
     //look for other peaks or valleys if present                    //Recusrsively look for another peak or valley present
        peak1 (arr, low, mid);
    
        peak1 (arr, mid, high); 
        t = c+m;                                                     //Total castles that can be built
     
    } 

void peak (int arr[]){
    peak1(arr, 0, sizeof(arr) - 1);
   
    
}


int main() {  
    int arr[] = {63,87,45,98,39,109,27}; //Enter values here for the array
    peak(arr);
    printf("Total castles AEQ can build : %d\n", t);
}


