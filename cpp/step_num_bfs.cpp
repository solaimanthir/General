#include <iostream>
using namespace std;

void step_num_bfs(int n, int m, int digit)
{
	queue<int> q;
	q.push(digit);
	while(q.empty() == false) {
		int num = q.front();
		q.pop();
		
		if(num >= n && num <= m)
			cout << num << " ";
		if(digit == 0 || num > m)
			continue;
		int last_digit = num%10;
		int numA = (num*10)+(last_digit-1);
		int numB = (num*10)+(last_digit+1);
		if(last_digit != 0 && last_digit != 9){
			q.push(numA);
			q.push(numB);
		}
		if(last_digit == 0){
			q.push(numB);
		}
		if(last_digit == 9){
			q.push(numA);
		}
	}
}
int main()
{
	int n = 0, m = 12345678;
	for(int i = 0; i <= 9; ++i){
		step_num_bfs(n, m, i);	
	}
	printf("\n");
	return 0;	
}
