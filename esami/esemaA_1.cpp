/**
 * @file esemaA_1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 */

#include<iostream>
#include<string>

using namespace std;

int** func(bool ****A, int m, int n, int q, unsigned int l){
    int count_seq=0;
    int**B=new int*[m];
    for(int i=0; i<m; i++){
        B[i]=new int[n];
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int count=0;
            for(int t=0; t<q; t++){
                if(A[i][j][t]!=nullptr){
                    if((*A[i][j][t])==true){
                        count++;
                        if(count==l){
                            count_seq++;
                            count=0;
                        }
                    }else{count=0;}
                }
            }
            B[i][j]=count_seq;
        }
    }
    return B;
}

int main(){


}