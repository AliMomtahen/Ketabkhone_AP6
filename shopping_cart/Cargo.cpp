#include"Cargo.hpp"





Cargo::Cargo(int _id){
    id = _id;
    is_in_box = false;
    is_a_box = false;
    weight = 0;
}

int Cargo::my_price(){
    return 0;
}

int Cargo::total_price(){
    return 0;
}


int  Cargo::my_weight(){
    return weight;
}


Box::Box(int _id) : Cargo(_id){
    is_a_box = true;
}

int Box::my_price(){
    int total = 0;
    for(int i=0 ; i < my_cargos.size() ; i++){
        total += my_cargos[i]->my_price();
    }
    return total;
}

void Box::add_cargo(Cargo * new_cargo){
    my_cargos.push_back(new_cargo);
}

int Box::total_price(){
    int total_weight = 0;
    int total_cost = 0;
    for(int i=0 ; i < my_cargos.size() ; i++){
        std::cout << total_weight << "weight \n";
        total_weight += my_cargos[i]->my_weight();
    }
    for(int i=0 ; i < my_cargos.size() ; i++){
        std::cout << total_cost << "cost \n";
        
        total_cost += my_cargos[i]->my_price();
    }
    int weight_cost;
    if(total_weight >= 20){
        weight_cost = total_weight / 10;
    }
    else{
        weight_cost = total_weight / 2;
    }
    return total_cost + weight_cost;
}


int Box::my_weight(){
    int total = 0;
    for(int i=0 ; i < my_cargos.size() ; i++){
        total += my_cargos[i]->my_weight();
    }
    return total;
}






Item::Item(int _id , int _weight , int _cost) : Cargo( _id ) {
    weight = _weight;
    cost = _cost;
     is_a_box =false;   

}

int Item::my_price(){
    return cost;
}

