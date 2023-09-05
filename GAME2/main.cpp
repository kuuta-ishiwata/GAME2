#include <Novice.h>
#include <math.h>

const char kWindowTitle[] = "学籍番号";

struct Vector2
{
	float x, y;
};

const int MAPX = 25;
const int MAPY = 25;


int date[MAPY][MAPX]
{

	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

};
//ブロックサイズ
int BLOCKsize = 16;

struct Player
{
	Vector2 position;
	int radius;
	Vector2 speed;
	Vector2 progress;
	bool flag;
	int timer;
};


enum BLOCK
{
	NOME,
	block
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	int posX = 50;
	int posY = 50;

	Player player;
	player.position = { 100, 50 };
	player.radius = 50, 50;
	Player player2;
	player2.position = { 150,50 };
	player2.radius = 50;
	Player player3;
	player3.position = { 200,50 };
	player3.radius = 50;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

			//本持つ
		if (keys[DIK_SPACE])
		{


		}

		if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
		{



		}

		if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
		{


		}


		if (keys[DIK_UP] && preKeys[DIK_UP] == 0)
		{




		}

		if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
		{


		}


		if (keys[DIK_SPACE])
		{


		}



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::DrawBox(posX, posY, 25, 50, 0.0f, RED, kFillModeSolid);
		Novice::DrawBox(player.position.x, player.position.y, player.radius, player.radius, 0.0f, RED, kFillModeSolid);
		Novice::DrawBox(player2.position.x, player2.position.y, player2.radius, player2.radius, 0.0f, RED, kFillModeSolid);
		Novice::DrawBox(player3.position.x, player3.position.y, player3.radius, player3.radius, 0.0f, RED, kFillModeSolid);



		for (int i = 0; i < MAPX; i++)
		{
			for (int j = 0; j < MAPY; j++)
			{
				if (date[j][i] == block)
				{
					Novice::DrawBox(i * 32, j * 32, 35, 35, 0.0f, WHITE, kFillModeSolid);
				}
			}
		}


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
