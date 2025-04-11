#include<algorithm>
#include<vector>
#include<iostream>
#include<random>
#include<chrono>
using namespace std;
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> myVector;
        int size = nums.size();
        int num1,num2,num3;
        bool dupe = false;
        for(int i = 0 ; i < size ; i++){//iterates for num1
            num1 = nums[i];
            for(int j = i + 1 ; j < size ; j++){//interates for num2
                num2 = nums[j];
                if((i + 2) == size){//makes sure there will not be out of bounds error
                    return myVector;
                }
                for(int k = j + 1 ; k < size ; k++){//iterates for num3
                    num3 = nums[k];
                        if((num1 + num2 + num3) == 0){//checks if combination adds up to zero
                            vector<int> insertVector{num1,num2,num3};
                            sort(insertVector.begin(), insertVector.end());
                            for(int i = 0 ; i < myVector.size() ; i++){//checks for dupes
                                if(insertVector == myVector[i]){
                                    dupe = true;
                                }//if dupe
                            }//for check dupe
                            if(!dupe){
                                myVector.push_back(insertVector);//push vector that satisfy 3Sum conditions in to our return vector
                            }//if !dupe
                            dupe = false;
                        }//if == 0
                    }//for k
            }//for j
        }//for i
        return myVector;
    }

int main(){
    random_device rd;
    mt19937 gen(rd());  
    uniform_int_distribution<> dis(1,1000);
    int a = dis(gen);
    int b = dis(gen);
    for(int i = 100 ; i < 8000 ; i = i * 2){
    vector<int> vec(i);
    vec[0] = -a;
    vec[1] = -b;
    vec[2] = a + b;
    for(int i = 3 ; i < vec.size() ; i++){
        vec[i] = dis(gen);
    }
    auto start = chrono::high_resolution_clock::now();
    vector<vector<int>> result = threeSum(vec);
    auto end = chrono::high_resolution_clock::now();
    double time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
    cout<<"Number of entries : " << i << " time(ms  : "<<time_ms<<endl;
    }
}


