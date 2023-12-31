#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "2042_BOOK TIDINESS";

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
	1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10,0,11,0,0,0,1,
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

struct Mark
{

	Vector2 position;


};

enum BLOCK
{

	NOME,
	block,
	block2,
	block3,
	block4,
	block5
	
   
};

enum  Book
{
	None,
	book1


};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 800, 675);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	
	int a = 0;
	int b = 0;
	int flag = false;
	int flag2 = false;

	int countflag = false;
	int countflag2 = false;
	int countflag3 = false;
	int countflag4 = false;
	int countflag5 = false;
	int countflag6 = false;
	int countflag7 = false;
	int countflag8 = false;
	int countflag9 = false;
	int countflag10 = false;
	int countflag11 = false;
	int countflag12 = false;
	int countflag13 = false;


	Player player;
	player.position = { 95, 282 };
	player.radius = { 10,40 };
	player.speed = { 25,25 };
	
	block2;

	book Book;
	Book.position = { 350,287 };
	Book.radius = { 10, 40 };
	Book.flag = false;


	book Book2;
	Book2.position = { 500,287 };
	Book2.radius = { 10,40 };
	Book2.flag = false;


	book Book3;
	Book3.position = { 450,287 };
	Book3.radius = { 10,40 };
	Book3.flag = false;


	book Book4;
	Book4.position = { 300,287 };
	Book4.radius = { 10,40 };
	Book4.flag = false;


	book Book5;
	Book5.position = { 150,287 };
	Book5.radius = { 10,40 };
	Book5.flag = false;
	
	book Book6;
	Book6.position = { 600,287 };
	Book6.radius = { 10,40 };
	Book6.flag = false;

	book Book7;
	Book7.position = { 250,287 };
	Book7.radius = { 10,40 };
	Book7.flag = false;

	book Book8;
	Book8.position = { 200,287 };
	Book8.radius = { 10,40 };
	Book8.flag = false;

	book Book9;
	Book9.position = { 550,287 };
	Book9.radius = { 10,40 };
	Book9.flag = false;

	book Book10;
	Book10.position = { 400,287 };
	Book10.radius = { 10,40 };
	Book10.flag = false;


	//Mark
	Mark Mark1;
	Mark1.position= { 150,287 };

	Mark Mark2;
	Mark2.position = { 200,287 };

	Mark Mark3;
	Mark3.position = { 250,287 };

	Mark Mark4;
	Mark4.position = { 300,287 };
	
	Mark Mark5;
	Mark5.position = { 350,287 };

	Mark Mark6;
	Mark6.position = { 400,287 };

	Mark Mark7;
	Mark7.position = { 450,287 };

	Mark Mark8;
	Mark8.position = { 500,287 };

	Mark Mark9;
	Mark9.position = { 550,287 };

	Mark Mark10;
	Mark10.position = { 600,287 };

	int timer = 0;
	int count = 0;
	int scene = 0;

	int grahHandle = Novice::LoadTexture("./GJ3_Frame.png");
	int count0 = Novice::LoadTexture("./count0.png");
	int count1 = Novice::LoadTexture("./count.png");
	int count2 = Novice::LoadTexture("./count2.png");
	int count3 = Novice::LoadTexture("./count3.png");
	int count4 = Novice::LoadTexture("./count4.png");
	int count5 = Novice::LoadTexture("./count5.png");
	int count6 = Novice::LoadTexture("./count6.png");
	int count7 = Novice::LoadTexture("./count7.png");
	int count8 = Novice::LoadTexture("./count8.png");
	int count9 = Novice::LoadTexture("./count9.png");
	int count10 = Novice::LoadTexture("./count10.png");
	int count11 = Novice::LoadTexture("./count30.png");
	int count12 = Novice::LoadTexture("./count60.png");

	int view = Novice::LoadTexture("./view.png");
	int Cleare = Novice::LoadTexture("./CLEAR.png");
	int GameOver = Novice::LoadTexture("./GameOver.png");
	int explanation = Novice::LoadTexture("./explanation.png");
	int start = Novice::LoadTexture("./start.png");


	int Book1 = Novice::LoadTexture("./GJ3_Book1_1.png");
	int BOOK2 = Novice::LoadTexture("./GJ3_Book1_2.png");
	int BOOK3 = Novice::LoadTexture("./GJ3_Book1_3.png");
	int BOOK4 = Novice::LoadTexture("./GJ3_Book1_4.png");
	int BOOK5 = Novice::LoadTexture("./GJ3_Book1_5.png");
	int BOOK6 = Novice::LoadTexture("./GJ3_RedBook_1.png");
	int BOOK7 = Novice::LoadTexture("./GJ3_RedBook_2.png");
	int BOOK8 = Novice::LoadTexture("./GJ3_RedBook_3.png");
	int BOOK9 = Novice::LoadTexture("./GJ3_RedBook_4.png");
	int BOOK10 = Novice::LoadTexture("./GJ3_RedBook_5.png");


	int Music = Novice::LoadAudio("./gamemusic.mp3");


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




		if (!Novice::IsPlayingAudio(Music))
		{
			Novice::PlayAudio(Music, true, 0.5f);
		}

		switch (scene)
		{

		case 0:

			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0)
			{

				countflag = false;
				timer = 0;
				scene = 1;
				player.position = { 95, 282 };
				Book.position = { 350,287 };
				Book2.position = { 500,287 };
				Book3.position = { 450,287 };
				Book4.position = { 300,287 };
				Book5.position = { 150,287 };
				Book6.position = { 600,287 };
				Book7.position = { 250,287 };
				Book8.position = { 200,287 };
				Book9.position = { 550,287 };
				Book10.position = { 400,287 };

			}

			break;

		case 1:


			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0)
			{

				scene = 2;

			}

			break;

		case 2:

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

					flag = true;

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

					Book2.flag = true;

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
			if (keys[DIK_SPACE] == preKeys[DIK_SPACE] == 0)
			{

				if (player.position.x == Book4.position.x - 5 && player.position.y == Book4.position.y - 5)
				{

					Book4.flag = true;

				}

			}


			if (Book4.flag == true)
			{

				player.position.x = Book4.position.x - 5;
				player.position.y = Book4.position.y - 5;


				if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
				{
					Book4.position.x -= player.speed.x;
				}

				if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
				{
					Book4.position.x += player.speed.x;
				}

				if (keys[DIK_UP] && preKeys[DIK_UP] == 0)
				{
					Book4.position.y -= player.speed.y;
				}

				if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
				{
					Book4.position.y += player.speed.y;

				}


			}

			if (keys[DIK_A] == preKeys[DIK_A] == 0)
			{

				Book4.flag = false;

			}


			if (keys[DIK_S] == preKeys[DIK_S] == 0)
			{

				if (Book.position.x == Book4.position.x && Book.position.x == Book4.position.y)
				{

					flag = true;

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

				if (Book2.position.x == Book4.position.x && Book2.position.x == Book4.position.y)
				{

					Book2.flag = true;

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

			//Book5


			if (keys[DIK_SPACE] == preKeys[DIK_SPACE] == 0)
			{

				if (player.position.x == Book5.position.x - 5 && player.position.y == Book5.position.y - 5)
				{
					Book5.flag = true;
				}


			}


			if (Book5.flag == true)
			{

				player.position.x = Book5.position.x - 5;
				player.position.y = Book5.position.y - 5;


				if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
				{
					Book5.position.x -= player.speed.x;
				}

				if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
				{
					Book5.position.x += player.speed.x;
				}

				if (keys[DIK_UP] && preKeys[DIK_UP] == 0)
				{
					Book5.position.y -= player.speed.y;
				}

				if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
				{
					Book5.position.y += player.speed.y;

				}


			}



			if (keys[DIK_A] == preKeys[DIK_A] == 0)
			{

				Book5.flag = false;

			}


			if (keys[DIK_S] == preKeys[DIK_S] == 0)
			{

				if (Book.position.x == Book5.position.x && Book.position.x == Book5.position.y)
				{

					flag = true;

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


				if (Book2.position.x == Book5.position.x && Book2.position.x == Book5.position.y)
				{

					Book2.flag = true;

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


			//Book6


			if (keys[DIK_SPACE] == preKeys[DIK_SPACE] == 0)
			{


				if (player.position.x == Book6.position.x - 5 && player.position.y == Book6.position.y - 5)
				{
					Book6.flag = true;
				}


			}


			if (Book6.flag == true)
			{

				player.position.x = Book6.position.x - 5;
				player.position.y = Book6.position.y - 5;


				if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
				{
					Book6.position.x -= player.speed.x;
				}

				if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
				{
					Book6.position.x += player.speed.x;
				}

				if (keys[DIK_UP] && preKeys[DIK_UP] == 0)
				{
					Book6.position.y -= player.speed.y;
				}

				if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
				{
					Book6.position.y += player.speed.y;

				}


			}



			if (keys[DIK_A] == preKeys[DIK_A] == 0)
			{

				Book6.flag = false;

			}

			/*
			if (keys[DIK_S] == preKeys[DIK_S] == 0)
			{

				if (Book.position.x == Book6.position.x && Book.position.x == Book6.position.y)
				{

					flag = true;

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


				if (Book2.position.x == Book6.position.x && Book2.position.x == Book6.position.y)
				{

					Book2.flag = true;

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
			*/


			//Book7


			if (keys[DIK_SPACE] == preKeys[DIK_SPACE] == 0)
			{


				if (player.position.x == Book7.position.x - 5 && player.position.y == Book7.position.y - 5)
				{
					Book7.flag = true;
				}


			}


			if (Book7.flag == true)
			{

				player.position.x = Book7.position.x - 5;
				player.position.y = Book7.position.y - 5;


				if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
				{
					Book7.position.x -= player.speed.x;
				}

				if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
				{
					Book7.position.x += player.speed.x;
				}

				if (keys[DIK_UP] && preKeys[DIK_UP] == 0)
				{
					Book7.position.y -= player.speed.y;
				}

				if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
				{
					Book7.position.y += player.speed.y;

				}


			}



			if (keys[DIK_A] == preKeys[DIK_A] == 0)
			{

				Book7.flag = false;

			}


			if (keys[DIK_S] == preKeys[DIK_S] == 0)
			{

				if (Book.position.x == Book7.position.x && Book.position.x == Book7.position.y)
				{

					flag = true;

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


				if (Book2.position.x == Book7.position.x && Book2.position.x == Book7.position.y)
				{

					Book2.flag = true;

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

			//Book8


			if (keys[DIK_SPACE] == preKeys[DIK_SPACE] == 0)
			{


				if (player.position.x == Book8.position.x - 5 && player.position.y == Book8.position.y - 5)
				{
					Book8.flag = true;
				}


			}


			if (Book8.flag == true)
			{

				player.position.x = Book8.position.x - 5;
				player.position.y = Book8.position.y - 5;


				if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
				{
					Book8.position.x -= player.speed.x;
				}

				if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
				{
					Book8.position.x += player.speed.x;
				}

				if (keys[DIK_UP] && preKeys[DIK_UP] == 0)
				{
					Book8.position.y -= player.speed.y;
				}

				if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
				{
					Book8.position.y += player.speed.y;

				}


			}



			if (keys[DIK_A] == preKeys[DIK_A] == 0)
			{

				Book8.flag = false;

			}


			if (keys[DIK_S] == preKeys[DIK_S] == 0)
			{

				if (Book.position.x == Book8.position.x && Book.position.x == Book8.position.y)
				{

					flag = true;

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


				if (Book2.position.x == Book8.position.x && Book2.position.x == Book8.position.y)
				{

					Book2.flag = true;

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

			//Book9


			if (keys[DIK_SPACE] == preKeys[DIK_SPACE] == 0)
			{


				if (player.position.x == Book9.position.x - 5 && player.position.y == Book9.position.y - 5)
				{
					Book9.flag = true;
				}


			}


			if (Book9.flag == true)
			{


				player.position.x = Book9.position.x - 5;
				player.position.y = Book9.position.y - 5;


				if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
				{

					Book9.position.x -= player.speed.x;

				}

				if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
				{

					Book9.position.x += player.speed.x;

				}

				if (keys[DIK_UP] && preKeys[DIK_UP] == 0)
				{

					Book9.position.y -= player.speed.y;

				}

				if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
				{

					Book9.position.y += player.speed.y;

				}


			}



			if (keys[DIK_A] == preKeys[DIK_A] == 0)
			{

				Book9.flag = false;

			}


			if (keys[DIK_S] == preKeys[DIK_S] == 0)
			{

				if (Book.position.x == Book9.position.x && Book.position.x == Book9.position.y)
				{

					flag = true;

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


				if (Book2.position.x == Book9.position.x && Book2.position.x == Book9.position.y)
				{

					Book2.flag = true;

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

			//Book10


			if (keys[DIK_SPACE] == preKeys[DIK_SPACE] == 0)
			{


				if (player.position.x == Book10.position.x - 5 && player.position.y == Book10.position.y - 5)
				{
					Book10.flag = true;
				}


			}


			if (Book10.flag == true)
			{

				player.position.x = Book10.position.x - 5;
				player.position.y = Book10.position.y - 5;


				if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
				{
					Book10.position.x -= player.speed.x;
				}

				if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
				{
					Book10.position.x += player.speed.x;
				}

				if (keys[DIK_UP] && preKeys[DIK_UP] == 0)
				{
					Book10.position.y -= player.speed.y;
				}

				if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
				{
					Book10.position.y += player.speed.y;

				}


			}



			if (keys[DIK_A] == preKeys[DIK_A] == 0)
			{

				Book10.flag = false;

			}


			if (keys[DIK_S] == preKeys[DIK_S] == 0)
			{

				if (Book.position.x == Book10.position.x && Book.position.x == Book10.position.y)
				{

					flag = true;

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


				if (Book2.position.x == Book10.position.x && Book2.position.x == Book10.position.y)
				{

					Book2.flag = true;

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



			timer++;
			if (timer >= 60)
			{
				count = 1;
			}
			if (timer >= 120)
			{
				count = 2;
			}
			if (timer >= 180)
			{
				count = 3;
			}


			if (Book.position.x== 150 && Book.position.y == 287&&
				Book2.position.x == 200 && Book2.position.y == 287&&
				Book3.position.x == 250 && Book3.position.y == 287&&
				Book4.position.x == 300 && Book4.position.y == 287&&
				Book5.position.x == 350 && Book5.position.y == 287&&
		        Book6.position.x == 400 && Book6.position.y == 287&&
		        Book7.position.x == 450 && Book7.position.y == 287&&
		        Book8.position.x == 500 && Book8.position.y == 287&&
		        Book9.position.x == 550 && Book9.position.y == 287&&
		        Book10.position.x == 600 && Book10.position.y == 287)
			{
			
				scene = 3;
			
			}



			if (timer >= 6000)
			{
				scene = 4;
			}


			break;


		case 3:

			

			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0)
			{
				
				scene = 0;

			}
			break;



		case 4:

			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0)
			{
				
				scene = 0;

			}


			break;


		}
		

		



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


		if (scene == 0)
		{

			Novice::DrawSprite(0, 0, start, 1, 1, 0.0f, WHITE);

		}

		else if (scene == 1)
		{

			Novice::DrawSprite(0, 0, explanation, 1, 1, 0.0f, WHITE);
		
		}

		

		else if (scene == 2)
		{

			Novice::DrawSprite(0, 0, view, 1, 1, 0.0f, WHITE);
			for (int i = 0; i < MAPX; i++)
			{
				for (int j = 0; j < MAPY; j++)
				{
					if (date[j][i] == block)
					{

						Novice::DrawBox(i * 32, j * 32 + 200, 35, 35, 0.0f, WHITE, kFillModeSolid);

					}
				}
			}

			//for (int i = 0; i < MAPX; i++)
			//{
			//	for (int j = 0; j < MAPY; j++)
			//	{
			//
			//		if (date[j][i] == 2)
			//		{
			//
			//			Novice::DrawBox(i * 32, j * 32, Book.radius.x, Book.radius.y, 0.0f, RED, kFillModeSolid);
			//
			//		}
			//
			//	}
			//}

			//for (int i = 0; i < MAPX; i++)
			//{
			//
			//	for (int j = 0; j < MAPY; j++)
			//	{
			//
			//		if (date[j][i] == block2)
			//		{
			//
			//			Novice::DrawSprite(i * 32+135, j * 32+192, BOOK2, 1, 1, 0.0f, WHITE);
			//
			//		}
			//
			//	}
			//
			//}

		   

			Novice::DrawSprite(player.position.x, player.position.y, grahHandle, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(Book.position.x, Book.position.y, Book1, 1,1, 0.0f, WHITE);
			Novice::DrawSprite(Book2.position.x, Book2.position.y, BOOK2,1,1, 0.0f, WHITE);
			Novice::DrawSprite(Book3.position.x, Book3.position.y, BOOK3,1,1, 0.0f, WHITE);
			Novice::DrawSprite(Book4.position.x, Book4.position.y, BOOK4, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(Book5.position.x, Book5.position.y, BOOK5, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(Book6.position.x, Book6.position.y, BOOK6, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(Book7.position.x, Book7.position.y, BOOK7, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(Book8.position.x, Book8.position.y, BOOK8, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(Book9.position.x, Book9.position.y, BOOK9, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(Book10.position.x, Book10.position.y, BOOK10, 1, 1, 0.0f, WHITE);




			Novice::DrawSprite(Mark1.position.x -5, Mark1.position.y-5, grahHandle, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(Mark2.position.x - 5, Mark2.position.y - 5, grahHandle, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(Mark3.position.x - 5, Mark3.position.y - 5, grahHandle, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(Mark4.position.x - 5, Mark4.position.y - 5, grahHandle, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(Mark5.position.x - 5, Mark5.position.y - 5, grahHandle, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(Mark6.position.x - 5, Mark6.position.y - 5, grahHandle, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(Mark7.position.x - 5, Mark7.position.y - 5, grahHandle, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(Mark8.position.x - 5, Mark8.position.y - 5, grahHandle, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(Mark9.position.x - 5, Mark9.position.y - 5, grahHandle, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(Mark10.position.x - 5, Mark10.position.y - 5, grahHandle, 1, 1, 0.0f, WHITE);




			timer++;


			if (countflag == false)
			{
				Novice::DrawSprite(350, 0, count12, 1, 1, 0.0f, WHITE);
			}


			if (timer >= 3000 && countflag2 == false)
			{
				countflag = true;
				Novice::DrawSprite(350, 0, count11, 1, 1, 0.0f, WHITE);

			}

			if (timer >= 5000 && countflag3 == false)
			{
				countflag2 = true;
				Novice::DrawSprite(350, 0, count10, 1, 1, 0.0f, WHITE);

			}
			if (timer >= 5100 && countflag4 == false)
			{
				countflag3 = true;
				Novice::DrawSprite(350, 0, count9, 1, 1, 0.0f, WHITE);

			}
			if (timer >= 5200 && countflag5 == false)
			{
				countflag4 = true;
				Novice::DrawSprite(350, 0, count8, 1, 1, 0.0f, WHITE);

			}
			if (timer >= 5300 && countflag6 == false)
			{
				countflag5 = true;
				Novice::DrawSprite(350, 0, count7, 1, 1, 0.0f, WHITE);

			}
			if (timer >= 5400 && countflag7 == false)
			{
				countflag6 = true;
				Novice::DrawSprite(350, 0, count6, 1, 1, 0.0f, WHITE);

			}

			if (timer >= 5500 && countflag8 == false)
			{

				countflag7 = true;
				Novice::DrawSprite(350, 0, count5, 1, 1, 0.0f, WHITE);

			}

			if (timer >= 5600 && countflag9 == false)
			{
				countflag8 = true;
				Novice::DrawSprite(350, 0, count4, 1, 1, 0.0f, WHITE);

			}
			if (timer >= 5700 && countflag10 == false)
			{
				countflag9 = true;
				Novice::DrawSprite(350, 0, count3, 1, 1, 0.0f, WHITE);

			}

			if (timer >= 5800 && countflag11 == false)
			{

				countflag10 = true;
				Novice::DrawSprite(350, 0, count2, 1, 1, 0.0f, WHITE);


			}

			if (timer >= 5900 && countflag12 == false)
			{

				countflag11 = true;
				Novice::DrawSprite(350, 0, count1, 1, 1, 0.0f, WHITE);

			}

			if (timer >= 6000 && countflag13 == false)
			{

				countflag12 = true;
				Novice::DrawSprite(350, 0, count0, 1, 1, 0.0f, WHITE);

			}


			if (timer >= 6000)

			{

				scene = 4;
			}
		}
		else if (scene == 3)
		{

			Novice::DrawSprite(0, 0, Cleare, 1, 1, 0.0f, WHITE);

		}
		else if (scene == 4)
		{

			Novice::DrawSprite(0, 0, GameOver, 1, 1, 0.0f, WHITE);

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
