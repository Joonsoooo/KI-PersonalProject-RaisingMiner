#include "gotoxy.h"

void gotoxy(int x, int y)
{

    //x, y ��ǥ ����
    COORD pos = { x,y }; // windows.h ������Ͽ� ���ǵǾ� �ִ� ����ü 

    //Ŀ�� �̵�
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

    //STD_OUTPUT_HANDLE = ǥ�� ��� ��ġ �ڵ� , ���⼭ �ڵ��� �͹̳� â 
    //GetStdHandle = �ڵ��� ������ 
    //SetConsoleCursorPosition = pos�� ��ǥ ���� ��� 

}

// gotoxy �Լ��� ǥ�� ��� ��ġ�� �ڵ�(�ܼ� â = �͹̳� â)�� ������ pos�� �ش��ϴ� ��ǥ�� Ŀ���� �̵���Ű�� ����
