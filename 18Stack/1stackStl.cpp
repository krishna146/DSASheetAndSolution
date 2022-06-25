// Problem Link -
/* By Krishna Kumar */
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    // creaton of stack
    stack<int> st;
    int n;
    cin >> n;
    while (n--)
    {
        int el;
        cin >> el;
        st.push(el);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(5);
    int mid = st.size() / 2;
    if (!(mid & 1)){
        mid = mid + 1;
    }
    while(mid > 1){
        st.pop();
    }
    cout << st.top() << endl;

    //insertion
    st.push(5);
    st.push(7);
    st.push(9);

    //check size
    cout << st.size() << endl;

    //check empty or not
    cout << st.empty() << endl;

    st.pop();
    st.pop();
    cout << st.top() << endl;
}