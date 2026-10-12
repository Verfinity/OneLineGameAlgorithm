#include "field.h"
#include "cell.h"

#include <vector>
#include <memory>

Field::Field(int width, int height) {
    this->width = width;
    this->height = height;
}

bool Field::InitializeCells(CellType *cellsTypes) {
    bool hasStart = false;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; j++) {
            if (cellsTypes[i*height+j] == empty) {
                continue;
            }

            // is start
            bool isStart = cellsTypes[i*height+j] == startCell;
            if (isStart && hasStart) {
                this->cells.clear();
                return false;
            }
            hasStart = true;
            
            std::shared_ptr<Cell> cell = std::make_shared<Cell>(Point{j, i}, isStart);

            if (j > 0 && cellsTypes[i*height+j-1] != empty) {
                auto lastCell = this->cells.back();
                lastCell->AddNeighboredCell(cell);
                cell->AddNeighboredCell(lastCell);
            }

            this->cells.push_back(cell);
            cellsTypes[i*height+j] = (CellType)this->cells.size();
        }
    }
}