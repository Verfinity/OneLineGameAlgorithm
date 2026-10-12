#pragma once

#include <memory>
#include <vector>

class Cell {
public:
    std::weak_ptr<Cell> NextCell;
private:
    int x, y;
    bool isFinish = false;
    std::vector<std::weak_ptr<Cell>> neighboredCells;

public:
    Cell(bool isFinish, short x, short y);

    void AddNeighboredCell(std::shared_ptr<Cell> cell);

    std::vector<std::weak_ptr<Cell>> & GetNeighboredCells();
};