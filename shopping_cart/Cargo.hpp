#ifndef CARGO_HPP
#define CARGO_HPP

#include<iostream>
#include<string>
#include<vector>


const std::string ID_ERROR = "Not found in cart";
const std::string ID_UNIQ_ERROR = "Item already exists in cart";
const std::string BOX_ERROR = "Not a box";



class Cargo{
protected:
    int id;
    int weight;

public:
    Cargo(int _id);
    bool is_in_box;
    int get_id(){ return id;}
    virtual int total_price();
    virtual int my_weight();
    virtual int my_price();
    bool is_a_box;
    virtual void add_cargo(Cargo * new_cargo){ }

};





class Box : public Cargo{
private:
    std::vector<Cargo *> my_cargos;

public:
    Box(int _id);
    virtual int total_price();
    virtual int my_weight();
    virtual int my_price();
    virtual void add_cargo(Cargo * new_cargo);
    

};


class Item : public Cargo{
private:
    int cost;
public:
    Item(int _id , int _weight , int _cost);
    virtual int my_price();
};
















#endif

