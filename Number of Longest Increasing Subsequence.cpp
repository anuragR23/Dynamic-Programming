int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp_l(n,1);
        vector<int>dp_c(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp_l[j]+1>dp_l[i]){
                        dp_l[i]=1+dp_l[j];
                        dp_c[i]=dp_c[j];
                    }
                    else if(dp_l[j]+1==dp_l[i]){
                        dp_c[i]+=dp_c[j];
                    }
                }
            }
        }
        int ans=INT_MIN;
        //int ans;
        int count=0;
        for(int i=0;i<n;i++){
            cout<<dp_l[i]<<" ";
            ans=max(ans,dp_l[i]);
        }
        cout<<ans<<endl;
        for(int i=0;i<n;i++){
            if(dp_l[i]==ans){
                count+=dp_c[i];
            }
        }
        return count;
        
    }
