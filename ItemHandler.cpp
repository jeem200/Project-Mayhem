#include "tinyxml\tinystr.h";
#include "tinyxml\tinyxml.h"
#include "Graphics.h"
#include "ItemHandler.h"
#include "Inventory.h"

ItemHandler::ItemHandler()
{
	// Load all different items
	TiXmlDocument doc("items.xml");
	doc.LoadFile();

	// Get the root element
	TiXmlElement* root = doc.FirstChildElement();

	// Load items from the file
	for(TiXmlElement* item = root->FirstChildElement("Item"); item != NULL; item = item->NextSiblingElement("Item"))
	{
		ItemData ItemData;
		ItemData.name = item->Attribute("name") == NULL ? "#NOVALUE" : item->Attribute("name");
		ItemData.armor = item->Attribute("armor") == NULL ? 0 : atoi(item->Attribute("armor"));
		ItemData.health = item->Attribute("health") == NULL ? 0 : atoi(item->Attribute("health"));
		ItemData.mana = item->Attribute("mana") == NULL ? 0 : atoi(item->Attribute("mana"));
		ItemData.weight = item->Attribute("weight") == NULL ? 0 : atoi(item->Attribute("weight"));
		ItemData.damage = item->Attribute("damage") == NULL ? 0 : atoi(item->Attribute("damage"));
		ItemData.textureSource = item->Attribute("texture");

		if(item->Attribute("texture") != NULL)
			ItemData.texture = gGraphics->loadTexture(item->Attribute("texture"));
		else
			ItemData.texture = NULL;

		SlotId slotId;
		string slot = item->Attribute("slot");
		if(slot == "head") slotId = HEAD;
		else if(slot == "weapon") slotId = WEAPON;
		else if(slot == "chest") slotId = CHEST;
		else if(slot == "legs") slotId = LEGS;
		else if(slot == "shield") slotId = SHIELD;
		else if(slot == "misc1") slotId = MISC1;
		else if(slot == "misc2") slotId = MISC2;

		ItemData.slot = slotId;

		mDataMap[item->Attribute("name")] = ItemData;
	}
}
	
ItemHandler::~ItemHandler()
{

}

ItemData ItemHandler::getData(string name)
{
	// Return the attributes
	return mDataMap[name];
}

map<string, ItemData> ItemHandler::getDataMap()
{
	return mDataMap;
}