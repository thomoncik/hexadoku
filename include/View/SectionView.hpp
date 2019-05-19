#ifndef HEXADOKU_SECTIONVIEW_HPP
#define HEXADOKU_SECTIONVIEW_HPP

#include "AbstractView.hpp"

class SectionView : public AbstractView {
public:
    SectionView(int size, int x, int y);

    void Draw() override;

private:
    int size;
    int x;
    int y;
};

#endif //HEXADOKU_SECTIONVIEW_HPP
