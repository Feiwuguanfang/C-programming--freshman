#pragma once
#include<easyx.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>

#define NODE_WIDTH 40

typedef struct {
	int x;
	int y;
}node;
enum direction
{
	eup,
	edown,
	eleft,
	eright
};
void paintGrid();
void paintSnake(node* snake, int n);
node snakemove(node* snake, int length, int direction);
void changedirection(enum direction* pD);
void paintfood(node food);
node creatfood(node* snake, int length);
bool isgameover(node* snake, int length);
void reset(node* snake, int* plength, enum direction* d);