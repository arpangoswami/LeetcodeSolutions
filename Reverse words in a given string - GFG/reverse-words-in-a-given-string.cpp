// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        vector<string> arr;
        istringstream iss(S);
        string s;
        while(getline(iss,s,'.')){
            arr.push_back(s);
        }
        reverse(arr.begin(),arr.end());
        ostringstream oss;
        int N = arr.size();
        for(int i=0;i<N;i++){
            oss << arr[i];
            if(i != (N-1)){
                oss << '.';
            }
        }
        return oss.str();
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends