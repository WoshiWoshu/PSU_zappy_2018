/*
** EPITECH PROJECT, 2018
** $NAME_OF_THE_PROJECT
** File description:
** Here is coded a super function
*/

#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_

class Inventory {
  public:
    Inventory();
    ~Inventory();
    void setLinemate(int v) { _linemate = v;};
    void setDeraumere(int v) { _deraumere = v;};
    void setSibur(int v) { _sibur = v;};
    void setMendiane(int v) { _mendiane = v;};
    void setPhiras(int v) {  _phiras = v;};
    void setThystame(int v) { _thystame = v;};
    int getLinemate() const { return _linemate;};
    int getDeraumere() const { return _deraumere;};
    int getSibur() const { return _sibur;};
    int getMendiane() const { return _mendiane;};
    int getPhiras() const { return _phiras;};
    int getThystame() const { return _thystame;};

  private:
    int _linemate;
    int _deraumere;
    int _sibur;
    int _mendiane;
    int _phiras;
    int _thystame;
};

#endif
