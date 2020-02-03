#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define hight 40
#define length 29
void setCursor(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
COORD getCursor()
{
	COORD cur;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	cur.X = curInfo.dwCursorPosition.X;
	cur.Y = curInfo.dwCursorPosition.Y;
	return cur;
}
int map[hight][length] = {
	//  0  2  4  6  8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 50 52 54 56 x��ǥ
	//  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 �迭��ȣ
	9, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 10,//0
	8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8,//1
	8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8,//2
	8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8,//3
	8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8,//4
	8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8,//5
	8, 7, 9, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 10, 7, 8,//6
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//7
	8, 7, 8, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//8
	8, 7, 8, 7, 7, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//9
	8, 7, 8, 7, 7, 0, 7, 0, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 7, 0, 0, 0, 0, 0, 8, 7, 8,//10
	8, 7, 8, 7, 7, 7, 0, 0, 7, 0, 7, 0, 0, 7, 0, 7, 0, 0, 7, 0, 7, 0, 0, 0, 0, 7, 8, 7, 8,//11
	8, 7, 8, 7, 7, 0, 7, 0, 7, 0, 7, 0, 0, 7, 0, 7, 0, 0, 0, 0, 7, 0, 7, 0, 7, 0, 8, 7, 8,//12
	8, 7, 8, 7, 7, 0, 7, 0, 7, 0, 7, 0, 0, 7, 0, 7, 0, 0, 7, 0, 7, 7, 0, 0, 0, 7, 8, 7, 8,//13
	8, 7, 8, 7, 7, 7, 0, 0, 7, 0, 0, 7, 7, 0, 0, 0, 7, 7, 0, 0, 7, 0, 7, 0, 7, 0, 8, 7, 8,//14
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//15
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//16
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//17
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//18
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//19
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//20
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//21
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//22
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//23
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//24
	8, 7, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 11, 7, 8,//25
	8, 7, 9, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 10, 7, 8,//26
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//27
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//28
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//29
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//30
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//31
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//32
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//33
	8, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 7, 8,//34
	8, 7, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 11, 7, 8,//35
	8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8,//36
	8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8,//37
	8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8,//38
	12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 11// 39
};

float score = 0;
float relay = 0; //���� �� ���� Ƚ��
int blocklevel = 3; //3~6���� ������ ������ �� ���� ��ȭ
int level = 1; //���� ��������
int nowSec = 0;
//���� 1,2������ ���� ����. 3������ �� ���� ����. 4���� �������� ���� ����.
int removed[6]; //ȭ�鿡�� ����� �� �ѹ� ����
int removeIndex = 0; //����� �� �迭 �ε���
int pastRemoved[6] = { 7, 7, 7, 7, 7, 7 }; //������ �̹� ������ ��
int pastReIndex = 0;

int Play(int);
void ShowBase(int);
void ShowMap();
void ReNewUpBlocks();
void ShowShootingBlock(int*);
void Shoot(int, int*);
void Check(int, int, int);
void GetDown();
void GetUp();
int RemovedBlock();
void Save();
int Road();
void ShowLastMent();

///////////////////////////////////////////////////////////////////////////////
int main()
{
	int end; //���� �ѹ� ����
	int repeat = 1; //while�� �ݺ���. 0�� �Ǹ� ����.
	int choice; //������ ���� �� ���û��� �޴� ����
	int road; //����� ���� �ҷ������� ����
	system("mode con: cols=90 lines=50");
	srand((unsigned int)time(NULL));

	ShowMap();	//��ֹ� ���� ��
	setCursor(20, 16);
	printf("1. �ҷ�����");	//Ű �Է¹��� �� 49
	setCursor(20, 17);
	printf("2. �� ���� ����");//Ű �Է¹��� �� 50
	while (1)
	{
		setCursor(20, 18);
		printf("What will you do? ");
		choice = getchar();
		if (choice == 49 | choice == 50)
			break;
		else
		{
			setCursor(20, 19);
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է�.");
			setCursor(38, 18);
			printf("  ");
			fflush(stdin);
			continue;
		}
	}

	switch ((int)choice)
	{
	case 49: road = 1; break;
	case 50: road = 0;
		system("cls");
		ShowBase(0); //��, ��ֹ� ��Ÿ��� ��� 
		break;
	}

	fflush(stdin);

	while (repeat)
	{
		end = Play(road); //1=������? 2=���󿣵� 3=���ӿ��� 4=����
		switch (end)
		{
		case 5:
		case 1: //������ ����
			score = score - nowSec*0.5;
			setCursor(8, 31);
			printf("Total Score: %.2f", score);
			while (1)
			{
				setCursor(8, 32);
				printf("Next level?(Y-1/N-2) ");
				choice = getchar();
				if (choice == 49)
				{
					level++;
					if (level != 3)
						blocklevel++;
					road = 0;
					system("cls");
					ShowBase(0);
					fflush(stdin);
					break;
				}
				else if (choice == 50)
				{
					road = 0;
					system("cls");
					ShowBase(0);
					fflush(stdin);
					break;
				}
				else
				{
					setCursor(8, 33);
					printf("�߸��� �Է��Դϴ�. �ٽ� �Է�.");
					setCursor(28, 32);
					printf("  ");
					fflush(stdin);
					continue;
				}
			}
			break;
			/////////////////////////
		case 2:
			score = score - nowSec*0.5;
			setCursor(8, 31);
			printf("Total Score: %.2f", score);
			ShowLastMent();
			setCursor(8, 32);
			printf("Finish!! You're Great!!!");
			repeat--;
			break;
			/////////////////////////
		case 3: //�ٽ� �÷���?
			score = score - nowSec*0.5;
			setCursor(8, 31);
			printf("Total Score: %.2f", score);
			while (1)
			{
				setCursor(8, 32);
				printf("Paly Again?(Y-1/N-2) ");
				choice = getchar();
				if (choice == 49)
				{
					system("cls");
					score = 0;
					road = 0;
					ShowBase(0);
					fflush(stdin);
					break;
				}
				else if (choice == 50)
				{
					road = 0;
					system("cls");
					ShowBase(0);
					fflush(stdin);
					break;
				}
				else
				{
					setCursor(8, 33);
					printf("�߸��� �Է��Դϴ�. �ٽ� �Է�.");
					setCursor(28, 32);
					printf("  ");
					fflush(stdin);
					continue;
				}
			}
			break;
			/////////////////////////
		case 4:
			while (1)
			{
				setCursor(30, 31);
				printf("Save?(Y-1/N-2) ");
				choice = getchar();
				if (choice == 49)
				{
					setCursor(30, 32);
					printf("����Ǿ����ϴ�.");
					Save();
					repeat--;
					break;
				}
				else if (choice == 50)
				{
					fflush(stdin);
					end = 0;
					setCursor(30, 31);
					printf(" S: ����		  ");
					road = 0;
					break;
				}
				else
				{
					setCursor(30, 32);
					printf("�ٽ� �Է�.");
					setCursor(44, 31);
					printf("  ");
					fflush(stdin);
					continue;
				}
			}
			break;
		default: break;
		} //switch ��
	}
	int count = 5;
	int CountTime = GetTickCount();
	setCursor(8, 33);
	printf("5�� �� â�� �����ϴ�. %d", count);
	while (count>0)
	{
		if (GetTickCount() - CountTime >= 1000)
		{
			CountTime = GetTickCount();
			count--;
			setCursor(8, 33);
			printf("5�� �� â�� �����ϴ�. %d", count);
		}
	}
	return 0;
}
void ShowMap()
{
	setCursor(0, 0);
	for (int i = 0; i<hight; i++)
	{
		for (int j = 0; j<length; j++)
		{
			switch (map[i][j])
			{
			case 0: printf("  "); break;
			case 1: printf("��"); break;
			case 2: printf("��"); break;
			case 3: printf("��"); break;
			case 4: printf("��"); break;
			case 5: printf("��"); break;
			case 6: printf("��"); break;
			case 7: printf("��"); break;//1
			case 8: printf("��"); break;//2
			case 9: printf("��"); break;//3
			case 10: printf("��"); break;//4
			case 11: printf("��"); break;//5
			case 12: printf("��"); break;//6
			case 13: printf("��"); break;//7
			}
		}
		printf("\n");
	}
}
void ReNewUpBlocks()
{
	int i, j;
	int lineEnd;
	srand((unsigned int)time(NULL));
	if (level<3)
		lineEnd = 16;
	else if (level >= 3)
		lineEnd = 12;

	for (i = 7; i<lineEnd; i++)
	{
		for (j = 3; j<26; j++)
		{
			map[i][j] = rand() % (blocklevel + 1); //blocklevel=3�̸� 0~3������ ���� ���� ����
		}
	}

	for (i = lineEnd; i<24; i++)
	{
		for (j = 3; j<26; j++)
		{
			map[i][j] = 0;
		}
	}

	////�׽�Ʈ�� ��
	//for(i=7;i<8;i++)
	//{
	//	for(j=3;j<26;j++)
	//	{
	//		map[i][j]=rand()%(blocklevel+1); //blocklevel=3�̸� 0~3������ ���� ���� ����
	//	}
	//}
}
void ShowBase(int road)
{
	if (road == 0)
		ReNewUpBlocks(); //�μ� �� ��������
	ShowMap(); //�����
	setCursor(8, 27);
	printf("Level %d", level);
	setCursor(8, 28);
	printf("Score: %.2f", score);
	setCursor(30, 28);
	printf("��: �����̵�");
	setCursor(30, 29);
	printf("��: �������̵�");
	setCursor(30, 30);
	printf("��: �߻�");
	setCursor(30, 31);
	printf(" S: ����");
	setCursor(58, 11);
}
void ShowShootingBlock(int*num) //��� ��. �� ������ ������� ���ƾ� ������ ���� ����
{
	switch (*num)
	{
	case 0: printf("��"); break;
	case 1: printf("��"); break;
	case 2: printf("��"); break;
	case 3: printf("��"); break;
	case 4: printf("��"); break;
	case 5: printf("��"); break;
	}
}
int Play(int road)
{
	int StartTime = GetTickCount(); //�ð� ī��Ʈ ���۽ð�
	int lineStatTime = GetTickCount(); //�� �������� �ð� ī��Ʈ
	nowSec = 0; //�ð� ī��Ʈ �ʱ�ȭ
	int shotBlock; //��� �� ���� ����
	int x, y, count = 0;
	int endnum = 0; //1-���������� 2-���󿣵� 3-���� 4-����
	removeIndex = 0;
	pastReIndex = 0;
	for (int i = 0; i<6; i++)
	{
		pastRemoved[i] = 7;
		removed[i] = 7;
	}

	if (road)
	{
		road = Road();
		if (!road)
		{
			setCursor(18, 18);
			printf("����� ������ �����ϴ�-");
			setCursor(18, 19);
			printf("���ο� ������ �����մϴ�-");
			Sleep(2000);
			ShowBase(road);
		}
	}

	x = 28; y = 24;
	shotBlock = rand() % blocklevel; //��� �� ��������
	setCursor(x, y);
	ShowShootingBlock(&shotBlock); //Ŀ�� �ڸ��� �� ���

	while (1)
	{
		if (_kbhit() != 0)
		{
			int keynum;
			keynum = _getch();
			if (keynum == 224){
				keynum = _getch();
				if (keynum == 77) //������
				{
					x += 2;
					if (x == 52)
						x -= 2;
					else
					{
						setCursor(x, y);
						ShowShootingBlock(&shotBlock);
						setCursor(x - 2, y);
						printf("  ");
					}
				}
				else if (keynum == 75) //����
				{
					x -= 2;
					if (x == 4)
						x += 2;
					else
					{
						setCursor(x, y);
						ShowShootingBlock(&shotBlock);
						setCursor(x + 2, y);
						printf("  ");
					}
				}
				else if (keynum == 72) //�� -> �߻�
				{
					Shoot(x, &shotBlock);
					setCursor(8, 28);
					printf("Score: %.2f", score);
					x = 28; y = 24;
					shotBlock = rand() % blocklevel;

					//ȭ�鿡 ���ŵ� ���� �ִ��� Ȯ��
					removed[removeIndex] = RemovedBlock();
					if (removed[removeIndex] != 7)
						removeIndex++;
					for (;;)
					{
						if (shotBlock == removed[0])
							shotBlock = rand() % blocklevel;
						else if (shotBlock == removed[1])
							shotBlock = rand() % blocklevel;
						else if (shotBlock == removed[2])
							shotBlock = rand() % blocklevel;
						else if (shotBlock == removed[3])
							shotBlock = rand() % blocklevel;
						else if (shotBlock == removed[4])
							shotBlock = rand() % blocklevel;
						else if (shotBlock == removed[5])
							shotBlock = rand() % blocklevel;
						else break;
						if (removeIndex == blocklevel)
							break;
					}

					//���� ������?
					for (int y = 23; y >= 7; y--)
					{
						for (int x = 3; x <= 25; x++)
						{
							if (map[y][x] == 0)
								count++;
						}
					}
					if (count == 391)
					{
						endnum = 1;
						break;
					}
					else
						count = 0;

					//�Ʒ� ��ҳ�?
					for (int x = 3; x <= 25; x++)
					{
						if (map[23][x] != 0)
						{
							endnum = 3;
							break;
						}
					}

					setCursor(x, y);
					ShowShootingBlock(&shotBlock);
				}
			}
			else if (keynum == 115) //����
				endnum = 4;
			else if (keynum == 101)	//e�Է�->����
				endnum = 2;
			else if (keynum == 113)	//q�Է�->nextlevel
			{
				score += 100;
				endnum = 5;
			}
			else if (keynum == 112)	//p�Է�->�� �ö�
			{
				GetUp();
				setCursor(x, y);
				ShowShootingBlock(&shotBlock);
			}
			else if (keynum == 104)	//h�Է�->�� ������
			{
				GetDown();
				setCursor(x, y);
				ShowShootingBlock(&shotBlock);
			}
			//endnum Ȯ��
			if (endnum != 0)
				break;
		}//Ű������ ���� �� ��
		else
		{
			setCursor(8, 29);
			printf("Time: %d", nowSec);
			if (GetTickCount() - StartTime >= 1000)
			{
				nowSec++;
				StartTime = GetTickCount();
				setCursor(12, 29);
				printf("%d", nowSec);
			}
			else if (GetTickCount() - lineStatTime >= 40000)
			{
				if (level >= 3)
				{
					lineStatTime = GetTickCount();
					GetDown();
				}
			}
		}
	}//while�� ��

	if (level == 5 && count == 391)
		endnum = 2;
	else if (level == 5 && endnum == 5)
		endnum = 2;
	return endnum;
}
void Shoot(int x, int *num) //x�� ��ǥ��
{
	int y;
	setCursor(x, 24);
	printf("  ");

	for (y = 24; y >= 6; y--)
	{
		if (map[y][x / 2] != 0)
			break;
	}
	setCursor(x, y + 1);
	ShowShootingBlock(num);
	map[y + 1][x / 2] = *num + 1;
	Check(x / 2, y + 1, *num + 1);

	system("cls");
	ShowBase(1);
}
void Check(int x, int y, int num)
{
	if (map[y - 1][x] == num)
	{
		map[y][x] = 0;
		map[y - 1][x] = 0;
		Check(x, y - 1, num);
		score += 3;
		relay++;
	}
	if (map[y + 1][x] == num)
	{
		map[y][x] = 0;
		map[y + 1][x] = 0;
		Check(x, y + 1, num);
		score += 3;
		relay++;
	}
	if (map[y][x + 1] == num)
	{
		map[y][x] = 0;
		map[y][x + 1] = 0;
		Check(x + 1, y, num);
		score += 3;
		relay++;
	}
	if (map[y][x - 1] == num)
	{
		map[y][x] = 0;
		map[y][x - 1] = 0;
		Check(x - 1, y, num);
		score += 3;
		relay++;
	}
	if (relay != 0)
		score = score + relay*0.5;
	relay = 0;
	return;
}
void GetDown()
{
	int i, j;
	srand((unsigned int)time(NULL)); //7��->8�� .... 16��->17��
	for (i = 22; i>6; i--)
	{
		for (j = 3; j<26; j++)
			map[i + 1][j] = map[i][j];
	}
	for (j = 3; j<26; j++)
	{
		map[7][j] = rand() % (blocklevel + 1);
		for (;;)
		{
			if (map[7][j] == removed[0] + 1)
				map[7][j] = rand() % (blocklevel + 1);
			else if (map[7][j] == removed[1] + 1)
				map[7][j] = rand() % (blocklevel + 1);
			else if (map[7][j] == removed[2] + 1)
				map[7][j] = rand() % (blocklevel + 1);
			else if (map[7][j] == removed[3] + 1)
				map[7][j] = rand() % (blocklevel + 1);
			else if (map[7][j] == removed[4] + 1)
				map[7][j] = rand() % (blocklevel + 1);
			else if (map[7][j] == removed[5] + 1)
				map[7][j] = rand() % (blocklevel + 1);
			else
				break;
		}
	}

	system("cls");
	ShowBase(1);
}
void GetUp()
{
	int i, j;
	for (i = 8; i<25; i++)
	{
		for (j = 3; j<26; j++)
			map[i - 1][j] = map[i][j];
	}
	ShowBase(1);
	score += 30;
}
int RemovedBlock()
{
	int i, j;
	int count[6] = { 0 };
	for (i = 0; i<24; i++)
	{
		for (j = 0; j<length; j++)
		{
			switch (map[i][j])
			{
			case 1: count[0]++; break;//��
			case 2: count[1]++; break;//��
			case 3: count[2]++; break;//��
			case 4: count[3]++; break;//��
			case 5: count[4]++; break;//��
			case 6: count[5]++; break;//��
			}
		}
	}
	switch (level)
	{
	case 1: count[3]++; count[4]++; count[5]++; break;
	case 2:
	case 3: count[4]++; count[5]++; break;
	case 4: count[5]++; break;
	case 5: break;
	}
	for (i = 0; i<6; i++)
	{
		if (count[i] == 0)
		{
			int thereis = 0;
			for (int a = 0; a <= pastReIndex; a++)
			{
				if (i == pastRemoved[a])
				{
					thereis = 1;
					break;
				}
			}
			if (thereis)
				continue;
			else
				break;
		}
		else
			continue;
	}
	if (i == 6)
		return 7;
	else
	{
		pastRemoved[pastReIndex] = i;
		pastReIndex++;
		return i; //�ʿ� ǥ�õǴ� ���ں��� 1 ����
	}
}
void Save()
{
	FILE *fp = fopen("save.txt", "w");
	for (int y = 0; y <= hight; y++)
	{
		for (int x = 0; x <= length; x++)
		{
			fprintf(fp, "%d ", map[y][x]);
		}
		fprintf(fp, "\n");
	}
	fprintf(fp, "%d %d %f %d", level, blocklevel, score, nowSec);
	fprintf(fp, "\n");
	for (int i = 0; i<6; i++)
	{
		fprintf(fp, "%d ", removed[i]);
	}
	fprintf(fp, "\n");
	for (int i = 0; i<6; i++)
	{
		fprintf(fp, "%d ", pastRemoved[i]);
	}
	fprintf(fp, "\n");
	fprintf(fp, "%d %d", removeIndex, pastReIndex);
	fclose(fp);
}
int Road()
{
	FILE *fp = fopen("save.txt", "r");
	if (fp == NULL)
		return 0;

	for (int y = 0; y <= hight; y++)
	{
		for (int x = 0; x <= length; x++)
		{
			fscanf(fp, "%d", &map[y][x]);
		}
	}
	fscanf(fp, "%d %d %f %d", &level, &blocklevel, &score, &nowSec);
	for (int i = 0; i<6; i++)
	{
		fscanf(fp, "%d ", &removed[i]);
	}
	for (int i = 0; i<6; i++)
	{
		fscanf(fp, "%d ", &pastRemoved[i]);
	}
	fscanf(fp, "%d %d", &removeIndex, &pastReIndex);
	fclose(fp);
	ShowBase(1);
	return 1;
}
void ShowLastMent()
{
	setCursor(10, 15);
	printf("           �����մϴ�!!");
	Sleep(2000);
	setCursor(10, 15);
	printf("     ��� ������ ����ϼ̱���!!");
	Sleep(2000);
	setCursor(10, 15);
	printf(" �̷� ����� ������ ������ �س��ôٴ�");
	Sleep(2000);
	setCursor(10, 15);
	printf("  ����� �����̵� �س� ����̳׿�!   ");
	Sleep(2000);
	setCursor(10, 15);
	printf("         ������ �ϼ��ϼ�����      ");
	Sleep(2000);
	setCursor(10, 15);
	printf("      �Ѱ��� ���� �帮�ڽ��ϴ�.");
	Sleep(2000);
	setCursor(10, 15);
	printf("     �� ���ӿ��� ġƮŰ�� �ִ�ϴ�.");
	Sleep(2000);
	setCursor(10, 15);
	printf("       �ٳ��� ġƮŰ(h)�� �ְ�	   ");
	Sleep(2000);
	setCursor(10, 15);
	printf("       �ٿø� ġƮŰ��(p) �ְ�");
	Sleep(2000);
	setCursor(10, 15);
	printf("   ������ �ø��� ġƮŰ(q)�� �ְ�");
	Sleep(2000);
	setCursor(10, 15);
	printf("�ѹ濡 �������� ���� ġƮŰ(e)�� �ֽ��ϴ�.");
	Sleep(2000);
	setCursor(10, 15);
	printf("    �ν� ���� Blocks�� ��ܺ�����^^      ");
	Sleep(2000);
}