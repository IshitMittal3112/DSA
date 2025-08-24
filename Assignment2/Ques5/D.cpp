#include <iostream>
using namespace std;

void Display(int* arr, int n) {
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<"\t";
	}
}

int main()
{
    int mat[4][4]={{1,2,3,4},{0,5,6,7},{0,0,8,9},{0,0,0,10}};
    int n=sizeof(mat[0])/sizeof(mat[0][0]);
    
    int totele= (n*(n+1))/2;
    
    int utm[totele];
    int k=0;
    
    for(int i=0; i<n; i++){
        for(int j=i;j<n;j++){
            utm[k]=mat[i][j];
            k++;
        }
    }
    Display(utm,totele);

    return 0;
}