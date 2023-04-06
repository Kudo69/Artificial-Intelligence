#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
using namespace std;

#define tankcapacity_X 9 //Suc chua binh X
#define tankcapacity_Y 4 //Suc chua binh Y
#define empty 0
#define goal 6 //Muc tieu luong nuoc can dong duoc
#define Maxlength 100 //§Su dung cai dat Ngan xep (Stack)

//Khai bao cau truc trang thai
typedef struct
{
	int x; //Luong nuoc trong binh x
	int y; //Luong nuoc trong binh y
} State;

//Khoi tao trang thai binh X= 0 va Y =0
void makeNullState (State *state)
{
	state->x = 0;
	state->y = 0;
}

//In trang thai
void print_State(State state)
{
	printf("\n X:%d --- Y:%d", state.x, state.y);
}

//Ham kiem tra trang thai muc tieu
int goalcheck(State state) 
{
	return (state.x==goal || state.y==goal);
}

//Lam day nuoc binh X
int pourWaterFullX(State cur_state, State *result)
{
	if(cur_state.x < tankcapacity_X)
	{
		result->x = tankcapacity_X;
		result->y = cur_state.y;
		return 1;
	}
	return 0;
}

//Lam day nuoc binh Y
int pourWaterFullY(State cur_state, State *result)
{
	if(cur_state.y < tankcapacity_Y)
	{
		result->y = tankcapacity_Y;
		result->x = cur_state.x;
		return 1;
	}
	return 0;
}

//Ham lam rong nuoc trong X
int pourWaterEmptyX(State cur_state, State *result) 
{
	if(cur_state.x>0)
	{
		result->x = empty;
		result->y = cur_state.y;
		return 1;
	}
	return 0;
}

//Ham lam rong nuoc trong Y
int pourWaterEmptyY(State cur_state, State *result) 
{
	if(cur_state.y>0)
	{
		result->y = empty;
		result->x = cur_state.x;
		return 1;
	}
	return 0;
}

//Chuyen nuoc tu binh X sang binh Y
int pourWaterXY (State cur_state, State *result)
{
	if(cur_state.x>0 && cur_state.y<tankcapacity_Y)
	{
		result->x = max(cur_state.x - (tankcapacity_Y - cur_state.y), empty) ;
		result->y = min(cur_state.x + cur_state.y, tankcapacity_Y);
		return 1;
	}
	return 0;
}


//Chuyen nuoc tu binh Y sang binh X
int pourWaterYX (State cur_state, State *result)
{
	if(cur_state.y>0 && cur_state.x<tankcapacity_X)
	{
		result->y = max(cur_state.y - (tankcapacity_X - cur_state.x), empty) ;
		result->x = min(cur_state.y + cur_state.x, tankcapacity_X);
		return 1;
	}
	return 0;
}

//Goi cac phep toan tren trang thai
int call_operator(State cur_state, State *result, int option) 
{
	switch (option) 
	{
		case 1: return pourWaterFullX(cur_state, result);
		case 2: return pourWaterFullY(cur_state, result);
		case 3: return pourWaterEmptyX(cur_state, result);
		case 4: return pourWaterEmptyY(cur_state, result);
		case 5: return pourWaterXY (cur_state, result);
		case 6: return pourWaterYX(cur_state, result);
		default: printf("Error calls operators");
			return 0;

	}
}

//Dinh nghia gia tri cac bien tankcapacity_X, tankcapacity_Y, empty, goal, Maxlength
//Hằng chuối để in ra tên các hành động
const char* action[] = {"First State","pour Water Full x","pour Water Full Y",
				"pour Water Empty X","pour Water Empty Y",
				"pour Water X to Y","pour Water Y to X"};

//Khai bao cau truc trang thai
//Cài đặt các hàm hành động trạng thái
//Cài đặt hàm call operator

//Khai bao cau truc nut (dinh) de dung cay tim kiem
typedef struct Node
{
	State state;
	struct Node* Parent;
	int no_function;
} Node;

//Khai bao cau truc Stack de luu trang thai duyet
typedef struct
{
	Node* Elements[Maxlength] ;
	int Top_idx;
}Stack;

//Dua 1 phan tu len ngan xep
void push(Node* x, Stack *stack)
{
	if (full_Stack(*stack))
		printf ("Error!Stack is full");
	else
	{
		stack->Top_idx -=1;
		stack->Elements[stack->Top_idx]=x;

	}
}

//Khoi tao ngan xep rong
void makeNull_Stack(Stack *stack)
{
	stack->Top_idx = Maxlength;
}

//Kiem tra xem ngan xep co rong hay khong
int empty_Stack(Stack stack)
{
	return stack.Top_idx == Maxlength;
}

/*Kiem tra ngan xep co day khong*/
int full_Stack(Stack stack) 
{
	return stack.Top_idx == 0;
}

//Tra ve phan tu tren dinh ngan xep
Node* top (Stack stack) 
{
	if (!empty_Stack(stack))
		return stack.Elements[stack.Top_idx];
	return NULL;
}

//Xoa phan tu tai dinh ngan xep
void pop (Stack *stack)
{
	if (!empty_Stack(*stack))
		stack->Top_idx+=1;
	else 
		printf("Error! Stack is empty");

}


//Tim trang thai trong Stack Open/Close
// int find_State(State state, Stack openStack) 
// {
// 	while(!empty_Stack(openStack))
// 	{
// 		if(compareStates(top(openStack)->state,state))
// 			return 1;
// 		pop (&openStack) ;
// 	}
// 	return 0;
// }


int main()
{
	State cur_state = {5, 4}, result;
	printf ("Trang thai bat dau");
	print_State(cur_state);
	int opt;
	for(opt=1; opt<=6; opt++)
	{
		int thuchien = call_operator(cur_state, &result, opt);
		if(thuchien == 1)
		{
			//thuc hien hanh dong thanh cong
			printf ("\nHanh dong %s thanh cong", action[opt]);
			print_State (result);
		}
		else
			printf("\nHanh dong %s KHONG thanh cong", action[opt]);
	}
	return 0;
}









