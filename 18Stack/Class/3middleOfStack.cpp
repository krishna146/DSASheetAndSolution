// Problem Link -
/* By Krishna Kumar */
#include <iostream>
#include <stack>
using namespace std;

void getMiddle(stack<int> &st, int totalSize, int &ans)
{
    if(st.size() == (totalSize / 2 + 1)){
        ans = st.top();
        return;
    }
    int el = st.top();
    st.pop();
    getMiddle(st, totalSize, ans);
    st.push(el);
}
int main()
{
    stack<int> st;
    st.push(4);
    st.push(6);
    st.push(8);
    st.push(10);
    int ans;
    int totalSize = st.size();
    getMiddle(st, totalSize, ans);
    cout << ans << endl;
}