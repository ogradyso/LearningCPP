//#define OLC_PGE_APPLICATION
//#include "olcPixelGameEngine.h"
//
//class BreakOut : public olc::PixelGameEngine
//{
//public:
//	BreakOut()
//	{
//		sAppName = "Tutorial - BreakOut Clone";
//	}
//
//private:
//	float fBatPos = 20.0f;
//	float fBatWidth = 40.0f;
//
//	olc::vf2d vBall = { 200.0f, 200.0f };
//	olc::vf2d vBallVel = { 200.0f, -100.0f };
//	float fBatSpeed = 250.0f;
//	float fBallRadius = 5.0f;
//
//public:
//	bool OnUserCreate() override
//	{
//		// Called once at the start, so create things here
//		srand(100);
//		return true;
//	}
//
//	bool OnUserUpdate(float fElapsedTime) override
//	{
//
//		// Handle User Input
//		if (GetKey(olc::Key::LEFT).bHeld) fBatPos -= fBatSpeed * fElapsedTime;
//		if (GetKey(olc::Key::RIGHT).bHeld) fBatPos += fBatSpeed * fElapsedTime;
//
//		if (fBatPos < 11.0f) fBatPos = 11.0f;
//		if (fBatPos + fBatWidth > float(ScreenWidth()) - 10.0f) fBatPos = float(ScreenWidth()) - 10.0f - fBatWidth;
//
//		//Update ball
//		vBall += vBallVel * fElapsedTime;
//
//		//arena detection
//		if (vBall.y <= 10.0f) vBallVel.y *= -1.0f;
//		if (vBall.x <= 10.0f) vBallVel.x *= -1.0f;
//		if (vBall.x >= float(ScreenWidth()) - 10.0f) vBallVel.x *= -1.0f;
//
//		//Check bat 
//		if (vBall.y >= (float(ScreenHeight()) - 20.0f) && (vBall.x > fBatPos) && (vBall.x < fBatPos + fBatWidth))
//			vBallVel.y *= -1.0f;
//
//		//check if ball has gone off screen
//		if (vBall.y > ScreenHeight())
//		{
//			//Reset ball location
//			vBall = { 200.0f, 200.0f };
//			//choose random direction
//			float fAngle = (float(rand()) / float(RAND_MAX)) * 2.0f * 3.14159f;
//			vBallVel = { 300.0f * cos(fAngle), 300.0f * sin(fAngle) };
//		}
//
//		Clear(olc::DARK_BLUE);
//
//		//Boundary
//		DrawLine(10, 10, ScreenWidth()-10, 10, olc::YELLOW);
//		DrawLine(10, 10, 10, ScreenHeight()-10, olc::YELLOW);
//		DrawLine(ScreenWidth() -10, 10, ScreenWidth() -10, ScreenHeight() -10, olc::YELLOW);
//		DrawLine(10, ScreenHeight() - 10, ScreenWidth() - 10, ScreenHeight() - 10, olc::YELLOW);
//
//		FillRect(15,15,50,10, olc::DARK_RED);
//		FillRect(75, 15, 50, 10, olc::MAGENTA);
//
//		//draw bat
//		FillRect(int(fBatPos), ScreenHeight() - 20, int(fBatWidth), 10, olc::GREEN);
//
//		//draw ball
//		FillCircle(vBall, 5, olc::CYAN);
//
//		return true;
//	}
//};
//
//
//int main()
//{
//	BreakOut demo;
//	if (demo.Construct(512, 480, 2, 2))
//		demo.Start();
//	return 0;
//}