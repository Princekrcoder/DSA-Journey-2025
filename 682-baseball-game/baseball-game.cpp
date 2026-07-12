class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(string op: operations) {
            if(op == "+") {
                int last = st.top();
                st.pop();

                int secondLast = st.top();
                
                st.push(last);
                st.push(last + secondLast);
            }
            else if(op == "D") {
                st.push(st.top() * 2);
            }
            else if(op == "C") {
                st.pop();
            }
            else {
                st.push(stoi(op));
            }
        }

        int sum = 0;

        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};