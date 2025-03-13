#include "gotoxy.h"

void gotoxy(int x, int y)
{

    //x, y 좌표 설정
    COORD pos = { x,y }; // windows.h 헤더파일에 정의되어 있는 구조체 

    //커서 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

    //STD_OUTPUT_HANDLE = 표준 출력 장치 핸들 , 여기서 핸들은 터미널 창 
    //GetStdHandle = 핸들을 가져옴 
    //SetConsoleCursorPosition = pos의 좌표 값에 출력 

}

// gotoxy 함수는 표준 출력 장치의 핸들(콘솔 창 = 터미널 창)을 가져와 pos에 해당하는 좌표로 커서를 이동시키는 역할
