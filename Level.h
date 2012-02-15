#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include "enums.h"
#include "Vector.h"

using namespace std;

class Player;
class Tile;
class TileHandler;
class Object;

class Level
{
public:
	Level();
	~Level();

	void init();
	void update(float dt);
	void draw();

	void saveToFile(string file);
	void loadFromFile(string file);

	void addObject(Object* object);
	void addPlayer(Player* player);
	void removeObject(Object* object);
	void removeObjectAt(float x, float y);
	void moveObjects(float dx, float dy);

	void addTile(float x, float y, string name);
	void removeTile(float x, float y);

	void addProjectile(Object* shooter, Vector target, int spread = 0);
	TileHandler* getTileHandler();
	string getTile(int x, int y);
	int getTileWidth();
	int getTileHeight();
	Vector getOffset();
	Object* getObjectAt(Vector pos);
	Player* getPlayer();
	bool isInEditor() {return mEditorMode;}

	void setInEditor(bool b) { mEditorMode = b;}

private:
	std::vector<Object*>	mObjectList;
	std::vector<Tile*>		mTileList;
	TileHandler*			mTileHandler;		// NOTE: Maybe combine TileHandler and the tile array
	Player*					mPlayer;
	Vector					mOffset;		// TODO: Use this for all objects!
	Vector					mCameraOffset;
	bool					mEditorMode;

	int mWidth, mHeight;
	int mTileWidth, mTileHeight;
};	// Class

#endif