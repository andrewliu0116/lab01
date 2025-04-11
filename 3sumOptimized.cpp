#include<algorithm>
#include<vector>
#include<iostream>
#include<random>
#include<chrono>
using namespace std;
    vector<vector<int>> threeSum(vector<int>& nums) {
        int const size = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> myVec;
        bool dupe = false;
        for(int i = 0 ; i < (size - 2) ; i++){
            int* begin = &nums[i+1];
            int* end = &nums[size-1];
            while(begin < end){
                int sum = nums[i] + (*begin) + (*end);
                if(sum == 0){
                    vector<int> insertVec = {nums[i] , (*begin) , (*end)};
                    for(int i = 0 ; i < myVec.size() ; i++){
                        if(insertVec == myVec[i]){
                            dupe = true;
                        }//if check dupe
                    }//if check for dupes
                    if(!dupe){
                        myVec.push_back(insertVec);
                    }
                    dupe = false;
                    begin++;
                    end--;
                }//if sum == 0
                else if(sum < 0){
                    begin++;
                }
                else if(sum > 0){
                    end--;
                }
            }//while
        }//for i
        return myVec;
    }

int main(){
random_device rd;
    mt19937 gen(rd());  
    uniform_int_distribution<> dis(1,1000);
    int a = dis(gen);
    int b = dis(gen);
    for(int i = 3000 ; i < 200000 ; i = i * 2){
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
