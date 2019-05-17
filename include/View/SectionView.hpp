#ifndef HEXADOKU_SECTIONVIEW_HPP
#define HEXADOKU_SECTIONVIEW_HPP

#include "AbstractView.hpp"

class SectionView : public AbstractView {
public:
    void Draw(int x, int y) override;
};

#endif //HEXADOKU_SECTIONVIEW_HPP
