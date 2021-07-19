#include <stdio.h>
#include <math.h>
#include <random>

	/*
	��P�O��
	�Q�_�Ԃ̋��������߂�֐����쐬���Ă��������B
	*/
float CalcPointDistance(float x1, float y1, float x2, float y2)
{
	float distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	printf("%f\n", distance);
	return distance;
}

	/*
	��P�P��
	�J�[�h�\���̂��쐬���Ă��������B
	���̃J�[�h�̓g�����v�̃J�[�h�̂��Ƃł��B
	���Ƃ��āA�Ȃ�̃J�[�h�Ȃ̂��������Ă��Ă��������B
	�X�y�[�h��7�ł���A�n�[�g��13�ł���ȂǁB
	���̍\���̂ɂ͌��݂̎����̏���ݒ肷�鏈���ƁA
	���݂̎����̏����J�����鏈��������Ă��������B
	*/

	/*
	�g�����v�̎R�D�̍\���̂��쐬���Ă��������B
	���̍ۃJ�[�h�ɂ͐�قǍ�����\���̂��g�p���Ă��������B
	�ȉ��̏����𖞂����Ă������ƁB
	�g�����v�̖�����53��(1 �` 13 * 4 + �W���[�J�[1)
	Card card[53];
	*/

	/*
	�V���b�t���@�\����������B
	card[53]�Ƀ����_���ɃJ�[�h����t�^���Ă��������B
	card[0]���N���u��6�Acard[1]���n�[�g��5�Ƃ������悤�ɁB
	���̍ۓ����J�[�h�͑��݂��Ȃ��悤�ɂ��Ă��������B
	*/
struct Card
{
private:
	int cardNum;
public:
	void SetCardNum(int num) { cardNum = num; }
	int GetCardNum() { return cardNum; }
};

struct Deck
{
private:
	Card card[53];
public:
	void InitDeck()
	{
		for (int i = 0; i < 53; i++)
		{
			card[i].SetCardNum(i + 1);
		}
	}
	void Shuffle()
	{
		std::random_device std;
		for (int i = 0; i < 53; i++)
		{
			int j = std() % 53;
			Card store = card[i];
			card[i] = card[j];
			card[j] = store;
		}
	}
	void DrawCard()
	{
		for (int i = 0; i < 53; i++)
		{
			if (card[i].GetCardNum() < 14)
			{
				printf("���̃J�[�h�̓n�[�g%d�ł��B\n", card[i].GetCardNum());
			}
			else if (card[i].GetCardNum() > 13 && card[i].GetCardNum() < 27)
			{
				printf("���̃J�[�h�̓X�y�[�h%d�ł��B\n", card[i].GetCardNum() - 13);
			}
			else if (card[i].GetCardNum() > 26 && card[i].GetCardNum() < 40)
			{
				printf("���̃J�[�h�̓_�C��%d�ł��B\n", card[i].GetCardNum() - 26);
			}
			else if (card[i].GetCardNum() > 39 && card[i].GetCardNum() < 53)
			{
				printf("���̃J�[�h�̓N���[�o�[%d�ł��B\n", card[i].GetCardNum() - 39);
			}
			else if (card[i].GetCardNum() == 53)
			{
				printf("���̃J�[�h�̓W���[�J�[�ł��B\n");
			}
		}
	}
};

int main()
{
	/*
	��P��
	�ȉ��̌v�Z�ɓ�����B
	1011 + 0101
	110100 + 11011
	1011 + 110011
	*/
	//printf("%d\n", 0b1011 + 0b0101);
	//printf("%d\n", 0b110100 + 0b11011);
	//printf("%d\n", 0b1011 + 0b110011);
	//�����F
	//1011 + 0101 = 16
	//110100 + 11011 = 79
	//1011 + 110011 = 62

	/*
	��Q��
	�ȉ��̌v�Z�ɓ�����B
	FF + FF
	ed + 10
	563 + cd
	*/
	//printf("%d\n", 0xFF + 0xFF);
	//printf("%d\n", 0xed + 0x10);
	//printf("%d\n", 0x563 + 0xcd);
	//�����F
	//FF + FF = 510
	//ed + 10 = 253
	//563 + cd = 1584

	/*
	��R��
	char�Aint�Afloat�Adouble�̃T�C�Y�͂��ꂼ�ꂢ����������B
	*/
	//�����F
	//char�̃T�C�Y��1�o�C�g�B
	//int�̃T�C�Y��4�o�C�g�B
	//float�̃T�C�Y��4�o�C�g�B
	//double�̃T�C�Y��8�o�C�g�B

	/*
	��S��
	int judge = true;
	if (judge)
	{
		�@
	}
	else
	{
		�A
	}
	�@�ƇA�ǂ��炪��������邩������B
	*/
	//�����F
	//�@�����������B

	/*
	��T��
	for (int i = 0; i < 100; i = i + 3)
	{
		�@
	}
	�@�̏�����������s����邩������B
	*/
	//�����F
	//�@�̏�����34����s�����B

	/*
	��U��
	int i = 0;
	while (i < 100)
	{
		i = i + 5;
		�@
	}
	�@�̏����͉�����s����邩������B
	*/
	//�����F
	//�@�̏�����20����s�����B

	/*
	��V��
	int array[4][5];
	��L�z��̃T�C�Y�͂�����������B
	*/
	//�����F
	//80�o�C�g�ł��B

	/*
	��W��
	int array[5][20]
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < �@; ++j)
		{
			array[i][j] = i * �@ + j;
		}
	}
	�@�ɂ͉��Ƃ������������邩������B
	*/
	//�����F
	//20

	/*
	��X��
	�@ testFunc(int a)
	{
		return;
	}
	�@�ɂ�int, float, void�̂ǂꂪ��������������B
	*/
	//�����F
	//int

	//��P�O�⌟�ؗp
	//CalcPointDistance(10, 10, 5, 5);

	//��P�P�⌟�ؗp
	Deck deck;
	deck.InitDeck();
	deck.Shuffle();
	deck.DrawCard();
}