#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>


class Cell_Genome_Anml
{
public:
	enum ch  {RED=RED_ch _ID, GREEN=GREEN_ch _ID, BLUE=BLUE_ch _ID, NEUTRAL=NEUTRAL_ch _ID};
	static Cell_Genome_Anml* ProduceAvg(std::vector<Cell_Genome_Anml*> partners);
	Cell_Genome_Anml(COLORREF color);
	Cell_Genome_Anml(Cell_Genome_Anml* Cell_Genome_Anml) : Cell_Genome_Anml(Cell_Genome_Anml->brushColor) {}
	HBRUSH Get_cell();
	ch  Getch ();
	COLORREF Get_cellColor();
	bool Equals(Cell_Genome_Anml* Cell_Genome_Anml);
	~Cell_Genome_Anml();
private:
	COLORREF brushColor;
	HBRUSH brush;
};

class Genome_Anml
{
public:
    Genome_Anml(std::string name);
    Genome_Anml();
    ~Genome_Anml();
    int read_file(std::string path);
    std::string get_body();
    std::string get_name();
    int get_len();
    void print_info();

private:
    std::string name;
    std::string body;
    int len;
    int adenine_count;
    int cytosine_count;
    int guanine_count;
    int thymine_count;
};

