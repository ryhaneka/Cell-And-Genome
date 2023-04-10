#include "Cell.h"
using std::vector;


Cell::cell_genome Cell::Getcell_genome()
{
	static const int DIFF = 50;
	byte r = GetRValue(cell_rate);
	byte g = GetGValue(cell_rate);
	byte b = GetBValue(cell_rate);
	if (r - g >= DIFF && r - b >= DIFF)
		return cell_genome::RED;
	if (g - r >= DIFF && g - b >= DIFF)
		return cell_genome::GREEN;
	if (b - r >= DIFF && b - g >= DIFF)
		return cell_genome::BLUE;
	return cell_genome::NEUTRAL;
}

Cell::Cell(COLORREF cell_rate)
{
	this->cell_rate = cell_rate;
	this->brush = CreateSolidBrush(this->cell_rate);
}

HBRUSH Cell::GetBrush()
{
	return brush;
}

COLORREF Cell::Getcell_rate()
{
	return cell_rate;
}

bool Cell::Equals(Cell* cell)
{
	return cell != nullptr && this->cell_rate == cell->cell_rate;
}
void Cell::mutation_cell(string s1,int n,string s2,int m){
    n=n-1;
    m=m-1;
    int place_celln1=chro[n].DNA[0].size();
    int place_celln2=chro[n].DNA[1].size();
    int place_cellm1=chro[m].DNA[0].size();
    int place_cellm2=chro[m].DNA[1].size();
    if(chro[n].DNA[0].find(s1)!=string::nplace_cell)
        place_celln1=chro[n].DNA[0].find(s1);
    if(chro[n].DNA[1].find(s1)!=string::nplace_cell)
        place_celln2=chro[n].DNA[1].find(s1);
    if(chro[m].DNA[0].find(s2)!=string::nplace_cell)
        place_cellm1=chro[m].DNA[0].find(s2);
    if(chro[m].DNA[1].find(s2)!=string::nplace_cell)
        place_cellm2=chro[m].DNA[1].find(s2);
    if(place_celln1<place_celln2){
        chro[n].DNA[0].replace(place_celln1,s1.size(),s2);
        chro[n].DNA[1].replace(place_celln1,s1.size(),complement(s2));
    }
    else{
        chro[n].DNA[1].replace(place_celln2,s1.size(),s2);
        chro[n].DNA[0].replace(place_celln2,s1.size(),complement(s2));
    }
    if(place_cellm1<place_cellm2){
        chro[m].DNA[0].replace(place_cellm1,s2.size(),s1);
        chro[m].DNA[1].replace(place_cellm1,s2.size(),complement(s1));
    }
    else{
        chro[m].DNA[1].replace(place_cellm2,s2.size(),s1);
        chro[m].DNA[0].replace(place_cellm2,s2.size(),complement(s1));
    }
    show();
}       

Cell* Cell::ProduceAvg(vector<Cell*> cromosome)
{
	int count = cromosome.size();
	int sumR = 0;
	int sumG = 0;
	int sumB = 0;
	for (int i = 0; i < count; ++i)
	{
		sumR += GetRValue(cromosome[i]->cell_rate);
		sumG += GetGValue(cromosome[i]->cell_rate);
		sumB += GetBValue(cromosome[i]->cell_rate);
	}
	return new Cell(RGB(sumR / count, sumG / count, sumB / count));
}

Cell::~Cell()
{
	DeleteObject(this->brush);
}