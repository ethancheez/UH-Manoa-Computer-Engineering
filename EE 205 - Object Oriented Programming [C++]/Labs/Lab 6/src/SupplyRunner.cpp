#include "Storeroom.hpp"
#include "Ingredient.hpp"
#include "SupplyRunner.hpp"

#include <string>
#include <vector>
#include <map>

using namespace std;

SupplyRunner::SupplyRunner(Storeroom& storeroom_) :
    storeroom(storeroom_) {}

vector<Ingredient> SupplyRunner::get_ingredients(IngredientMap ingredients) {
    vector<Ingredient> avail_Ingredients;

    map<string, int>::iterator find;
    for(auto find = ingredients.begin(); find != ingredients.end(); find++) {
        if(storeroom.find(find->first) == storeroom.end()) {
            throw "Ingredient not Found";
        } else if(find->second > storeroom[find->first]) {
            throw "Not enough Ingredients";
        }
    }

    for(auto find = ingredients.begin(); find != ingredients.end(); find++) {
        for(int i = 0; i < find->second; i++) {
            storeroom[find->first]--;
            avail_Ingredients.push_back(find->first);
        }
    }

    return avail_Ingredients;
}