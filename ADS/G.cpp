#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isNum(char C) {
	if(C >= '0' && C <= '9') return true;
	return false;
}
bool IsOperator(char C){
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
} 
int inOperation(char operation, int operand1, int operand2){
	if(operation == '+') return operand1 +operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	return -1; 
}
int inTesting(string expression){
	stack<int> S;
	for(int i = 0;i< expression.length();i++) { 
		if(expression[i] == ' ' || expression[i] == ',') continue; 
		else if(IsOperator(expression[i])) {
			int operand2 = S.top(); S.pop();
			int operand1 = S.top(); S.pop();
			int result = inOperation(expression[i], operand1, operand2);
			S.push(result);
		}
		else if(isNum(expression[i])){
			int operand = 0; 
			while(i<expression.length() && isNum(expression[i])) {
				operand = (operand*10) + (expression[i] - '0'); 
				i++;
			}
			i--;
			S.push(operand);
		}
	}
	return S.top();
}
int main() {
	string expression; 
	getline(cin,expression);
	int result = inTesting(expression);
	cout<<result<<"\n";
}