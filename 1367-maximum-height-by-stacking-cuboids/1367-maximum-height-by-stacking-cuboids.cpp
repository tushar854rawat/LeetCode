class Solution {
public:
    bool check(vector<int>& base,vector<int>& newbox){
        if(newbox[0]<=base[0] && newbox[1]<=base[1] && newbox[2]<=base[2]){
            return true;
        }
        return false;
    }
    int f(int n,vector<vector<int>>& arr){
        vector<int>currrow(n+1,0);
        vector<int>nextrow(n+1,0);

        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int incl = 0;
                if(prev==-1 || check(arr[curr],arr[prev])){
                    incl = arr[curr][2]+nextrow[curr+1];
                }
                int exe = 0+nextrow[prev+1];
                currrow[prev+1] = max(incl,exe);
            }
            nextrow=currrow;
        }
        return nextrow[0];
    }
    int maxHeight(vector<vector<int>>& arr) {
        for(auto& x : arr){
            sort(x.begin(),x.end());
        }

        sort(arr.begin(),arr.end());

        return f(arr.size(),arr);
    }
};