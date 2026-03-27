#include <iostream>
#include <stack>
using namespace std;

string simplifyPath(string path){
    int n = path.length();

    int i = 1;

    stack<string> filenames;

    for(i = 1; i < n; i++){
        string name = "";

        // Ignoring slashes
        while(i < n && path[i] == '/') i++;

        if(i >= n) break;

        if(path[i] == '.' && i + 1 < n && path[i + 1] == '.' && i + 2 < n && path[i + 2] != '.'){
            // Going back

            if(!filenames.empty()) filenames.pop();
            continue;
        }
        else if(path[i] == '.' && i + 1 < n && path[i + 1] != '.'){
            continue;
        }

        while(i < n && path[i] != '/'){
            name += path[i];
            i++;
        }

        filenames.push(name);
    }

    stack<string> rev_filenames;
    string finalPath = "";

    while(!filenames.empty()){
        string name = filenames.top();
        rev_filenames.push(name);
        filenames.pop();
    }
    while(!rev_filenames.empty()){
        string name = rev_filenames.top();
        finalPath += "/";
        finalPath += name;
        rev_filenames.pop();
    }

    if(finalPath.length() == 0){
        return "/";
    }

    return finalPath;
}

int main()
{
    string path = "/a//b////c/d//././/..";

    cout << simplifyPath(path);

    cout << endl;
    return 0;
}
