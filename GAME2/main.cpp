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
	1,0,2,0,3,0,4,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,2,0,3,0,4,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,2,0,3,0,4,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
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
	Vector2 radius;
	Vector2 speed;
	Vector2 progress;
	bool flag;
	int timer;
};

struct book
{
	Vector2 position;
	Vector2 radius;
	bool flag;
};


enum BLOCK
{
	NOME,
	block
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 800, 675);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	int posX = 50;
	int posY = 50;

	int a = 0;
	int b = 0;
	int flag = false;
	int flag2 = false;

	Player player;
	player.position = { 95, 45 };
	player.radius = { 10,40 };
	player.speed = { 25,25 };
	
	book Book;
	Book.position = { 150,50 };
	Book.radius = { 10, 40 };
	Book.flag = false;
	book Book2;
	Book2.position = { 200,50 };
	Book2.radius = { 10,40 };
	Book2.flag = false;
	book Book3;
	Book3.position = { 250,50 };
	Book3.radius = { 10,40 };
	Book3.flag = false;
	book Book4;
	Book4.position = { 300,50 };
	Book4.radius = { 10,40 };
	Book4.flag = false;
	book Book5;
	Book5.position = { 350,50 };
	Book5.radius = { 10,40 };
	Book5.flag = false;

	int grahHandle = Novice::LoadTexture("./GJ3_Frame.png");
	
	

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

		

		if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
		{
		
			player.position.x -= player.speed.x;

		}
		if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
		{

			player.position.x += player.speed.x;

		}
		if (keys[DIK_UP] && preKeys[DIK_UP] == 0)
		{

			player.position.y -= player.speed.y;
		}

		if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
		{

			player.position.y += player.speed.y;

		}

		

		//book
			if (keys[DIK_SPACE] == preKeys[DIK_SPACE] == 0)
			{

				if (player.position.x == Book.position.x - 5 && player.position.y == Book.position.y - 5)
				{
					flag = true;
				}

			}
			if (flag == true)
			{

				player.position.x = Book.position.x - 5;
				player.position.y = Book.position.y - 5;

				if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
				{
					Book.position.x -= player.speed.x;
				}
				if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
				{
					Book.position.x += player.speed.x;
				}
				if (keys[DIK_UP] && preKeys[DIK_UP] == 0)
				{
					Book.position.y -= player.speed.y;
				}
				if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
				{
					Book.position.y += player.speed.y;
				}

			}

			if (keys[DIK_A] == preKeys[DIK_A] == 0)
			{
				flag = false;
			}

			//Book2

		if (keys[DIK_SPACE] == preKeys[DIK_SPACE] == 0)
		{
			if (player.position.x == Book2.position.x - 5 && player.position.y == Book2.position.y - 5)
			{
				Book2.flag = true;
			}
		}

		if (Book2.flag == true)
		{
			player.position.x = Book2.position.x - 5;
			player.position.y = Book2.position.y - 5;

			if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
			{
				Book2.position.x -= player.speed.x;

			}
			if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
			{

				Book2.position.x += player.speed.x;

			}
			if (keys[DIK_UP] && preKeys[DIK_UP] == 0)
			{

				Book2.position.y -= player.speed.y;
			}

			if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
			{

				Book2.position.y += player.speed.y;

			}

		}

		if (keys[DIK_A] == preKeys[DIK_A] == 0)
		{
			Book2.flag = false;

		}
		
		//Book3
		if (keys[DIK_SPACE] == preKeys[DIK_SPACE] == 0)
		{

			if (player.position.x == Book3.position.x - 5 && player.position.y == Book3.position.y - 5)
			{
				Book3.flag = true;
			}

		}
		if (Book3.flag == true)
		{

			player.position.x = Book3.position.x - 5;
			player.position.y = Book3.position.y - 5;

			if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
			{
				Book3.position.x -= player.speed.x;
			}
			if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
			{
				Book3.position.x += player.speed.x;
			}
			if (keys[DIK_UP] && preKeys[DIK_UP] == 0)
			{
				Book3.position.y -= player.speed.y;
			}
			if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
			{
				Book3.position.y += player.speed.y;
			}

		}

		if (keys[DIK_A] == preKeys[DIK_A] == 0)
		{
			Book3.flag = false;
		}


		if (keys[DIK_S] == preKeys[DIK_S] == 0)
		{
			if (Book.position.x == Book3.position.x && Book.position.x == Book3.position.y)
			{
				if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
				{
					Book.position.x -= player.speed.x;
				}
				if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
				{
					Book.position.x += player.speed.x;
				}
				if (keys[DIK_UP] && preKeys[DIK_UP] == 0)
				{
					Book.position.y -= player.speed.y;
				}
				if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
				{
					Book.position.y += player.speed.y;
				}
			}

			if (Book2.position.x == Book3.position.x && Book2.position.x == Book3.position.y)
			{
				if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
				{
					Book2.position.x -= player.speed.x;

				}
				if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
				{

					Book2.position.x += player.speed.x;

				}
				if (keys[DIK_UP] && preKeys[DIK_UP] == 0)
				{

					Book2.position.y -= player.speed.y;
				}

				if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
				{

					Book2.position.y += player.speed.y;

				}
			}
		}

		//Book4


		//Book5






		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		//Novice::DrawBox(posX, posY, 25, 50, 0.0f, RED, kFillModeSolid);
		//Novice::DrawBox(player.position.x, player.position.y, player.radius.x, player.radius.y, 0.0f, BLUE, kFillModeSolid);
		//Novice::DrawBox(player2.position.x, player2.position.y, player2.radius.x, player2.radius.y, 0.0f, WHITE, kFillModeSolid);
		//Novice::DrawBox(player3.position.x, player3.position.y, player3.radius.x, player3.radius.y, 0.0f, BLACK, kFillModeSolid);



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
		Novice::DrawSprite(player.position.x, player.position.y, grahHandle, 1, 1, 0.0f, WHITE);
		Novice::DrawBox(Book.position.x, Book.position.y, Book.radius.x, Book.radius.y, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(Book2.position.x, Book2.position.y, Book2.radius.x, Book2.radius.y, 0.0f, BLACK, kFillModeSolid);
		Novice::DrawBox(Book3.position.x, Book3.position.y, Book3.radius.x, Book3.radius.y, 0.0f, RED, kFillModeSolid);


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
