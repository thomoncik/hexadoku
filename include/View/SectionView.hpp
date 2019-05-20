#ifndef HEXADOKU_SECTIONVIEW_HPP
#define HEXADOKU_SECTIONVIEW_HPP

#include "AbstractView.hpp"
#include <vector>

class SectionView : public AbstractView {
public:
    SectionView(int size, std::vector<int> values, int x, int y);

    void Draw() override;

private:
    std::vector<int> values;
    int size;
    int x;
    int y;
};

#endif //HEXADOKU_SECTIONVIEW_HPP
