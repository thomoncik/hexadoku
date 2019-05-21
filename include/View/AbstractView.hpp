#ifndef HEXADOKU_ABSTRACTVIEW_HPP
#define HEXADOKU_ABSTRACTVIEW_HPP

class AbstractView {
public:
    virtual void Draw() const = 0;

    void SetPosition(int x, int y);

protected:
    int x{0};
    int y{0};
};

#endif //HEXADOKU_ABSTRACTVIEW_HPP
