class Solution {
private:
    bool chk(int a,int b, int c, int d){
        // if new numbers are answer
        if(b-a < d-c){
            return true;
        }
        else if(b-a == d-c){
            if(a<c){return true;}
        }

        // new number dont have minimum difference
        // uptill now
        return false;
    }
public:
    vector<int> smallestRange(vector<vector<int>>& a) {
        int ansx = -1e5, ansy = 1e5; 
        int total_list = a.size();

        // UNCOMMENT TO CHECK HOW GIVEN ARRAY PRINT AFTER SORT
        // sort(a.begin(), a.end());
        //     cout<<"[";
        // for(int i=0;i<total_list;i++){
        //     cout<<"[";
        //     for(int j=0;j<a[i].size();j++){
        //         cout<<a[i][j]<<((j==a[i].size()-1)?"":",");
        //     }
        //     cout<<"]"<<((i==total_list-1)?"":",");
        // }
        //     cout<<"]";
        // cout<<endl;
        // cout<<endl;

        vector<pair<int,int>> vp;
        for(int i=0;i<total_list;i++){
            for(int j=0;j<a[i].size();j++){
                vp.push_back({a[i][j],i});
            }
        }


        sort(vp.begin(), vp.end());

        // UNCOMMENT TO CHECK HOW VECTOR IS PRINTING AFTER SORT
        // int cnt=0;
        // cout<<"[";
        // for(auto& val:vp){
        //     cout<<"["<<val.first<<","<<val.second<<"]";
        //     cnt++;
        //     if(cnt!=vp.size()){cout<<",";}
        // }
        // cout<<"]";

        unordered_map<int,int> um;
        int l=0, r=0;
        int n = vp.size();
        while(r<n){
            int num = vp[r].first;
            int list = vp[r].second;

            um[list]++;

            while(um.size() >= total_list){
                //    |-----new range---------| |--old range--|
                if(chk(vp[l].first,vp[r].first,   ansx, ansy )){
                    // cout<<"Possible ans = "<<ansx<<" "<<ansy<<endl;
                    ansx = vp[l].first;
                    ansy = vp[r].first;
                    // cout<<"Possible ans = "<<ansx<<" "<<ansy<<endl;
                }

                int old_list = vp[l].second;
                
                um[old_list]--;
                l++;

                if(um[old_list]==0){um.erase(old_list);}
            }

            r++;
        }

        return {ansx, ansy};
    }
};