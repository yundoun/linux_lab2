#include <stdio.h>
#include <stdlib.h>

// 행렬을 생성하고 초기화하는 함수
int **createMatrix(int rows, int cols)
{
  int **matrix = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++)
  {
    matrix[i] = (int *)malloc(cols * sizeof(int));
  }
  return matrix;
}

// 행렬을 해제하는 함수
void freeMatrix(int **matrix, int rows)
{
  for (int i = 0; i < rows; i++)
  {
    free(matrix[i]);
  }
  free(matrix);
}

// 두 행렬을 더하는 함수
void addMatrices(int **A, int **B, int **result, int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      result[i][j] = A[i][j] + B[i][j];
    }
  }
}

int main()
{
  int rows, cols;

  // 행렬의 크기를 입력 받음
  printf("행렬의 행 수를 입력하세요: ");
  scanf("%d", &rows);
  printf("행렬의 열 수를 입력하세요: ");
  scanf("%d", &cols);

  // 행렬 A 생성 및 초기화
  int **A = createMatrix(rows, cols);
  printf("첫 번째 행렬 A의 요소를 입력하세요:\n");
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      scanf("%d", &A[i][j]);
    }
  }

  // 행렬 B 생성 및 초기화
  int **B = createMatrix(rows, cols);
  printf("두 번째 행렬 B의 요소를 입력하세요:\n");
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      scanf("%d", &B[i][j]);
    }
  }

  // 결과 행렬 생성
  int **result = createMatrix(rows, cols);

  // 두 행렬을 더함
  addMatrices(A, B, result, rows, cols);

  // 결과 출력
  printf("두 행렬의 합:\n");
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  // 할당된 메모리 해제
  freeMatrix(A, rows);
  freeMatrix(B, rows);
  freeMatrix(result, rows);

  return 0;
}