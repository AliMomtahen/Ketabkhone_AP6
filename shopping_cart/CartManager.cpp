#include"CartManager.hpp"




CartManager::CartManager(){

}

CartManager::~CartManager(){

}


Cargo * CartManager::find_cargo(int id){
    for(int i=0 ; i < cargoes.size() ; i++){
        if(id == cargoes[i]->get_id()){
            return cargoes[i];
        }
    }
    return NULL;
}



void CartManager::add_item(int id, int cost, int weight){
    Cargo *cargo = find_cargo(id);
    if( cargo != NULL){
        std::cout << ID_UNIQ_ERROR << '\n';
        exit(EXIT_SUCCESS);
    }
    cargoes.push_back(new Item(id , weight , cost));

}


void CartManager::add_box(int id){
    Cargo *cargo = find_cargo(id);
    if( cargo != NULL){
        std::cout << ID_UNIQ_ERROR << '\n';
        exit(EXIT_SUCCESS);
    }
    cargoes.push_back(new Box(id));
}

void CartManager::add_to_box(int box_id, int id){
    Cargo *box = find_cargo(box_id);
    Cargo *cargo = find_cargo(id);
    if(!box->is_a_box){
        std::cout << BOX_ERROR << '\n';
        exit(EXIT_SUCCESS);
    }
    if(box == NULL || cargo == NULL){
        std::cout << ID_ERROR << '\n';
        exit(EXIT_SUCCESS);
    }
    box->add_cargo(cargo);
    cargo->is_in_box = true;

}

int CartManager::evaluate_cart(){
    int total_cart = 0; 
    for(int i=0 ; i < cargoes.size() ; i++){
        if(!cargoes[i]->is_in_box){
            std::cout << total_cart << "  " << cargoes[i]->get_id() << '\n';
            total_cart += cargoes[i]->total_price();
        }
    }
    return total_cart;
}



