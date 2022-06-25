#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution
{
    private:
        void storePermutation(string &str, int index, vector<string> ans){
            if(str[index] == '\0')
            {
                ans.push_back(str);
                return;
            }
            for(int i = index ; i < str.size() ; i++){
                swap(str[i], str[index]);
                storePermutation(str, index + 1, ans);
                swap(str[i], str[index]);
            }
           
        }
	public:
		vector<string >find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    storePermutation(S, 0, ans);
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
  
    
	    string S = "ABC";
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    
}