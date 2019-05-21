#ifndef HEXADOKU_SECTIONVIEW_HPP
#define HEXADOKU_SECTIONVIEW_HPP

#include "AbstractView.hpp"
#include <vector>
#include <Model/BoardSection.hpp>

class SectionView : public AbstractView {
public:
    explicit SectionView(BoardSection boardSection);

    void Draw() const override;

private:
    BoardSection section;
    int size;

    void DrawGrid() const;
};

#endif //HEXADOKU_SECTIONVIEW_HPP
