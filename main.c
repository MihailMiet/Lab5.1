//Создать функцию для поиска максимального отрицательного элемента произвольного массива целых чисел.
// Вернуть указатель на максимальный элемент. 
// Тестовая программа: 
// 1.Создать и инициализировать 2 массива A[N1], B[N2] 
// 2. Найти положение максимального отрицательного элемента массива. Полученный указатель разделяет массив на 2 части. 
// 3.Определить в какой части количество элементов больше 4. Пункты 2 и 3 выполнить для массивов A и B

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
 
int rand_print(int *M, int N) {
	int count=0;
	printf("\n");
	while (count < N) {
		M[count] = (-1) * rand();
		printf("%d ", M[count]);
		count++;
	}
	return M;
}

int findmaxneg(int* M, int N) {
	int count=0, maxneg = 0, index=0;
	M=rand_print(M, N);
	maxneg = M[0];
	while (count + 1 < N) {
		if (M[count] < 0 && M[count] > maxneg) { maxneg = M[count]; index = count; }
		else if (M[count] == maxneg) { count++; continue; }
		count++;
	}
	printf("\n\n%d\n", index+1);
	return index;
}

int split(int* M, int N) {
	int maxneg = findmaxneg(M, N);
	if (N % 2 == 0) {
		if (maxneg > N / 2) { return "\n right \n"; }
		else { return "\n left \n"; }
	}
	else {
		if (maxneg > N / 2) { return "\n right \n"; }
		else if (maxneg < N / 2) { return "\n left \n"; }
		else { return "\n none \n"; }
	}
}

int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int *A, *B, N1=0, N2=0, line=0;
	while (1) {
		scanf_s("%d %d", &N1, &N2);
		while (line < 20) { printf("="); line++; }
		line = 0;
		A = malloc(N1 * sizeof(int)); 
		B = malloc(N2 * sizeof(int));
		printf(split(A, N1));
		while (line < 20) { printf("="); line++; }
		printf(split(B, N2));
		free(A);
		free(B);
	}
	return 0;
}