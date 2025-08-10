#include <iostream>
using namespace std;

int SumByRow(int (&arr)[3][3], int row, int size){
    int sum=0;
    if (row>2){
        cout<<"Not enough rows"<<endl;
    }
    
    else{
    for(int i =0; i<3; i++){
        sum += arr[row][i];
    }
    }
    return sum;
    
}

int SumByCol(int (&arr)[3][3], int col, int size){
    int sum=0;
    if (col>size){
        cout<<"Not enough coloumns"<<endl;
    }
    
    else{
    for(int i =0; i<size; i++){
        sum += arr[i][col];
    }
    }
    return sum;
    
}

int main()
{
    int arr[3][3]={
        {1,2,3}, {4,5,6}, {7,8,9}
    };
    
    char c;
    cout<<"Enter R to get sum of Row"<<endl;
    cout<<"Enter C to get sum of Coloumn"<<endl;
    
    cin>>c;
    
    switch(c){
        case 'R':{
            int no;
            cout<<"Enter the no. of row of whose sum is to be found: ";
            cin>>no;
            int sum=SumByRow(arr,no,3);
            cout<<sum;
            break;
        }
        
        case 'C':{
             int no;
            cout<<"Enter the no. of Coloumn of whose sum is to be found: ";
            cin>>no;
            int sum=SumByCol(arr,no,3);
            cout<<sum;
            break;
        
        }
        
        default:{
            cout<<"Invalid Input";
            break;
        }
    }

    return 0;
}