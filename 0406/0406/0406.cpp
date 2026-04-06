// 0406.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void asdf()
{

}


int g_p = 0;

int main()
{
    /// 포인터와 배열의 문법이 동일해요.
    int aa[5] = { 0, };
    int array[5] = { 1, 2, 3, 4, 5 };
    int* ap = array;        /// 배열변수 array는 그 자체로 주소다.
    /// 배열 변수명은 선언되자 마자 상수가 된다.
    /// 배열이 가리키는 주소가 변경되면 찾을 수 없다.
    //array = aa;
    ap = aa;
    printf("array : %d %d %d %d %d\n",
        array[0], array[1], array[2], array[3], array[4]);
    printf("array : %d %d %d %d %d\n",
        *(array + 0), *(array + 1), *(array + 2), *(array + 3), *(array + 4));

    printf("ap : %d %d %d %d %d\n",
        ap[0], ap[1], ap[2], ap[3], ap[4]);
    printf("ap : %d %d %d %d %d\n",
        *(ap + 0), *(ap + 1), *(ap + 2), *(ap + 3), *(ap + 4));

    /// 동적 메모리 할당으로 배열 형태를 포인터로 만들자
    int* aap = nullptr;
    aap = (int*)malloc(sizeof(int) * 5);
    aap[0] = 9;
    *(aap + 1) = 99;
    aap[2] = 999;
    *(aap + 3) = 9999;
    aap[4] = 99999;
    printf("ap : %d %d %d %d %d\n",
        aap[0], aap[1], aap[2], aap[3], aap[4]);
    printf("ap : %d %d %d %d %d\n",
        *(aap + 0), *(aap + 1), *(aap + 2), *(aap + 3), *(aap + 4));

    free(aap);

    /// 범용 포인터 : void*
    /// void 자료형 선언 불가능 : 크기를 알 수 없다.
    //void v = 0;
    int i = 9;
    char c = 65;
    double d = 999.987;

    /*
    int* iip = &c;
    char* ccp = &d;
    double* ddp = &i;
    */

    /// void는 자료형 선언 불가지만, void*는 가능한 이유
    /// 단순하게 주소를 가리키키만 할 수 있는 자료형이기 때문.
    void* ip = &i;
    void* cp = &c;
    void* dp = &d;
    /*
    *ip;    /// 값에 대한 접근 불가능
    ip[0];
    *(ip + 3);
    */

    /// 다중 포인터의 사용 예제
    int iii = 0;            /// int = int;
    int* p1 = &iii;         /// int* = &int
    int* pp1 = p1;          /// int* = int*
    int** p2 = &p1;         /// int** = &int*
    int** pp2 = p2;         /// int** = int**
    int*** p3 = &p2;        /// int*** = &int**
    int*** pp3 = p3;        /// int*** = int***
    int**** p4 = &p3;       /// int**** = &int***
    *p1 = 9;        /// *int* == int == iii
    printf("p1[ %d ] iii[ %d ]\n", *p1, iii);
    **p2 = 99;      /// *int** == int* == p1
                    /// p1 == int* => *int* == iii
    printf("p2[ %d ] iii[ %d ]\n", **p2, iii);
    ***p3 = 999;
    printf("p3[ %d ] iii[ %d ]\n", ***p3, iii);
    ****p4 = 9999;
    printf("p4[ %d ] iii[ %d ]\n", ****p4, iii);

    printf("\n\ng_p : %p\n", &g_p);
    printf("iii[%d] : %p\n", iii, &iii);
    printf("p1[%d] : %p %p\n", *p1, &p1, p1);
    printf("p2[%d] : %p %p %p\n", **p2, &p2, p2, *p2);
    printf("p3[%d] : %p %p %p %p\n", ***p3, &p3, p3, *p3, **p3);
    printf("p4[%d] : %p %p %p %p %p\n", ****p4, &p4, p4, *p4, **p4, ***p4);
    
    /// 참조 타입(reference)
    /// 포인터 문법이 아니지만, 내부에서 포인터처럼
    /// 사용할 수 있도록 만들어주는 방법
    int i1 = 999;
    int& r = i1;        /// 참조 타입의 선언
                        /// 자료형 &변수명 = 참조할변수;
                        /// r == i1
    /// 참조 타입 사용에 주의사항!
    /*
    int& rr;        /// 이니셜라이저가 필요합니다 오류!
    int& rrr = nullptr;     /// 상수 값으로 초기화 불가능!
    int& rrrr = NULL;       /// 상수 값으로 초기화 불가능!
    int& rrrrr = 9;         /// 상수 값으로 초기화 불가능!
    */
    /// 참조 타입 변수는 반드시 변수로 초기화해야 동작!!!!

    r = 9;
    printf("r[ %d ] i1[ %d ]\n", r, i1);
    i1 = 9999;
    printf("r[ %d ] i1[ %d ]\n", r, i1);

    /// 배열
    /// 동일한 성격과 특징을 갖는 다수 개의 변수를 한꺼번에 선언한다.
    /// 40명의 학생 정보 : 7개씩
    /*
    int cs1, cs2, cs3, cs4, ..., cs40;
    /// ==> int cs[40];
    /// 첫번째 인덱스가 항상 0으로 시작!
    /// 배열도 주소를 이용한 연산을 수행하기 때문에
    /// 인덱스 값이 1부터 시작하면 첫번째 값이 아니라
    /// 두번째 값부터 접근하게 되므로...
    /// cs[0] O
    /// cs[1] X
    int aa1, aa2, aa3, aa4, ..., aa40;
    int cs1, cs2, cs3, cs4, ..., cs40;
    int aa1, aa2, aa3, aa4, ..., aa40;
    int cs1, cs2, cs3, cs4, ..., cs40;
    int cs1, cs2, cs3, cs4, ..., cs40;
    int aa1, aa2, aa3, aa4, ..., aa40;
    */
    int arr1[54] = { 98, 77 };
    int* arrp = arr1;
    printf("arr1 : %d %d %d\n", arr1[0], *(arr1 + 0), *arr1);
    printf("arrp : %d %d %d\n", arrp[0], *(arrp + 0), *arrp);
    //arr1[87] = 990;

    /// 구조체 Vs. 배열(동일 특성, 자료형)
    /// 서로 다른 특성과 자료형을 갖는 변수를 한꺼번에 선언한다.
    /// 구조체 선언
    /// 예약어 구조체이름 { 멤버 변수1; 멤버 변수2; ... };
    struct character
    {
        char name[20];      /// 자신의 캐릭터 이름
        int level;          /// 캐릭터의 레벨
        int hp;             /// 캐릭터의 체력
        char mp;            /// 캐릭터의 마법~
        char pat_name[8];   /// 펫의 이름
    }       /// 구조체의 선언
    myC;    /// 변수명을 주면, 변수까지 즉시 선언!
    /// 선언 즉시 변수까지 선언
    /// 구조체의 멤버에 접근하는 연산자
    /// 1. . 연산자(직접 멤버 연산자) : 일반 변수
    /// 2. -> 연산자(간접 멤버 연산자) : 포인터 변수
    myC.level = 99;
    printf("level : %d\n", myC.level);

    /// 선언되어 있는 구조체의 변수를 선언
    /// C언어 스타일의 구조체 변수 선언법
    struct character e1;
    /// C++언어 스타일의 구조체 변수 선언법
    character e2;
    e1.level = 3;
    e2.level = 5;
    /// 동일한 구조체 변수라면 대입 연산이 가능!!!
    e1 = e2;

    /// 구조체 선언 == 자료형의 선언 == #define 자료형
    /// character == int 랑 같은 형식이다.
    /// 구조체형 포인터를 선언하고, 주소를 받는 선언.
    character* ep = &e1;
    /// 구조체형 포인터를 이용하여 간접 멤버 연산자로
    /// 구조체 멤버의 값을 접근하는 방법
    printf("e1 level : %d\n", ep->level);

    /// typedef A B
    typedef
    /// A의 시작
    struct asdf
    {
        int a;
        int b;
        int c;
    }
    /// A의 끝
    ASDF,       /// B               ==> 일반 선언
    *PASDF      /// B   ==> ASDF*   ==> 포인터 선언
    ;
    ASDF asdf1;
    ASDF* pppp = &asdf1;
    PASDF pasdf = &asdf1;

    /// 예제 7-4
    typedef struct STag
    {
        int m;
        char str1[4];
        const char* str2;
    } SType;

    SType s1;
    s1.m = 2017;
    memcpy(s1.str1, "C++", 4);
    s1.str2 = "World";
    /// "World" 문자열은 상수
    const char* ppp99 = "World";
    /// 상수와 전역변수는 data 영역에 만들어 진다.

    SType s2;
    s2 = s1;

    std::cout << "Hello World!\n";
}
