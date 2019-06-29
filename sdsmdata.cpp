#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	unsigned int length, height, combined, digits, mult[64], mult_lo[64], mult_hi[64];
	string name, lo, hi, fileName;

	if (argc != 4)
	{
		cout << "\n  Usage: " << argv[0] << " <name of project>";
		cout << " <length of map>" << " <height of map>" << endl;
		cout << "\n  Length and height should be numbers between 1 and 64." << endl;
		cout << "\n  Example:" << endl;
		cout << "\n    sdsmdata myproject 10 14" << endl << endl;
	}
	else
	{
		name = argv[1];

		sscanf (argv[2], "%d", &length);
		sscanf (argv[3], "%d", &height);

		combined = length * height;

		if (combined < 10 ? digits=1 :
			(combined < 100 ? digits=2 :
			(combined < 1000 ? digits=3 :
			digits = 4)));

		fileName = name + "_map.asm";
		lo = name + "_map_lo:";
		hi = name + "_map_hi:";

		ofstream theFile (fileName.c_str());
		if (theFile.is_open())
		{
			int overall = 0;


			overall = 0;
			theFile << lo << "\n";
			for (int h = 0; h < height; h=h+1)
			{
				theFile << "\t.byte ";

					for (int z = 0; z < length; z=z+1)
					{
						theFile << "<dummy";
						theFile << setfill('0');
						theFile << setw(digits);
						theFile << overall;
						if (z != length-1)
						{
							theFile << ",";
						}
						else
						{
							theFile << "\n";
						}
						overall += 1;
					}

			}

			overall = 0;

			theFile << hi << "\n";
			for (int q = 0; q < height; q=q+1)
			{
				theFile << "\t.byte ";

					for (int r = 0; r < length; r=r+1)
					{
						theFile << ">dummy";
						theFile << setfill('0');
						theFile << setw(digits);
						theFile << overall;
						if (r != length-1)
						{
							theFile << ",";
						}
						else
						{
							theFile << "\n";
						}
						overall += 1;
					}

			}

			theFile << "\n\n";
			
			overall = 0;
			
			for (int x = 0; x < combined; x++)
			{
				theFile << "dummy";
				theFile << setfill('0');
				theFile << setw(digits);
				theFile << x;
				theFile << ":\n\n";
			}


			overall = 0;
			for (int t = 0; t < height; t++)
			{
				mult[t] = t * length;
				mult_lo[t] = mult[t] & 0xff;
				if (mult[t] <= 255)
				{
					mult_hi[t] = 0;
				}
				else
				{
					mult_hi[t] = ((mult[t] >> 8) & 0xff);
				}
				overall++;
			}

			theFile << "mult_lo:\n\t.byte ";
			for (int y = 0; y < overall; y++)
			{
				theFile << "$" << setfill('0') << setw(2) << hex << mult_lo[y];
				if (y != overall-1)
				{
					theFile << ",";
				}
				else
				{
					theFile << "\n";
				}
			}

			theFile << "mult_hi:\n\t.byte ";
			for (int p = 0; p < overall; p++)
			{
				theFile << "$" << setfill('0') << setw(2) << hex << mult_hi[p];
				if (p != overall-1)
				{
					theFile << ",";
				}
				else
				{
					theFile << "\n";
				}
			}
				theFile << "\n";

			theFile << ";Needed in zeropage:\n";
			theFile << ";temp_16bit_1:\t\t\t.res 2\n";
			theFile << ";temp_16bit_2:\t\t\t.res 2\n";
			theFile << ";temp_16bit_3:\t\t\t.res 2\n";
			theFile << ";map_y:\t\t\t\t\t.res 1\n";
			theFile << ";map_x:\t\t\t\t\t.res 1\n\n";
			theFile << "map_coords:\n";
			theFile << "\tldx map_y\n";
			theFile << "\tlda map_x\n";
			theFile << "\tclc\n";
			theFile << "\tadc mult_lo, x\n";
			theFile << "\tsta temp_16bit_1+0\n";
			theFile << "\tlda mult_hi, x\n";
			theFile << "\tadc #$00\n";
			theFile << "\tsta temp_16bit_1+1\n\n";

			theFile << "\tlda #<" << name << "_map_lo\n";
			theFile << "\tclc\n";
			theFile << "\tadc temp_16bit_1+0\n";
			theFile << "\tsta temp_16bit_2+0\n";
			theFile << "\tlda #>" << name << "_map_lo\n";
			theFile << "\tadc temp_16bit_1+1\n";
			theFile << "\tsta temp_16bit_2+1\n\n";

			theFile << "\tlda #<" << name << "_map_hi\n";
			theFile << "\tclc\n";
			theFile << "\tadc temp_16bit_1+0\n";
			theFile << "\tsta temp_16bit_3+0\n";
			theFile << "\tlda #>" << name << "_map_hi\n";
			theFile << "\tadc temp_16bit_1+1\n";
			theFile << "\tsta temp_16bit_3+1\n\n";

			theFile << "\tldy #$00\n";
			theFile << "\tlda (temp_16bit_2), y\n";
			theFile << "\tsta temp_16bit_1+0\n";
			theFile << "\tlda (temp_16bit_3), y\n";
			theFile << "\tsta temp_16bit_1+1\n";
			theFile << "\trts\n";

			theFile.close();
		}
		else
		{
			cout << "NO FILE FOR YOU";
		}

    }

	return 0;
}
