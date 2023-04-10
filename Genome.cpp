#include <fstream>
#include <iostream>
#include "Genome.h"
#include <iomanip>
#include <string>


class Genclass{
public:
    float sumA,sumB;
    float sumA2,sumB2,sumAB;
    float varA,varB,covAB,r,alpha,beta,num;
    float meanA,meanB;
    unsigned n;
    Eigen::ArrayXf vecA,vecB;
    
    Genclass(unsigned dim);
    void initialize(Eigen::VectorXf a, Eigen::VectorXf b);
    void getCorr(void);
    float getVariance(Eigen::VectorXf a);
};

void Chromosome_mation::posGenome()
{
    MapPos.resize(get_num_loci());
    for(unsigned i=0;i<MapPos.size();i++){
        MapPos[i]=(*this)[i].map_pos;
    }
}

unsigned Genome_mation::Alllocation()
{
    unsigned Allloc=0;
    for(auto &i: *this   ){
        Allloc += i.get_num_loci();
    }
    
    return(Allloc);
}
