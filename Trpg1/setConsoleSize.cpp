#include "setConsoleSize.h"

void SetConsoleSize(int width, int height) {
    // �ܼ� �ڵ� ��������
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // ���� ũ�� ����
    COORD bufferSize = { (SHORT)width, (SHORT)height };
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    // â ũ�� ����
    SMALL_RECT windowSize = { 0, 0, (SHORT)(width - 1), (SHORT)(height - 1) };
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

