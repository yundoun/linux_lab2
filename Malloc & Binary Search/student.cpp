#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 학생 정보를 저장하는 구조체
struct Student
{
  char name[50];
  int midterm;
  int final;
  struct Student *left;
  struct Student *right;
};

// 새로운 학생 노드를 생성하여 반환하는 함수
struct Student *createStudent(char name[], int midterm, int final)
{
  struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
  strcpy(newStudent->name, name);
  newStudent->midterm = midterm;
  newStudent->final = final;
  newStudent->left = NULL;
  newStudent->right = NULL;
  return newStudent;
}

// 학생을 이진 탐색 트리에 삽입하는 함수
struct Student *insert(struct Student *root, char name[], int midterm, int final)
{
  if (root == NULL)
  {
    return createStudent(name, midterm, final);
  }

  // 학생 이름을 기준으로 비교하여 적절한 위치에 삽입
  if (strcmp(name, root->name) < 0)
  {
    root->left = insert(root->left, name, midterm, final);
  }
  else if (strcmp(name, root->name) > 0)
  {
    root->right = insert(root->right, name, midterm, final);
  }

  return root;
}

// 학생 정보를 중위 순회로 출력하는 함수
void inorderTraversal(struct Student *root)
{
  if (root != NULL)
  {
    inorderTraversal(root->left);
    printf("이름: %s, 중간 점수: %d, 기말 점수: %d\n", root->name, root->midterm, root->final);
    inorderTraversal(root->right);
  }
}

int main()
{
  int studentCount;
  printf("학생 수를 입력하세요: ");
  scanf("%d", &studentCount);

  struct Student *root = NULL;

  for (int i = 0; i < studentCount; i++)
  {
    char name[50];
    int midterm, final;
    printf("학생 이름, 중간 점수, 기말 점수를 입력하세요: ");
    scanf("%s %d %d", name, &midterm, &final);
    root = insert(root, name, midterm, final);
  }

  printf("학생 정보:\n");
  inorderTraversal(root);

  // 메모리 해제
  // (실제 프로덕션 코드에서는 메모리 해제를 더 신중하게 처리해야 합니다.)
  free(root);

  return 0;
}