#include<bits/stdc++.h>
#include <sys/stat.h>
#include <dirent.h>

using namespace std;

/*
 * explodes a string by delimiter and returns a vector of exploded parts
 */
vector<string> explode(string const & s, char delim)
{
    vector<string> result;
    istringstream iss(s);
    for (string token; getline(iss, token, delim); )
        result.push_back(move(token));
    return result;
}

/*
 * checks whether value ends with ending or not
 */
inline bool ends_with(std::string const & value, std::string const & ending)
{
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

/*
 * checks whether path is of a directory or not
 */
bool isDirs(const char *path){
    if(ends_with((string)path,".")){
        return false;
    }
    struct stat s;

    if( stat(path,&s) == 0 )
    {
        if( s.st_mode & S_IFDIR )
        {
            //directory
            return true;
        }
        else if( s.st_mode & S_IFREG )
        {
            //file
            return false;
        }
    }
    return false;
}

/*
 * search in file
 * if search key is found result is send in stdout
 */
bool CheckWord(string filename, string search)
{
    cout<<"\n"<<filename;
    int offset,lineno=0;

    string line;
    ifstream Myfile;
    Myfile.open (filename);

    if (Myfile.is_open())
    {
        while (!Myfile.eof())
        {   lineno++;
            getline(Myfile,line);
            if ((offset = line.find(search, 0)) != string::npos)
            {
                cout<<"\n\t "<<char(204)<<" line number:"<<lineno<<":\t '" << line << "'";
            }
        }
        Myfile.close();
    }
    else
        cout << "Unable to open this file." << endl;

    return false;
}

/*
 * list directory recursively
 */
void listdir (const string path1,string exte,string search_key)
{
    const char *path=path1.c_str();

    ostringstream c_content;
    DIR *c_dir = NULL;
    c_dir = opendir (path);
    struct dirent *contents = NULL;
    if (c_dir == NULL)
    {
        cout << "\nError: current directory could not be opened correctly";
        return;
    }

    while (contents = readdir (c_dir))
    {
        if (contents == NULL)
        {
            cout << "\nError: current directory could not be read correctly";
            return;
        }
        c_content << contents->d_name << "\n";
    }
    closedir(c_dir);
    string cdir_parse = c_content.str();

    vector<string> entries=explode(cdir_parse,'\n');
    for(auto xd:entries){
        if(xd=="." || xd=="..")continue;
        string f_path=(string)path+"/"+xd;
        if(isDirs(f_path.c_str())){
            listdir(f_path,exte,search_key);
        }else if(ends_with(f_path,exte)){
            CheckWord(f_path, search_key);
        }
    }

}

/*
 * To check whether the path exists or not
 */
bool IsPathExist(const string &s)
{
    struct stat buffer;
    return (stat (s.c_str(), &buffer) == 0);
}

/*
 * to store results
 */
vector<pair<string,map<string,string>>> results;
vector<string> file_search_res;


/*
 * driver function to search directory
 */
int directory_search(char *dir_path, string file_ext, string search_key){
    /*
     * other options here if any
     */
    listdir(dir_path,file_ext,search_key);

}


int main() {
    string ini_msg="Directory search\n"
                   "It will help you searching files and text file content in a specific directory\n"
                   "What you have to provide is directory path, file extension and search key";
    cout<<ini_msg<<endl;
    cout<<"enter directory:";
    string dir_path,file_ext,search_key;
    cin>>dir_path;
    cout<<dir_path<<":";
    if(IsPathExist((string)dir_path)) {
        cout << "Exists" << endl;
        cout<<" Enter file extension without dot(eg txt php cpp etc):";
        cin>>file_ext;
        cout<<" Enter search key:";
        cin>>search_key;
        directory_search(&dir_path[0],file_ext,search_key);

    }else
        cout<<"Doesn't Exists"<<endl;

    int dummy;
    cin>>dummy;
    return 0;
}
