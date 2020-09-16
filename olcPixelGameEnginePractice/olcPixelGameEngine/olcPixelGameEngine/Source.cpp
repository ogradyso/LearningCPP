#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class BreakOut : public olc::PixelGameEngine
{
public:
	BreakOut()
	{
		sAppName = "Tutorial - BreakOut Clone";
	}

private:
	float fBatPos = 20.0f;
	float fBatWidth = 40.0f;

	olc::vf2d vBall = { 200.0f, 200.0f };
	float fBatSpeed = 0.1f;

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::DARK_BLUE);

		// Handle User Input
		if (GetKey(olc::Key::LEFT).bHeld) fBatPos -= fBatSpeed;
		if (GetKey(olc::Key::RIGHT).bHeld) fBatPos += fBatSpeed;

		if (fBatPos < 11.0f) fBatPos = 11.0f;
		if (fBatPos + fBatWidth > float(ScreenWidth()) - 10.0f) fBatPos = float(ScreenWidth()) - 10.0f - fBatWidth;

		//Boundary
		DrawLine(10, 10, ScreenWidth()-10, 10, olc::YELLOW);
		DrawLine(10, 10, 10, ScreenHeight()-10, olc::YELLOW);
		DrawLine(ScreenWidth() -10, 10, ScreenWidth() -10, ScreenHeight() -10, olc::YELLOW);
		DrawLine(10, ScreenHeight() - 10, ScreenWidth() - 10, ScreenHeight() - 10, olc::YELLOW);

		FillRect(15,15,50,10, olc::DARK_RED);
		FillRect(75, 15, 50, 10, olc::MAGENTA);

		//draw bat
		FillRect(int(fBatPos), ScreenHeight() - 20, int(fBatWidth), 10, olc::GREEN);

		//draw ball
		FillCircle(vBall, 5, olc::CYAN);

		return true;
	}
};


int main()
{
	BreakOut demo;
	if (demo.Construct(512, 480, 2, 2))
		demo.Start();
	return 0;
}