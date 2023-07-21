#include <Novice.h>
#include"MyMatrix4x4.h"
#include"MatrixScreenPrintf.h"
#include"MyVector3.h"
#include"VectorScreenPrintf.h"
#include"calc.h"
#include"Grid.h"
#include"Sphere.h"
#include<imgui.h>
#include"Line.h"
#include"Collision.h"
#include"Camera.h"
#include"Plane.h"
#include"Triangle.h"
#include"AABB.h"
#include"OBB.h"
#include"Draw.h"

const char kWindowTitle[] = "学籍番号";

const int kWindowWidth = 1280;
const int kWindowHeight = 720;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	MyVector3 a{ 0.2f,1.0f,0.0f };
	MyVector3 b{ 2.4f,3.1f,1.2f };
	MyVector3 c = a + b;
	MyVector3 d = a - b;
	MyVector3 e = a * 2.4f;
	MyVector3 f = a / 2.0f;
	MyVector3 rotate{ 0.4f,1.43f,-0.8f };
	MyMatrix4x4 rotateX = MyMatrix4x4::MakeRotateXMatrix(rotate.x);
	MyMatrix4x4 rotateY = MyMatrix4x4::MakeRotateYMatrix(rotate.y);
	MyMatrix4x4 rotateZ = MyMatrix4x4::MakeRotateZMatrix(rotate.z);
	MyMatrix4x4 rotateMat = rotateX * rotateY * rotateZ;
	MyVector3 g1 = MyMatrix4x4::Multiply(a, rotateMat);
	MyVector3 g2 = a * rotateMat;

	
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
		
		ImGui::Begin("Window");
		ImGui::Text("c:%f,%f,%f", c.x, c.y, c.z);
		ImGui::Text("d:%f,%f,%f", d.x, d.y, d.z);
		ImGui::Text("e:%f,%f,%f", e.x, e.y, e.z);
		ImGui::Text("f:%f,%f,%f", f.x, f.y, f.z);
		ImGui::Text("g1:%f,%f,%f", g1.x, g1.y, g1.z);
		ImGui::Text("g2:%f,%f,%f", g2.x, g2.y, g2.z);
		ImGui::Text("matrix:\n%f,%f,%f,%f\n%f,%f,%f,%f\n%f,%f,%f,%f\n%f,%f,%f,%f",
			rotateMat.m[0][0], rotateMat.m[0][1], rotateMat.m[0][2], rotateMat.m[0][3],
			rotateMat.m[1][0], rotateMat.m[1][1], rotateMat.m[1][2], rotateMat.m[1][3],
			rotateMat.m[2][0], rotateMat.m[2][1], rotateMat.m[2][2], rotateMat.m[2][3],
			rotateMat.m[3][0], rotateMat.m[3][1], rotateMat.m[3][2], rotateMat.m[3][3]);
		ImGui::End();

		

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		

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
