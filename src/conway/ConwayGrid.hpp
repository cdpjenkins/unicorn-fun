
#ifndef CONWAY_GRID_H
#define CONWAY_GRID_H

constexpr int GRID_WIDTH  = 32;
constexpr int GRID_HEIGHT = 32;

class ConwayGrid {
public:
    int width = GRID_WIDTH;
    int height = GRID_HEIGHT;
    bool running;
    int generation = 0;

    ConwayGrid();
    void init_to_blank();

    void print();
    void step();
    void run();
    void pause();

    void invert_cell(int grid_x, int grid_y);

    inline bool cell_alive_at(int x, int y) {
        return current_grid[grid_index(x, y)];
    }

private:
    bool grid1[GRID_WIDTH * GRID_HEIGHT];
    bool grid2[GRID_WIDTH * GRID_HEIGHT];
    bool* current_grid;
    bool* next_grid;

    int num_living_neighbours(int x, int y);

    inline void set_cell(bool* grid, int x, int y, bool value) {
        current_grid[grid_index(x, y)] = value;
    }

    inline int grid_index(int column, int row) {
        return row * width + column;
    }
};

#endif // CONWAY_GRID_H
