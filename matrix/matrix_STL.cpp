#include <iostream>
#include <vector>

using namespace std;

// 행렬을 더하는 함수
vector<vector<int>> addMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
  int rows = A.size();
  int cols = A[0].size();
  vector<vector<int>> result(rows, vector<int>(cols));

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      result[i][j] = A[i][j] + B[i][j];
    }
  }

  return result;
}

int main()
{
  int rows, cols;

  // 행렬의 크기를 입력 받음
  cout << "행렬의 행 수를 입력하세요: ";
  cin >> rows;
  cout << "행렬의 열 수를 입력하세요: ";
  cin >> cols;

  // 행렬 A 입력
  vector<vector<int>> A(rows, vector<int>(cols));
  cout << "첫 번째 행렬 A의 요소를 입력하세요:\n";
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cin >> A[i][j];
    }
  }

  // 행렬 B 입력
  vector<vector<int>> B(rows, vector<int>(cols));
  cout << "두 번째 행렬 B의 요소를 입력하세요:\n";
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cin >> B[i][j];
    }
  }

  // 두 행렬을 더함
  vector<vector<int>> result = addMatrices(A, B);

  // 결과 출력
  cout << "두 행렬의 합:\n";
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}