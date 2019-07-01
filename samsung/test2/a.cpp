/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack for Stack operations 
#include<bits/stdc++.h>
#define MAXN  100005

using namespace std; 

int n, value = 0;
char a[MAXN], b[MAXN];
char  B[2 * MAXN], A[2 * MAXN];

//Function to return precedence of operators 
int prec(char c) 
{ 
	if(c == '^') 
	return 3; 
	else if(c == '*' || c == '/') 
	return 2; 
	else if(c == '+' || c == '-') 
	return 1; 
	else
	return -1; 
} 

// The main function to convert infix expression 
//to postfix expression 
void infixToPostfix(string s) 
{ 
	std::stack<char> st; 
	st.push('N'); 
	int l = s.length(); 
	string ns; 
	for(int i = 0; i < l; i++) 
	{ 
		// If the scanned character is an operand, add it to output string. 
		if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) 
		ns+=s[i]; 

		// If the scanned character is an ‘(‘, push it to the stack. 
		else if(s[i] == '(') 
		
		st.push('('); 
		
		// If the scanned character is an ‘)’, pop and to output string from the stack 
		// until an ‘(‘ is encountered. 
		else if(s[i] == ')') 
		{ 
			while(st.top() != 'N' && st.top() != '(') 
			{ 
				char c = st.top(); 
				st.pop(); 
			ns += c; 
			} 
			if(st.top() == '(') 
			{ 
				char c = st.top(); 
				st.pop(); 
			} 
		} 
		
		//If an operator is scanned 
		else{ 
			while(st.top() != 'N' && prec(s[i]) <= prec(st.top())) 
			{ 
				char c = st.top(); 
				st.pop(); 
				ns += c; 
			} 
			st.push(s[i]); 
		} 

	} 
	//Pop all the remaining elements from the stack 
	while(st.top() != 'N') 
	{ 
		char c = st.top(); 
		st.pop(); 
		ns += c; 
	} 
	
	cout << ns << endl; 

} 

//Driver program to test above functions 
int main() 
{ 
			cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i < n; ++i) {
		char t;
		cin >> t;
		if (t == '0') {
			b[i] = '-';
		}
		else if (t == '1') {
			b[i] = '+';
		}
		else  {
			b[i] = '*';
		}
	}

	A[0] = a[0];
	int j = 1;
	for (int i = 1; i < n; ++i) {
		A[j] = b[i];
		++j;
		A[j] = a[i];
		++j;
	}
	string exp = "a+b*(c^d-e)^(f+g*h)-i"; 
	infixToPostfix(A); 
	return 0; 
} 
// This code is contributed by Gautam Singh 
