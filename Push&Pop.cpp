class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		if (pushed.size() == 0)
			return true;

			//setup two counters

			int num_pushed = 0;
			int num_popped = 0;

			//create the stack
			stack<int> st;

			//try to pop as many numbers as popped
			
			while (num_popped < popped.size()) {

				//top() exists and top() matches the current output
				//try to match the top element to the current element in the vector popped.
				if (!st.empty() && st.top() == popped[num_popped]) {
					++num_popped;
					st.pop();
				}

				else {		//stack top does not exist or not match output
					while (num_pushed < pushed.size()) {
						int temp = pushed[num_pushed];
						st.push(temp);
						++num_pushed;

						if (st.top() == popped)[num_popped])
						break;

					}

					if (st.top() != popped[num_popped])
						return false;
				}
			}
			return true;

	}
};