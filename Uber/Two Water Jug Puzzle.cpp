You are on the side of the river. You are given a m liter jug and a n liter jug where 0 < m < n. Both the jugs are initially empty. The jugs don’t have markings to allow measuring smaller quantities. You have to use the jugs to measure d liters of water where d < n. Determine the minimum no of operations to be performed to obtain d liters of water in one of jug.

Solutions:
/*
 * WaterJug_main.cpp
 *
 *  Created on: 24-Jul-2020
 *      Author: aditi
 */
#include<iostream>
#include <time.h>
#include<vector>
using namespace std ;

int gcdCal(int a, int b){
	if(a == 0) return b ;
	return gcdCal(b%a, a) ;
}

void printAnswer(vector<vector<int>>nums){

	for(vector<int> num: nums){
		for(int a : num){
			cout << a << ",";
		}
		cout << endl ;
	}
}

int calPath(int jug1, int jug2 , int target, vector<vector<int>>& nums){

	/*
	 * This is jug is used to fill the other jug
	 */
	int from = jug1 ;

	/*
	 * This is the jug which is to be filles and intially it is empty
	 */
	int to = 0 ;

	/*
	 * This is used to count he number of the step
	 */
	int step = 0 ;

	/*
	 * Whenever we are increasing the step we are also all it to the nums vector
	 */
	nums.push_back({from,to}) ;
	step++ ;

	while(from != target && to != target ){

		int minTransfer = min(from , jug2-to) ;

		from = from - minTransfer ;
		to = to + minTransfer ;

		nums.push_back({from,to}) ;
		step++ ;

		if(from == target || to == target) break ;

		/*
		 * The fillin jug becomes empty => refill it
		 */
		if(from == 0){
			from = jug1 ;
			nums.push_back({from,to}) ;
			step++ ;
		}
		/*
		 * The filled jug is full => empty it
		 */
		if(to == jug2){
			to = 0 ;
			nums.push_back({from,to}) ;
			step++ ;
		}
	}


	return step ;
}


int main(){

	int jug1 ;
	int jug2 ;
	int target ;
	cout << "Enter Jug 1 :" ;
	cin >> jug1 ;
	cout << "Enetr Jug2 :" ;
	cin >> jug2 ;
	cout << "Enter target amount :" ;
	cin >> target ;

	if(target > max(jug1,jug2)) {cout << "Not possible " ; return 0 ;}

	if(target % gcdCal(jug1, jug2) != 0) {cout << "Not possible " ; return 0 ;}

	//the processing is possible and it is required

	vector<vector<int>>answer1 ;
	vector<vector<int>>answer2 ;

	int pathSize1 = calPath(jug1, jug2 , target, answer1) ;
	int pathSize2 = calPath(jug2, jug1 , target, answer2) ;

	if(pathSize1 < pathSize2) {
		printAnswer(answer1) ;
	}
	else{
		printAnswer(answer2) ;
	}

	return 0 ;
}



