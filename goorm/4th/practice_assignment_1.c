/*
1. 구조체 연습문제(1)
다음 소스 코드를 완성하여 2차원 좌표 x, y를 표현하는 구조체 Point를 정의하고, 10 20이 출력되도록 하는 코드를 제출하시오. (좌표의 자료형은 int)

소스 코드)

#include <stdio.h>
1)
struct______________
____________________
____________________
____________________
int main()
{
    2)________________ p1;
    3)_______________
    p1.y = 20;
    printf("%d %d\n", p1.x, p1.y);
    return 0;
}


정답)

struct point {
int x;
int y;
} Point;
Point p1;
p1.x = 10;
*/

/*
2. 구조체 연습문제(2)
학생 구조체 Student 가 아래와 같이 정의되어 있다. 소스 코드를 완성하여 학생 정보가 아래 정답과 같이 출력되도록  빈칸 코드(1~3)를 작성하여 제출하시오.

소스 코드)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[20];
    int grade;
    int class;
    float average;
}Student;
int main(){
    Student *s1 = 1)___________________________;

    2)_______________________________
    ________________________________
    ________________________________
    ________________________________

    printf("이름: %s\n", s1->name);
    printf("학년: %d\n", s1->grade);
    printf("반: %d\n", s1->class);
    printf("평균점수: %f\n", s1->average);

    free(s1);

    return 0;
}


정답) 

(Student *)malloc(sizeof(Student)

s1->name = "고길동"
s1->grade = 1;
s1->class = 3;
s1->average = 65.389999;
*/

/*
3. 구조체 연습문제(3)
상품 구조체 Item이 정의되어 있습니다. 다음 소스 코드를 완성하여 "한정판"이 출력되게 만드세요.

소스 코드)

#include <stdio.h>
#include <stdbool.h>

struct Item {
    char name[100];
    int price;
    bool limited;
};

int main()
{
    struct Item item1 = { "베를린 필하모닉 베토벤 교향곡 전집", 100000, false };
    1)____________________

    2)____________________

    ptr->limited = true;

    if (ptr->limited == true)
        printf("한정판\n");
    else
        printf("일반판\n");

    return 0;
}


정답)

struct Item* ptr
ptr = &item1
*/

/*
다음 두 코드의 차이점에 대해 서술하시오.

int * ptr[4]

int (*ptr)[4]

첫 번째는 int형 포인터 값 4개를 저장하는 포인터 배열이고
두 번쨰는 열의 크기가 4개인 2차원 배열을 가리키는 배열 포인터이다.
*/