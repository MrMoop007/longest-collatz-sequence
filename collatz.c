#include <stdio.h>
#include <stdlib.h>

//returns the number of steps it takes for an integer n
//to terminate in the collatz sequence
long long int collatz(long long int n){
    long long int steps = 0;
    long long int original = n;
    while(n > 1){
        if(n%2==0){
            n /= 2;
            steps += 1;
        }
        else{
            n = 3*n + 1;
            n /= 2;
            steps += 2;
        }
    }
    return steps;
}

int find_largest_element(long long int arr[], long long int size) {
    long long int largest = arr[0]; 
    int largestindex = 0;
    for (long long int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i]; 
            largestindex = i;
        }
    }
    return largestindex;
}

//finds the longest collatz sequence under n
int longest_collatz_sequence(long long int n){
    //get every length in an array
    long long int* lengths = malloc(n * sizeof(long long int));
    if (lengths == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }
    int i;
    for(i = 0; i<n; i++){
        lengths[i] = collatz(i);
    }
    int max = find_largest_element(lengths, n);
    return max;
}

int main(){
    char numinput[10];
    scanf("%s", numinput);
    long long int num = strtol(numinput, NULL, 10);
    printf("\n%d", longest_collatz_sequence(num));
}