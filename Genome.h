#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace Eigen;
using namespace std;
using namespace boost;


class Genome_mation: public vector<Animal_genome>
{
public:
    Genome_mation(){mapPosDone=false;}
    unsigned num_traits, num_breeds, num_chrom;
    double mutRate;
    void display(void);
    unsigned getTotalLoci();
    void set_num_chrom(unsigned n){resize(n);}
    unsigned get_num_chrom(void){return size();}
    
    bool mapPosDone;
    void mkMapPos()
    {
        for( auto &i : *this){
            i.mkMapPosFromCell_genome();
        }
        mapPosDone=true;
    };
    
    ArrayXd alleleFreqGenome;
};
class Cell_genome
{
public:
    string locusType;       
    float map_pos;
    double alleleFreq;
};

class Animal_genome: public vector <Cell_genome>
{
public:
    void     set_num_loci(unsigned n){resize(n);}
    unsigned get_num_loci(void){return size();}
    long double chr_length;
    ArrayXf MapPos;
    void     mkMapPosFromCell_genome();
};




#endif  