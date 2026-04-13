// 0413_report.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include "add.h"
#include "minus.h"


int main()
{
    int x = addFunc(3, 5);
    int y = minusFunc(15, 7);
    printf("%d %d\n", x, y);
    std::cout << "Hello World!\n";
}
