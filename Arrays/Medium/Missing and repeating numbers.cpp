#include <bits/stdc++.h> 
#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{

	long long x = 0, x2 = 0, y = 0, y2 = 0;

	for(int i : arr){
		x += i; // calcualte S sum of the array elements
		x2 += i*i; // calculate S^2 sum of square of array elements
	}
		

	for(int i = 1; i <= n; i++){
		y += i;  // calcualte S sum of the elements from 1 to N
		y2 += i*i;	 // calcualte S^2 sum of the square of the elements from 1 to N
	}
		
	
	long long s = x - y, s2 = x2 - y2;

	long long xpy = s2/s;

	long long a = (xpy + s)/2, b = (xpy - s)/2;

	return {b, a};
	
}
