#include "DxLib.h"
#include <math.h>

#define SHOT 100
#define MAX_SPARK 800
#define MARGIN 10



// WinMain�֐�
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



	// ��ʃ��[�h�̐ݒ�
	SetGraphMode(1000, 560, 16);

	x1 = 0;
	x2 = 640;
	y1 = 350;
	y2 = 200;
	bx1 = 0;
	// �c�w���C�u��������������
	if (DxLib_Init() == -1) return -1;

	// �O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	// �{�[���N�̃O���t�B�b�N���������Ƀ��[�h���\�����W���Z�b�g
	BallGraph = LoadGraph("Ball.png");
	BallX = 0; BallY = 200;

	// �l�p�N�̃O���t�B�b�N���������Ƀ��[�h���\�����W���Z�b�g
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

	// �l�p�N�̃_���[�W���̃O���t�B�b�N���������Ƀ��[�h
	BossDamageGraph = LoadGraph("SikakuDam.png");

	// �{�X�����c�߂Ă��邩�ǂ����̕ϐ��Ɂw�c�߂Ă��Ȃ��x��\���O����
	BossDamageFlag = 0;

	//�{�X���ǂꂾ���{�[���N�̍U�����󂯂��̂����J�E���g����ϐ���������
	BossDamageCounter = 0;

	// �G�̒e�̃O���t�B�b�N�����[�h
	ETamaGraph = LoadGraph("EShot.png");

	// �G�̒e�̃O���t�B�b�N�̃T�C�Y�𓾂�
	GetGraphSize(ETamaGraph, &ETamaW, &ETamaH);

	//�w�i�摜�̃O���t�B�b�N�����[�h
	gh = LoadGraph("guradhiusu.png");

	// �G�̒e�����ł��邩�ǂ�����ێ�����ϐ��Ɂw���ł��Ȃ��x��\���O����
	ETamaFlag = 0;

	// �G���e�����^�C�~���O����邽�߂̌v���p�ϐ��ɂO����
	ETamaCounter = 0;

	// �e�̃O���t�B�b�N���������Ƀ��[�h
	ShotGraph = LoadGraph("Shot.png");

	//�X�e�[�W��BGM���������Ƀ��[�h
	int bgm1;
	bgm1 = LoadSoundMem("loop_47.wav");

	//�G�ɋ��𓖂Ă����̌��ʉ����������Ƀ��[�h
	int se1;
	se1 = LoadSoundMem("baku003.wav");

	//�������e��ł������̌��ʉ����������Ƀ��[�h
	int se2;
	se2 = LoadSoundMem("shot.wav");

	//�{�X���j���̌��ʉ����������Ƀ��[�h
	int se3;
	se3 = LoadSoundMem("gameclear.wav");

	// �e����ʏ�ɑ��݂��Ă��邩�ێ�����ϐ��Ɂw���݂��Ă��Ȃ��x���Ӗ�����O�������Ă���
	for (i = 0; i < SHOT; i++)
	{
		ShotFlag[i] = 0;
	}

	// �V���b�g�{�^�����O�̃t���[���ŉ����ꂽ���ǂ�����ۑ�����ϐ��ɂO(�����ꂢ�Ȃ�)����
	ShotBFlag = 0;

	// �l�p�N�̈ړ��������Z�b�g
	SikakuMuki5 = 1;
	SikakuMuki19 = 1;
	SikakuMuki25 = 1;
	BossMuki = 1;

	// �e�̃O���t�B�b�N�̃T�C�Y������
	GetGraphSize(ShotGraph, &ShotW, &ShotH);

	// �l�p�N�̃O���t�B�b�N�̃T�C�Y�𓾂�
	GetGraphSize(SikakuGraph, &SikakuW, &SikakuH);

	// �{�[���N�ƒe�̉摜�̃T�C�Y�𓾂�
	GetGraphSize(BallGraph, &Bw, &Bh);
	GetGraphSize(ShotGraph, &Sw, &Sh);
	GetGraphSize(gh, &BackX, &BackY);


	PlaySoundMem(bgm1, DX_PLAYTYPE_LOOP);

	// �ړ����[�`��
	while (1)
	{
		// ��ʂ�������(�^�����ɂ���)
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


		// �{�[���N�̑��샋�[�`��
		{
			// ���L�[�������Ă�����{�[���N����Ɉړ�������
			if (CheckHitKey(KEY_INPUT_UP) == 1) BallY -= 3;
			if (BallY != 0)y1 += 10;
			if (BallY != 560)y2 -= 10;


			// ���L�[�������Ă�����{�[���N�����Ɉړ�������
			if (CheckHitKey(KEY_INPUT_DOWN) == 1) BallY += 3;
			if (BallY != 560)y1 -= 10;
			if (BallY != 0)y2 += 10;

			// ���L�[�������Ă�����{�[���N�����Ɉړ�������
			if (CheckHitKey(KEY_INPUT_LEFT) == 1) BallX -= 3;
			if (BallX != 0)x1 += 10;
			if (BallX != 1000)x2 -= 10;

			// ���L�[�������Ă�����{�[���N���E�Ɉړ�������
			if (CheckHitKey(KEY_INPUT_RIGHT) == 1) BallX += 3;
			if (BallX != 1000)x1 -= 10;
			if (BallX != 0)x2 += 10;

			// �X�y�[�X�L�[���������ꍇ�͏����𕪊�
			if (CheckHitKey(KEY_INPUT_SPACE))
			{
				// �O�t���[���ŃV���b�g�{�^���������������ۑ�����Ă���ϐ����O��������e�𔭎�
				if (ShotBFlag == 0)
				{
					// ��ʏ�ɂłĂ��Ȃ��e�����邩�A�e�̐������J��Ԃ��Ē��ׂ�
					for (i = 0; i < SHOT; i++)
					{
						// �ei����ʏ�ɂłĂ��Ȃ��ꍇ�͂��̒e����ʂɏo��
						if (ShotFlag[i] == 0)
						{
							int Bw, Bh, Sw, Sh;

							// �{�[���N�ƒe�̉摜�̃T�C�Y�𓾂�
							GetGraphSize(BallGraph, &Bw, &Bh);
							GetGraphSize(ShotGraph, &Sw, &Sh);

							// �ei�̈ʒu���Z�b�g�A�ʒu�̓{�[���N�̒��S�ɂ���
							ShotX[i] = (Bw - Sw) / 2 + BallX;
							ShotY[i] = (Bh - Sh) / 2 + BallY;

							// �ei�͌����_�������đ��݂���̂ŁA���ݏ�Ԃ�ێ�����ϐ��ɂP��������
							ShotFlag[i] = 1;

							//���ʂ��Đ�
							PlaySoundMem(se2, DX_PLAYTYPE_BACK);

							// ��e���o�����̂Œe���o�����[�v���甲���܂�
							break;
						}
					}
				}

				// �O�t���[���ŃV���b�g�{�^����������Ă�������ۑ�����ϐ��ɂP(������Ă���)����
				ShotBFlag = 1;
			}
			else
			{
				// �V���b�g�{�^����������Ă��Ȃ������ꍇ��
				// �O�t���[���ŃV���b�g�{�^����������Ă�������ۑ�����ϐ��ɂO(������Ă��Ȃ�)����
				ShotBFlag = 0;
			}


			// �{�[���N����ʍ��[����͂ݏo�����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă�����
			if (BallX < 0) BallX = 0;

			// �{�[���N����ʉE�[����͂ݏo�����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă�����
			if (BallX > 900) BallX = 899;

			// �{�[���N����ʏ�[����͂ݏo�����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă�����
			if (BallY < 30) BallY = 31;

			// �{�[���N����ʉ��[����͂ݏo�����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă�����
			if (BallY > 480) BallY = 479;

			// �{�[���N��`��
			DrawGraph(BallX, BallY, BallGraph, TRUE);
		}

		// �e�̐������e�𓮂����������J��Ԃ�
		for (i = 0; i < SHOT; i++)
		{
			// ���@�̒ei�̈ړ����[�`��( ���ݏ�Ԃ�ێ����Ă���ϐ��̓��e���P(���݂���)�̏ꍇ�̂ݍs�� )
			if (ShotFlag[i] == 1)
			{
				// �ei���P�U�h�b�g�E�Ɉړ�������
				ShotX[i] += 16;

				// ��ʊO�ɏo�Ă��܂����ꍇ�͑��ݏ�Ԃ�ێ����Ă���ϐ��ɂO(���݂��Ȃ�)��������
				if (ShotX[i] > 1000)
				{
					ShotFlag[i] = 0;
				}

				// ��ʂɒei��`�悷��
				DrawGraph(ShotX[i], ShotY[i], ShotGraph, TRUE);
			}
		}

		// �l�p�N�̈ړ����[�`��
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
						//�e�̔��ˈʒu��ݒ肷��
						ETamaX = BossX + SikakuW / 2 - ETamaW / 2;
						ETamaY = (BossY + 100) + SikakuH / 2 - ETamaH / 2;

						// �e�̏�Ԃ�ێ�����ϐ��Ɂw���ł���x�������P��������
						ETamaFlag = 1;
					}

					if (ETamaFlag == 1)
					{
						// �e���ړ�������
						ETamaX -= 6;

						// �����e����ʂ���͂ݏo�Ă��܂����ꍇ�͒e�̏�Ԃ��w���ł��Ȃ��x
						// ��\���O�ɂ���
						if (ETamaY > 560 || ETamaY < 0 ||
							ETamaX > 1000 || ETamaX < 0) ETamaFlag = 0;

						// ��ʂɕ`�悷��( ETamaGraph : �G�̒e�̃O���t�B�b�N�̃n���h�� )
						DrawGraph((int)ETamaX, (int)ETamaY, ETamaGraph, FALSE);
					}

					//�J�E���^�[�ɂO�������āA�ŏ�����J�E���g���Ȃ���
					ETamaCounter = 0;
				}
			}
				// �c��ł��Ȃ��ꍇ�͍��܂Œʂ�̏���

				// �l�p�N�̍��W���ړ����Ă�������Ɉړ�����
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


				// �l�p�N����ʉ��[����ł����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă����A�ړ�������������]����
				if (SikakuY5 > 460)
				{
					SikakuY5 = 459;
					SikakuMuki5 = 0;
				}


				// �l�p�N����ʏ�[����ł����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă����A�ړ�������������]����
				if (SikakuY5 < 40)
				{
					SikakuY5 = 41;
					SikakuMuki5 = 1;
				}

				// �l�p�N����ʉ��[����ł����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă����A�ړ�������������]����
				if (SikakuY19 > 460)
				{
					SikakuY19 = 459;
					SikakuMuki19 = 0;
				}


				// �l�p�N����ʏ�[����ł����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă����A�ړ�������������]����
				if (SikakuY19 < 40)
				{
					SikakuY19 = 41;
					SikakuMuki19 = 1;
				}

				// �l�p�N����ʉ��[����ł����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă����A�ړ�������������]����
				if (SikakuY25 > 460)
				{
					SikakuY25 = 459;
					SikakuMuki25 = 0;
				}


				// �l�p�N����ʏ�[����ł����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă����A�ړ�������������]����
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

				// �l�p�N��`��
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


				// �e�����^�C�~���O���v�����邽�߂̃J�E���^�[�ɂP�𑫂�
				ETamaCounter++;


				// �����J�E���^�[�ϐ���30�������ꍇ�͒e�����������s��
				if (ETamaCounter == 30)
				{
					// �������ɒe���w���ł��Ȃ��x��Ԃ������ꍇ�̂ݔ��ˏ������s��
					if (ETamaFlag == 0 )
					{
						// �e�̔��ˈʒu��ݒ肷��
						ETamaX = BossX + SikakuW / 2 - ETamaW / 2;
						ETamaY = (BossY + SikakuH / 2 - ETamaH / 2) + 50;


						// �e�̈ړ����x��ݒ肷��
						{
							double sb, sbx, sby, bx, by, sx, sy;

							sx = ETamaX + ETamaW / 2;
							sy = ETamaY + ETamaH / 2;

							bx = BallX + Bw / 2;
							by = BallY + Bh / 2;

							sbx = bx - sx;
							sby = by - sy;

							// �����������߂�̂ɕW���֐��� sqrt ���g���A
							// ������g���ɂ� math.h ���C���N���[�h����K�v������
							sb = sqrt(sbx * sbx + sby * sby);

							// �P�t���[��������12�h�b�g�ړ�����悤�ɂ���
							ETamaSx = sbx / sb * 12;
						}

						// �e�̏�Ԃ�ێ�����ϐ��Ɂw���ł���x�������P��������
						ETamaFlag = 1;
					}

					// �e��ł^�C�~���O���v�����邽�߂̕ϐ��ɂO����
					ETamaCounter = 0;
				} 

		// �G�̒e�̏�Ԃ��w���ł���x�ꍇ�̂ݒe�̈ړ��������s��
		if (ETamaFlag == 1)
		{
				// �e���ړ�������
				ETamaX -= 15;

				// �����e����ʂ���͂ݏo�Ă��܂����ꍇ�͒e�̏�Ԃ��w���ł��Ȃ��x
				// ��\���O�ɂ���
				if (ETamaX > 1000 || ETamaX < 20) ETamaFlag = 0;

				// ��ʂɕ`�悷��( ETamaGraph : �G�̒e�̃O���t�B�b�N�̃n���h�� )
				DrawGraph(ETamaX, ETamaY, ETamaGraph, TRUE);

			// �e�ƓG�̓����蔻��A�e�̐������J��Ԃ�
			for (i = 0; i < SHOT; i++)
			{
				// �ei�����݂��Ă���ꍇ�̂ݎ��̏����ɉf��
				if (ShotFlag[i] == 1)
				{
					// �l�p�N�Ƃ̓����蔻��
					if (((ShotX[i] > BossX && ShotX[i] < BossX + SikakuW + 75) ||
						(BossX > ShotX[i] && BossX < ShotX[i] + ShotW)) &&
						((ShotY[i] > BossY && ShotY[i] < BossY + SikakuH + 75) ||
							(BossY > ShotY[i] && BossY < ShotY[i] + ShotH)))
					{
						// �ڐG���Ă���ꍇ�͓��������e�̑��݂�����
						ShotFlag[i] = 0;

						//�{�X���ǂꂾ���U�����󂯂��̂����J�E���g����
						BossDamageCounter += 1;

						//�����������̌��ʉ���ݒ�
						PlaySoundMem(se1, DX_PLAYTYPE_BACK);

					}
				}
			}
		}

		// ����ʂ̓��e��\��ʂɃR�s�[����
		ScreenFlip();

		// Windows ���L�̖ʓ|�ȏ������c�w���C�u�����ɂ�点��
		// -1 ���Ԃ��Ă����烋�[�v�𔲂���
		if (ProcessMessage() < 0)break;

		// �����d�r�b�L�[��������Ă����烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;
	}
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;					// �\�t�g�̏I��
}