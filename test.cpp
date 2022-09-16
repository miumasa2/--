#include "DxLib.h"
#include <math.h>

#define SHOT 100
#define MAX_SPARK 800
#define MARGIN 10



// WinMain関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	static int g_CameraPosX = 640 / 2.0f;
	static int g_CameraPosY = 480 / 2.0f;
	int Bw, Bh, Sw, Sh;
	int cw, ch;
	int BallX, BallY, BallGraph;
	int SikakuX, SikakuY, SikakuMuki, SikakuGraph;
	int SikakuX2, SikakuY2, SikakuGraph2;
	int SikakuX3, SikakuY3, SikakuGraph3;
	int SikakuX4, SikakuY4, SikakuGraph4;
	int SikakuX5, SikakuY5, SikakuMuki5,SikakuGraph5;
	int SikakuX6, SikakuY6, SikakuGraph6;
	int SikakuX7, SikakuY7, SikakuGraph7;
	int SikakuX8, SikakuY8, SikakuGraph8;
	int SikakuX9, SikakuY9, SikakuGraph9;
	int SikakuX10, SikakuY10, SikakuGraph10;
	int SikakuX11, SikakuY11, SikakuGraph11;
	int SikakuX12, SikakuY12, SikakuGraph12;
	int SikakuX13, SikakuY13, SikakuGraph13;
	int SikakuX14, SikakuY14, SikakuGraph14;
	int SikakuX15, SikakuY15, SikakuGraph15;
	int SikakuX16, SikakuY16, SikakuGraph16;
	int SikakuX17, SikakuY17, SikakuGraph17;
	int SikakuX18, SikakuY18, SikakuGraph18;
	int SikakuX19, SikakuY19, SikakuMuki19,SikakuGraph19;
	int SikakuX20, SikakuY20, SikakuGraph20;
	int SikakuX21, SikakuY21, SikakuGraph21;
	int SikakuX22, SikakuY22, SikakuGraph22;
	int SikakuX23, SikakuY23, SikakuGraph23;
	int SikakuX24, SikakuY24, SikakuGraph24;
	int SikakuX25, SikakuY25, SikakuMuki25,SikakuGraph25;
	int SikakuX26, SikakuY26, SikakuGraph26;
	int SikakuX27, SikakuY27, SikakuGraph27;
	int SikakuX28, SikakuY28, SikakuGraph28;
	int SikakuX29, SikakuY29, SikakuGraph29;
	int BossX, BossY, BossMuki,BossGraph,BossDamageGraph;
	int BossDamageFlag, BossDamageCounter, SikakuDamageGraph;
	int SikakuDamageFlag2, SikakuDamageCounter2, SikakuDamageGraph2;
	int ShotX[SHOT], ShotY[SHOT], ShotFlag[SHOT], ShotGraph;
	int SikakuW, SikakuH, ShotW, ShotH;
	int ShotBFlag;
	int i;
	int ETamaCounter = 0;
	double ETamaX, ETamaY;
	int ETamaW, ETamaH, ETamaGraph;
	double ETamaSx, ETamaSy;
	int ETamaFlag = 0;
	int gh, BackX, BackY;
	int x1, x2, y1, y2;
	int bx1;
	int Random[6];
	
	SRand(123456);
	Random[0] = GetRand(10);
	Random[1] = GetRand(10);
	Random[2] = GetRand(10);
	Random[3] = GetRand(10);
	Random[4] = GetRand(10);
	Random[5] = GetRand(10);



	// 画面モードの設定
	SetGraphMode(1000, 560, 16);

	x1 = 0;
	x2 = 640;
	y1 = 350;
	y2 = 200;
	bx1 = 0;
	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;

	// グラフィックの描画先を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	// ボール君のグラフィックをメモリにロード＆表示座標をセット
	BallGraph = LoadGraph("Ball.png");
	BallX = 0; BallY = 200;

	// 四角君のグラフィックをメモリにロード＆表示座標をセット
	BossGraph = LoadGraph("Boss3.png");
	BossX = BallX + 1500; BossY = 220;

	SikakuGraph2 = LoadGraph("Sikaku.png");
	SikakuX2 = 1500; SikakuY2 = 100;

	SikakuGraph3 = LoadGraph("Sikaku.png");
	SikakuX3 = 2200; SikakuY3 = 300;

	SikakuGraph4 = LoadGraph("Sikaku.png");
	SikakuX4 = 2700; SikakuY4 = 250;

	SikakuGraph5 = LoadGraph("Sikaku.png");
	SikakuX5 = 3300; SikakuY5 = 150;

	SikakuGraph6 = LoadGraph("Sikaku.png");
	SikakuX6 = -2500; SikakuY6 = 400;

	SikakuGraph7 = LoadGraph("Sikaku.png");
	SikakuX7 = 4600; SikakuY7 = 200;

	SikakuGraph8 = LoadGraph("Sikaku.png");
	SikakuX8 = 5500; SikakuY8 = 150;

	SikakuGraph9 = LoadGraph("Sikaku.png");
	SikakuX9 = 6400; SikakuY9 = 225;

	SikakuGraph10 = LoadGraph("Sikaku.png");
	SikakuX10 = 7300; SikakuY10 = 250;

	SikakuGraph11 = LoadGraph("Sikaku.png");
	SikakuX11 = 8200; SikakuY11 = 275;

	SikakuGraph12 = LoadGraph("Sikaku.png");
	SikakuX12 = 9100; SikakuY12 = 250;

	SikakuGraph13 = LoadGraph("Sikaku.png");
	SikakuX13 = 10000; SikakuY13 = 350;

	SikakuGraph14 = LoadGraph("Sikaku.png");
	SikakuX14 = 10800; SikakuY14 = 210;

	SikakuGraph15 = LoadGraph("Sikaku.png");
	SikakuX15 = 11600; SikakuY15 = 180;

	SikakuGraph16 = LoadGraph("Sikaku.png");
	SikakuX16 = 12400; SikakuY16 = 230;

	SikakuGraph17 = LoadGraph("Sikaku.png");
	SikakuX17 = 13200; SikakuY17 = 280;

	SikakuGraph18 = LoadGraph("Sikaku.png");
	SikakuX18 = 14000; SikakuY18 = 290;

	SikakuGraph19 = LoadGraph("Sikaku.png");
	SikakuX19 = 9000; SikakuY19 = 320;

	SikakuGraph20 = LoadGraph("Sikaku.png");
	SikakuX20 = 10000; SikakuY20 = 240;

	SikakuGraph21 = LoadGraph("Sikaku.png");
	SikakuX21 = 10600; SikakuY21 = 180;

	SikakuGraph22 = LoadGraph("Sikaku.png");
	SikakuX22 = 11200; SikakuY22 = 190;

	SikakuGraph23 = LoadGraph("Sikaku.png");
	SikakuX23 = 11800; SikakuY23 = 240;

	SikakuGraph24 = LoadGraph("Sikaku.png");
	SikakuX24 = 12400; SikakuY24 = 270;

	SikakuGraph25 = LoadGraph("Sikaku.png");
	SikakuX25 = 13000; SikakuY25 = 300;

	SikakuGraph26 = LoadGraph("Sikaku.png");
	SikakuX26 = 13600; SikakuY26 = 320;

	SikakuGraph27 = LoadGraph("Sikaku.png");
	SikakuX27 = 14200; SikakuY27 = 200;

	SikakuGraph28 = LoadGraph("Sikaku.png");
	SikakuX28 = 14800; SikakuY28 = 360;

	SikakuGraph29 = LoadGraph("Sikaku.png");
	SikakuX29 = 15400; SikakuY29 = 350;

	SikakuGraph = LoadGraph("Sikaku.png");
	SikakuX = 600; SikakuY = 200;

	// 四角君のダメージ時のグラフィックをメモリにロード
	BossDamageGraph = LoadGraph("SikakuDam.png");

	// ボスが顔を歪めているかどうかの変数に『歪めていない』を表す０を代入
	BossDamageFlag = 0;

	//ボスがどれだけボール君の攻撃を受けたのかをカウントする変数を初期化
	BossDamageCounter = 0;

	// 敵の弾のグラフィックをロード
	ETamaGraph = LoadGraph("EShot.png");

	// 敵の弾のグラフィックのサイズを得る
	GetGraphSize(ETamaGraph, &ETamaW, &ETamaH);

	//背景画像のグラフィックをロード
	gh = LoadGraph("guradhiusu.png");

	// 敵の弾が飛んでいるかどうかを保持する変数に『飛んでいない』を表す０を代入
	ETamaFlag = 0;

	// 敵が弾を撃つタイミングを取るための計測用変数に０を代入
	ETamaCounter = 0;

	// 弾のグラフィックをメモリにロード
	ShotGraph = LoadGraph("Shot.png");

	//ステージのBGMをメモリにロード
	int bgm1;
	bgm1 = LoadSoundMem("loop_47.wav");

	//敵に球を当てた時の効果音をメモリにロード
	int se1;
	se1 = LoadSoundMem("baku003.wav");

	//自分が弾を打った時の効果音をメモリにロード
	int se2;
	se2 = LoadSoundMem("shot.wav");

	//ボス撃破時の効果音をメモリにロード
	int se3;
	se3 = LoadSoundMem("gameclear.wav");

	// 弾が画面上に存在しているか保持する変数に『存在していない』を意味する０を代入しておく
	for (i = 0; i < SHOT; i++)
	{
		ShotFlag[i] = 0;
	}

	// ショットボタンが前のフレームで押されたかどうかを保存する変数に０(押されいない)を代入
	ShotBFlag = 0;

	// 四角君の移動方向をセット
	SikakuMuki5 = 1;
	SikakuMuki19 = 1;
	SikakuMuki25 = 1;
	BossMuki = 1;

	// 弾のグラフィックのサイズをえる
	GetGraphSize(ShotGraph, &ShotW, &ShotH);

	// 四角君のグラフィックのサイズを得る
	GetGraphSize(SikakuGraph, &SikakuW, &SikakuH);

	// ボール君と弾の画像のサイズを得る
	GetGraphSize(BallGraph, &Bw, &Bh);
	GetGraphSize(ShotGraph, &Sw, &Sh);
	GetGraphSize(gh, &BackX, &BackY);


	PlaySoundMem(bgm1, DX_PLAYTYPE_LOOP);

	// 移動ルーチン
	while (1)
	{
		// 画面を初期化(真っ黒にする)
		ClearDrawScreen();


		DrawExtendGraph(bx1, 0, BackX, 570, gh, TRUE);

		if (BackX < 3000)
		{
			BackX = 2999;
			bx1 = -11850;
			if (BossMuki == 1)BossY += 7;
			else BossY -= 7;
		}
		else if (BackX < 3150)
		{
			bx1 -= 1;
			BackX -= 1;
			BossX -= 5;
		}
		else if (BackX < 3400)
		{
			bx1 -= 2;
			BackX -= 2;
		}
		else if (BackX < 3900)
		{
			bx1 -= 4;
			BackX -= 4;
		}
		else if (BackX < 5400)
		{
			bx1 -= 7;
			BackX -= 7;
		}
		else if (BackX >= 5400)
		{
			bx1 -= 10;
			BackX -= 10;
		}


		// ボール君の操作ルーチン
		{
			// ↑キーを押していたらボール君を上に移動させる
			if (CheckHitKey(KEY_INPUT_UP) == 1) BallY -= 3;
			if (BallY != 0)y1 += 10;
			if (BallY != 560)y2 -= 10;


			// ↓キーを押していたらボール君を下に移動させる
			if (CheckHitKey(KEY_INPUT_DOWN) == 1) BallY += 3;
			if (BallY != 560)y1 -= 10;
			if (BallY != 0)y2 += 10;

			// ←キーを押していたらボール君を左に移動させる
			if (CheckHitKey(KEY_INPUT_LEFT) == 1) BallX -= 3;
			if (BallX != 0)x1 += 10;
			if (BallX != 1000)x2 -= 10;

			// →キーを押していたらボール君を右に移動させる
			if (CheckHitKey(KEY_INPUT_RIGHT) == 1) BallX += 3;
			if (BallX != 1000)x1 -= 10;
			if (BallX != 0)x2 += 10;

			// スペースキーを押した場合は処理を分岐
			if (CheckHitKey(KEY_INPUT_SPACE))
			{
				// 前フレームでショットボタンを押したかが保存されている変数が０だったら弾を発射
				if (ShotBFlag == 0)
				{
					// 画面上にでていない弾があるか、弾の数だけ繰り返して調べる
					for (i = 0; i < SHOT; i++)
					{
						// 弾iが画面上にでていない場合はその弾を画面に出す
						if (ShotFlag[i] == 0)
						{
							int Bw, Bh, Sw, Sh;

							// ボール君と弾の画像のサイズを得る
							GetGraphSize(BallGraph, &Bw, &Bh);
							GetGraphSize(ShotGraph, &Sw, &Sh);

							// 弾iの位置をセット、位置はボール君の中心にする
							ShotX[i] = (Bw - Sw) / 2 + BallX;
							ShotY[i] = (Bh - Sh) / 2 + BallY;

							// 弾iは現時点を持って存在するので、存在状態を保持する変数に１を代入する
							ShotFlag[i] = 1;

							//効果を再生
							PlaySoundMem(se2, DX_PLAYTYPE_BACK);

							// 一つ弾を出したので弾を出すループから抜けます
							break;
						}
					}
				}

				// 前フレームでショットボタンを押されていたかを保存する変数に１(おされていた)を代入
				ShotBFlag = 1;
			}
			else
			{
				// ショットボタンが押されていなかった場合は
				// 前フレームでショットボタンが押されていたかを保存する変数に０(おされていない)を代入
				ShotBFlag = 0;
			}


			// ボール君が画面左端からはみ出そうになっていたら画面内の座標に戻してあげる
			if (BallX < 0) BallX = 0;

			// ボール君が画面右端からはみ出そうになっていたら画面内の座標に戻してあげる
			if (BallX > 900) BallX = 899;

			// ボール君が画面上端からはみ出そうになっていたら画面内の座標に戻してあげる
			if (BallY < 30) BallY = 31;

			// ボール君が画面下端からはみ出そうになっていたら画面内の座標に戻してあげる
			if (BallY > 480) BallY = 479;

			// ボール君を描画
			DrawGraph(BallX, BallY, BallGraph, TRUE);
		}

		// 弾の数だけ弾を動かす処理を繰り返す
		for (i = 0; i < SHOT; i++)
		{
			// 自機の弾iの移動ルーチン( 存在状態を保持している変数の内容が１(存在する)の場合のみ行う )
			if (ShotFlag[i] == 1)
			{
				// 弾iを１６ドット右に移動させる
				ShotX[i] += 16;

				// 画面外に出てしまった場合は存在状態を保持している変数に０(存在しない)を代入する
				if (ShotX[i] > 1000)
				{
					ShotFlag[i] = 0;
				}

				// 画面に弾iを描画する
				DrawGraph(ShotX[i], ShotY[i], ShotGraph, TRUE);
			}
		}

		// 四角君の移動ルーチン
		{
				if (BossDamageCounter == 3)
				{
					DeleteGraph(SikakuGraph);
					DeleteGraph(SikakuGraph2);
					DeleteGraph(SikakuGraph3);
					DeleteGraph(SikakuGraph4);
					DeleteGraph(SikakuGraph5);
					DeleteGraph(SikakuGraph6);
					DeleteGraph(SikakuGraph7);
					DeleteGraph(SikakuGraph8);
					DeleteGraph(SikakuGraph9);
					DeleteGraph(SikakuGraph10);
					DeleteGraph(SikakuGraph11);
					DeleteGraph(SikakuGraph12);
					DeleteGraph(SikakuGraph13);
					DeleteGraph(SikakuGraph14);
					DeleteGraph(SikakuGraph15);
					DeleteGraph(SikakuGraph16);
					DeleteGraph(SikakuGraph17);
					DeleteGraph(SikakuGraph18);
					DeleteGraph(SikakuGraph19);
					DeleteGraph(SikakuGraph20);
					DeleteGraph(SikakuGraph21);
					DeleteGraph(SikakuGraph22);
					DeleteGraph(SikakuGraph23);
					DeleteGraph(SikakuGraph24);
					DeleteGraph(SikakuGraph25);
					DeleteGraph(SikakuGraph26);
					DeleteGraph(SikakuGraph27);
					DeleteGraph(SikakuGraph28);
					DeleteGraph(SikakuGraph29);
					DeleteGraph(ShotGraph);
					DeleteGraph(ETamaGraph);
					DeleteGraph(BossGraph);
					DeleteSoundMem(bgm1);
					DeleteSoundMem(se1);
					DeleteSoundMem(se2);
					PlaySoundMem(se3,DX_PLAYTYPE_NORMAL);

				}

				if (ETamaCounter == 100)
				{
					if (ETamaFlag == 0)
					{
						//弾の発射位置を設定する
						ETamaX = BossX + SikakuW / 2 - ETamaW / 2;
						ETamaY = (BossY + 100) + SikakuH / 2 - ETamaH / 2;

						// 弾の状態を保持する変数に『飛んでいる』を示す１を代入する
						ETamaFlag = 1;
					}

					if (ETamaFlag == 1)
					{
						// 弾を移動させる
						ETamaX -= 6;

						// もし弾が画面からはみ出てしまった場合は弾の状態を『飛んでいない』
						// を表す０にする
						if (ETamaY > 560 || ETamaY < 0 ||
							ETamaX > 1000 || ETamaX < 0) ETamaFlag = 0;

						// 画面に描画する( ETamaGraph : 敵の弾のグラフィックのハンドル )
						DrawGraph((int)ETamaX, (int)ETamaY, ETamaGraph, FALSE);
					}

					//カウンターに０を代入して、最初からカウントしなおす
					ETamaCounter = 0;
				}
			}
				// 歪んでいない場合は今まで通りの処理

				// 四角君の座標を移動している方向に移動する
				if (Random[0] % 2 == 0)
				{
					SikakuX -= 5;
					SikakuX7 -= 5;
					SikakuX14 -= 5;
					SikakuX15 -= 5;
					SikakuX21 -= 5;
					SikakuX22 -= 5;
					SikakuX23 -= 5;
					SikakuX24 -= 5;
					SikakuX25 -= 5;
					if (SikakuMuki25 == 1)SikakuY25 -= 7;
					else SikakuY25 += 6;
					SikakuX26 -= 5;
					SikakuX27 -= 5;
					SikakuX28 -= 5;
					SikakuX29 -= 5;
				}
				else
				{
					SikakuX -= 2;
					SikakuX7 -= 2;
					SikakuX14 -= 2;
					SikakuX15 -= 2;
				}

				if (Random[1] % 2 == 0)
				{
					SikakuX2 -= 5;
					SikakuX8 -= 5;
					SikakuX13 -= 5;
					SikakuX16 -= 5;
				}
				else
				{
					SikakuX2 -= 8;
					SikakuX8 -= 8;
					SikakuX13 -= 8;
					SikakuX16 -= 8;
				}

				if (Random[2] % 2 == 0)
				{
					SikakuX3 -= 5;
					SikakuX9 -= 5;
					SikakuX12 -= 5;
					SikakuX17 -= 5;
				}
				else
				{
					SikakuX3 -= 10;
					SikakuX9 -= 10;
					SikakuX12 -= 10;
					SikakuX17 -= 10;
				}

				if (Random[3] % 2 == 0)
				{
					SikakuX4 -= 3;
					SikakuX10 -= 3;
					SikakuX11 -= 3;
					SikakuX18 -= 3;
				}
				else
				{
					SikakuX4 -= 5;
					SikakuX10 -= 5;
					SikakuX11 -= 5;
					SikakuX18 -= 5;
				}

				if (Random[4] % 2 == 0)
				{
					SikakuX5 -= 7;
					SikakuX19 -= 7;
					if (SikakuMuki5 == 1)SikakuY5 += 4;
					else SikakuY5 -= 4;
					if (SikakuMuki19 == 1)SikakuY19 -= 7;
					else SikakuY19 -= 7;
				}
				else
				{
					SikakuX5 -= 4;
					SikakuX20 -= 3;
					if (SikakuMuki5 == 1)SikakuY5 += 7;
					else SikakuY5 -= 4;
					SikakuX20 -= 3;

				}

				if (Random[5] % 2 == 0)
				{
					SikakuX6 += 6;
				}
				else
				{
					SikakuX6 += 9;
				}


				// 四角君が画面下端からでそうになっていたら画面内の座標に戻してあげ、移動する方向も反転する
				if (SikakuY5 > 460)
				{
					SikakuY5 = 459;
					SikakuMuki5 = 0;
				}


				// 四角君が画面上端からでそうになっていたら画面内の座標に戻してあげ、移動する方向も反転する
				if (SikakuY5 < 40)
				{
					SikakuY5 = 41;
					SikakuMuki5 = 1;
				}

				// 四角君が画面下端からでそうになっていたら画面内の座標に戻してあげ、移動する方向も反転する
				if (SikakuY19 > 460)
				{
					SikakuY19 = 459;
					SikakuMuki19 = 0;
				}


				// 四角君が画面上端からでそうになっていたら画面内の座標に戻してあげ、移動する方向も反転する
				if (SikakuY19 < 40)
				{
					SikakuY19 = 41;
					SikakuMuki19 = 1;
				}

				// 四角君が画面下端からでそうになっていたら画面内の座標に戻してあげ、移動する方向も反転する
				if (SikakuY25 > 460)
				{
					SikakuY25 = 459;
					SikakuMuki25 = 0;
				}


				// 四角君が画面上端からでそうになっていたら画面内の座標に戻してあげ、移動する方向も反転する
				if (SikakuY25 < 40)
				{
					SikakuY25 = 41;
					SikakuMuki25 = 1;
				}

				if (BossY < 40)
				{
					BossY = 41;
					BossMuki = 1;
				}

				if (BossY > 430)
				{
					BossY = 429;
					BossMuki = 0;
				}

				// 四角君を描画
				DrawGraph(SikakuX, SikakuY, SikakuGraph, TRUE);
				DrawGraph(SikakuX2, SikakuY2, SikakuGraph2, TRUE);
				DrawGraph(SikakuX3, SikakuY3, SikakuGraph3, TRUE);
				DrawGraph(SikakuX4, SikakuY4, SikakuGraph4, TRUE);
				DrawGraph(SikakuX5, SikakuY5, SikakuGraph5, TRUE);
				DrawGraph(SikakuX6, SikakuY6, SikakuGraph6, TRUE);
				DrawGraph(SikakuX7, SikakuY7, SikakuGraph7, TRUE);
				DrawGraph(SikakuX8, SikakuY8, SikakuGraph8, TRUE);
				DrawGraph(SikakuX9, SikakuY9, SikakuGraph9, TRUE);
				DrawGraph(SikakuX10, SikakuY10, SikakuGraph10, TRUE);
				DrawGraph(SikakuX11, SikakuY11, SikakuGraph11, TRUE);
				DrawGraph(SikakuX12, SikakuY12, SikakuGraph12, TRUE);
				DrawGraph(SikakuX13, SikakuY13, SikakuGraph13, TRUE);
				DrawGraph(SikakuX14, SikakuY14, SikakuGraph14, TRUE);
				DrawGraph(SikakuX15, SikakuY15, SikakuGraph15, TRUE);
				DrawGraph(SikakuX16, SikakuY16, SikakuGraph16, TRUE);
				DrawGraph(SikakuX17, SikakuY17, SikakuGraph17, TRUE);
				DrawGraph(SikakuX18, SikakuY18, SikakuGraph18, TRUE);
				DrawGraph(SikakuX19, SikakuY19, SikakuGraph19, TRUE);
				DrawGraph(SikakuX20, SikakuY20, SikakuGraph20, TRUE);
				DrawGraph(SikakuX21, SikakuY21, SikakuGraph21, TRUE);
				DrawGraph(SikakuX22, SikakuY22, SikakuGraph22, TRUE);
				DrawGraph(SikakuX23, SikakuY23, SikakuGraph23, TRUE);
				DrawGraph(SikakuX24, SikakuY24, SikakuGraph24, TRUE);
				DrawGraph(SikakuX25, SikakuY25, SikakuGraph25, TRUE);
				DrawGraph(SikakuX26, SikakuY26, SikakuGraph26, TRUE);
				DrawGraph(SikakuX27, SikakuY27, SikakuGraph27, TRUE);
				DrawGraph(SikakuX28, SikakuY28, SikakuGraph28, TRUE);
				DrawGraph(SikakuX29, SikakuY29, SikakuGraph29, TRUE);
				DrawGraph(BossX, BossY, BossGraph, TRUE);


				// 弾を撃つタイミングを計測するためのカウンターに１を足す
				ETamaCounter++;


				// もしカウンター変数が30だった場合は弾を撃つ処理を行う
				if (ETamaCounter == 30)
				{
					// もし既に弾が『飛んでいない』状態だった場合のみ発射処理を行う
					if (ETamaFlag == 0 )
					{
						// 弾の発射位置を設定する
						ETamaX = BossX + SikakuW / 2 - ETamaW / 2;
						ETamaY = (BossY + SikakuH / 2 - ETamaH / 2) + 50;


						// 弾の移動速度を設定する
						{
							double sb, sbx, sby, bx, by, sx, sy;

							sx = ETamaX + ETamaW / 2;
							sy = ETamaY + ETamaH / 2;

							bx = BallX + Bw / 2;
							by = BallY + Bh / 2;

							sbx = bx - sx;
							sby = by - sy;

							// 平方根を求めるのに標準関数の sqrt を使う、
							// これを使うには math.h をインクルードする必要がある
							sb = sqrt(sbx * sbx + sby * sby);

							// １フレーム当たり12ドット移動するようにする
							ETamaSx = sbx / sb * 12;
						}

						// 弾の状態を保持する変数に『飛んでいる』を示す１を代入する
						ETamaFlag = 1;
					}

					// 弾を打つタイミングを計測するための変数に０を代入
					ETamaCounter = 0;
				} 

		// 敵の弾の状態が『飛んでいる』場合のみ弾の移動処理を行う
		if (ETamaFlag == 1)
		{
				// 弾を移動させる
				ETamaX -= 15;

				// もし弾が画面からはみ出てしまった場合は弾の状態を『飛んでいない』
				// を表す０にする
				if (ETamaX > 1000 || ETamaX < 20) ETamaFlag = 0;

				// 画面に描画する( ETamaGraph : 敵の弾のグラフィックのハンドル )
				DrawGraph(ETamaX, ETamaY, ETamaGraph, TRUE);

			// 弾と敵の当たり判定、弾の数だけ繰り返す
			for (i = 0; i < SHOT; i++)
			{
				// 弾iが存在している場合のみ次の処理に映る
				if (ShotFlag[i] == 1)
				{
					// 四角君との当たり判定
					if (((ShotX[i] > BossX && ShotX[i] < BossX + SikakuW + 75) ||
						(BossX > ShotX[i] && BossX < ShotX[i] + ShotW)) &&
						((ShotY[i] > BossY && ShotY[i] < BossY + SikakuH + 75) ||
							(BossY > ShotY[i] && BossY < ShotY[i] + ShotH)))
					{
						// 接触している場合は当たった弾の存在を消す
						ShotFlag[i] = 0;

						//ボスがどれだけ攻撃を受けたのかをカウントする
						BossDamageCounter += 1;

						//当たった時の効果音を設定
						PlaySoundMem(se1, DX_PLAYTYPE_BACK);

					}
				}
			}
		}

		// 裏画面の内容を表画面にコピーする
		ScreenFlip();

		// Windows 特有の面倒な処理をＤＸライブラリにやらせる
		// -1 が返ってきたらループを抜ける
		if (ProcessMessage() < 0)break;

		// もしＥＳＣキーが押されていたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;
	}
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;					// ソフトの終了
}