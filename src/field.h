#pragma once

#include <memory>
#include <vector>

class Cell;

enum CellType { empty=0, cell=1, startCell=2 };

struct ReturnPoint {
    std::weak_ptr<Cell> ReturnCell;
    int NextNeighboredCellIndex;
};

class Field {
private:
    std::vector<std::shared_ptr<Cell>> cells;
    int width, height;

    std::vector<ReturnPoint> returnPoints;
public:
    Field(int width, int height);

    bool FindPath();
    bool InitializeCells(CellType *cellTypes);
};