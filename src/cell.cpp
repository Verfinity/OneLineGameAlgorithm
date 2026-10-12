#include "cell.h"

Cell::Cell(Point point, bool isStart) {
    this->point = point;
    this->isStart = isStart;
}

void Cell::AddNeighboredCell(std::shared_ptr<Cell> cell) {
    this->neighboredCells.push_back(cell);
}

std::vector<std::weak_ptr<Cell>> & Cell::GetNeighboredCells() {
    return this->neighboredCells;
}

Direction Cell::GetDirectionTo(Point point) {
    if (this->point.x != point.x && this->point.y != point.y) {
        return none;
    }
    
    if (this->point.y < point.y) {
        return down;
    } else if (this->point.y > point.y) {
        return up;
    }

    if (this->point.x < point.x) {
        return right;
    } else if (this->point.x > point.x) {
        return left;
    }

    return none;
}