//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//long long ans = 6;
//int guess(int num)
//{
//	if (ans == num)
//		return 0;
//	return ans < num ? -1 : 1;
//}
//
//long long B_S(long long left, long long right)
//{
//	if (left == right)
//		return left;
//	long long the_guess = (left + right) / 2;
//	if (!guess(the_guess))
//		return the_guess;
//	long long temans;
//	return temans = guess(the_guess) == -1 ?  B_S(left, the_guess - 1) :  B_S(the_guess + 1, right);
//}
//
//int guessNumber(int n) 
//{
//	return B_S(1, n);
//}
//
//int main()
//{
//	cout<<guessNumber(10);
//}
///////////374


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long ans = 8;
long long money = 0;
int guess(int num)
{
	if (ans == num)
		return 0;
	return ans < num ? -1 : 1;
}
long long B_S(long long left, long long right)
{
	cout<<"test"<<endl;
	if (left == right)
		return left;
	long long the_guess = (left + right) / 2;
	if (!guess(the_guess))
		return the_guess;
	money += the_guess;
	cout << the_guess << endl;
	long long temans;
	return temans = guess(the_guess) == -1 ?  B_S(left, the_guess - 1) :  B_S(the_guess + 1, right);
}
int getMoneyAmount(int n) {
	cout << "B_S:" << B_S(1, n) << endl;
	return money;
}
int main()
{
	cout << getMoneyAmount(10);
}