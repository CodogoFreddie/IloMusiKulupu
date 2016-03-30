#pragma once

#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <sstream>

#include <Math/pow.h>

namespace generator{

template<class Type, size_t order, size_t dictSize>
class Markov{
private:
    std::vector<int> probabilityLookup;
    std::vector<int> totalProbabilityLookup;

    const std::vector<Type> dictionary;
    const Type starter;
    const Type ender;

    std::vector<Type> workingSpace;

    std::unordered_map<int, Type> indexToLanguage;
    std::unordered_map<Type, int> languageToIndex;

    size_t minSize = 0, maxSize = 0;

    int instToIndexTotal(const Type chunk[order - 1]){
        int acc = 0;
        int exponent = order - 2;
        for(int i = 0; i < order - 1; i++){
            Type x = chunk[i];
            acc += math::ipow(dictSize, exponent--) * languageToIndex[x];
        }
        return acc;
    }

    int instToIndex(const Type chunk[order]){
        int acc = 0;
        int exponent = order - 1;
        for(int i = 0; i < order; i++){
            Type x = chunk[i];
            acc += math::ipow(dictSize, exponent--) * languageToIndex[x];
        }
        return acc;
    }

    Type indexToInst(int index){
        // workingSpace.resize(0);
        workingSpace.resize(order, starter);
        int i = order - 1;
        while(index != 0){
            int lsf = index % dictSize;
            index = index / dictSize;
            workingSpace[i--] = indexToLanguage[lsf];
        }
        return workingSpace[order - 1];
    }

public:
    Markov(const Type* dictionary_):
            dictionary(dictionary_, dictionary_ + dictSize),
            starter(*dictionary.begin()),
            ender(*(--dictionary.end())),
            probabilityLookup(math::ipow(dictSize, order)),
            totalProbabilityLookup(math::ipow(dictSize, order - 1)){

        for(int i = 0; i < dictionary.size(); i++){
            indexToLanguage[i] = dictionary[i];
            languageToIndex[dictionary[i]] = i;
        }
    }

    ~Markov(){}

    void trainOnInstance(const Type* inst, const int length){
        workingSpace.reserve(length + (order * 2));
        workingSpace.resize(0);
        for(int i = 0; i < order - 1; i++){
            workingSpace.push_back(starter);
        }
        for(int i = 0; i < length ; i++){
            workingSpace.push_back(inst[i]);
        }
        workingSpace.push_back(ender);

        for(int i = 0; i < length + 1; i++){
            int wholeChunkIndex = instToIndex(&workingSpace[i]);
            probabilityLookup[wholeChunkIndex]++;

            int allButOneIndex = instToIndexTotal(&workingSpace[i]);
            totalProbabilityLookup[allButOneIndex]++;
        }
    }

    void setLimits(int minSize_, int maxSize_){
        if(minSize_ != -1)
            minSize = minSize_;
        if(maxSize != -1)
            maxSize = maxSize_;
    }

    const std::vector<Type> generateInstance(){
        std::vector<Type> inst;
        inst.reserve(maxSize);
        inst.resize(order - 1, starter);
        Type append = starter;

        while((maxSize == 0 || inst.size() < maxSize) && append != ender){
            Type* penultimateCharacters = &(inst[inst.size() - order + 1]);
            int penultimateCharactersIndex = instToIndexTotal(penultimateCharacters);
            int totalProbability = totalProbabilityLookup[penultimateCharactersIndex];
            int randomTarget = std::max(1, rand() % (totalProbability + 1));

            inst.push_back(starter);
            int startingIndex = instToIndex(penultimateCharacters);
            inst.pop_back();

            int probAcc = 0;
            for(int i = startingIndex; i < startingIndex + dictSize; i++){
                probAcc = probAcc + probabilityLookup[i];
                if(probAcc >= randomTarget){
                    append = indexToLanguage[i % dictSize];
                    inst.push_back(append);
                    break;
                }
            }
        }

        std::vector<Type> generated(inst.begin()+order - 1, inst.end() - 1);
        if(generated.size() > minSize){
            return generated;
        }
        else{
            return generateInstance();
        }
    }

    const std::string toString(){
        std::stringstream ss;
        int j = 0;
        for(int i = 0; i < probabilityLookup.size(); i++){
            if(i % dictSize == 0)
                ss << totalProbabilityLookup[j++] << std::endl;
            indexToInst(i);
            for(auto x : workingSpace){
                ss << x;
            }
            ss << '\t' << probabilityLookup[i] << std::endl;
        }
        return ss.str();
    }

};

}
