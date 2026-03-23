// 0323.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

void a()
{
    int i = 0;
    i = i + 1;
    /// 자바 스타일
    if (i < 10) {
        i = i * 10;
    }
    /// C 스타일
    if (i < 10)
    {
        i = i * 10;
    }
    /// 이상한 스타일
if (i < 10)
{
i = i * 10;
}

    i = i * 100                             ;
    if (i > 10)
    {
        i = i * 100                         ;
        while (true) i = i + 1              ;
    }
    /// 코드 작성 시 가장 중요한 문제
    /// 나중에 알아볼 수 있느냐? 또는 다른 사람이 알아볼 수 있느냐?
}

/// 매크로 함수 정의 : 앞으로 절대 사용하지 마세요!
/// 전처리기 : 매크로 함수 => 해당 위치를 다음의 코드로 단순 교체
/// 단순 교체로 인한 문제가 발생 : 해당 문제를 찾기가 어렵다.
#define SWAP(a, b)  { a ^= b; b ^= a; a ^= b; }
/// 매크로 함수의 순수 기능 : 변수 값 교환

/// 예제 4-5
int Add(int a, int b)
{
    return a + b;
}

int main()
{
    /// 특정 예약어를 사용한 문장 구조의 특징
    /// 예약어( ... ) => 바로 뒤의 한 문장만 예약어에 소속된 문장
    /// if( 조건식 ) ...;

    int a = 0;
    int b = 1;

    if (0)       /// 무조건 거짓
        SWAP(a, b);
        /*
    a ^= b;     /// if문장의 끝
    /// if 문장 소속이 아닌 아래 2문장은 그냥 실행
    b ^= a;
    a ^= b;
    */

    std::cout << a << " " << b << std::endl;

    /// switch ~ case 문장
    /// 문장 구조
    /// switch( 변수 ) { case 상수:  ... default: break; }
    switch (a)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    default:        /// 최근 형상관리 도구에서는 default가 없으면 오류 처리!
        break;
    }
    /// switch ~ case 문장은 QA/QC 쪽에서 매우 싫어하는 코드!!!
    /// 의도 확인이 어려움!!! 기계어 코드가 증가! => 느려져!

    //나의변수 = 임시변수 = Add(3, 5);
    Add(3, 5);
    Add(3, 5);
    Add(3, 5);
    //int r = Add(3, 5);
    /// 예제 4-5
    switch (Add(1, 2))  /// 결과적으로 Add 함수의 결과 값은 임시 변수가 갖늗다.
    {
    case 0:         /// break 가 없다면 break 만날때까지 계속 실행
    case 1:         /// if( ( tmp == 0 ) || ( tmp == 1 ) || ( tmp == 2 ) ... )
    case 2:
    case 3:         /// {
        a = 3;
        b = 7;
        if (1)
            cout << Add(a, b) << endl;
    case 4:
        a = 30;
        b = 70;
        if (1)
            cout << Add(a, b) << endl;
                    /// }
    }


    /// 문장들을 반복하고자 하는 경우 반드시 필요한 구성요소 3가지
    /// 초기식, 조건식, 제어식이 존재해야만 반복이 가능하다.
    /// 생략이 가능한 구성 요소가 있다 : 3가지 모두 가능
    
    int i = 0;          /// 초기식

    for (; i < 10; )    /// 조건식
    {
        i++;            /// 제어식
    }
    /// 위의 구조를 다른 형식으로 표현하면
    while (i < 10)
    {
        i++;
    }

    /// 여러분이 하는 게임이 있어요.
    /// 그 게임에 어마어마한 이벤트가 열려요~
    /// 그 이벤트에 참여하려면 5가지 조건을 만족해야 해요.
    /// 5가지 조건을 만족하는지 여부를 확인
    int event[5] = { 1, 1, 0, 0, 1 };

    if ((event[0] == 1) &&
        (event[1] == 1) &&
        (event[2] == 1) &&
        (event[3] == 1) &&
        (event[4] == 1))
    {
        /// 5개가 모두 1로 설정되었다면!!!! ==> 이벤트 시작 퀘스트
        cout << " 전설급 이벤트 시작\n";
    }
    else
    {
        cout << " 전설급 이벤트를 시작할 수 없습니다.\n";
        /// 어떤 조건이 부족한지 알려줘야 한다! => 
    }

    int f = 0;
    /// 사용 용도 : 필요 조건을 모두 만족했는지 확인하는 용도
    do
    {
        if (event[0] != 1)
        {
            f = 0;
            cout << "1번 조건 미충족\n";
            break;
        }
        if (event[1] != 1)
        {
            f = 1;
            cout << "2번 조건 미충족\n";
            break;
        }
        if (event[2] != 1)
        {
            f = 2;
            cout << "3번 조건 미충족\n";
            break;
        }
        if (event[3] != 1)
        {
            f = 3;
            cout << "4번 조건 미충족\n";
            break;
        }
        if (event[4] != 1)
        {
            f = 4;
            cout << "5번 조건 미충족\n";
            break;
        }
        /// 이 위치에 도달했다면..... => 조건 5개가 만족되는 상태
        cout << "전설급 이벤트 시작합니다~\n";
        return 0;

    } while (true);
    /// 이 위치 : 조건이 하나라도 만족하지 못한다.

    /// 예제 4-13
    for (int i = 2; i < 10; i++)
    {
        for (int j = 2; j < 10; j++)

            cout << i << " * " << j << " = " << i * j << endl;
        cout << endl;
    }

    /// break : 반복을 더 이상 수행하지 않는다.
    /// continue : 반복을 더 이상 수행하지 않고, 반복의 시작 위치로 이동한다.
    /// ==> 나랑 가까운, 나를 포함하는 반복문으로 이동한다.
    for (int a1 = 0; a1 < 10; a1++)
    {
        for (int a2 = 0; a2 < 10; a2++)
        {
            break;      /// a2의 break;
        }
        break;          /// a1의 break;

        if (1)          /// 제어문이지, 반복문이 아니다!
            break;      /// a1의 break;
    }

    /// * 출력 문제
    for (int j = 0; j < 5; j++)             /// j = 0, 1, 2, 3, 4
                                            /// j = 1, 
    {
        /// 공백 출력용 반복문
        for (int ii = 0; ii < 4 - j; ii++)
            printf(" ");
        /// * 출력용 반복문
        for (int k = 0; k < j + 1; k++)      /// k = 0, 1, 2, 3, 4
            printf("*");
        printf("\n");
    }


    std::cout << "Hello World! " << f << "\n";
}
