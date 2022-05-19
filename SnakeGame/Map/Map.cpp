#include "Map.h"
#include <string>
#include <vector>
#include <fstream>

struct Position
{
    int x, y;

    // 구조체 생성자
    Position() : x(0), y(0) {}
    Position(int col, int row) : x(col), y(row) {}
};

class Stage
{
public:
    int nowStage = 0;
    bool clear;

    Stage()
    {
    }

    ~Stage()
    {
    }

    int getNowStage() { return nowStage; }

    void setNowStage(int nowStage) { this->nowStage = nowStage; }

    void Update(float eTime)
    {
    }

    void Render()
    {
    }

};

Stage* stage;

Map::Map() // load txt file. named stageName. ex) 1.txt 2.txt 3.txt 4.txt
{
}

Map::~Map()
{
}

void Map::Load()
{

    std::ifstream readFile;
    std::string src = "map/map" + std::to_string(stage->getNowStage() + 1) + ".txt"; // 읽어들일 파일 이름 

    readFile.open(src);
    int height = 0;

    while (!readFile.eof())  // 파일을 읽는 동안
    {
        char temp[120];
        readFile.getline(temp, 120);

        for (int i = 0; i < WIDTH; i++)
        {
            data[height][i] = temp[i];
        }

        height++;
    }
}

void* Map::GetData()
{
    return data;
}

void Map::PatchData(int y, int x, char patchData)
{
    data[y][x] = patchData;
}

void Map::Render()
{
}

void Map::Update(float eTime)
{
}

