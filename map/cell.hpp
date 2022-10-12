#ifndef CELL_HPP
#define CELL_HPP

class Cell{
private:
    bool isPassable;
public:
    Cell(bool passable = true);
    void set_passable(bool passable);
    bool is_passable() const;
    ~Cell();
};

#endif