// 2023.4.8,1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

// 열거문 enum
// enum 은 여러가지 상태 값을 문자로 표현 할 수 있다 --> 가독성이 증가
// 값을 순차적으로 증가시키며 관리 한다. (값을 임의로 넣는 경우 넣은 값부터 뒤로 갈수록 1씩 증가
// 중간부터 설정도 가능
// enum 문으로 선언된 변수에 설정된 값에 대한 제한을 걸 수 있다.
enum E_NUMBERS{EN_ZERO, EN_ONE, EN_TWO, EN_THREE, EN_MAX};

// 캐릭터의 상태값
// 보통 선언, 인수 모두 대문자로 씀
enum E_STATE{E_IDLE = 0, E_MOVE_LEFT, E_MOVE_RIGHT, E_MOVE_UP, E_MOVE_DOWN, E_FIGHT, E_STATE_NMAX};
// 전투중 캐릭터의 상대값
enum E_FIGHTING{E_RUNAWAY, E_ATTACK, E_MAGIC, E_DEFENCE};
// 몬스터 종류
enum E_MONTYPE{E_ORC, E_ELF, E_TROLL, E_HUMAN, E_MON_MAX};

int main()
{
    /*
    int nCondition = rand() % 5;

    switch (nCondition)
    {
    case 0:
        cout << "0이 나왔다." << endl;
        break;
    case 1:
        cout << "1이 나왔다." << endl;
        break;
    case 2:
        cout << "2이 나왔다." << endl;
        break;
    default:
        cout << "3 또는 4가 나왔다." << endl;
        break;
    }
    */
    /*
    E_STATE eState = E_IDLE;

    switch (eState) // switch 문 자동완성 후 eState 타이핑 후 자동완성 시키면 밑에 조건문도 자동완성됨
    {
    case E_IDLE:
        break;
    case E_MOVE_LEFT:
        break;
    case E_MOVE_RIGHT:
        break;
    case E_MOVE_UP:
        break;
    case E_MOVE_DOWN:
        break;
    case E_FIGHT:
        break;
    case E_STATE_NMAX:
        break;
    default:
        break;
    }
    */
    srand(time(NULL));
    rand();

    E_STATE eState = E_IDLE;        //  캐릭터의 현재 상태
    int nHp = 100;                  //  캐릭터의 체력
    int nCoordX = 0, nCoordY = 0;   //  캐릭터의 위치
    int nSelect;                    //  행동을 입력받기 위한 변수

    int nMonHp[E_MON_MAX];
    int nMonX[E_MON_MAX];
    int nMonY[E_MON_MAX];

    for (int i = 0; i < E_MON_MAX; i++)
    {
        nMonHp[i] = 100;
        nMonX[i] = 5 + i * 5;
        nMonY[i] = 0;
    }

    while (true)
    {
        system("cls");

        cout << "현재 위치 : X(" << nCoordX << ") Y(" << nCoordY << ")" << endl;

        if (eState == E_IDLE)
            cout << "입력하시오. (0. 대기 1. 왼쪽 2. 오른쪽 3. 위쪽 4. 아래쪽) : ";
        else if (eState == E_FIGHT)
            cout << "입력하시오. (0. 도망 1. 공격 2. 마법공격 3. 방어) : ";

        cin >> nSelect;

        cout << ".";
        Sleep(500); // 0.5초 delay
        cout << ".";
        Sleep(500); // 0.5초 delay
        cout << ".";
        Sleep(500); // 0.5초 delay

        if (eState == E_IDLE)
        {
            switch (nSelect)
            {
            case E_IDLE:
                {
                cout << "한턴 휴식" << endl;
                }
                break;
            case E_MOVE_LEFT:
                {
                cout << "왼쪽으로 한칸 이동" << endl;
                nCoordX--;
                }
                break;
            case E_MOVE_RIGHT:
                {
                cout << "오른쪽으로 한칸 이동" << endl;
                nCoordX++;
                }
                break;
            case E_MOVE_UP:
                {
                cout << "위쪽으로 한칸 이동" << endl;
                nCoordY++;
                }
                break;
            case E_MOVE_DOWN:
                {
                cout << "아래쪽으로 한칸 이동" << endl;
                nCoordY--;
                }
                break;
            default:
                {
                cout << "잘못된 입력! 강제로 한턴 휴식" << endl;
                }
                break;
            }

            for (int i = 0; i < E_MON_MAX; i++)
            {
                if (nCoordX == nMonX[i] && nCoordY == nMonY[i])
                {
                    switch (i)
                    {
                    case E_ORC:
                        cout << "오크를 만났다!!" << endl;
                        break;
                    case E_ELF:
                        cout << "엘프를 만났다!!" << endl;
                        break;
                    case E_TROLL:
                        cout << "트롤을 만났다!!" << endl;
                        break;
                    case E_HUMAN:
                        cout << "도적을 만났다!!" << endl;
                        break;
                    }

                    eState = E_FIGHT;
                }
            }
        }

        else if (eState == E_FIGHT)
        {
            switch (nSelect)
            {
            case E_RUNAWAY:
                {
                int nRand = rand() % 2;
                if (nRand == 0)
                    {
                    cout << "도주 성공!" << endl;
                    nCoordX += 1;
                    eState = E_IDLE; 
                    }
                else
                    {
                    cout << "도주 실패!" << endl;
                    }
                }
                break;
            case E_ATTACK:
                break;
            case E_MAGIC:
                break;
            case E_DEFENCE:
                break;
            default:
                cout << "잘못된 입력! 강제로 한턴 휴식" << endl;
                break;
            }
        }

        Sleep(2000);
    }

    system("pause");

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
