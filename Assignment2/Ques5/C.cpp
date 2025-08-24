#include <iostream>
using namespace std;

void Display(int* arr, int n) {
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<"\t";
	}
}

int main()
{
    int mat[4][4]={{1,0,0,0},{2,3,0,0},{4,5,6,0},{7,8,9,10}};
    int n=sizeof(mat[0])/sizeof(mat[0][0]);
    
    int totele= (n*(n+1))/2;
    
    int ltm[totele];
    int k=0;
    
    for(int i=0; i<n; i++){
        for(int j=0;j<=i;j++){
            ltm[k]=mat[i][j];
            k++;
        }
    }
    Display(ltm,totele);

    return 0;
}