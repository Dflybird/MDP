/*Copyright(C), 2018- , gq.
File name: MDP
Author: gq
version: 1.0
Date: 2018.
Description: ┌ ┐ └ ┘ ┬ ┴ ┤ ├ ┼ ─ │ ↑ ↓ ← → ▄ █ ▀ ▐ ▌
             ┌────┬────┬────┬────┐
         3   │    │    │    │ +1 │            ↑0.8
             ├────┼────┼────┼────┤          ┌───┐
         2   │    │████│    │ -1 │    0.1 ← │ ↑ │ → 0.1
             ├────┼────┼────┼────┤          └───┘
         1   │sta │    │    │    │
             └────┴────┴────┴────┘
               1    2    3    4
A MDP consists of a set of states(S); a set of actions in each state(A); a transition model(P); and a reward function(R).
*/

#include <stdio.h>
#include <Windows.h>
#include "matrix.h"
#include "stack.h"

//The intended outcome occurs with probability 0.8, with probability 0.1 turn left or turn right to the intended direction
#define pa {0.1, 0.8, 0.1}	
//Negative reward in all states except the terminal states
#define R -0.04

enum Dir
{
	up, down, right, left, absorb, null
};
enum action {
	turn_left, go_on, turn_right
};
struct S
{
	int x, y;
	Dir act;
	S* next_state;
};

int main(int argc, char* argv[]) {

	init();

	system("pause");
	return 0;
}

/*Return the expected sum of discounted reward if the agent executes an optimal policy, we write this as U(s);
U(s) is the "long term" total reward diffrent to R(s), the "short term" reward;
calculated with gamma = 1, U(s) = E[R(s)] + r∑(s'∈S)P(s'|a, s)U(s')
*/

int RealDir(action act, Dir dir, Dir* realDir) {
	//If direction is up, the probability of up is 0.8, of left is 0.1, of right is 0.1

}

void init() {
	/*An optimal policy for the stochastic environment
	    ┌───┬───┬───┬───┐
	3	│ → │ → │ → │+1 │
    	├───┼───┼───┼───┤
	2	│ ↑ │███│ ↑ │-1 │
		├───┼───┼───┼───┤
	1	│ ↑ │ ← │ ← │ ← │
		└───┴───┴───┴───┘
		  1   2   3   4
	*/

	double Rs[3][4] = { { R, R, R, 1 },
	{ R, 0, R, -1 },
	{ R, R, R, R } };
	Dir A[3][4] = { { right, right, right, absorb },
	{ up, null, up, absorb },
	{ up, left, left, left } };

	double P[3][4] = { { 1, 1, 1, 1 },
	{ 1, 0, 1, -1 },
	{ 1, 1, 1, 1 } };
	//Utility
	double U[3][4] = { { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 } };


	S* s0;
	s0->x = 1;
	s0->y = 1;
	s0->act = up;
	S* s1;
	s1->x = 1;
	s1->y = 2;
	s1->act = up;
	S* s2;
	s2->x = 1;
	s2->y = 3;
	s2->act = right;
	S* s3;
	s3->x = 2;
	s3->y = 3;
	s3->act = right;
	S* s4;
	s4->x = 3;
	s4->y = 3;
	s4->act = right;
	S* s5;
	s5->x = 2;
	s5->y = 1;
	s5->act = left;
	S* s6;
	s6->x = 2;
	s6->y = 1;
	s6->act = left;
	S* s7;
	s7->x = 3;
	s7->y = 1;
	s7->act = left;
	S* s8;
	s8->x = 4;
	s8->y = 1;
	s8->act = left;
	S* s9;
	s9->x = 3;
	s9->y = 2;
	s9->act = up;

	s0->next_state = s1;
	s1->next_state = s2;
	s2->next_state = s3;
	s3->next_state = s4;
	s4->next_state = NULL;
	s5->next_state = s0;
	s6->next_state = s5;
	s7->next_state = s6;
	s8->next_state = s4;
}