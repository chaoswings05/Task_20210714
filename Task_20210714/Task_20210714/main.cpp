#include <stdio.h>
#include <math.h>
#include <random>

	/*
	第１０問
	２点間の距離を求める関数を作成してください。
	*/
float CalcPointDistance(float x1, float y1, float x2, float y2)
{
	float distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	printf("%f\n", distance);
	return distance;
}

	/*
	第１１問
	カード構造体を作成してください。
	このカードはトランプのカードのことです。
	情報として、なんのカードなのかを持っていてください。
	スペードの7である、ハートの13であるなど。
	この構造体には現在の自分の情報を設定する処理と、
	現在の自分の情報を開示する処理を作ってください。
	*/

	/*
	トランプの山札の構造体を作成してください。
	その際カードには先ほど作った構造体を使用してください。
	以下の条件を満たしておくこと。
	トランプの枚数は53枚(1 ～ 13 * 4 + ジョーカー1)
	Card card[53];
	*/

	/*
	シャッフル機能を実装する。
	card[53]にランダムにカード情報を付与してください。
	card[0]がクラブの6、card[1]がハートの5といったように。
	その際同じカードは存在しないようにしてください。
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
				printf("このカードはハート%dです。\n", card[i].GetCardNum());
			}
			else if (card[i].GetCardNum() > 13 && card[i].GetCardNum() < 27)
			{
				printf("このカードはスペード%dです。\n", card[i].GetCardNum() - 13);
			}
			else if (card[i].GetCardNum() > 26 && card[i].GetCardNum() < 40)
			{
				printf("このカードはダイヤ%dです。\n", card[i].GetCardNum() - 26);
			}
			else if (card[i].GetCardNum() > 39 && card[i].GetCardNum() < 53)
			{
				printf("このカードはクローバー%dです。\n", card[i].GetCardNum() - 39);
			}
			else if (card[i].GetCardNum() == 53)
			{
				printf("このカードはジョーカーです。\n");
			}
		}
	}
};

int main()
{
	/*
	第１問
	以下の計算に答えよ。
	1011 + 0101
	110100 + 11011
	1011 + 110011
	*/
	//printf("%d\n", 0b1011 + 0b0101);
	//printf("%d\n", 0b110100 + 0b11011);
	//printf("%d\n", 0b1011 + 0b110011);
	//答え：
	//1011 + 0101 = 16
	//110100 + 11011 = 79
	//1011 + 110011 = 62

	/*
	第２問
	以下の計算に答えよ。
	FF + FF
	ed + 10
	563 + cd
	*/
	//printf("%d\n", 0xFF + 0xFF);
	//printf("%d\n", 0xed + 0x10);
	//printf("%d\n", 0x563 + 0xcd);
	//答え：
	//FF + FF = 510
	//ed + 10 = 253
	//563 + cd = 1584

	/*
	第３問
	char、int、float、doubleのサイズはそれぞれいくつか答えよ。
	*/
	//答え：
	//charのサイズは1バイト。
	//intのサイズは4バイト。
	//floatのサイズは4バイト。
	//doubleのサイズは8バイト。

	/*
	第４問
	int judge = true;
	if (judge)
	{
		①
	}
	else
	{
		②
	}
	①と②どちらが処理されるか答えよ。
	*/
	//答え：
	//①が処理される。

	/*
	第５問
	for (int i = 0; i < 100; i = i + 3)
	{
		①
	}
	①の処理が何回実行されるか答えよ。
	*/
	//答え：
	//①の処理は34回実行される。

	/*
	第６問
	int i = 0;
	while (i < 100)
	{
		i = i + 5;
		①
	}
	①の処理は何回実行されるか答えよ。
	*/
	//答え：
	//①の処理は20回実行される。

	/*
	第７問
	int array[4][5];
	上記配列のサイズはいくつか答えよ。
	*/
	//答え：
	//80バイトです。

	/*
	第８問
	int array[5][20]
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < ①; ++j)
		{
			array[i][j] = i * ① + j;
		}
	}
	①には何という数字が入るか答えよ。
	*/
	//答え：
	//20

	/*
	第９問
	① testFunc(int a)
	{
		return;
	}
	①にはint, float, voidのどれが正しいか答えよ。
	*/
	//答え：
	//int

	//第１０問検証用
	//CalcPointDistance(10, 10, 5, 5);

	//第１１問検証用
	Deck deck;
	deck.InitDeck();
	deck.Shuffle();
	deck.DrawCard();
}