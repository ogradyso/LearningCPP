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
	float fBatSpeed = 250.0f;

	olc::vf2d vBallPos = { 0.0f, 0.0f };
	olc::vf2d vBallDir = { 0.0f; 0.0f };
	float fBallSpeed = 20.0f;
	float fBallRadius = 5.0f;

	olc::vi2d vBlockSize = { 16, 16 };
	std::unique_ptr<int[]> blocks;

	std::unique_ptr<olc::Sprite> sprTile;

public:
	bool OnUserCreate() override
	{
		blocks = std::make_unique<int[]>(24 * 30);
		for (int y = 0; y < 30; y++)
		{
			for (int x = 0; x < 24; x++)
			{
				if (x == 0 || y == 0 || x == 23)
					blocks[y * 24 + x] = 10;
				else
					blocks[y * 24 + x] = 0;

				if (x > 2 && x <= 20 && y > 3 && y <= 5)
					blocks[y * 24 + x] = 1;
				if (x > 2 && x <= 20 && y > 5 && y <= 7)
					blocks[y * 24 + x] = 2;
				if (x > 2 && x <= 20 && y > 7 && y <= 9)
					blocks[y * 24 + x] = 3;
			}
		}
		//load sprite
		sprTile = std::make_unique<olc::Sprite>("./gfx/tut_tiles.png");

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		//calculate where ball should be, if no collision
		olc::vf2d vPotentialBallPos = vBallPos + vBallDir * fBallSpeed * fElapsedTime;

		//test for hits 4 points around ball
		olc::vf2d vTileBallRadialDims = { fBallRadius / vBlockSize.x, fBallRadius / vBlockSize.y };

		auto TestResolveCollisionReport = [&](const olc::vf2d& point) {
			olc::vi2d vTestPoint = vPotentialBallPos + vTileBallRadialDims * point;
			auto& tile = blocks[vTestPoint.y * 24 + vTestPoint.x];
			if (tile == 0)
			{
				//Do nothing, no collision
				return false;
			}
			else
			{
				//Ball has collided with a tile
				bool bTileHit = tile < 10;
				if (bTileHit) tile--;

				//Collision response
				if (point.x == 0.0f)
					vBallDir.y *= -1.0f;
				if (point.y == 0.0f)
					vBallDir.x *= -1.0f;
				return bTileHit;
			}
		};

		Clear(olc::DARK_BLUE);
		SetPixelMode(olc::Pixel::MASK);
		for (int y = 0; y < 30; y++)
		{
			for (int x = 0; x < 24; x++) {
				switch (blocks[y * 24 + x]) 
				{
				case 0: // do nothing
					break;
				case 10:
					DrawPartialSprite(olc::vi2d(x, y) * vBlockSize, sprTile.get(), olc::vi2d(0, 0) * vBlockSize, vBlockSize);
					break;
				case 1: //draw red block
					DrawPartialSprite(olc::vi2d(x, y) * vBlockSize, sprTile.get(), olc::vi2d(1, 0) * vBlockSize, vBlockSize);
					break;
				case 2:
					DrawPartialSprite(olc::vi2d(x, y) * vBlockSize, sprTile.get(), olc::vi2d(2, 0) * vBlockSize, vBlockSize);
					break;
				case 3:
					DrawPartialSprite(olc::vi2d(x, y) * vBlockSize, sprTile.get(), olc::vi2d(3, 0) * vBlockSize, vBlockSize);
					break;
				}
			}
		}
		SetPixelMode(olc::Pixel::NORMAL);
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