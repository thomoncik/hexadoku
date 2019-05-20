//
// Created by Jakub Kiermasz on 2019-05-11.
//

#ifndef HEXADOKU_BOARDCELL_HPP
#define HEXADOKU_BOARDCELL_HPP


class BoardCell {
public:
    static const int EMPTY_VALUE;
    BoardCell();
    void SetValue(int value);
    int GetValue() const;
    void SetSelected(bool isSelected);
    void SetIsCorrect(bool isCorrect);
private:
    int value;
    bool isSelected;
    bool isCorrect;
};


#endif //HEXADOKU_BOARDCELL_HPP
