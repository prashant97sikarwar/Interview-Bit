#Problem Link:- https://www.interviewbit.com/problems/evaluate-expression/

class Solution:
    # @param A : list of strings
    # @return an integer
    def evalRPN(self, tokens):
        st = []
        s = set(['+', '-', '*', '/'])
        n = len(tokens)
        for i in range(n):
            if tokens[i] in s:
                 first = st.pop()
                 sec = st.pop()
                 if tokens[i] == '+':
                    st.append(sec + first)
                 elif tokens[i] == '-':
                    st.append(sec - first)
                 elif  tokens[i] == '/':
                    st.append(int(sec/first))
                 elif tokens[i] == '*':
                    st.append(sec * first)
            else:
                 st.append(int(tokens[i]))
        return st[-1]