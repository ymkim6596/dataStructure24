// 202310302 �迵��

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
	double* p1;
	p1 = (double *)malloc(sizeof(double));
	if(p == NULL) {
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.\n");
		exit(1);
	}
	*p1 = 23.92;

	printf("%.2f", *p1);

	free(p1);
	return 0;
}