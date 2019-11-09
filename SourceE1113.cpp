#include "../std_lib_facilities.h"

void in_file_text(string& name_file, vector<string>&vs);            // The function of reading text from file to vector.
void reverse_word_order(vector<string>& vs1, vector<string>& vs2);  // The function of rearranging words in the text in reverse order.
void out_file_text(vector<string>& vs, string& name_file);          // The function of writing text from a vector to a file.

int main()
{
    vector<string>vs;
    cout << "Enter file name to read text:\n";
    string name;
    cin >> name;
    in_file_text(name, vs);
    vector<string>vsr;
    reverse_word_order(vs, vsr);
    cout << "Enter a file name for recording converted text:\n";
    cin >> name;
    out_file_text(vsr, name);
    return 0;
}

void in_file_text(string& name_file, vector<string>&vs)
{
    ifstream ist(name_file);
    if(!ist) error("Unable to open input file ", name_file);
    ist.exceptions(ist.exceptions() | ios_base::badbit);
    string new_line = "\n";
    for(string temp; getline(ist, temp);)
    {
        {
            stringstream ss(temp);
            for(string s; ss >> s;)
            {
                vs.push_back(s);
            }
        }
        if(!ist.eof())
            vs.push_back(new_line);
    }
}

void reverse_word_order(vector<string>& vs1, vector<string>& vs2)
{
    for(int i = vs1.size(); i > 0; --i)
    {
        vs2.push_back(vs1[i-1]);
    }
}

void out_file_text(vector<string>& vs, string& name_file)
{
    ofstream ost{name_file};
   if (!ost) error("Unable to open output file ", name_file);
   for(string x: vs)
   {
        if(x != "\n")
            ost << x << " ";
        else
        {
            ost << x;
        }
   }
}