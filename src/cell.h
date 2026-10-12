#pragma once

#include <memory>
#include <vector>

enum Direction { none, up, down, left, right };

struct Point {
    int x, y;
};

class Cell {
public:
    std::weak_ptr<Cell> NextCell;
private:
    Point point;
    bool isStart = false;
    std::vector<std::weak_ptr<Cell>> neighboredCells;

public:
    Cell(Point point, bool isStart);

    void AddNeighboredCell(std::shared_ptr<Cell> cell);

    std::vector<std::weak_ptr<Cell>> & GetNeighboredCells();

    Direction GetDirectionTo(Point point);
};