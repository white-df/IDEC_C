#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void update(int a, int b) {
    a += b;
}

void updatePointer(int* a, int b) {
    *a += b;
}

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printIntArray(int a[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    
    
    // 1. 포인터를 실습해보자
    int n = 5; // 5라는 값을 가진 정수형 변수 num
    int *p = &n; // 변수 n의 주소값을 p라는 포인터 변수에 저장
    int **p2 = &p;

    printf("n이 담고 있는 값: %d\n", n);
    printf("n의 주소 값 :    %p\n", &n);
    printf("p가 담고 있는 값: %p\n", p);
    printf("p가 가리키는 값:  %d\n", *p);
    printf("p의 주소 값 :    %p\n", &p);
    printf("p2가 담고 있는 값:%p\n", p2);
    printf(" : %d\n\n", **p2);

    // 변수 t1과 숫자 n을 입력받아 변수 t1의 값을 숫자 n을 더해 업데이트하는 void 함수를 작성하시오.
    int t1 = 5;
    update(t1, 3);
    printf("After normal update,  t1의 값: %d\n", t1);
    // 예상 값이 8이 나오도록 작성해보시오.
    
    updatePointer(&t1, 3);
    printf("After pointer update, t1의 값: %d\n\n", t1);
    // 기본적으로 함수의 매개변수는 변수 그 자체를 입력받는 것이 아니라 변수가 가지고 있는 그 값만 입력받는 것
    // 그래서 함수 코드 내에서 값을 업데이트해주는 것은 매개변수로 넣는 변수에 어떠한 영향을 끼치지 못한다.
    // 따라서 변수가 가지는 값에 변화를 주고 싶으면, 변수의 주소를 입력으로 넣어 주소가 가리키는 값을 직접 바꿔주는 방식으로 접근해야 한다.

    // 변수 t2와 변수 t3의 값을 서로 바꾸는 void 함수를 작성하시오.
    int t2 = 2;
    int t3 = 4;
    swap(t2, t3);
    printf("After normal swap,  t2의 값: %d, t3의 값: %d\n", t2, t3);
    swapPointer(&t2, &t3);
    printf("After pointer swap, t2의 값: %d, t3의 값: %d\n\n", t2, t3);






    // 2. 배열을 실습해보자.
    // 배열을 만드는 법
    int arr1[5] = {1, 2, 3, 4, 5};
    printIntArray(arr1, sizeof(arr1)/sizeof(int));

    int arr2[] = {1, 2, 3, 4, 5};
    printIntArray(arr2, 5);

    int arr3[5];
    printIntArray(arr3, 5);

    int arr4[5] = {1, 2};
    printIntArray(arr4, 5);

    int arr5[5] = {};
    printIntArray(arr5, 5);

    printf("\n");
    
    // 배열의 길이를 알 수 있는 방법
    int length = sizeof(arr1)/sizeof(arr1[0]);
    printf("The size of array   : %lu\n", sizeof(arr1));
    printf("The size of integer : %lu\n", sizeof(int));
    printf("The length of array : %d\n\n", length);

    // 배열의 원소에 접근하는 법
    int i = 0;
    printf("%d번째 인덱스의 원소 값: %d\n\n", i, arr1[i]);
    
    
    // 연습 1) 반복문을 이용해 1차원 정수형 배열의 원소값들을 출력해보자.
    
    
    
    // 배열과 포인터 간의 관계
    int temp[] = {2, 5, 8, 15, 23};
    printf("temp의 주소값   : %p\n", temp);
    printf("temp[0]의 주소값: %p\n\n", &temp[0]);
    // 사실 배열은 그 자체로 배열의 첫번째 값의 주소값을 반환한다.

    printf("*temp: %d\n\n", *temp);
    // 배열의 주소가 가리키는 값은 해당 배열의 첫번째 원소이다.
    // 따라서 배열명 앞에 *을 붙이면 첫번째 원소 값을 반환한다.

    int j = 3;
    printf("*(temp+%d): %d\n\n", j, *(temp+j));
    // 이를 이용해 우리는 배열의 인덱싱을 할 수 있는데
    // 배열의 주소 값에 특정 값 i를 더하면 우리는 배열의 i번째 원소의 포인터 값을 알 수 있다.
    // 따라서 *(배열+i) 를 통해 배열의 i번째 원소 값을 알 수 있다.
    

    // 연습 2) 1차원 정수형 배열을 매개변수로 입력받아 해당 배열의 원소값들을 출력하는 함수를 만들고 실행시켜보자.
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // 우리가 배열의 길이를 구할 때, 배열의 size를 이용해 길이를 구했는데
    // 만약 함수의 매개변수로 배열을 사용하면 단순히 포인터 주소값만 입력받기 때문에
    // 함수 내에서는 해당 배열의 size를 알 수 없다.
    // 단순히 포인터 주소 값의 size만을 반환한다.
    // 따라서 만약 함수 내에서 배열의 길이를 필요로 하면 함수 밖에서 배열의 길이를 구하고 매개변수로 입력해야 한다.
    
    // 연습 2-1) 1차원 정수형 배열과 배열의 길이를 매개변수로 입력받아 해당 배열의 원소값들을 출력하는 함수를 만들고 실행시켜보자.
    
    
    
    
    
    
    
    
    

    // 이중배열을 만들어보자.
    int twoDim[3][4] = {{3, 5, 7, 0},
                        {2, 6, 9, 11},
                        {1, 4, 8, 10}};
    int a = 0;
    int b = 1;
    printf("twoDim[%d][%d]: %d\n", a, b, twoDim[a][b]);
    printf("r : %lu\n", sizeof(twoDim)/sizeof(twoDim[0]));
    printf("c : %lu\n", sizeof(twoDim[0])/sizeof(twoDim[0][0]));
    printf("\n");

    // 각자 충분히 이중배열을 만들어보고 인덱싱을 연습해보자
    
    
    // 연습 3) 2차원 정수형 배열의 원소값들을 출력하는 함수를 정의하고 실행시켜보자.
    
    
    
    
    // 이중 배열과 포인터
    int iNums[2][3] = {{1, 2, 3},
                       {4, 5, 6}};
    
    printf("%p\n", iNums);
    printf("%p\n", *iNums);
    printf("%d\n", **iNums);
    
    printf("%d\n", **(iNums+1)        );
    printf("%d\n", *((*iNums)+1)      );
    printf("%d\n", *(*(iNums+1)+1)    );
    printf("%d\n\n", *(*(iNums+1)+1)+1);


    


    // 3. 문자열을 실습해보자.

    // 배열과 동일한 방법으로 문자열을 선언하는 법
    char strExample[20] = "Hello, World!";
    int len1 = sizeof(strExample)/sizeof(char);
    printf("%s\n", strExample);
    printf("%d\n", len1);
    // 문자열의 길이가 1이 더 큰 이유는 마지막에 자동으로 들어가는 NULL 문자 때문이고
    // 따라서 이렇게 구한 길이의 1을 빼야 한다.
    
    strExample[2] = 'r';
    printf("%s\n\n", strExample);
    // 문자열 내의 원소를 다음과 같은 방법으로 수정도 가능

    // 포인터를 이용해 문자열을 선언하는 법
    char* strExample2 = "Hello, World!";
    int len2 = sizeof(strExample2)/sizeof(char);
    printf("%s\n", strExample2);
    printf("%d\n", len2);
    // 사실 일반적인 배열 또한 포인터를 이용해서 선언할 수도 있다.
    // 포인터로 선언한 배열은 포인터로만 값을 가지고 있기 때문에 길이를 구할 수 없다.
    
//    *(strExample2+2) = 'r';
//    printf("%s\n\n", strExample2);
    // 포인터를 이용한 문자열 선언은 일종의 상수형 문자열과 같아 문자열 내 문자를 수정할 수 없음
    // 문자열을 새롭게 생성한 후 재할당할 수 밖에 없음 (아래와 같음)
//    strExample2 = "Herlo, World!";
//    printf("%s\n\n", strExample2);

    int len3 = (int)strlen(strExample2);
    printf("\nstrlen: %d\n", len3);
    // 이럴 경우, string.h 이라는 헤더 파일을 이용해 문자열을 쉽게 다룰 수 있다.
    // strlen 이라는 함수를 사용하면 문자열의 길이를 알 수 있다.
    
    // 문자열을 정수로 바꿀 땐, stdlib.h에 있는 atoi 함수를 사용
    char* c = "256";
    int ci = atoi(c);
    printf("%s, %d\n", c, ci);
    
    // 문자열을 실수로 바꿀 땐, stdlib.h에 있는 atof 함수를 사용
    char* c2 = "2.34";
    float c2i = atof(c2);
    printf("%s, %f\n", c2, c2i);
    
    // 두 문자열을 비교할 땐, strcmp를 사용
    // 완전히 같으면 0을 반환
    if (!strcmp(c, c2)) { printf("True\n\n"); }
    else { printf("False\n\n"); }
    
    // 정수를 출력시킬 때, 빈 자리는 0을 채우는 방법
    // 예를 들어, 125는 00125로
    // 우리가 풀었던 시간 문제를 예로 들면, 1:3:15가 아니라 01:03:15 가 출력되는 방법
    printf("%05d\n", 125);
    // %0nd 는 빈 공간을 0으로, %nd는 빈 공간을 공백으로
    
    
    return 0;
}

