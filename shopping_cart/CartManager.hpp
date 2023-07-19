#ifndef CARTMANAGER_HPP
#define CARTMANAGER_HPP



#include<iostream>
#include<string>
#include<vector>
#include"Cargo.hpp"


class CartManager {
public:
    CartManager();
    ~CartManager();
    void add_item(int id, int cost, int weight);
    void add_box(int id);
    void add_to_box(int box_id, int id);
    int evaluate_cart();
    Cargo * find_cargo(int id);
private:
    std::vector<Cargo *> cargoes;

};








#endif