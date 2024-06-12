#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k) {
        set<int> st;
        for (int i = 0; i < k; i++) {
            st.insert(arr[i]);
        }

        set<int>::iterator it = st.end();
        it--;
        vector<int> res = {*(it)};

        for (int i = k; i < n; i++) {
            st.erase(st.find(arr[i - k]));
            st.insert(arr[i]);

            it = st.end();
            it--;
            res.push_back(*(it));
        }

        return res;

    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < (int)res.size(); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}