// 202310302 김영민

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERMS 101
typedef struct {
	float coef;
	int expon;
} polynomial;
polynomial terms[MAX_TERMS] = { { 8,3 },{ 7,1 },{ 1,0 },{ 10,3 },{ 3,2 },{ 1,0 } };
int avail = 6;

// 두 개의 정수를 비교
char compare(int a, int b)
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

// 새로운 항을 다항식에 추가한다.
void attach(float coef, int expon)
{
	if (avail > MAX_TERMS) {
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}

 //C = A + B
void poly_sub2(int Astart, int Aend, int Bstart, int Bend, int* Cstart, int* Cend) {
	float tempcoef;
	*Cstart = avail;
	while (Astart <= Aend && Bstart <= Bend) {
		switch (compare(terms[Astart].expon, terms[Bstart].expon)) {
		case '>': // A의 차수 > B의 차수
			attach(terms[Astart].coef, terms[Astart].expon);
			Astart++;
			break;
		case '=': // A의 차수 == B의 차수
			tempcoef = terms[Astart].coef - terms[Bstart].coef;
			if (tempcoef)
				attach(tempcoef, terms[Astart].expon);
			Astart++;
			Bstart++;
			break;
		case '<': // A의 차수 < B의 차수
			attach(-terms[Bstart].coef, terms[Bstart].expon);
			Bstart++;
			break;
		}
	}
	// A의 나머지 항들을 이동함
	for (; Astart <= Aend; Astart++)
		attach(terms[Astart].coef, terms[Astart].expon);
	// B의 나머지 항들을 이동함
	for (; Bstart <= Bend; Bstart++)
		attach(terms[Bstart].coef, terms[Bstart].expon);
	*Cend = avail - 1;
}

void print_poly(int start, int end)
{
	for (int i = start; i < end; i++) {
		printf("%3.1fx^%d ", terms[i].coef, terms[i].expon);
		if (terms[i + 1].coef >= 0)
			printf("+");
		}
	printf("%3.1fx^%d\n", terms[end].coef, terms[end].expon);
}

int main(void)
{
	int Astart = 0, Aend = 2, Bstart = 3, Bend = 5, Cstart, Cend;
	poly_sub2(Astart, Aend, Bstart, Bend, &Cstart, &Cend);
	print_poly(Astart, Aend);
	print_poly(Bstart, Bend);
	printf("-----------------------------------------------------------------------------\n");
	print_poly(Cstart, Cend);
	return 0;
}